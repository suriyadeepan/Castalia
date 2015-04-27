#include "OurProt.h"

Define_Module(OurProt);

void OurProt::startup(){


	boundTo = -1;
	my_DATA_Slot = -1;
	my_DREP_Slot = -1;
	del_t = 0;
	rounds = 0;

	totalDataPktCount = 0;
	totalDataPktTxCount = 0;
	totalCntlPkts = 0;

	node_0_wake_time = -1;
	node_x_wake_time = -1;

	// begin mobility trace timer
	//setTimer(MOB_TRACE,0.1);

	trace() << "NODE:" << SELF_MAC_ADDRESS << " startup()";
	DT_nodeType = par("nodeType");
	trace() << "NODE:" << SELF_MAC_ADDRESS << " is type:" << DT_nodeType;

	// if < STATIC_NODE >
	// 	set timer to wake up during Discovery Request Phase
	if(DT_nodeType == STATIC_NODE){
	/*if( simTime().dbl() < 0.06 )
		setTimer(25,0.06000 - simTime().dbl());*/
	dataPktCount = 0;
	setTimer(WAKE_TO_DREQ, 1);
	}
	// if < MOBILE_NODE >
	//  switch radio to "rx"
	else{
//		trace() << "NODE:" << SELF_MAC_ADDRESS << " put in rx mode";
		toRadioLayer(createRadioCommand(SET_STATE,RX));
	}

}

void OurProt::fromNetworkLayer(cPacket * pkt, int destination) { //This will only be used in Source, no one else generates packets

}


bool OurProt::isActive(int addr){

	for(int i=0;i<boundNodes.size();i++)
		if(boundNodes[i].address == addr)
				return boundNodes[i].active;

	return false;
}

void OurProt::activateNode(int addr){

	for(int i=0;i<boundNodes.size();i++)
		if(boundNodes[i].address == addr){
			boundNodes[i].active = true;
			break;
		}
}

void OurProt::deactivateNode(int addr){

	for(int i=0;i<boundNodes.size();i++)
		if(boundNodes[i].address == addr)
			boundNodes[i].active = false;
}


void OurProt::removeRedundancy(int addr){

	for(int i=0;i<boundNodes.size();i++)
		if(boundNodes[i].address == addr)
			boundNodes.erase(boundNodes.begin() + i);
}



void OurProt::fromRadioLayer(cPacket * pkt, double rssi, double lqi)
{

	CPacket *incPacket = dynamic_cast <CPacket*>(pkt);


	//------- DISCOVERY REQ received by MOBILE NODE --------//
	if(incPacket->getPtype() == DISC_REQ_PKT && DT_nodeType == MOBILE_NODE){

		if(rssi > -89){
			boundTo = incPacket->getSource();
			trace() << "Received DISC_REQ_PKT from NODE_" << boundTo; 
			trace() << "WAKE_TO_DREP : " << incPacket->getTime_val() - 0.000212;
			if( incPacket->getTime_val() - 0.000212 > 0){
				setTimer(WAKE_TO_DREP,incPacket->getTime_val() - 0.000212);
				toRadioLayer(createRadioCommand(SET_STATE,SLEEP));
			}
			else
				boundTo = -1;
		}
		return;
	}
	//----------------------------------------------------//
	


	//------- DISCOVERY REP received by STATIC NODE --------//
	if(incPacket->getPtype() == DISC_REP_PKT && DT_nodeType == STATIC_NODE && incPacket->getDestination() == SELF_MAC_ADDRESS){

		trace() << "Received DISC_REP_PKT from NODE_" << incPacket->getSource();
		removeRedundancy(incPacket->getSource());
		if(boundNodes.size() < x)
			boundNodes.push_back(Node(incPacket->getSource()));
		return;
	}
	//----------------------------------------------------//

	if(incPacket->getPtype() == SCHED_PKT && DT_nodeType == MOBILE_NODE && incPacket->getSource() == boundTo){

		trace() << "Received SCHED_PKT from NODE_" << incPacket->getSource();
		for(int iter=0;iter<incPacket->getSlots();iter++)
			if(incPacket->getNode_id(iter) == SELF_MAC_ADDRESS){

				my_DATA_Slot = incPacket->getSlot_info(iter);
				toRadioLayer(createRadioCommand(SET_STATE,SLEEP));
				return;
			}

		boundTo = -1;
		return;
	}

	if(incPacket->getPtype() ==  DATA_REQUEST_PKT && DT_nodeType == MOBILE_NODE && incPacket->getDestination() == SELF_MAC_ADDRESS ){
		my_DATA_Slot = incPacket->getTime_val();
		trace() << "Received DATA_REQUEST_PKT from NODE_" << incPacket->getSource() << " SLOT : " << my_DATA_Slot;
		trace() << "Bound To " << boundTo;
		//trace() << "DIFF : " << node_x_wake_time << " - " << incPacket->getDel_t() << " = " << node_x_wake_time - incPacket->getDel_t();
		del_t = 0.8 * (node_x_wake_time - incPacket->getDel_t());
		return;
	}

	if(incPacket->getPtype() ==  DATA_REPLY_PKT && DT_nodeType == STATIC_NODE && incPacket->getDestination() == SELF_MAC_ADDRESS){
		activateNode(incPacket->getSource());
		trace() << "Received DATA_REPLY_PKT from NODE_" << incPacket->getSource();
		dataPktCount++;
		totalDataPktCount++;
		return;
	}


}


