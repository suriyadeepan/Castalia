#ifndef _MAFTMAC_H_
#define _MAFTMAC_H_

#include <omnetpp.h>
#include "VirtualMac.h"
#include "VirtualMobilityManager.h"
#include "MaftPacket_m.h"

#include <vector>
 
using namespace std;


// ----------------------------------------
// --- 0.0004 seconds = 0.4 ms = 400 us ---
// ------- slot size ----------------------
const double MFT_SLOT = 0.004;
const double MFT_MINI_SLOT = 0.0004;

const int MFT_NUM_DATA_PKTS = 10;

const int MFT_CNTL_CHANNEL = 11;

const int MFT_NODE_DENSITY = 10;

int MFT_PKT_GEN_TIME;

enum MFT_PType {
	SYNC_PKT = 1,
	META_PKT = 2,
	SCHED_PKT = 3,
	DATA_PKT = 4
};

// ------ NODE Type ------
enum MFT_NType { 
	CLUSTER_HEAD = 1,
	MOBILE_NODE = 2,
	BASE_STATION = 3
};
// ----------------------

// ------ Timers --------
enum MFT_Timers {

	MOB_TRACE = 1,
	WAKE_TO_SLEEP = 2,
	WAKE_TO_RX = 3,

	WAKE_TO_SYNC = 4,
	WAKE_TO_META = 5,
	WAKE_TO_SEND_META = 6,
	WAKE_TO_SCHED = 7,
	WAKE_TO_SEND_DATA = 8,
	WAKE_TO_REC_SCHED = 9,

	DATA_TRANSFER_TIMEOUT = 10,

	// -- Pkt Generation every 4ms -- //
	GEN_PKT = 11

};

// --- In terms of MFT_SLOT --- //
enum MFT_frameDuration{

	SYNC_P  = 1,
	META_P  = 5,
	SCHED_P = 1
};
// ---------------------------- //

enum MFT_Phase{

	P_SYNC  = 1,
	P_META  = 2,
	P_SCHED = 3
};
enum MFT_MAC_STATE{

	REC = 1,
	SEN = 2,
	IDL = 3
};

/*class MNode{

	public:
		MNode(int);

		int address;
		bool active;
};*/


class MaftMac: public VirtualMac
{
	protected:
		// --- compulsory ---
		void startup();
		void fromRadioLayer(cPacket *, double, double);
		void fromNetworkLayer(cPacket *, int);

		void timerFiredCallback(int);
		void sendPacket(MaftPacket*);

		// ------- Data Transfer --------- //
		void broadcastSync(double time_val);
		void sendMeta();
		void broadcastSched(double time_val);
		void sendData();
		// ------------------------------//
		

		// ------- Mobility ------------ //
		void initMobilityManager();
		void getSelfLocation(int &,int &);
		double getSpeed();
		double getDirection();
		// -----------------------------//


		int nodeType;
		int  macType;
		int dataChannel;
		int dataPair;

		int pktsRxed;

		int boundTo;
		int phase;

		// -- pkts generated -- //
		int pktsGen;		
		// -- location -- 
		int x,y;

		// -- time correction -- 
		double del_t;	
		double node_x_sched_wakeup;
		double node_0_sched_wakeup;

		// -- kth round -- //
		int round;

		int txBuffer[MFT_NODE_DENSITY/2];
		int txBufferX[MFT_NODE_DENSITY/2];
		int txBufferY[MFT_NODE_DENSITY/2];

		int rxBuffer[MFT_NODE_DENSITY/2];
		int rxBufferX[MFT_NODE_DENSITY/2];
		int rxBufferY[MFT_NODE_DENSITY/2];

		int boundNodes[MFT_NODE_DENSITY];
		int boundNodesSizes[MFT_NODE_DENSITY];
		int boundNodesX[MFT_NODE_DENSITY];
		int boundNodesY[MFT_NODE_DENSITY];

		int rxBufferSize;
		int txBufferSize;
		int boundNodesSize;
		// -- Mobility Manager -- //
		VirtualMobilityManager *nodeMobilityModule; 
};

#endif
