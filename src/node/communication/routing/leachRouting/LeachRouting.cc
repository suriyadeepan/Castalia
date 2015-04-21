//****************************************************************************
//*  Copyright (c) Federal University of Para, brazil - 2011                 *
//*  Developed at the Research Group on Computer Network and Multimedia      *
//*  Communication (GERCOM)     				             *
//*  All rights reserved    				                     *
//*                                                                          *
//*  Permission to use, copy, modify, and distribute this protocol and its   *
//*  documentation for any purpose, without fee, and without written         *
//*  agreement is hereby granted, provided that the above copyright notice,  *
//*  and the author appear in all copies of this protocol.                   *
//*                                                                          *
//*  Module:   LEACH Clustering Protocol for Castalia Simulator              *
//*  Version:  0.2                                                           *
//*  Author(s): Adonias Pires <adonias@ufpa.br>                              *
//*             Claudio Silva <claudio.silva@itec.ufpa.br>                   *
//****************************************************************************/

#include "LeachRouting.h"

Define_Module(LeachRouting);

void LeachRouting::startup()
{	
	/*--- The .ned file's parameters ---*/
	percentage = par("percentage");
	roundLength = par("roundLength");
	isSink = par("isSink");
	slotLength = par("slotLength");
	advPacketSize = par("advPacketSize");
	joinPacketSize = par("joinPacketSize");
	tdmaPacketSize = par("tdmaPacketSize");
	dataPacketSize = par("dataPacketSize");
	applicationID = par("applicationID").stringValue(); 

	/*--- Class parameters ---*/
	CHcandidates.clear();
	clusterMembers.clear();
	roundNumber=0;
	probability = 0;
	isCH = false;
	endFormClus = false;
	isCt = false;
	
	readXMLparams();
	if(!isSink) setTimer(START_ROUND, 0);
}

void LeachRouting::fromApplicationLayer(cPacket *pkt, const char *destination)
{	
	if(!isSink)
	{
		string dst(destination);
		LeachRoutingPacket *netPacket = new LeachRoutingPacket("Leach routing data packet", NETWORK_LAYER_PACKET);
		netPacket->setLeachRoutingPacketKind(LEACH_ROUTING_DATA_PACKET);
		netPacket->setByteLength(dataPacketSize);
		netPacket->setSource(SELF_NETWORK_ADDRESS);
		encapsulatePacket(netPacket, pkt);
		if (!isCH && endFormClus)
		{
			CHInfo info = *CHcandidates.begin();
			stringstream buffer;
			buffer << info.src;
			string dst = buffer.str();
			netPacket->setDestination(dst.c_str());	
			bufferPacket(netPacket);
		}	
		else if (!isCH && !endFormClus) 
		{
			tempTXBuffer.push(netPacket);
		}
		else if (isCH) 
		{
			bufferAggregate.push_back(*netPacket);
		}
	}		
}

void LeachRouting::fromMacLayer(cPacket *pkt, int macAddress, double rssi, double lqi){
	LeachRoutingPacket *netPacket = dynamic_cast <LeachRoutingPacket*>(pkt);

	if (!netPacket)
		return;

	switch (netPacket->getLeachRoutingPacketKind()) {

		case LEACH_ROUTING_DATA_PACKET:{
			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<macAddress<<" "<<"LEACH_ROUTING_DATA_PACKET "<<netPacket ->getSource() ;
			string dst(netPacket->getDestination());
			if (isCH && dst.compare(SELF_NETWORK_ADDRESS) == 0){
				//trace() << "Node " << self << " Aggregate Data Frame \n";
				bufferAggregate.push_back(*netPacket);	
			}else if (dst.compare(SINK_NETWORK_ADDRESS) == 0 && isSink) {
				trace() << "Node " << self << " Processing Data Packet \n";
				toApplicationLayer(decapsulatePacket(netPacket));
			}
			break;	
		}
		case LEACH_ROUTING_ADV_PACKET:{
		Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<macAddress<<" "<<"LEACH_ROUTING_ADV_PACKET "<<netPacket ->getSource() ;	
			if(!isCH && !isSink)
			{	
				//trace() << "Node " << self << " Received a Advertisement Message of node " << netPacket->getSource() << " with RSSI: " << rssi << "\n";	
				CHInfo rec;
				rec.src = atoi(netPacket->getSource());
				rec.rssi = rssi;
				CHcandidates.push_front(rec);
			}
			break;
		}
		case LEACH_ROUTING_JOIN_PACKET:{
		Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<macAddress<<" "<<"LEACH_ROUTING_JOIN_PACKET "<<netPacket ->getSource() ;
			string dst(netPacket->getDestination());
			if(isCH && dst.compare(SELF_NETWORK_ADDRESS) == 0) {
				//trace() << "Node " << self << " Received a Join Request. Adding to clusterMembers\n";
				clusterMembers.push_back(atoi(netPacket->getSource()));
			}
	 		break;
		}
		case LEACH_ROUTING_TDMA_PACKET:{
		Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<macAddress<<" "<<"LEACH_ROUTING_TDMA_PACKET "<<netPacket ->getSource() ;
			if(!isCH && !isSink)
			{
				clusterLength = netPacket->getScheduleArraySize();
				for(int i=0; i<netPacket->getScheduleArraySize(); i++) {
					if (netPacket->getSchedule(i)==atoi(SELF_NETWORK_ADDRESS)) {	
						setStateSleep();
						setTimer(START_SLOT, i*slotLength);
						//trace() << "Node " << self << " Received TDMA pkt, I am: "<< i << "th \n";
						break;
					}			
				}
			}
			break;
		}
	}
}

