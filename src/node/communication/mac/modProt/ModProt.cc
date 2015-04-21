#include "ModProt.h"

Define_Module(ModProt);

void ModProt::startup(){

	myClusterHead = -1;
	frame_count = 0;

	trace() << "NODE:" << SELF_MAC_ADDRESS << " startup()";
	//getSelfLocation(selfX, selfY);
	
	//trace() << "NODE:" << SELF_MAC_ADDRESS << " put to RX";
	
	nodeType = par("nodeType");

	if(nodeType == CLUSTER_HEAD)
		setTimer(WAKE_TO_SYNCPHASE, WAKE_TIME);
	else
		toRadioLayer(createRadioCommand(SET_STATE, RX));
	
	/*if(TRACE_MOBILITY) {
		setTimer(MOBILITY_TRACE, 0.1);
	}*/

}

void ModProt::fromNetworkLayer(cPacket * pkt, int destination) { //This will only be used in Source, no one else generates packets

	/*trace() << "New packet generated #begin";
	ModPacket* newPacket = new  ModPacket("Data Packet", MAC_LAYER_PACKET);
	newPacket->setFdst(DEST_N);
	newPacket->setPtype(DATA_PACKET);
	newPacket->setFdst(DEST_N);
	
	if(bestNode == NO_BEST_NODE) {
		trace() << "No best node, starting discovery";
		BufferDataPacket(newPacket);
		if(!findingBestNode) {
			findBestNode();
		} else {
			trace() << "Already finding a best node.";
		}
	} else {
		trace() << "Already have a bestNode, sending to " << bestNode;
		newPacket->setDestination(bestNode);
		sendPacket(newPacket);
	}*/
}



void ModProt::fromRadioLayer(cPacket * pkt, double rssi, double lqi)
{

	ModPacket *incPacket = dynamic_cast <ModPacket*>(pkt);

	if(incPacket->getPtype() == SYNC_PKT && nodeType != CLUSTER_HEAD){
		trace() << "Received SYNC_PKT from NODE:" << incPacket->getSource();

		if(rssi > -90){
			myClusterHead = incPacket->getSource();
			setTimer(WAKE_TO_SEND_REQ,incPacket->getSleep_time() + (SLOT * SELF_MAC_ADDRESS) );
			toRadioLayer(createRadioCommand(SET_STATE, SLEEP));
		}

		else{
			myClusterHead = -1;
			trace() << "NODE_" << SELF_MAC_ADDRESS << " ignored SYNC_PKT coz of low RSS: " << rssi;
			toRadioLayer(createRadioCommand(SET_STATE,RX));
		}

		return;
	}

	if(incPacket->getPtype() == REQ_PKT && nodeType == CLUSTER_HEAD && incPacket->getDestination() == SELF_MAC_ADDRESS){ 
		trace() << "Received REQ_PKT from NODE:" << incPacket->getSource();
		boundNodes.push_back(MyNode(incPacket->getSource(), incPacket->getMyX(), incPacket->getMyX() ));
		return;
	}

	if(incPacket->getPtype() == SCHED_PKT && nodeType != CLUSTER_HEAD && incPacket->getSource() == myClusterHead){ 
//		toRadioLayer(createRadioCommand(SET_STATE, SLEEP));
		//CLOG("Received SCHED_PKT");
		trace() << "Received SCHED_PKT from NODE:" << (int)incPacket->getSource();
		for(int iter=0;iter<incPacket->getSlots();iter++)
			if(incPacket->getNode_id(iter) == SELF_MAC_ADDRESS){

				setTimer(WAKE_TO_SEND_DATA,incPacket->getSlot_info(iter));
				toRadioLayer(createRadioCommand(SET_STATE, SLEEP));
				break;
			}
		return;
	}

	if(incPacket->getPtype() ==  DATA_PKT && nodeType == CLUSTER_HEAD && incPacket->getDestination() == SELF_MAC_ADDRESS){
		trace() << "Received DATA packet from NODE:" << (int)incPacket->getSource();
		DATA_PKT_RX_COUNT++;
		return;
	}

}

