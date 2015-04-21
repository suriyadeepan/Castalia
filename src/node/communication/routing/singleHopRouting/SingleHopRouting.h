
#ifndef _SINGLEHOPROUTING_H_
#define _SINGLEHOPROUTING_H_

#include <list>
#include <map>
#include <queue>
#include "VirtualRouting.h"
#include "SingleHopRoutingPacket_m.h"

using namespace std;

enum TimerIndex{
	HELLO_MESSAGE_REFRESH_TIMER = 0,
	WAIT_ACK_CH = 1,
	SENDING_TIME = 2,
	SENDING_FROM_BUFFER = 3,
	SLEEP_TIME_OUT =13,
	START_SLEEPING = 14,
};

struct NodeInfo
{
	int nodeID;
	int nPacket;
};

class SingleHopRouting: public VirtualRouting {

 public:

	queue<SHRoutingPacket* > Buffer;
	queue <NodeInfo> candidatesForSending;
	double helloInterval;
	double TimeSending; 
	double timeAck;
	
	bool isSink;

 protected:
	void startup();
	void fromApplicationLayer(cPacket *, const char *);
	void fromMacLayer(cPacket *, int, double, double);
	void timerFiredCallback(int index);
	void sendHelloMessage();
	void sendACK();
	void sendAllowSending(int dst);
	void processPackagesInBuffer(const char * dest);
	
};

#endif
