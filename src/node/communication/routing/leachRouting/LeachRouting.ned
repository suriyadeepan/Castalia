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

package node.communication.routing.leachRouting;

simple LeachRouting like node.communication.routing.iRouting
{
parameters:
	string applicationID = default ("throughputTest");
	bool collectTraceInfo;
	int maxNetFrameSize = default (0);
	int netDataFrameOverhead = default (14);
	int netBufferSize = default (32);		
	bool isSink = default (false);
	
	double percentage;	
	double roundLength @unit(s);	
	double slotLength;

	//routing layer packet sizes
	int advPacketSize = default (9); // Type + Source + Destination = 9 bytes
	int joinPacketSize = default (9);
	int tdmaPacketSize = default (150); // Type + Source + Destination + tdma = 150 bytes
	int dataPacketSize = default (9);

	//Parameters used to power control.
	xml powersConfig;

gates: 
	output toCommunicationModule;
	output toMacModule;
	input fromCommunicationModule;
	input fromMacModule;
	input fromCommModuleResourceMgr;
}

