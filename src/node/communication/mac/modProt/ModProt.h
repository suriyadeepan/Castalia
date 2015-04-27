#ifndef _MODPROT_H_
#define _MODPROT_H_

#include <omnetpp.h>
#include "VirtualMac.h"
#include "VirtualMobilityManager.h"
#include "ModPacket_m.h"
#include <vector>
#include <math.h>
 
//#include <random>
//#include <cstdlib>
//#include <cstdio>
//#include <cassert>

char my_ex_buf[50];

FILE *log_file;
#define CLOG(x)	{ log_file = fopen("node_log.txt","a");\
	fprintf(log_file, "%d %f %s\n", (int)SELF_MAC_ADDRESS, simTime().dbl(), x);\
	fclose(log_file);}


FILE *errorlogFile;
#define ERRORLOG(x)	{errorlogFile = fopen("errorlog.txt", "a");\
						fprintf(errorlogFile, "[%d] %s\n", SELF_MAC_ADDRESS, x);;\
					fclose(errorlogFile);}

using namespace std;

const int WAKE_TIME = 1; //The outside nodes use this to Wake up
const int TRACE_MOBILITY = 0; //Set this to 0 to disable mobility update traces

// ----------------------------------------
// --- 0.0004 seconds = 0.4 ms = 400 us ---
// ------- slot size ----------------------
const double SLOT = 0.004;

enum PType {
	SYNC_PKT = 1,
	REQ_PKT = 2,
	SCHED_PKT = 3,
	DATA_PKT = 4
};

// ------ NODE Type ------
enum NType { 
	CLUSTER_HEAD = 1,
	STATIC_NODE = 3,
	MOBILE_NODE = 2,
	BS = 4
};
// ----------------------

// ------ Timers --------
enum ModProtTimers {
	MOBILITY_TRACE = 1,
	ALL_WAKE = 2,
	WAKE_TO_SEND_REQ = 3,
	WAKE_TO_SEND_DATA = 4,
	WAKE_TO_REQPHASE = 5,
	WAKE_TO_SCHEDPHASE = 6,
	WAKE_TO_DATAPHASE = 7,
	WAKE_TO_SYNCPHASE = 8,
	WAKE_TO_BROADCAST_SYNC = 9,
	WAKE_TO_BROADCAST_SCHED = 10,
	WAKE_TO_RX = 11
};
// ----------------------

enum ModProtMACStates {
	SYNC = 1,
	REQ_PHASE = 2,
	SCHED = 3,
	DATA = 4,
};

// ---- Duration of each phase -------------------
const double	SYNC_P = 2*SLOT; // 0.4 ms----------
const double	REQ_PHASE_P = 10*SLOT; // 4 ms -----
const double	SCHED_P = 2*SLOT; // 0.4 ms --------
const double	DATA_P = 10*SLOT; // varies based --
					// ---- on number of bound nodes -------
// -----------------------------------------------

// ---- Duration of each phase ---------------
//const int	SYNC_P = 1; // 0.4 ms----------
//const int	REQ_PHASE_P = 1; // 4 ms -----
//const int	SCHED_P = 1; // 0.4 ms --------
//const int	DATA_P = 1; // varies based --
					// ---- on number of bound nodes ---
// -------------------------------------------


int current_phase = 1;

// stats
int DATA_PKT_TX_COUNT = 0;
int DATA_PKT_RX_COUNT = 0;
int REQ_PKT_TX_COUNT = 0;
int REQ_PKT_RX_COUNT = 0;
int SCHED_PKT_TX_COUNT = 0;
int SCHED_PKT_RX_COUNT = 0;
int SYNC_PKT_TX_COUNT = 0;
int SYNC_PKT_RX_COUNT = 0;

int CNTL_PKT_TX_COUNT = 0;

class MyPacketContainer {
public:
	MyPacketContainer(int, int);
	int timerId;  //Ranges from REP_TIMER_START to +REP_BUFFER_SIZE
	int dest; // dest == -1 => This buffer location is ready to be used
};

class MyNode {
public:
	MyNode(int, int, int);
	int address;
	int x;
	int y;
};


class ModProt: public VirtualMac
{
	protected:
		void startup();
		void fromRadioLayer(cPacket *, double, double);
		void fromNetworkLayer(cPacket *, int);
		void timerFiredCallback(int);
		void getSelfLocation(int&, int&);
		void getLocation(int&, int&, int);
		void broadcastRequest();
		void sendPacket(ModPacket*);
		double getRandom(double,int,double);

		void broadcastSyncPkt(double);

		void broadcastPkt(int);
		void sendReqPacket(void);
		void logBoundNodes();
		void buildAndBroadcastSchedPkt(double);
		void sendDataPacket(void);

		void logChStats();
		void logNonChStats();


		int nodeType;
		int selfX, selfY;
		int sourceX, sourceY, destX, destY;
		int bestNode;
		int findingBestNode; //Set this to 1 while discovery is in process to avoid multiple DREQ

		double myDataSlot;

		int myClusterHead;
		int frame_count;


		vector<ModPacket*> DataPacketBuffer;
		vector<MyNode> bestNodeContenders; //Holds the list of Nodes who replied
		vector<MyPacketContainer> replyBuffer; //Buffer holding <timer_id, destination> objects. Size = 10
		vector<MyPacketContainer> dataReplyBuffer; //Buffer holding <timer_id, destination> objects for DREP.

		vector<MyNode> boundNodes; //Holds the list of Nodes who requested for connection


};

#endif
