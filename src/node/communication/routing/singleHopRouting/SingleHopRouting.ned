

package node.communication.routing.singleHopRouting;

simple SingleHopRouting like node.communication.routing.iRouting

{
 parameters:
	bool collectTraceInfo = default (true);
	int maxNetFrameSize = default (0);	// bytes
	int netDataFrameOverhead = default (10);	// bytes
	int netBufferSize = default (64);	// number of messages

	bool isSink = default (false);	
	double helloInterval = default (500);	
	double TimeWaitAck = default (100);
	double TimeSending = default (20);
 gates:
	output toCommunicationModule;
	output toMacModule;
	input fromCommunicationModule;
	input fromMacModule;
	input fromCommModuleResourceMgr;
}