void ModProt::sendPacket(ModPacket *packet) {

	packet->setSource(SELF_MAC_ADDRESS);
	toRadioLayer(packet);
	toRadioLayer(createRadioCommand(SET_STATE, TX));
}


void ModProt::getSelfLocation(int& x, int& y) {
	VirtualMobilityManager *nodeMobilityModule = check_and_cast<VirtualMobilityManager*>(getParentModule()->getParentModule()->getParentModule()->getSubmodule("node",SELF_MAC_ADDRESS)->getSubmodule("MobilityManager"));
	x = nodeMobilityModule->getLocation().x;
	y = nodeMobilityModule->getLocation().y;
}


void ModProt::getLocation(int& x, int& y, int i) {
	VirtualMobilityManager *nodeMobilityModule = check_and_cast<VirtualMobilityManager*>(getParentModule()->getParentModule()->getParentModule()->getSubmodule("node",i)->getSubmodule("MobilityManager"));
	x = nodeMobilityModule->getLocation().x;
	y = nodeMobilityModule->getLocation().y;
}

// ---- NOTE_TO_SELF :  Modify this method to work properly ----
double ModProt::getRandom(double fromV, int n, double inc) { //Returns a random value between 0.1 & 0.5
	int rnd = rand() % n + 1;
	return fromV + rnd * inc;
}
// -------------------------------------------------------------

MyPacketContainer::MyPacketContainer(int t, int d) {
	timerId = t;
	dest = d;
}

MyNode::MyNode(int a, int axe, int ye) {
	address = a;
	x = axe;
	y = ye;
}

void ModProt::broadcastPkt(int pktType){

	ModPacket *syncPacket;
	syncPacket = new ModPacket("Broadcast Packet", MAC_LAYER_PACKET);
	syncPacket->setDestination(BROADCAST_MAC_ADDRESS);
	syncPacket->setPtype(pktType);
	getSelfLocation(selfX, selfY);
	syncPacket->setMyX(selfX);
	syncPacket->setMyY(selfY);
	sendPacket(syncPacket);
}

void ModProt::sendReqPacket(){

	ModPacket *reqPkt;
	reqPkt = new ModPacket("Request Packet", MAC_LAYER_PACKET);
	reqPkt->setSource(SELF_MAC_ADDRESS);
	reqPkt->setDestination(myClusterHead);
	reqPkt->setPtype(REQ_PKT);
	getSelfLocation(selfX, selfY);
	reqPkt->setMyX(selfX);
	reqPkt->setMyY(selfY);
	sendPacket(reqPkt);
}

void ModProt::sendDataPacket(){
	ModPacket *dataPkt;
	dataPkt = new ModPacket("Data Packet", MAC_LAYER_PACKET);
	dataPkt->setDestination(myClusterHead);
	dataPkt->setPtype(DATA_PKT);
	getSelfLocation(selfX, selfY);
	dataPkt->setMyX(selfX);
	dataPkt->setMyY(selfY);
	sendPacket(dataPkt);
}

void ModProt::logBoundNodes(){

	for(int iter=0;iter<boundNodes.size();iter++){
		sprintf(my_ex_buf,"NODE:%d @ (%d,%d)",boundNodes[iter].address,boundNodes[iter].x,boundNodes[iter].y);
		trace() << my_ex_buf;
	}
}

void ModProt::buildAndBroadcastSchedPkt(double sleep_t){

	ModPacket *schedPkt;
	schedPkt = new ModPacket("Schedule Packet", MAC_LAYER_PACKET);

	schedPkt->setDestination(BROADCAST_MAC_ADDRESS);
	schedPkt->setPtype(SCHED_PKT);

	schedPkt->setSlots(boundNodes.size());

	for(int iter=0;iter<boundNodes.size();iter++){
		schedPkt->setNode_id(iter,boundNodes[iter].address);
		schedPkt->setSlot_info(iter,(boundNodes[iter].address * SLOT)+ sleep_t);
	}

	sendPacket(schedPkt);
}

