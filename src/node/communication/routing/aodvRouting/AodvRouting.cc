/***********************************************************************************************
 *  Copyright (c) Federal University of Para, brazil - 2012                                    *
 *  Developed at the Research Group on Computer Network and Multimedia Communication (GERCOM)  *
 *  All rights reserved                                                                        *
 *                                                                                             *
 *  Permission to use, copy, modify, and distribute this protocol and its documentation for    *
 *  any purpose, without fee, and without written agreement is hereby granted, provided that   *
 *  the above copyright notice, and the author appear in all copies of this protocol.          *
 *                                                                                             *
 *  Author(s): C. Perkins                                                                      *
 *  Reference Paper: RFC 3561                                                                  *
 *  Implementarion: Thiago Fernandes <thiago.oliveira@itec.ufpa.br> <thiagofdso.ufpa@gmail.com>* 
 **********************************************************************************************/

#include "AodvRouting.h"
#include <csimulation.h>

Define_Module(AodvRouting);

void AodvRouting::startup()
{
	//parametres
	activeRouteTimeout = (double)par("activeRouteTimeout") / 1000.0;
	allowedHelloLoss = par("allowedHelloLoss");
	helloInterval = (double)par("helloInterval") / 1000.0;
	localAddTTL = par("localAddTTL");
	netDiameter = par("netDiameter");
	nodeTraversalTime = (double)par("nodeTraversalTime") / 1000.0;
	rerrRatelimit = par("rerrRatelimit");
	rreqRetries = par("rreqRetries");
	rreqRatelimit = par("rreqRatelimit");
	timeoutBuffer = par("timeoutBuffer");
	ttlStart = par("ttlStart");
	ttlIncrement = par("ttlIncrement");
	ttlThreshould = par("ttlThreshould");
	currSeqNum = 1; 
	currRreqID = 0; 
	rt = new RoutingTable();

declareOutput("inBuffer");

}

void AodvRouting::finish(){
	VirtualRouting::finish();
	AodvRREQPacket* rreqpkt;
	AodvRERRPacket* rerrpkt;
	// clear the buffer
	while (!rreqBuffer.empty()) {
		rreqpkt = rreqBuffer.front();
		rreqBuffer.pop();
		cancelAndDelete(rreqpkt);
	}
	while (!rerrBuffer.empty()) {
		rerrpkt = rerrBuffer.front();
		rerrBuffer.pop();
		cancelAndDelete(rerrpkt);
	}

}

void AodvRouting::setRreqBoardcastDropTimer(const char* dest, const char* source, int id){
	if(checkExpireEntry(&rreqBroadcast, source, id)){
		return;
	}
	RreqExpireTimerSet rets;
	rets.canceled = false;
	rets.dest = string(dest);
	rets.lifetime = simTime().dbl() + 0.6;	
	rets.originator = string(source);
	rets.rreqID = id;
	//if the first to expire changes
	if(!rreqBroadcast.empty() && rets.lifetime < rreqBroadcast.top().lifetime){
		cancelTimer(AODV_RREQ_BOARDCAST_DROP_TIMER);
	}
	rreqBroadcast.push(rets);
	if(getTimer(AODV_RREQ_BOARDCAST_DROP_TIMER).dbl()<=0){
		setTimer(AODV_RREQ_BOARDCAST_DROP_TIMER, rreqBroadcast.top().lifetime - simTime().dbl());
	}

}

bool AodvRouting::isInRreqBlacklist(const char* dest){
    for(list<string>::const_iterator i=rreqBlacklist.begin();i!=rreqBlacklist.end();++i){
        string s = *i;
        if(s.compare(dest)==0){
            return true;
        }
    }
    return false;
}

bool AodvRouting::checkExpireEntry(const priority_queue <RreqExpireTimerSet, vector<RreqExpireTimerSet>, RreqExpireLifetimeCompare>* exq,
								const char* dest){
	const RreqExpireTimerSet* q0;
	if(!(exq->empty())){
		q0 = &(exq->top());
		for(unsigned int i = 0; i < exq->size(); i++){
			if(q0[i].dest.compare(dest)==0){
				return true;
			}
		}
	}
	return false;
}

void AodvRouting::cancelExpireEntry(priority_queue <RreqExpireTimerSet, vector<RreqExpireTimerSet>, RreqExpireLifetimeCompare>* exq,
								const char* dest){
	RreqExpireTimerSet* q0;
		if(!(exq->empty())){
			q0 = (RreqExpireTimerSet*)&(exq->top());
			for(unsigned int i = 0; i < exq->size(); i++){
				if(q0[i].dest.compare(dest)==0){
					q0[i].canceled = true;
					return;
				}
			}
		}
		return;
}

