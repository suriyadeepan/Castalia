// ***********************************************************************************************
// *  Copyright (c) Federal University of Para, brazil - 2011                                    *
// *  Developed at the Research Group on Computer Network and Multimedia Communication (GERCOM)  *
// *  All rights reserved                                                                        *
// *                                                                                             *
// *  Permission to use, copy, modify, and distribute this protocol and its documentation for    *
// *  any purpose, without fee, and without written agreement is hereby granted, provided that   *
// *  the above copyright notice, and the author appear in all copies of this protocol.          *
// *                                                                                             *
// *  Author(s): Kassio Machado <kassio.comp@gmail.com> ,                                        *
// *             Thiago Oliveira <thiagofdso.ufpa@gmail.com>                                     *
// ***********************************************************************************************

package node.communication.routing.aodvRouting;

simple AodvRouting like node.communication.routing.iRouting
//====================================================================================
// Network_GenericFrame has the following real-world
// (non-simulation-specific) fields:
//    unsigned short int frameType; --> 2bytes
//    string source;  ----------------> 2bytes
//    string destinationCtrl; --------> 2bytes
//    string lastHop; ------------> 2bytes
//    string nextHop; ------------> 2bytes
//    unsigned short int ttl; ----> 2bytes
//    string applicationID; ------> 2bytes
// Total bytes = 7*2 = 14 (|*|)
// From these 14bytes, BypassRoutingModule doesn't use everything.
// It doesn't use the ttl and applicationID fields.
// Concluding the calculations, the Network_GenericFrame for
// BypassRoutingModule has a total overhead of:
// 14-(2+2) = 10 bytes
//====================================================================================
{
 parameters:
	bool collectTraceInfo = default (false);
	int maxNetFrameSize = default (0);	// bytes
	int netDataFrameOverhead = default (10);	// bytes
	int netBufferSize = default (32);	// number of messages

	int activeRouteTimeout = default(60000); //ACTIVE_ROUTE_TIMEOUT in ms
	int allowedHelloLoss = default(4);  
	int helloInterval = default(25000); //in ms
	int localAddTTL = default(2);
	int netDiameter = default(35);
	int nodeTraversalTime = default(4000); //in ms
	int rerrRatelimit = default(10);
	int rreqRetries = default(2);
	int rreqRatelimit = default(10);
	int timeoutBuffer = default(2);
	int ttlStart = default(1);
	int ttlIncrement = default(2);
	int ttlThreshould = default(7);



 gates:
	output toCommunicationModule;
	output toMacModule;
	input fromCommunicationModule;
	input fromMacModule;
	input fromCommModuleResourceMgr;
}