void OurProt::getSelfLocation(int& x, int& y) {
	VirtualMobilityManager *nodeMobilityModule = check_and_cast<VirtualMobilityManager*>(getParentModule()->getParentModule()->getParentModule()->getSubmodule("node",SELF_MAC_ADDRESS)->getSubmodule("MobilityManager"));
	x = nodeMobilityModule->getLocation().x;
	y = nodeMobilityModule->getLocation().y;
}


void OurProt::sendPacket(CPacket *packet) {

	packet->setSource(SELF_MAC_ADDRESS);
	toRadioLayer(packet);
	toRadioLayer(createRadioCommand(SET_STATE, TX));
}


/*void OurProt::getLocation(int& x, int& y, int i) {
	VirtualMobilityManager *nodeMobilityModule = check_and_cast<VirtualMobilityManager*>(getParentModule()->getParentModule()->getParentModule()->getSubmodule("node",i)->getSubmodule("MobilityManager"));
	x = nodeMobilityModule->getLocation().x;
	y = nodeMobilityModule->getLocation().y;
}*/


// ---- NOTE_TO_SELF :  Modify this method to work properly ----
double OurProt::getRandom(double fromV, int n, double inc) { //Returns a random value between 0.1 & 0.5
	int rnd = rand() % n + 1;
	return fromV + rnd * inc;
}

double OurProt::random(){


	//std::default_random_engine generator;
	//std::uniform_real_distribution<double> dist(0.001, 0.05);
	//std::uniform_real_distribution<double> dist(10,190);


	double randomNumber; //= dist(generator);


	//return  randomNumber;

	if(randomGenFlipper){
		randomNumber =  rand()%RANDOMNESS_GRANULARITY;
		randomNumber /= RANDOMNESS_GRANULARITY;
	}
	else
	{
		rand();
		randomNumber = rand()%RANDOMNESS_GRANULARITY;
		randomNumber /= RANDOMNESS_GRANULARITY;
	}

	randomGenFlipper = !randomGenFlipper;

	if( (int)(randomNumber*x) < 1 )
		return 0.1;
	else if ( (int)(randomNumber*x) > x)
		return (x-1)*0.1;

	return randomNumber; 
}


// -------------------------------------------------------------

PacketContainer::PacketContainer(int t, int d) {
	timerId = t;
	dest = d;
}

Node::Node(int a){
	address = a;
	slot_id = -1;
}

void OurProt::broadcastDREQ(double time_val){

	totalCntlPkts++;
	//trace() << "Time value sent with DREQ : " << time_val;
	CPacket *syncPacket;
	syncPacket = new CPacket("Broadcast Packet", MAC_LAYER_PACKET);
	syncPacket->setDestination(BROADCAST_MAC_ADDRESS);
	syncPacket->setPtype(DISC_REQ_PKT);
	syncPacket->setTime_val(time_val);
	sendPacket(syncPacket);
}