void AodvRouting::setRrepAckTimer(const char* neib){
	//check if is already waiting for the neighbor to ack
	const RoutingTableEntryExpireTimerSet* q0;
	if(!(rrepAckExpire.empty())){
		q0 = &(rrepAckExpire.top());
		for(unsigned int i = 0; i < rrepAckExpire.size(); i++){
			if(q0[i].destination.compare(neib)==0){
				return;
			}
		}
	}
	rrepAcked[string(neib)]=false;
	RoutingTableEntryExpireTimerSet ratts;
	ratts.destination = string(neib);
	ratts.lifetime = simTime().dbl() + 2 * nodeTraversalTime;
	rrepAckExpire.push(ratts);
	if(getTimer(AODV_RREP_ACK_WAIT_TIMER).dbl()<=0){
		setTimer(AODV_RREP_ACK_WAIT_TIMER, rrepAckExpire.top().lifetime - simTime().dbl());
	}
}

void AodvRouting::setRreqBlacklistTimer(const char* neib){
	//check if is already in the blacklist
	const RoutingTableEntryExpireTimerSet* q0;
	if(!(rreqBlacklistTimeout.empty())){
		q0 = &(rreqBlacklistTimeout.top());
		for(unsigned int i = 0; i < rreqBlacklistTimeout.size(); i++){
			if(q0[i].destination.compare(neib)==0){
				return;
			}
		}
	}
	RoutingTableEntryExpireTimerSet rbetts;
	rbetts.destination = string(neib);
	rbetts.lifetime = simTime().dbl() + 2 * rreqRetries * nodeTraversalTime * netDiameter;
	rreqBlacklistTimeout.push(rbetts);
	if(getTimer(AODV_RREQ_BLACKLIST_REMOVE_TIMER).dbl()<=0){
		setTimer(AODV_RREQ_BLACKLIST_REMOVE_TIMER, rreqBlacklistTimeout.top().lifetime - simTime().dbl());
	}
}

void AodvRouting::setRreqExpirationTimer(const char* dest){
	if(checkExpireEntry(&rreqRequest, dest)){
		return;
	}
	double expTime = 2 * netDiameter * nodeTraversalTime;
	for (int i=1;i<rreqRetryCount[string(dest)];i++){
		expTime *= 2;
	}
	RreqExpireTimerSet rets;
	rets.canceled = false;
	rets.dest = string(dest);

	rets.lifetime = simTime().dbl() + activeRouteTimeout/10; 
	rets.originator = string(SELF_NETWORK_ADDRESS);
	rets.rreqID = currRreqID;
	//if the first to expire changes
	if(!rreqRequest.empty() && rets.lifetime < rreqRequest.top().lifetime){
		cancelTimer(AODV_RREQ_EXPIRATION_TIMER);
	}
	rreqRequest.push(rets);
	if(getTimer(AODV_RREQ_EXPIRATION_TIMER).dbl()<=0){
		setTimer(AODV_RREQ_EXPIRATION_TIMER,rreqRequest.top().lifetime - simTime().dbl());
	}

}

bool AodvRouting::isRreqRequstActive(const char* dest){
	const RreqExpireTimerSet* q0;
	AodvRREQPacket** q1;
	//on going
	if(!(rreqRequest.empty())){
		q0 = &(rreqRequest.top());
		for(unsigned int i = 0; i < rreqRequest.size(); i++){
			if(q0[i].dest.compare(dest)==0){
				return true;
			}
		}
	}
	//buffered
	if(!rreqBuffer.empty()){
		q1 = &(rreqBuffer.front());
		for(unsigned int i = 0; i < rreqBuffer.size(); i++){
			if(string(q1[i]->getDestinationAodv()).compare(dest)==0){
				return true;
			}
		}
	}
	return false;
}

bool AodvRouting::checkExpireEntry(const priority_queue <RreqExpireTimerSet, vector<RreqExpireTimerSet>, RreqExpireLifetimeCompare>* exq,
		const char* orig, int idx){
	const RreqExpireTimerSet* q0;
	if(!(exq->empty())){
		q0 = &(exq->top());
		for(unsigned int i = 0; i < exq->size(); i++){
			if(q0[i].rreqID==idx && q0[i].originator.compare(orig)==0){
				return true;
			}
		}
	}
	return false;
}

double AodvRouting::getRemainingLifetimeTime(const char * dest){
	const RoutingTableEntryExpireTimerSet* q0;
	double x = 0;
	if(!rtExpireSeq.empty()){
		q0 = &rtExpireSeq.top();
		for (int i = rtExpireSeq.size() - 1 ; i >=0; i--){
			if (!q0[i].canceled && q0[i].destination.compare(dest)==0){
				if (q0[i].lifetime > x){
					x = q0[i].lifetime;
				}
			}
		}
	}
	return x;
}

void AodvRouting::updateLifetimeEntry(const char * dest, double time){
	if(rt->getState(dest)!=VALID){
		return;
	}
	RoutingTableEntryExpireTimerSet rteet;
	rteluc[string(dest)]++;
	rteet.destination = string(dest);
	rteet.lifetime = simTime().dbl() + time;
	rteet.canceled = false;
	rtExpireSeq.push(rteet);
}