void ModProt::broadcastSyncPkt(double sleep_t){

	ModPacket *syncPacket;
	syncPacket = new ModPacket("Synchronization Packet", MAC_LAYER_PACKET);
	syncPacket->setDestination(BROADCAST_MAC_ADDRESS);
	syncPacket->setPtype(SYNC_PKT);
	syncPacket->setSleep_time(sleep_t);
	sendPacket(syncPacket);
}

void ModProt::logChStats(){

	trace() << "STAT : Received DATA PKTS : " << DATA_PKT_RX_COUNT ;//<< " vs " << frame_count << " frames!";
	trace() << "STAT : Transmitted DATA PKTS : " << DATA_PKT_TX_COUNT;
	trace() << "STAT : PDR : " << (double)DATA_PKT_RX_COUNT/(double)DATA_PKT_TX_COUNT;
}




void ModProt::timerFiredCallback(int timer) {


	switch(timer){

		case WAKE_TO_REQPHASE:
			// ----------------- Request Phase ----------------
			setTimer(WAKE_TO_SCHEDPHASE,REQ_PHASE_P);
			trace() << "Node:" << SELF_MAC_ADDRESS << " entering REQUEST PHASE";
			trace() << "Node:" << SELF_MAC_ADDRESS << " Listening to Request msgs";
			//--- Node:0 -> listens to request packets -> Go to fromRadioLayer() ---
			toRadioLayer(createRadioCommand(SET_STATE, RX));
			break;
			// ------------------------------------------------
	
		case WAKE_TO_SCHEDPHASE:
			// ----------------- Schedule Phase ----------------
			setTimer(WAKE_TO_DATAPHASE,SCHED_P);
			toRadioLayer(createRadioCommand(SET_STATE, RX));
			trace() << "Node:" << SELF_MAC_ADDRESS << " entering SCHEDULE PHASE";
			if(boundNodes.size() > 0)
				buildAndBroadcastSchedPkt( getTimer(WAKE_TO_DATAPHASE).dbl() - simTime().dbl() );
			break;
			// -------------------------------------------------

		case WAKE_TO_DATAPHASE:
			// ----------------- Data Phase ----------------
			setTimer(WAKE_TO_SYNCPHASE,SLOT*(2+boundNodes.size()) );
			trace() << "Node:" << SELF_MAC_ADDRESS << " entering DATA PHASE";
			logBoundNodes();
			boundNodes.erase(boundNodes.begin(), boundNodes.end());
			logChStats();
			break;
			// ---------------------------------------------

		case WAKE_TO_SYNCPHASE:
			// ----------------- Synchronization Phase ----------------
			setTimer(WAKE_TO_REQPHASE,SYNC_P);
			frame_count++;
			trace() << "Node:" << SELF_MAC_ADDRESS << " entering SYNC PHASE";
			trace() << "Node:" << SELF_MAC_ADDRESS << " broadcasting SYNC Packets";
			broadcastSyncPkt(getTimer(WAKE_TO_REQPHASE).dbl()-simTime().dbl());
			break;
			// --------------------------------------------------------

		case WAKE_TO_SEND_REQ:
				trace() << "NODE:"<< SELF_MAC_ADDRESS <<" sending Request Packet";
				REQ_PKT_TX_COUNT++;
				sendReqPacket();
				setTimer(WAKE_TO_RX,SLOT);
				break;

		case WAKE_TO_SEND_DATA:
				trace() << "NODE:"<< SELF_MAC_ADDRESS <<" sending Data Packet";
				DATA_PKT_TX_COUNT++;
				sendDataPacket();
				setTimer(WAKE_TO_RX,SLOT);
				break;

		case WAKE_TO_RX:
				toRadioLayer(createRadioCommand(SET_STATE, RX));
	}

}