void LeachRouting::timerFiredCallback(int index)
{
	switch (index) {
		
		case START_ROUND:{
			setStateRx();
			setPowerLevel(maxPower);
			endFormClus = false;
			CHcandidates.clear();
			clusterMembers.clear();
			if (getTimer(START_SLOT) != 0) { 
				cancelTimer(START_SLOT);
			}
			
			if (roundNumber >= 1/percentage) {
				roundNumber=0;
				isCt = false;
				isCH = false;
				NodeStatinfos()<<self<<" NODE";
			}	
			
			double randomNumber = uniform(0,1);
			double timer = uniform(0,1);
			if(isCH) {
				isCH = false;
				isCt = true;
				NodeStatinfos()<<self<<" NODE";
			}
			if(isCt) {
				probability = 0;
			} else {
				if (roundNumber >= (1/percentage - 1)){
					probability = 1;
				}else {
					probability = percentage/(1-percentage*(roundNumber % (int) (1/percentage)));
				}
			}		
			if (randomNumber<probability) 
			{	
				setTimer(SEND_ADV, (timer));
				setTimer(MAKE_TDMA, 2.0+timer);
				//trace() << "Node " << self << " is Cluster Head.";
				isCH=true;
				NodeStatinfos()<<self<<" CLUSTER_HEAD";
			}
			if (!isCH) setTimer(JOIN_CH, (1.0+timer));
			roundNumber++;
			setTimer(START_ROUND, roundLength);
			break;
		}
		case SEND_ADV:{	
			LeachRoutingPacket *crtlPkt = new LeachRoutingPacket("ClusterHead Announcement Packet", NETWORK_LAYER_PACKET);
			crtlPkt->setByteLength(advPacketSize);
			crtlPkt->setLeachRoutingPacketKind(LEACH_ROUTING_ADV_PACKET);
			crtlPkt->setSource(SELF_NETWORK_ADDRESS);
			crtlPkt->setDestination(BROADCAST_NETWORK_ADDRESS);
			toMacLayer(crtlPkt, BROADCAST_MAC_ADDRESS);
			//trace() << "Node " << self << " Sent Beacon";
			break;
		}
		case JOIN_CH:{
			if(CHcandidates.size()!=0){	
				CHcandidates.sort(cmpRssi);
				LeachRoutingPacket *crtlPkt = new LeachRoutingPacket("ClusterMember Join Packet", NETWORK_LAYER_PACKET);
				crtlPkt->setLeachRoutingPacketKind(LEACH_ROUTING_JOIN_PACKET);
				crtlPkt->setByteLength(joinPacketSize);	
				crtlPkt->setSource(SELF_NETWORK_ADDRESS);
				CHInfo info = *CHcandidates.begin();
				stringstream buffer;
				buffer << info.src;
				string dst = buffer.str();
				crtlPkt->setDestination(dst.c_str());			
				toMacLayer(crtlPkt, BROADCAST_MAC_ADDRESS);
				endFormClus = true;
				//trace() << "Node " << self << " Sent Join Request to " << dst;
			}
			break;
		}
		case MAKE_TDMA:{
			if (clusterMembers.size()!=0){
				LeachRoutingPacket *crtlPkt = new LeachRoutingPacket("ClusterHead TDMA Packet", NETWORK_LAYER_PACKET);
				crtlPkt->setByteLength(tdmaPacketSize);
				crtlPkt->setLeachRoutingPacketKind(LEACH_ROUTING_TDMA_PACKET);
				crtlPkt->setSource(SELF_NETWORK_ADDRESS);
				crtlPkt->setDestination(BROADCAST_NETWORK_ADDRESS);
				clusterLength = clusterMembers.size();	
				crtlPkt->setScheduleArraySize(clusterMembers.size());	
				for(int i=0; i<clusterLength; i++) crtlPkt->setSchedule(i,clusterMembers[i]);
				toMacLayer(crtlPkt, BROADCAST_MAC_ADDRESS);
				//trace() << "Node " << self << " Sent TDMA pkt";
				setTimer(START_SLOT, clusterLength*slotLength);
			}
			else setTimer(START_SLOT, slotLength);					
			break;
		}
		case START_SLOT:{
			if(isCH && clusterMembers.size()==0) setTimer(START_SLOT, slotLength);	
			else setTimer(START_SLOT, clusterLength*slotLength);
			if (isCH) {
				sendAggregate(); 
				processBufferedPacket();
				//trace() << "Node " << self << " Sent Pkt Aggr"  << "\n";
			}
			if (!isCH){
				CHInfo info = *CHcandidates.begin();
				int power = maxPower - ((info.rssi)-(sensibility));
				levelTxPower(power);
				//trace() << "Node " << self << " Sent Data Packet"  << "\n";
				processBufferedPacket();
				setTimer(END_SLOT, slotLength);
			}
			break;
		}
		case END_SLOT:
		{
			//trace() << "Node " << self << " Sleept"  << "\n";
			if (!isSink && !isCH) setStateSleep();
			break;
		}
	}
}

