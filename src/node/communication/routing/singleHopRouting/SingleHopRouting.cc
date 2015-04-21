
#include "SingleHopRouting.h"

Define_Module(SingleHopRouting);

void SingleHopRouting::startup(){

	helloInterval = (double) par("helloInterval")/1000;
	isSink = par("isSink");
	timeAck =  (double)par("TimeWaitAck")/1000;
	TimeSending = (double)par("TimeSending")/1000;

	if(isSink)sendHelloMessage();

	declareOutput("inBuffer");
	declareOutput("packets sent");	
}

void SingleHopRouting::timerFiredCallback(int index){
switch(index){
	case HELLO_MESSAGE_REFRESH_TIMER:
	{
		sendHelloMessage();
		break;
	}
	case WAIT_ACK_CH:
	{

		if(isSink && !candidatesForSending.empty()){
			cancelTimer(HELLO_MESSAGE_REFRESH_TIMER);	
			setTimer(SENDING_TIME,0);	
		}		
		break;
	}

	case SENDING_TIME:
	{
		if(!candidatesForSending.empty()){	
				if(isSink){	

					NodeInfo info = candidatesForSending.front();
					int node = info.nodeID;				
					double time = info.nPacket * TimeSending;
				
					sendAllowSending(node);
					candidatesForSending.pop();	
					setTimer(SENDING_TIME,time);

				}
		}else{	
			setTimer(HELLO_MESSAGE_REFRESH_TIMER, helloInterval);		
		}
		break;
	}

	case SLEEP_TIME_OUT:
		{
			send(createRadioCommand(SET_STATE, RX), "toMacModule");	
			setTimer(START_SLEEPING,0.75);	
			trace()<<"node "<<SELF_NETWORK_ADDRESS<<" wack up";
			break;
		}
	case START_SLEEPING:
		{
			setTimer(SLEEP_TIME_OUT,0.25);
			send(createRadioCommand(SET_STATE, SLEEP), "toMacModule");
			trace()<<"node "<<SELF_NETWORK_ADDRESS<<" sleeped";	
			break;
		}

	case SENDING_FROM_BUFFER:
	{
		processPackagesInBuffer(SINK_NETWORK_ADDRESS);
		break;
	}
				
	default:
		return;

	}
	return;
}

void SingleHopRouting::fromApplicationLayer(cPacket * pkt, const char *destination)
{
	SHRoutingPacket *dataPacket = new SHRoutingPacket("SingleHopDataRouting packet", NETWORK_LAYER_PACKET);
	dataPacket->setSource(SELF_NETWORK_ADDRESS);
	dataPacket->setDestination(SINK_NETWORK_ADDRESS);
	dataPacket->setSingleHopRoutingPacketKind(SINGLE_HOP_ROUTING_DATA_PACKET);
	encapsulatePacket(dataPacket, pkt);
	string dst(destination);
	bufferPacket(dataPacket);
	collectOutput("inBuffer","",1);	
}

void SingleHopRouting::sendHelloMessage(){

	SHRoutingPacket* helloMsg = new SHRoutingPacket("hello message packet", NETWORK_LAYER_PACKET);
	helloMsg->setSource(SELF_NETWORK_ADDRESS);
	helloMsg->setDestination(BROADCAST_NETWORK_ADDRESS);
	helloMsg->setSingleHopRoutingPacketKind(SINGLE_HOP_ROUTING_HELLO_PACKET);
	toMacLayer(helloMsg, BROADCAST_MAC_ADDRESS);
	setTimer(HELLO_MESSAGE_REFRESH_TIMER, helloInterval);	
	setTimer(WAIT_ACK_CH,timeAck);
}

void SingleHopRouting::sendACK(){

	SHRoutingPacket* ACKMsg = new SHRoutingPacket("ACK message packet", NETWORK_LAYER_PACKET);
	ACKMsg->setSource(SELF_NETWORK_ADDRESS);
	ACKMsg->setDestination(SINK_NETWORK_ADDRESS);
	ACKMsg->setSomeData(TXBuffer.size());
	ACKMsg->setSingleHopRoutingPacketKind(SINGLE_HOP_ROUTING_ACK_PACKET);
	toMacLayer(ACKMsg, BROADCAST_MAC_ADDRESS);
}

void SingleHopRouting::sendAllowSending(int dst){

	SHRoutingPacket* AllowMsg = new SHRoutingPacket("Allow sending message packet", NETWORK_LAYER_PACKET);
	AllowMsg->setSource(SELF_NETWORK_ADDRESS);
	AllowMsg->setDestination(dst+"");
	AllowMsg->setSingleHopRoutingPacketKind(SINGLE_HOP_ROUTING_ALLOW_SEND_PACKET);
	toMacLayer(AllowMsg,dst);
}

void SingleHopRouting::fromMacLayer(cPacket * pkt, int srcMacAddress, double rssi, double lqi)
{

SHRoutingPacket *netPacket = dynamic_cast <SHRoutingPacket*>(pkt);

switch (netPacket->getSingleHopRoutingPacketKind()) {

		case SINGLE_HOP_ROUTING_DATA_PACKET:
		{
			if(isSink){
				toApplicationLayer(decapsulatePacket(netPacket));
			}
			trace()<<"data packet received from "<<srcMacAddress;

			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"DATA_PACKET "<<netPacket->getSource();
			break;
		}
			
		case SINGLE_HOP_ROUTING_HELLO_PACKET:{
	
			trace()<<"hello message received from "<<srcMacAddress;
			
			if(!TXBuffer.empty()){
				sendACK();
				cancelTimer(START_SLEEPING);
			}
			trace() << "Node " << self << " Sent ack"  << "\n";		
			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"HELLO_PACKET "<<srcMacAddress;
			break;
		}

		case SINGLE_HOP_ROUTING_ACK_PACKET:{
			
			trace()<<"ACK message received from "<<srcMacAddress;
			if (isSink) {
				NodeInfo rec;
				rec.nodeID = srcMacAddress;
				rec.nPacket = netPacket->getSomeData();
				
				candidatesForSending.push(rec);
				Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"ACK_PACKET "<<srcMacAddress;		
			}	
			break;
		}

		case SINGLE_HOP_ROUTING_ALLOW_SEND_PACKET:{
			// je t'autorise a m'envoyer les donnees
			trace()<<"Allow to send message received from "<<srcMacAddress;
			processPackagesInBuffer(SINK_NETWORK_ADDRESS);
			setTimer(START_SLEEPING,0);
			Cominfos()<<SELF_NETWORK_ADDRESS<<" "<<srcMacAddress<<" "<<"ALLOW_SEND_PACKET "<<srcMacAddress;		
			break;
		}
		
		
		default:
			return;
	}
	return;	
}

void SingleHopRouting::processPackagesInBuffer(const char * dest){

	SHRoutingPacket* currPkt;
	if (!TXBuffer.empty()) {
		currPkt = dynamic_cast <SHRoutingPacket*>(TXBuffer.front());
		currPkt->setDestination(dest);
		toMacLayer(currPkt, atoi(SINK_NETWORK_ADDRESS));
		collectOutput("packets sent");
		collectOutput("inBuffer","",-1);
		TXBuffer.pop();

		if(!TXBuffer.empty()){
			setTimer(SENDING_FROM_BUFFER,TimeSending);
		}
	}

}

