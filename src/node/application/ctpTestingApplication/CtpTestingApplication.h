/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2010                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Athanassios Boulis, Yuriy Tselishchev                        *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *
 ****************************************************************************/

 /*
  * @author Ugo Colesanti
  * @author Silvia Santini
  * @version 1.01 (January 3, 2012)
  */

#ifndef _CTPTESTINGAPPLICATION_H_
#define _CTPTESTINGAPPLICATION_H_

#include "VirtualApplication.h"

using namespace std;

struct packet_info {
	map<int,bool> packets_received;
};

enum CtpTestingApplicationTimers {
	SEND_PACKET = 1
};

class CtpTestingApplication: public VirtualApplication {
 private:
	double packet_rate;
	string recipientAddress;
	double startupDelay;

	float packet_spacing;
	// this table records the number of packets received by node 0 from each other node
	map <int,packet_info> packet_info_table;
	map <int,int> packet_ddr_table;

	int total_packets_received;
	int packets_lost_at_mac;
	int packets_lost_at_network;
	int dataSN;

 protected:
	void startup();
	void update_ddr_per_sn(int srcID, int SN);
	void fromNetworkLayer(ApplicationPacket *, const char *, double, double);
	void handleRadioControlMessage(RadioControlMessage *);
	void timerFiredCallback(int);
};

#endif				// _CTPTESTINGAPPLICATION_APPLICATIONMODULE_H_
