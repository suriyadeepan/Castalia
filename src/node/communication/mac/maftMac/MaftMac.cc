#include "MaftMac.h"

Define_Module(MaftMac);

void MaftMac::startup(){

	// variable init
	boundTo = -1;
	dataChannel = -1;
	dataPair = -1;
	pktsRxed = 0;
	del_t = 0;

	pktsGen = 0;
	round = 0;

	//MFT_PKT_GEN_TIME = 0.01;

	//--- init Mobility Manager ---//
	initMobilityManager();

	// -- Generate Packets -- //
	setTimer(GEN_PKT,MFT_SLOT);

	trace() << "NODE:" << SELF_MAC_ADDRESS << " startup()";
	nodeType = par("nodeType");
	trace() << "NODE:" << SELF_MAC_ADDRESS << " is type:" << nodeType;

	// set channel to MFT_CNTL_CHANNEL
	toRadioLayer(createRadioCommand(SET_CARRIER_FREQ, ((MFT_CNTL_CHANNEL-10)*5) + 2400) );
	
	if(nodeType == CLUSTER_HEAD)
		setTimer(WAKE_TO_SYNC, 1);
	else{
 
		macType = -1;
		/*if(SELF_MAC_ADDRESS % 2 == 0)
			macType = REC;
		else
			macType = SEN;*/

		toRadioLayer(createRadioCommand(SET_STATE,RX));
		trace() << "NODE:" << SELF_MAC_ADDRESS << " in RX";
	}

}



void MaftMac::fromNetworkLayer(cPacket * pkt, int destination) { //This will only be used in Source, no one else generates packets

}


void MaftMac::fromRadioLayer(cPacket * pkt, double rssi, double lqi){


	MaftPacket *incPacket = dynamic_cast <MaftPacket*>(pkt);
	
	if(incPacket->getPtype() == SYNC_PKT && nodeType == MOBILE_NODE && rssi > -89){

		// reinitialize variables
		pktsRxed = 0;
		dataChannel = -1;
		dataPair = -1;

		if(round == 0){
			round++;
			pktsGen = 0;
		}

		boundTo = incPacket->getSource();	

		trace() << "NODE_" << SELF_MAC_ADDRESS << " : Received SYNC from " << boundTo;
		trace() << "Time value : " << incPacket->getTime_val();
		setTimer(WAKE_TO_REC_SCHED,(MFT_SLOT * META_P) + incPacket->getTime_val() - (2*MFT_MINI_SLOT) + del_t);
		//setTimer(WAKE_TO_SEND_META,( (int)uniform(1,40) * MFT_MINI_SLOT ) + incPacket->getTime_val()  );
		setTimer(WAKE_TO_SEND_META,( SELF_MAC_ADDRESS * 5 * MFT_MINI_SLOT ) + incPacket->getTime_val()  );
		toRadioLayer(createRadioCommand(SET_STATE,SLEEP));
		return;
	}

	if(incPacket->getPtype() == META_PKT && nodeType == CLUSTER_HEAD){// && rssi > -89 && phase == P_META){
		trace() << "NODE_" << SELF_MAC_ADDRESS << " : Received META from " << incPacket->getSource() << " @ (" << incPacket->getX() << "," << incPacket->getY() << ")" << " moving at " << incPacket->getV() << " in " << incPacket->getAngle() << " dir";

		boundNodes[boundNodesSize] = incPacket->getSource();
		boundNodesX[boundNodesSize] = incPacket->getX();
		boundNodesY[boundNodesSize] = incPacket->getY();
		boundNodesSizes[boundNodesSize++] = incPacket->getDataSize();

		return;
	}

	if(incPacket->getPtype() == SCHED_PKT && nodeType == MOBILE_NODE && boundTo == incPacket->getSource()){
		trace() << "NODE_" << SELF_MAC_ADDRESS << " : Received SCHED_PKT from " << incPacket->getSource();
		boundTo = -1;

		if( SELF_MAC_ADDRESS == incPacket->getNewCH() ){
			trace() << "I, NODE_" << SELF_MAC_ADDRESS << " am elected by " << incPacket->getSource() << " as the new CH..";
			nodeType = CLUSTER_HEAD;
		}

		// -- time correction -- //
		del_t = 0.8 * (node_x_sched_wakeup - incPacket->getDel_t());
		// -------------------- //

		macType = -1;

		for(int i=0;i< incPacket->getPair_count();i++)
			if( incPacket->getNode(i) == SELF_MAC_ADDRESS ){
				macType = SEN;
				dataPair = incPacket->getPair(i);
				dataChannel = incPacket->getChannel(i);
				trace() << SELF_MAC_ADDRESS << " --> " << dataPair << " #" << dataChannel;
				toRadioLayer(createRadioCommand(SET_CARRIER_FREQ, ((dataChannel-10)*5) + 2400) );
				setTimer(WAKE_TO_SEND_DATA,MFT_MINI_SLOT);
				return;
			}

		for(int i=0;i< incPacket->getPair_count();i++)
			if( incPacket->getPair(i) == SELF_MAC_ADDRESS ){
				macType = REC;
				dataPair = incPacket->getNode(i);
				dataChannel = incPacket->getChannel(i);
				trace() << SELF_MAC_ADDRESS << " <-- " << dataPair << " #" << dataChannel;
				toRadioLayer(createRadioCommand(SET_CARRIER_FREQ, ((dataChannel-10)*5) + 2400) );
				setTimer(WAKE_TO_RX,MFT_MINI_SLOT);
				return;
			}

		macType = IDL;
		return;
	}

	if(macType == REC && incPacket->getPtype() == DATA_PKT && incPacket->getDestination() == SELF_MAC_ADDRESS && incPacket->getSource() == dataPair){
			trace() << "NODE_" << SELF_MAC_ADDRESS << " received DATA_PKT from " << incPacket->getSource();
			pktsRxed++;
			cancelTimer(DATA_TRANSFER_TIMEOUT);
			setTimer(DATA_TRANSFER_TIMEOUT,2*MFT_MINI_SLOT);
			if(incPacket->getEOT()){
				cancelTimer(DATA_TRANSFER_TIMEOUT);
				toRadioLayer(createRadioCommand(SET_CARRIER_FREQ, ((MFT_CNTL_CHANNEL-10)*5) + 2400) );
				setTimer(WAKE_TO_RX,MFT_MINI_SLOT);
			}
			return;
	}

	return;
}