void AodvRouting::resetLifetimeEntry(const char * dest){
	RoutingTableEntryExpireTimerSet* q0;
	if(!(rtExpireSeq.empty())){
		q0 = (RoutingTableEntryExpireTimerSet*)&(rtExpireSeq.top());
		for(unsigned int i = 0; i < rtExpireSeq.size(); i++){
			if(q0[i].destination.compare(dest)==0){
				q0[i].canceled = true;
				return;
			}
		}
	}
	rteluc[string(dest)]=0;
	return;
}

void AodvRouting::updateRTEntry(const char* destinationAddr,unsigned long destinationSeqNum,
					bool isDestinationValid,RoutingFlag state,int hopCount,
					const char* nextHopAddr,std::list<std::string>* precursor){
	//refer to RFC3561 chapter 6.2
	RoutingTableEntryExpireTimerSet rteet;
	double oldLifetime = getRemainingLifetimeTime(destinationAddr);
	rteluc[string(destinationAddr)]++;
	rteet.destination = string(destinationAddr);
	rteet.lifetime = oldLifetime<=0 ? simTime().dbl() + activeRouteTimeout : oldLifetime + activeRouteTimeout;
	rteet.canceled = false;
	
	if(!rtExpireSeq.empty() && rteet.lifetime < rtExpireSeq.top().lifetime){
		cancelTimer(AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER);
	}
	rtExpireSeq.push(rteet);
	if(getTimer(AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER).dbl()<=0){
		setTimer(AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER, rtExpireSeq.top().lifetime - simTime().dbl());
	}
	rt->updateEntry(destinationAddr,  destinationSeqNum, isDestinationValid, state, hopCount, nextHopAddr, precursor);
}

void AodvRouting::updateRTEntry(const char* destinationAddr,unsigned long destinationSeqNum,
					bool isDestinationValid,RoutingFlag state,int hopCount,
					const char* nextHopAddr,std::list<std::string>* precursor,
					double lifetime){
	RoutingTableEntryExpireTimerSet rteet;
	double oldLifetime = getRemainingLifetimeTime(destinationAddr);
	rteluc[string(destinationAddr)]++;
	rteet.destination = string(destinationAddr);
	rteet.lifetime = oldLifetime<=0 ? simTime().dbl() + lifetime : oldLifetime + lifetime;
	rteet.canceled = false;

	if(!rtExpireSeq.empty() && rteet.lifetime < rtExpireSeq.top().lifetime){
		cancelTimer(AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER);
	}
	rtExpireSeq.push(rteet);
	if(getTimer(AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER).dbl()<=0){
		setTimer(AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER, rtExpireSeq.top().lifetime - simTime().dbl());
	}
	rt->updateEntry(destinationAddr,  destinationSeqNum, isDestinationValid, state, hopCount, nextHopAddr, precursor);
}

void AodvRouting::sendRreqRequest(int hopCount, int rreqID, const char* sourceAodv, const char* destAodv,
								unsigned long sSeq, unsigned long dSeq){
	AodvRREQPacket *rreqPacket =
	    new AodvRREQPacket("AODV routing RREQ packet", NETWORK_LAYER_PACKET);
	rreqPacket->setFlagD(false);
	rreqPacket->setFlagG(false);
	rreqPacket->setFlagJ(false);
	rreqPacket->setFlagR(false);
	rreqPacket->setFlagU(false);
	rreqPacket->setHopCount(hopCount);
	rreqPacket->setRreqID(rreqID);
	rreqPacket->setDestinationAodv(destAodv);
	rreqPacket->setDestinationSeqNum(dSeq);
	rreqPacket->setSourceAodv(sourceAodv);
	rreqPacket->setSourceSeqNum(sSeq);
	rreqPacket->setSource(SELF_NETWORK_ADDRESS);
	rreqPacket->setDestination(destAodv);
	rreqPacket->setId(AODV_RREQ_PACKET);
	if (getTimer(AODV_RREQ_RATE_LIMIT_TIMER).dbl() <= 0){
		++rreqRetryCount[string(destAodv)];
		setRreqBoardcastDropTimer(destAodv, sourceAodv, rreqID);
		if(string(sourceAodv).compare(SELF_NETWORK_ADDRESS)==0){
			setRreqExpirationTimer(destAodv);
		}
		setTimer(AODV_RREQ_RATE_LIMIT_TIMER, (double)1/rreqRatelimit);
		toMacLayer(rreqPacket, BROADCAST_MAC_ADDRESS);
	} else {
		rreqBuffer.push(rreqPacket);
	}

}