void OurProt::broadcastSCHED(){

	totalCntlPkts++;
	CPacket *schedPkt;
	schedPkt = new CPacket("Schedule Packet", MAC_LAYER_PACKET);

	schedPkt->setDestination(BROADCAST_MAC_ADDRESS);
	schedPkt->setPtype(SCHED_PKT);

	schedPkt->setSlots(boundNodes.size());

	DATA_P = 2 * DT_SLOT * boundNodes.size();

	for(int iter=0;iter<boundNodes.size();iter++){
		schedPkt->setNode_id(iter,boundNodes[iter].address);
		//boundNodes[iter].slot_id = (iter*2*DT_SLOT) + ( getTimer(WAKE_TO_DATA_P).dbl() - simTime().dbl() ) - (DT_SLOT*0.1); 
		boundNodes[iter].slot_id = iter*2;
		schedPkt->setSlot_info(iter,boundNodes[iter].slot_id);

		trace() << "[" << iter << "] NODE:" << boundNodes[iter].address << " DATA_SLOT : " << boundNodes[iter].slot_id;
		boundNodes[iter].active = false;
	}

	sendPacket(schedPkt);
}

void OurProt::updateTable(){

	for(int i=0;i<boundNodes.size();i++)
		if(boundNodes[i].active == false)
			boundNodes.erase(boundNodes.begin() + i);
}

void OurProt::sendDREP(){

	totalCntlPkts++;
	CPacket *drepPkt;
	drepPkt = new CPacket("Discovery Reply Packet", MAC_LAYER_PACKET);
	drepPkt->setDestination(boundTo);
	drepPkt->setPtype(DISC_REP_PKT);
	sendPacket(drepPkt);
}


void OurProt::sendDATA_REQ(int iter){

	totalCntlPkts++;
	CPacket *datareqPkt;
	datareqPkt = new CPacket("DATA Request Packet", MAC_LAYER_PACKET);
	datareqPkt->setDestination(boundNodes[iter].address);
	datareqPkt->setPtype(DATA_REQUEST_PKT);
	//trace() << "TO WAKE" << simTime().dbl() + (DT_SLOT * (11 + (2*iter) ) ) + ( getTimer(WAKE_TO_DREQ).dbl() - simTime().dbl() );
	datareqPkt->setTime_val( 11 + (boundNodes.size() * 2) );
	datareqPkt->setDel_t( node_0_wake_time + ((iter*2)*DT_SLOT) );
	//datareqPkt->setTime_val(DT_SLOT * 22);
	sendPacket(datareqPkt);
}

void OurProt::sendDATA_REP(){

	CPacket *datarepPkt;
	datarepPkt = new CPacket("DATA Reply Packet", MAC_LAYER_PACKET);
	datarepPkt->setDestination(boundTo);
	datarepPkt->setPtype(DATA_REPLY_PKT);

	datarepPkt->setDel_t(node_x_wake_time);

	totalDataPktTxCount++;
	sendPacket(datarepPkt);
}