void LeachRouting::sendAggregate()
{
	if(bufferAggregate.size()!=0)
	{	
		double bitsLength = bufferAggregate.size() * dataPacketSize * 1000;
		double energyBit = (aggrConsumption / pow(10,9)) * bitsLength;
		powerDrawn(energyBit);
		LeachRoutingPacket *aggrPacket = new LeachRoutingPacket("ClusterHead Aggredated Packet", NETWORK_LAYER_PACKET);
		aggrPacket->setByteLength(dataPacketSize+4);
		aggrPacket->setLeachRoutingPacketKind(LEACH_ROUTING_DATA_PACKET);
		aggrPacket->setSource(SELF_NETWORK_ADDRESS);
		aggrPacket->setDestination(SINK_NETWORK_ADDRESS);
		
		ApplicationPacket *newPacket = new ApplicationPacket("App generic packet", APPLICATION_PACKET);
		newPacket->setData(0);
		newPacket->getAppNetInfoExchange().destination = string("0");
		newPacket->getAppNetInfoExchange().source = selfAddress;
		newPacket->getAppNetInfoExchange().timestamp = simTime();
		newPacket->setApplicationID(applicationID.c_str());
		encapsulatePacket(aggrPacket, newPacket);

		bufferPacket(aggrPacket);
		bufferAggregate.clear();
	}
}

void LeachRouting::processBufferedPacket()
{
	while (!tempTXBuffer.empty())
	{
		cPacket *pkt = tempTXBuffer.front();	
		LeachRoutingPacket *netPacket = dynamic_cast <LeachRoutingPacket*>(pkt);
		CHInfo info = *CHcandidates.begin();
		stringstream buffer;
		buffer << info.src;
		string dst = buffer.str();
		netPacket->setDestination(dst.c_str());
		bufferPacket(netPacket); 
		tempTXBuffer.pop();
	}

	while (!TXBuffer.empty()) {
		toMacLayer(TXBuffer.front(), BROADCAST_MAC_ADDRESS);
		TXBuffer.pop();
	}	
}

void LeachRouting::setStateRx()
{
	send(createRadioCommand(SET_STATE, RX), "toMacModule");	
}

void LeachRouting::setPowerLevel(double powerLevel)
{
	send(createRadioCommand(SET_TX_OUTPUT, powerLevel), "toMacModule");
}

void LeachRouting::setStateSleep()
{
	send(createRadioCommand(SET_STATE, SLEEP), "toMacModule");
}

void LeachRouting::levelTxPower(int linkBudget)
{
	vector<int>::iterator constIterator;
	for (constIterator = powers.begin();
		constIterator != powers.end();
	        constIterator++ ) {
		if(*constIterator > (linkBudget))
		{
			setPowerLevel(*constIterator);
			break;
		}
	}
}

void LeachRouting::readXMLparams()
{
	cXMLElement *rootelement = par("powersConfig").xmlValue();
	if (!rootelement) endSimulation();
	cXMLElement* data = rootelement->getFirstChildWithTag("maxPower");
	maxPower = atoi(data->getNodeValue());
	data = rootelement->getFirstChildWithTag("sensibility");
	sensibility = atoi(data->getNodeValue());
	data = rootelement->getFirstChildWithTag("aggrConsumption");
	aggrConsumption = atoi(data->getNodeValue());
	cXMLElementList sources = rootelement->getChildrenByTagName("power");
	for (int s = 0; s < sources.size(); s++)
		powers.push_back(atoi(sources[s]->getNodeValue()));
	if (powers.size() < 1) endSimulation();
	sort(powers.begin(), powers.end());
}

bool cmpRssi(CHInfo a, CHInfo b){
	return (a.rssi > b.rssi);
}