void AodvRouting::fromApplicationLayer(cPacket * pkt, const char *destination)
{
	//the application module can only send data packets
	AodvDataPacket *dataPacket =
	    new AodvDataPacket("AODV routing data packet", NETWORK_LAYER_PACKET);
	dataPacket->setSource(SELF_NETWORK_ADDRESS);
	dataPacket->setDestinationAodv(destination);
	dataPacket->setDestination(destination);
	dataPacket->setId(AODV_DATA_PACKET);
	encapsulatePacket(dataPacket, pkt);
	if(string(destination).compare(BROADCAST_NETWORK_ADDRESS)==0){
		//do not route broadcast package
		return;
	}
	
	//refer to RFC3561 chapter 6.3
	//if in the routing table there is already an valid entry for the destination, send the package
	if(rt->isRouteValid(destination)){
		updateLifetimeEntry(destination, activeRouteTimeout);
		dataPacket->setDestination(rt->getNextHop(destination));
		toMacLayer(dataPacket, resolveNetworkAddress(rt->getNextHop(destination)));
		return;
	} else if(!isRreqRequstActive(destination)){
		//if in current time there are no rreq requests on going for the destination
		//send the RREQ to find a route
		currSeqNum++;
		currRreqID++;
		sendRreqRequest(0, currRreqID,SELF_NETWORK_ADDRESS, destination,
						currSeqNum, rt->getDestSeqNum(destination));
	}
	//buffer the packet
	bufferPacket(dataPacket);
	collectOutput("inBuffer","",1);
}

void AodvRouting::fromMacLayer(cPacket * pkt, int srcMacAddress, double rssi, double lqi)
{
	
	switch((dynamic_cast <PacketId*>(pkt))->getId()){
		case AODV_DATA_PACKET:
		{
			AodvDataPacket *dataPacket = dynamic_cast <AodvDataPacket*>(pkt);

			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"AODV_DATA_PACKET "<<dataPacket->getSource();

			trace() << "packet #"<<dataPacket->getSequenceNumber() 
			<<" Received from node "<< srcMacAddress << " source : " 
			<< dataPacket->getSource() << " Type=AODV_DATA_PACKET";

			//collectOutput("Packets received per node", atoi(""+srcMacAddress));

			if(string(dataPacket->getDestinationAodv()).compare(BROADCAST_NETWORK_ADDRESS)==0){
				toApplicationLayer(dataPacket->decapsulate());
				return;
			}
			if(string(dataPacket->getDestination()).compare(SELF_NETWORK_ADDRESS)!=0){
				return;
			}
			processDataPackage(dataPacket);
		}
			break;
		case AODV_RREQ_PACKET:
		{
			AodvRREQPacket *rreqPacket = dynamic_cast <AodvRREQPacket*>(pkt);

			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"AODV_RREQ_PACKET "<<rreqPacket->getSource();

			trace() << "packet #"<<rreqPacket->getSequenceNumber() 
			<<" Received from node "<< srcMacAddress << " source : " 
			<< rreqPacket->getSource() << " Type=AODV_RREQ_PACKET";

			//collectOutput("Packets received per node", atoi(""+srcMacAddress));

			processAodvRreqPackage(rreqPacket, srcMacAddress, rssi, lqi);
		}
			break;
		case AODV_RREP_PACKET:
		{
			AodvRREPPacket *rrepPacket = dynamic_cast <AodvRREPPacket*>(pkt);

			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"AODV_RREP_PACKET "<<rrepPacket ->getSource();
			
			trace() << "packet #"<<rrepPacket->getSequenceNumber() 
			<<" Received from node "<< srcMacAddress << " source : " 
			<< rrepPacket ->getSource() << " Type=AODV_RREP_PACKET";

			//collectOutput("Packets received per node", atoi(""+srcMacAddress));

			if(string(rrepPacket->getDestination()).compare(SELF_NETWORK_ADDRESS)!=0){
				return;
			}
			processAodvRrepPackage(rrepPacket, srcMacAddress, rssi, lqi);
		}
			break;
		case AODV_RREP_ACK_PACKET:
		{
			AodvRREPAckPacket* rrepaPacket = dynamic_cast <AodvRREPAckPacket*>(pkt);

			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"AODV_RREP_ACK_PACKET "<<rrepaPacket ->getSource() ;

			trace() << "packet #"<<rrepaPacket->getSequenceNumber() 
			<<" Received from node "<< srcMacAddress << " source : " 
			<< rrepaPacket ->getSource() << " Type=AODV_RREP_ACK_PACKET";

			//collectOutput("Packets received per node", atoi(""+srcMacAddress));

			rrepAcked[string(rrepaPacket->getSource())] = true;
			//if() trace() << "RSSI de ack =" << rssi << "from "<< srcMacAddress ; 
		}
			break;
		case AODV_HELLO_MESSAGE_PACKET:
		{
			AodvHelloMessage* helloMsg = dynamic_cast <AodvHelloMessage*>(pkt);

			trace() << "packet #"<<helloMsg->getSequenceNumber() 
			<<" Received from node "<< srcMacAddress << " source : " 
			<< helloMsg ->getSource() << " Type=AODV_HELLO_MESSAGE_PACKET";

			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"AODV_HELLO_MESSAGE_PACKET "<<helloMsg ->getSource();

			//collectOutput("Packets received per node", atoi(""+srcMacAddress));

			processHelloMsg(helloMsg);
			//trace() << "RSSI de HelloMessage =" << rssi << "from "<< srcMacAddress ; 
		}
			break;
		case AODV_RERR_PACKET:
		{
			AodvRERRPacket *rerrPacket = dynamic_cast <AodvRERRPacket*>(pkt);

			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"AODV_RERR_PACKET "<<rerrPacket ->getSource();

			trace() << "packet #"<<rerrPacket->getSequenceNumber() 
			<<" Received from node "<< srcMacAddress << " source : " 
			<< rerrPacket ->getSource() << " Type=AODV_RERR_PACKET";

			//collectOutput("Packets received per node", atoi(""+srcMacAddress));

			processAodvRerrPackage(rerrPacket, srcMacAddress, rssi, lqi);
		}
			break;
		default:
			return;
	}
	return;

}