void OurProt::timerFiredCallback(int timer) {

	switch(timer){


		case MOB_TRACE:
			trace() << "cool";
			getSelfLocation(selfX,selfY);
			trace() << "LOC (" << selfX << "," << selfY << ")";
			setTimer(MOB_TRACE,0.1);
			break;


		case WAKE_TO_DREQ:
			// ----------------- Discovery Request Phase ----------------
			rounds++;
			setTimer(WAKE_TO_DREP,DREQ_P);
			trace() << "CLUSTER_HEAD_" << SELF_MAC_ADDRESS << " : DATA_PKT_COUNT  " << dataPktCount;
			trace() << "STAT : # DATA_PKT_RX  " << totalDataPktCount;
			trace() << "STAT : # DATA_PKT_TX  " << totalDataPktTxCount;
			trace() << "STAT : # 1 CNTL_PKT_TX  " << totalCntlPkts;
			if(totalDataPktCount > 0 && totalDataPktTxCount > 0)
				trace() << "STAT:PDR " << (double) (totalDataPktCount)/(double) (totalDataPktTxCount+1) ;
			//dataPktCount = 0;
			trace() << "Node:" << SELF_MAC_ADDRESS << " entering DREQ PHASE";
			if(DT_nodeType == STATIC_NODE){
				setTimer(WAKE_TO_SEND_DREQ,DT_SLOT *0.1);
				updateTable();
				trace() << "round:" << rounds;
			}//}
		break;
	// ------------------------------------------------


		case WAKE_TO_DREP:
			setTimer(WAKE_TO_SCHED,DREP_P);
			trace() << "Node:" << SELF_MAC_ADDRESS << " entering DREP PHASE";
			if(DT_nodeType == MOBILE_NODE){
				my_DREP_Slot = random() * x; 
				trace() << "NODE:" << SELF_MAC_ADDRESS << " DREP SLOT : " << my_DREP_Slot;
				setTimer(WAKE_TO_SEND_DREP,my_DREP_Slot * DT_SLOT);
			}
			break;			


		case WAKE_TO_SCHED:
			trace() << "Node:" << SELF_MAC_ADDRESS << " entering SCHED PHASE";
			if(DT_nodeType == STATIC_NODE){
				setTimer(WAKE_TO_DATA_P,SCHED_P);
				setTimer(WAKE_TO_SEND_SCHED,DT_SLOT * 0.1);
				DP_iter = 0;
			}
			else{
				setTimer(WAKE_TO_DATA_PHASE,SCHED_P);
				toRadioLayer(createRadioCommand(SET_STATE,RX));
			}
			break;

		case WAKE_TO_SEND_DREQ:
			trace() << "Node:" << SELF_MAC_ADDRESS << " broadcasting DREQ_PKT";
			if(rounds < 500)
				broadcastDREQ(getTimer(WAKE_TO_DREP).dbl() - simTime().dbl());
			else
				broadcastDREQ(getTimer(WAKE_TO_DREP).dbl() - simTime().dbl() );
			break;


		case WAKE_TO_SEND_SCHED:
			trace() << "Node:" << SELF_MAC_ADDRESS << " broadcasting SCHED_PKT";
			broadcastSCHED();
			break;


		case WAKE_TO_DATA_P:
			if(DP_iter == 0 ){
				setTimer(WAKE_TO_DREQ,boundNodes.size() * 2 * DT_SLOT);
				trace() << "ENTER_DATA_PHASE NODE_" << SELF_MAC_ADDRESS;
				node_0_wake_time = simTime().dbl();
			}
			if(DP_iter < boundNodes.size()){
				setTimer(WAKE_TO_DATA_P,DT_SLOT*2);
				setTimer(WAKE_TO_SEND_DATA_REQ,DT_SLOT*0.2);
			}
			break;

		case WAKE_TO_DATA_PHASE:
				//trace() << "ENTER_DATA_PHASE NODE_" << SELF_MAC_ADDRESS;
				if(my_DATA_Slot >= 0)
					setTimer(WAKE_TO_REC_DATA_REQ,my_DATA_Slot*DT_SLOT + 0.00001);
				break;


		case WAKE_TO_SEND_DATA_REQ:
			trace() << "SEND_DATA_REQ NODE_" << SELF_MAC_ADDRESS << " " << boundNodes[DP_iter].address;
			sendDATA_REQ(DP_iter);
			DP_iter++;
			break;

//--------------|--------------|-----------------|--------------|-----------------//


		case WAKE_TO_SEND_DREP:
			//--- sleep the rest of Discovery Reply Phase --//
			trace() << "NODE:" << SELF_MAC_ADDRESS << " sending DISC_REP_PKT";
			sendDREP();
			//setTimer(WAKE_TO_SLEEP,0.0003);
			break;

		case WAKE_TO_SLEEP:
			toRadioLayer(createRadioCommand(SET_STATE,SLEEP));
			break;

		case WAKE_TO_RX:
			toRadioLayer(createRadioCommand(SET_STATE,RX));
			break;

		case WAKE_TO_REC_DATA_REQ:
			setTimer(WAKE_TO_SEND_DATA_REP,DT_SLOT);
			my_DATA_Slot = -1;
			trace() << "WOKE_FOR_DATA_REQ NODE_" << SELF_MAC_ADDRESS;
			node_x_wake_time = simTime().dbl();
			toRadioLayer(createRadioCommand(SET_STATE,RX));
			break;

		case WAKE_TO_SEND_DATA_REP:
			if(my_DATA_Slot != -1){
				setTimer(WAKE_TO_REC_DATA_REQ,(my_DATA_Slot * DT_SLOT) - del_t);
				trace() << "SEND_DATA_REP NODE_" << SELF_MAC_ADDRESS;
				sendDATA_REP();
				//trace() << "Node:" << SELF_MAC_ADDRESS << " going to SLEEP";
				setTimer(WAKE_TO_SLEEP, 0.0003);
			}
			else{
				boundTo = -1;
				toRadioLayer(createRadioCommand(SET_STATE,RX));
			}
//--------------------------------------------------------------------------------//


	}

}