void MaftMac::sendPacket(MaftPacket *packet) {

	packet->setSource(SELF_MAC_ADDRESS);
	toRadioLayer(packet);
	toRadioLayer(createRadioCommand(SET_STATE, TX));
}


void MaftMac::sendMeta(){

	MaftPacket *metaPkt;
	metaPkt = new MaftPacket("Meta Packet", MAC_LAYER_PACKET);
	metaPkt->setDestination(boundTo);
	metaPkt->setPtype(META_PKT);
	getSelfLocation(x,y);
	metaPkt->setX(x);
	metaPkt->setY(y);
	metaPkt->setV(getSpeed());
	metaPkt->setAngle(getDirection());
	metaPkt->setDataSize(pktsGen);
	sendPacket(metaPkt);
}



void MaftMac::broadcastSync(double time_val){

	MaftPacket *syncPacket;
	syncPacket = new MaftPacket("Sync Packet", MAC_LAYER_PACKET);
	syncPacket->setDestination(BROADCAST_MAC_ADDRESS);
	syncPacket->setPtype(SYNC_PKT);
	syncPacket->setTime_val(time_val);
	sendPacket(syncPacket);
}

void MaftMac::broadcastSched(double time_val){

	MaftPacket *schedPkt;
	schedPkt = new MaftPacket("Sync Packet", MAC_LAYER_PACKET);
	schedPkt->setDestination(BROADCAST_MAC_ADDRESS);
	schedPkt->setPtype(SCHED_PKT);
	schedPkt->setTime_val(time_val);
	schedPkt->setDel_t(node_0_sched_wakeup);

	schedPkt->setNewCH(boundTo);

	int pairCount = boundNodesSize/2;
	int j=0;
	schedPkt->setPair_count(pairCount);

	// --- before scheduling, sort boundNodes buffer --- //
	gnomesort(pairCount, boundNodes);

	// ------- construct schedule ------------ //
	trace() << "----------- SCHED ------------";
	for(int i=0;i<pairCount;i++){

		j = i + ceil(boundNodesSize/2);

		schedPkt->setNode(i,boundNodes[i]);
		schedPkt->setPair(i,boundNodes[j]);
		schedPkt->setChannel(i,12+i);
		trace() << " [" << i << "] " << boundNodes[i]<< " -> " << boundNodes[j] << " @" << 12+i;
	} // --------------------------------------//
	trace() << "------------------------------";

	sendPacket(schedPkt);
}

void MaftMac::sendData(bool EOT){

	MaftPacket *dataPkt;
	dataPkt = new MaftPacket("Meta Packet", MAC_LAYER_PACKET);
	dataPkt->setDestination(dataPair);
	dataPkt->setPtype(DATA_PKT);
	dataPkt->setEOT(EOT);
	sendPacket(dataPkt);
}