void AodvRouting::processDataPackage(AodvDataPacket* pkt){
	AodvDataPacket *ndPacket = pkt->dup();
	if(string(pkt->getDestinationAodv()).compare(SELF_NETWORK_ADDRESS)==0){
		toApplicationLayer(pkt->decapsulate());
		return;
	} else if(rt->isRouteValid(pkt->getDestinationAodv())&&rt->getNextHop(pkt->getDestinationAodv())){
		updateLifetimeEntry(pkt->getDestinationAodv(), activeRouteTimeout);
		ndPacket->setDestination(rt->getNextHop(pkt->getDestinationAodv()));
		toMacLayer(ndPacket, resolveNetworkAddress(rt->getNextHop(pkt->getDestinationAodv())));//rachid
		//trace()<<"next hope "<<rt->getNextHop(pkt->getDestinationAodv())<<" resolve affress "<<resolveNetworkAddress(rt->getNextHop(pkt->getDestinationAodv()));
		return;
	} else if(!isRreqRequstActive(pkt->getDestinationAodv())){
		//if in current time there are no rreq requests on going for the destination
		//send the RREQ to find a route
		currSeqNum++;
		currRreqID++;
		sendRreqRequest(0, currRreqID,SELF_NETWORK_ADDRESS, pkt->getDestinationAodv(),
								currSeqNum, rt->getDestSeqNum(pkt->getDestinationAodv()));
		//buffer the packet
		bufferPacket(ndPacket);
		collectOutput("inBuffer","",1);
	}
}

void AodvRouting::processAodvRreqPackage(AodvRREQPacket * rreqPackage,int srcMacAddress, double rssi, double lqi){
	if(isInRreqBlacklist(rreqPackage->getSource())){
		return;
	}
	//updates a route to the previous hop without a valid seq number
	updateRTEntry(rreqPackage->getSource(), 0, false, VALID, 1, rreqPackage->getSource(),NULL);

	//check if this node has already processed for this rreq, if yes drop packet
	if(checkExpireEntry(&rreqBroadcast,rreqPackage->getSourceAodv(), rreqPackage->getRreqID())){
		return;
	}
	//update route for the originator
	updateRTEntry(rreqPackage->getSourceAodv(), rreqPackage->getSourceSeqNum(), true, VALID, rreqPackage->getHopCount() + 1, rreqPackage->getSource(),NULL);

	if(!((string(rreqPackage->getDestinationAodv()).compare(SELF_NETWORK_ADDRESS)==0))){ 
		//forwarding the rreq
		//refer to RFC3561 chapter 6.5
		sendRreqRequest(rreqPackage->getHopCount() + 1,
						rreqPackage->getRreqID(),
						rreqPackage->getSourceAodv(),
						rreqPackage->getDestinationAodv(),
						rreqPackage->getSourceSeqNum(),
						rt->getDestSeqNum(rreqPackage->getDestinationAodv()) > rreqPackage->getDestinationSeqNum() ?
							rt->getDestSeqNum(rreqPackage->getDestinationAodv()) : rreqPackage->getDestinationSeqNum());
	}

	else if(rt->getNextHop(rreqPackage->getDestinationAodv())){
		//current node has an active route to the destination
		//refer to RFC3561 chapter 6.6.2
		setRreqBoardcastDropTimer(rreqPackage->getDestinationAodv(), rreqPackage->getSourceAodv(), rreqPackage->getRreqID());
		sendRrepPacket(rt->getHopCount(rreqPackage->getDestinationAodv()),
						rreqPackage->getSourceAodv(),
						rreqPackage->getDestinationAodv(),
						rt->getDestSeqNum(rreqPackage->getDestinationAodv()),
						getRemainingLifetimeTime(rreqPackage->getDestinationAodv())-simTime().dbl(),
						false);
	} else {
		//current node is the destination
		//refer to RFC3561 chapter 6.6.1
		if(rreqPackage->getDestinationSeqNum()==currSeqNum){
			currSeqNum++;
		}
		setRreqBoardcastDropTimer(rreqPackage->getDestinationAodv(), rreqPackage->getSourceAodv(), rreqPackage->getRreqID());
		sendRrepPacket(0, rreqPackage->getSourceAodv(), SELF_NETWORK_ADDRESS,
						currSeqNum, 2 * activeRouteTimeout,  false);
	}
}

void AodvRouting::processAodvRrepPackage(AodvRREPPacket * rrepPackage,int srcMacAddress, double rssi, double lqi){
	sendRrepAckPacket(rrepPackage->getSource());
	if(getTimer(AODV_HELLO_MESSAGE_REFRESH_TIMER).dbl()<=0){
		sendHelloMessage();
	}


	//updates a route to the previous hop without a valid seq number
	updateRTEntry(rrepPackage->getSource(), 0, false, VALID, 1, rrepPackage->getSource(),NULL);
	//update route for the destination
	updateRTEntry(rrepPackage->getDestinationAodv(), rrepPackage->getDestinationSeqNum(),
				true, VALID, rrepPackage->getHopCount() + 1, rrepPackage->getSource(),
				NULL,rrepPackage->getLifetime());
	if (!(string(rrepPackage->getOriginator()).compare(SELF_NETWORK_ADDRESS)==0)){
		//forward the rrep
		sendRrepPacket(rrepPackage->getHopCount() + 1,
						rrepPackage->getOriginator(),
						rrepPackage->getDestinationAodv(),
						rrepPackage->getDestinationSeqNum(),
						rrepPackage->getLifetime(),
						true);
	} else {
		//routing table already updated for destination
		//send buffered packages for destination
		rreqRetryCount[string(rrepPackage->getDestinationAodv())] = 0;
		processPackagesInBuffer(rrepPackage->getDestinationAodv(), false);
		cancelExpireEntry(&rreqRequest,rrepPackage->getDestinationAodv());
	}
}

void AodvRouting::processPackagesInBuffer(const char * dest, bool drop){
	queue< cPacket* > bufferTemp;
	AodvDataPacket* currPkt;
	while (!TXBuffer.empty()) {
		currPkt = dynamic_cast <AodvDataPacket*>(TXBuffer.front());
		if(currPkt && string(dest).compare(currPkt->getDestinationAodv())==0){
			if(!drop && rt->getNextHop(dest)){
				currPkt->setDestination(rt->getNextHop(dest));
				toMacLayer(currPkt, resolveNetworkAddress(rt->getNextHop(dest)));
				collectOutput("inBuffer","",-1);
			}
		}
		else{
			bufferTemp.push(TXBuffer.front());
		}
		TXBuffer.pop();
		updateLifetimeEntry(dest, activeRouteTimeout);
	}
	while (!bufferTemp.empty()) {
		TXBuffer.push(bufferTemp.front());
		bufferTemp.pop();
	}

}