void MaftMac::timerFiredCallback(int timer) {

	switch(timer){

		// ----- Pkt generation -----//
		case GEN_PKT:
			if(pktsGen < 10)
				pktsGen++;
			setTimer(GEN_PKT,0.004);
			break;

		// ---------- CLUSTER HEAD -------------//
		case WAKE_TO_SYNC:
			trace() << "NODE_" << SELF_MAC_ADDRESS << " WAKE_TO_SYNC";
			phase = P_SYNC;
			setTimer(WAKE_TO_META,MFT_SLOT);
			broadcastSync( getTimer(WAKE_TO_META).dbl() - simTime().dbl() );
			boundNodesSize = 0;
			break;


		case WAKE_TO_META:
			trace() << "NODE_" << SELF_MAC_ADDRESS << " WAKE_TO_META";
			phase = P_META;
			setTimer(WAKE_TO_SCHED,META_P * MFT_SLOT);
			toRadioLayer(createRadioCommand(SET_STATE,RX));
			break;

		case WAKE_TO_SCHED:
			node_0_sched_wakeup = simTime().dbl();
			trace() << "NODE_" << SELF_MAC_ADDRESS << " WAKE_TO_SCHED";
			phase = P_SCHED;
			boundTo = chooseNewCH();
			broadcastSched( getTimer(WAKE_TO_SYNC).dbl() - simTime().dbl() );
			setTimer(WAKE_TO_SYNC,SCHED_P * MFT_SLOT);
			break;



	 // ----------- MOBILE NODE -------------- //
		case WAKE_TO_SEND_META:
			trace() << "NODE_" << SELF_MAC_ADDRESS << " WAKE_TO_SEND_META";
			sendMeta();
			setTimer(WAKE_TO_SLEEP,MFT_MINI_SLOT);
			//setTimer(WAKE_TO_RX,MFT_MINI_SLOT);
			break;

		case WAKE_TO_REC_SCHED:
			node_x_sched_wakeup = simTime().dbl();
			trace() << "NODE_" << SELF_MAC_ADDRESS << " WAKE_TO_REC_SCHED";
			toRadioLayer(createRadioCommand(SET_STATE,RX));
			break;

		case WAKE_TO_SEND_DATA:
			//trace() << "NODE_" << SELF_MAC_ADDRESS << " WAKE_TO_SEND_DATA";
			if(pktsGen > 0){
				setTimer(WAKE_TO_SEND_DATA,MFT_MINI_SLOT);
				if(pktsGen == 1)
					sendData(true);
				else
					sendData(false);
				pktsGen--;
			}
			else{//-- after sending out 10 packets --//
				//----- switch to control channel ----//
				toRadioLayer(createRadioCommand(SET_CARRIER_FREQ, ((MFT_CNTL_CHANNEL-10)*5) + 2400) );
				setTimer(WAKE_TO_RX,MFT_MINI_SLOT);
			}
			break;

			//-- when a receiver doesn't receive 10 packets --//
			//----- and the time alloted for data transfer --//
			//--------- has come to an end------------------//
		case DATA_TRANSFER_TIMEOUT:
			toRadioLayer(createRadioCommand(SET_CARRIER_FREQ, ((MFT_CNTL_CHANNEL-10)*5) + 2400) );
			setTimer(WAKE_TO_RX,MFT_MINI_SLOT);
			break;


	 // -------------- Common ---------------//
		case WAKE_TO_RX:
			trace() << "NODE_" << SELF_MAC_ADDRESS << " in RX";
			toRadioLayer(createRadioCommand(SET_STATE,RX));
			break;

		case WAKE_TO_SLEEP:
			trace() << "NODE_" << SELF_MAC_ADDRESS << " in SLEEP";
			toRadioLayer(createRadioCommand(SET_STATE,SLEEP));
			break;
	}


}

/*MNode::MNode(int a){
	address = a;
	active = false;
}*/

void MaftMac::initMobilityManager(){ nodeMobilityModule = check_and_cast <VirtualMobilityManager *> (getParentModule()->getParentModule()-> getSubmodule("MobilityManager")); }

void MaftMac::getSelfLocation(int& x, int& y) { x = nodeMobilityModule->getLocation().x;
 	y = nodeMobilityModule->getLocation().y;
}

double MaftMac::getSpeed(){ return nodeMobilityModule->getSpeed(); }
double MaftMac::getDirection(){ return nodeMobilityModule->getDirection(); }


// --- sort boundNodes based on data_size --- //
void MaftMac::gnomesort(int n, int ar[]) {

	int i = 0;
	
	while (i < n) {
		if (i == 0 || ar[i-1] >= ar[i]) i++;
		else {int tmp = ar[i]; ar[i] = ar[i-1]; ar[--i] = tmp;}
	}
}


int MaftMac::channelToFrequency(int channel){ return ((channel-10)*5) + 2400; } 
double MaftMac::distance(double x1, double y1, double x2, double y2){ return sqrt( ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)) ); }

int MaftMac::chooseNewCH(){

	double centroid_x=0, centroid_y=0;

	for(int i=0;i<boundNodesSize;i++){
		centroid_x += boundNodesX[i]/boundNodesSize; centroid_y += boundNodesY[i]/boundNodesSize;
	}

	double dist = 0;
	double minDist = 10000;
	int bestNode = -1;

	for(int i=0;i<boundNodesSize;i++){
		dist = distance(boundNodesX[i],boundNodesY[i],centroid_x,centroid_y);
		if(dist  < minDist){
			bestNode = boundNodes[i];
			minDist = dist;
		}
	}

	return bestNode;
}