void AodvRouting::timerFiredCallback(int index){
	switch(index){
	case AODV_RREQ_BOARDCAST_DROP_TIMER:
		rreqBroadcast.pop();
		if(!rreqBroadcast.empty()){
			setTimer(AODV_RREQ_BOARDCAST_DROP_TIMER, rreqBroadcast.top().lifetime - simTime().dbl());
		}
		break;

	case AODV_RREQ_EXPIRATION_TIMER:
	{
		if (rreqRequest.top().canceled){ 
			rreqRequest.pop();
			if(!rreqRequest.empty()){
				setTimer(AODV_RREQ_EXPIRATION_TIMER, rreqRequest.top().lifetime - simTime().dbl());
			}
			break;
		}
		string dest1 = string(rreqRequest.top().dest);
		rreqRequest.pop();
		if(!rreqRequest.empty()){
			setTimer(AODV_RREQ_EXPIRATION_TIMER, rreqRequest.top().lifetime - simTime().dbl());
		}
		if(rreqRetryCount[dest1] < rreqRetries){
			//send another rreq
			currRreqID++;
			sendRreqRequest(0, currRreqID, SELF_NETWORK_ADDRESS, dest1.c_str(),
							currSeqNum, rt->getDestSeqNum(dest1.c_str()));
		} else {
			rreqRetryCount[dest1] = 0;
			processPackagesInBuffer(dest1.c_str(),true);
		}
	}
		break;

	case AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER:
	{
		if(!rtExpireSeq.top().canceled){
			string dest2 = string(rtExpireSeq.top().destination);
			rteluc[dest2]--;
			if (rteluc[dest2]==0){
				if(rt->getState(dest2.c_str())==VALID){
					rt->updateState(dest2, INVALID);
				}
			}
		}
		rtExpireSeq.pop();
		//it is possible that multiple entry expires at the same time
		while(!rtExpireSeq.empty() && rtExpireSeq.top().lifetime - simTime().dbl()<=0){
			if(!rtExpireSeq.top().canceled){
				string dest3 = string(rtExpireSeq.top().destination);
				rteluc[dest3]--;

				if (rteluc[dest3]==0){
					if(rt->getState(dest3.c_str())==VALID){
						rt->updateState(dest3, INVALID);
					}
				}
			}
			rtExpireSeq.pop();
		}
		if(!rtExpireSeq.empty()){
			setTimer(AODV_ROUTING_TABLE_ENTRY_EXPIRATION_TIMER, rtExpireSeq.top().lifetime - simTime().dbl());
		}
	}
		break;

	case AODV_RREQ_RATE_LIMIT_TIMER:
		if(!rreqBuffer.empty()){
			processrreqBuffer();
		}
		break;

	case AODV_HELLO_MESSAGE_REFRESH_TIMER:
		sendHelloMessage();
		break;

	case AODV_HELLO_MESSAGE_EXPIRE_TIMER:
	{
		string neib = hmExpireSeq.top().destination;
		hmeluc[neib]--;
		if (hmeluc[neib]==0){   //se acaboou o timer
			list<string>* affectedDest = new list<string>();
			list<string>* affectedPrecursor = new list<string>();
			rt->reportLinkBroken(neib.c_str(), affectedDest, affectedPrecursor);
			resetLifetimeEntry(neib.c_str());
			sendRerrMessage(affectedDest, affectedPrecursor);
		}
		hmExpireSeq.pop();
		while(!hmExpireSeq.empty() && hmExpireSeq.top().lifetime - simTime().dbl()<=0){
			string dest3 = hmExpireSeq.top().destination;
			hmeluc[dest3]--;
			if (hmeluc[dest3]==0){
				list<string>* affectedDest = new list<string>();
				list<string>* affectedPrecursor = new list<string>();
				rt->reportLinkBroken(dest3.c_str(), affectedDest, affectedPrecursor);
				resetLifetimeEntry(dest3.c_str());
				sendRerrMessage(affectedDest, affectedPrecursor);
			}
			hmExpireSeq.pop();
		}
		if(!hmExpireSeq.empty()){
			setTimer(AODV_HELLO_MESSAGE_EXPIRE_TIMER, hmExpireSeq.top().lifetime - simTime().dbl());
		}
	}
		break;

	case AODV_RERR_RATE_LIMIT_TIMER:
		if(!rerrBuffer.empty()){
			toMacLayer(rerrBuffer.front(), resolveNetworkAddress(rerrBuffer.front()->getDestination()));
			rerrBuffer.pop();
			setTimer(AODV_RREQ_RATE_LIMIT_TIMER, (double)1/rerrRatelimit);
		}
		break;

	case AODV_RREP_ACK_WAIT_TIMER:
		if(!rrepAcked[string(rrepAckExpire.top().destination)]){
			rreqBlacklist.push_front(string(rrepAckExpire.top().destination));
			setRreqBlacklistTimer(rrepAckExpire.top().destination.c_str());
		}
		rrepAckExpire.pop();
		while(((rrepAckExpire.top().lifetime - simTime().dbl())<0)&&!rrepAckExpire.empty()){
			  rrepAckExpire.pop();
		}		
		
		if(!rrepAckExpire.empty()){
			setTimer(AODV_RREP_ACK_WAIT_TIMER, rrepAckExpire.top().lifetime - simTime().dbl());
		}
		break;

	case AODV_RREQ_BLACKLIST_REMOVE_TIMER:
		{
			string node = string(rreqBlacklistTimeout.top().destination);
			rreqBlacklist.remove(node);
			rreqBlacklistTimeout.pop();
			if(!rreqBlacklistTimeout.empty()){
				setTimer(AODV_RREQ_BLACKLIST_REMOVE_TIMER, rreqBlacklistTimeout.top().lifetime - simTime().dbl());
			}
		}
		break;
	default:
		return;

	}
	return;
}

void AodvRouting::sendHelloMessage(){
	AodvHelloMessage* helloMsg = new AodvHelloMessage("AODV hello message packet", NETWORK_LAYER_PACKET);
	helloMsg->setSource(SELF_NETWORK_ADDRESS);
	helloMsg->setDestination(BROADCAST_NETWORK_ADDRESS);
	helloMsg->setId(AODV_HELLO_MESSAGE_PACKET);
	toMacLayer(helloMsg, BROADCAST_MAC_ADDRESS);
	setTimer(AODV_HELLO_MESSAGE_REFRESH_TIMER, helloInterval);
}

void AodvRouting::processrreqBuffer(){
	string dest=string(rreqBuffer.front()->getDestinationAodv());
	++rreqRetryCount[dest];
	setRreqBoardcastDropTimer(rreqBuffer.front()->getDestinationAodv(),
								rreqBuffer.front()->getSourceAodv(),
								rreqBuffer.front()->getRreqID());

	if(string(rreqBuffer.front()->getSourceAodv()).compare(SELF_NETWORK_ADDRESS)==0){
		setRreqExpirationTimer(dest.c_str());
	}

	toMacLayer(rreqBuffer.front(), BROADCAST_MAC_ADDRESS);
	rreqBuffer.pop();
	setTimer(AODV_RREQ_RATE_LIMIT_TIMER, (double)1/rreqRatelimit);
}

void AodvRouting::sendRrepPacket(int hopCount, const char* orig, const char* destAodv,
								unsigned long dSeq, double lifetime,  bool forwarding){
	if(!rt->getNextHop(orig)) return;
	AodvRREPPacket *rrepPackage =
					new AodvRREPPacket("AODV routing RREP packet", NETWORK_LAYER_PACKET);
	rrepPackage->setFlagA(true);
	rrepPackage->setFlagR(false);
	rrepPackage->setPrefixSz(0);
	rrepPackage->setHopCount(hopCount);
	rrepPackage->setOriginator(orig);
	rrepPackage->setDestinationAodv(destAodv);
	rrepPackage->setDestinationSeqNum(dSeq);
	rrepPackage->setSource(SELF_NETWORK_ADDRESS);
	rrepPackage->setDestination(rt->getNextHop(orig));
	rrepPackage->setLifetime(lifetime);
	rrepPackage->setId(AODV_RREP_PACKET);
	if(string(destAodv).compare(SELF_NETWORK_ADDRESS)!=0){
		rt->updatePrecursor(destAodv, rt->getNextHop(orig));
	}
	if(forwarding){
		updateLifetimeEntry(orig, activeRouteTimeout);
	}

	toMacLayer(rrepPackage, resolveNetworkAddress(rt->getNextHop(orig)));
	setRrepAckTimer(rt->getNextHop(orig));
}

void AodvRouting::processHelloMsg(AodvHelloMessage* msg){
	RoutingTableEntryExpireTimerSet hmeet;
	hmeluc[string(msg->getSource())]++;
	hmeet.destination = string(msg->getSource());
	hmeet.lifetime = allowedHelloLoss * helloInterval + simTime().dbl();
	hmExpireSeq.push(hmeet);
	if(getTimer(AODV_HELLO_MESSAGE_EXPIRE_TIMER).dbl()<=0){
		setTimer(AODV_HELLO_MESSAGE_EXPIRE_TIMER, hmExpireSeq.top().lifetime - simTime().dbl());
	}
}

void AodvRouting::sendRerrMessage(list<string>* affDest, list<string>* affPrecur){
	if(affDest->empty()||affPrecur->empty()){
		return;
	}
	for (list<string>::const_iterator i=affPrecur->begin();i!=affPrecur->end();++i){
		sendSingleRerrMessage(affDest, affPrecur, (*i).c_str());
	}
}

void AodvRouting::sendSingleRerrMessage(list<string>* affDest, list<string>* affPrecur, const char* dest){
	int destCnt = affDest->size();
	AodvRERRPacket *rerrPackage =
						new AodvRERRPacket("AODV routing RERR packet", NETWORK_LAYER_PACKET);
	rerrPackage->setSource(SELF_NETWORK_ADDRESS);
	rerrPackage->setFlagN(true);
	rerrPackage->setDestCount(destCnt);
	rerrPackage->setUnreachableDestAddrArraySize(destCnt);
	rerrPackage->setUnreachableDestSeqNumArraySize(destCnt);
	rerrPackage->setDestination(dest);
	rerrPackage->setId(AODV_RERR_PACKET);
	for(int i=0;i<destCnt;i++){
		rerrPackage->setUnreachableDestAddr(i,affDest->front().c_str());
		rerrPackage->setUnreachableDestSeqNum(i,rt->getDestSeqNum(affDest->front().c_str()));
		affDest->pop_front();
	}
	if (getTimer(AODV_RERR_RATE_LIMIT_TIMER).dbl() <= 0){
		toMacLayer(rerrPackage, resolveNetworkAddress(dest));
		setTimer(AODV_RREQ_RATE_LIMIT_TIMER, (double)1/rerrRatelimit);
	} else {
		rerrBuffer.push(rerrPackage);
	}
}

void AodvRouting::processAodvRerrPackage(AodvRERRPacket* rerrPacket,int srcMacAddress, double rssi, double lqi){
	if(string(rerrPacket->getDestination()).compare(SELF_NETWORK_ADDRESS)!=0){
		return;
	}
	unsigned int affDestCount = (unsigned int)rerrPacket->getDestCount();
	if (affDestCount!=rerrPacket->getUnreachableDestAddrArraySize() ||
		affDestCount!=rerrPacket->getUnreachableDestSeqNumArraySize()){
		//broken rerr packet
		return;
	}
	list<string>* affDest = new list<string>();
	list<string>* affPre = new list<string>();
	for (unsigned int i = 0; i < affDestCount; i++){
		affDest->push_front(string(rerrPacket->getUnreachableDestAddr(i)));
		rt->updateSeqNum(rerrPacket->getUnreachableDestAddr(i),rerrPacket->getUnreachableDestSeqNum(i));
	}
	rt->forwardLinkBroken(rerrPacket->getSource(),affDest,affPre);
	sendRerrMessage(affDest,affPre);
}

void AodvRouting::sendRrepAckPacket(const char* neib){
	AodvRREPAckPacket *rrepaPacket =
						new AodvRREPAckPacket("AODV routing RREP ACK packet", NETWORK_LAYER_PACKET);
	rrepaPacket->setSource(SELF_NETWORK_ADDRESS);
	rrepaPacket->setDestination(neib);
	rrepaPacket->setId(AODV_RREP_ACK_PACKET);
	toMacLayer(rrepaPacket, resolveNetworkAddress(neib));
}



