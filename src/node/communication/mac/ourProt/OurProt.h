#ifndef _OURPROT_H_
#define _OURPROT_H_

#include <omnetpp.h>
#include "VirtualMac.h"
#include "VirtualMobilityManager.h"
#include "CPacket_m.h"
#include <vector>
#include <math.h>
 
#include <random>

/*FILE *log_file;
#define CLOG(x)	{ log_file = fopen("node_log.txt","a");\
	fprintf(log_file, "%d %f %s\n", (int)SELF_MAC_ADDRESS, simTime().dbl(), x);\
	fclose(log_file);}


FILE *errorlogFile;
#define ERRORLOG(x)	{errorlogFile = fopen("errorlog.txt", "a");\
						fprintf(errorlogFile, "[%d] %s\n", SELF_MAC_ADDRESS, x);;\
					fclose(errorlogFile);}
*/

using namespace std;

#define RANDOMNESS_GRANULARITY 1000

// ----------------------------------------
// --- 0.0004 seconds = 0.4 ms = 400 us ---
// ------- slot size ----------------------
const double DT_SLOT = 0.004;
const int x = 10;



enum DT_PType {
	DISC_REQ_PKT = 1,
	DISC_REP_PKT = 2,
	SCHED_PKT = 3,
	DATA_REQUEST_PKT = 4,
	DATA_REPLY_PKT = 5
};

// ------ NODE Type ------
enum DT_NType { 
	STATIC_NODE = 1,
	MOBILE_NODE = 2,
	BASE_STATION = 3
};
// ----------------------

// ------ Timers --------
enum DT_Timers {

	WAKE_TO_DREQ = 1,
	WAKE_TO_DREP = 2,
	WAKE_TO_SEND_DREP = 3,
	WAKE_TO_SCHED = 4,
	WAKE_TO_SEND_SCHED = 5,
	WAKE_TO_REC_SCHED = 6,
	WAKE_TO_DATA_P = 7,
	WAKE_TO_SEND_DATA_REQ= 8,
	WAKE_TO_REC_DATA_REQ = 9,
	WAKE_TO_SEND_DATA_REP = 10,
	WAKE_TO_SLEEP = 11,
	WAKE_TO_RX = 12,
	WAKE_TO_SEND_DREQ = 13,
	WAKE_TO_DATA_PHASE = 14,
	MOB_TRACE = 15

};
// ----------------------

/*enum OurProtMACStates {
	SYNC = 1,
	REQ_PHASE = 2,
	SCHED = 3,
	DATA = 4,
};*/

// ---- Duration of each phase -------------------
const double	DREQ_P = 1*DT_SLOT; // 0.4 ms----------
const double	DREP_P = x*DT_SLOT; // 4 ms -----
const double	SCHED_P = 1*DT_SLOT; // 0.4 ms --------
double	DATA_P = 10*DT_SLOT; // varies based --
					// ---- on number of bound nodes -------
// -----------------------------------------------
//

int totalDataPktCount; 
int totalDataPktTxCount;
int totalCntlPkts; 

class PacketContainer {
public:
	PacketContainer(int, int);
	int timerId;  //Ranges from REP_TIMER_START to +REP_BUFFER_SIZE
	int dest; // dest == -1 => This buffer location is ready to be used
};

class Node {
public:
	Node(int);

	int address;
	int slot_id;
	bool active;

};

class OurProt: public VirtualMac
{
	protected:
		void startup();
		void fromRadioLayer(cPacket *, double, double);
		void fromNetworkLayer(cPacket *, int);
		void timerFiredCallback(int);
		void sendPacket(CPacket*);
		double getRandom(double,int,double);

		void broadcastPkt(int);
		void sendReqPacket(void);
		void logBoundNodes();
		void broadcastSCHED();
		void sendDataPacket(void);

		void getSelfLocation(int&,int&);

		double random();
		void broadcastDREQ(double time_val);
		void sendDREP();
		void sendDATA_REQ(int);
		void sendDATA_REP();

		bool isActive(int);
		void activateNode(int);
		void deactivateNode(int);

		void updateTable();
		void removeRedundancy(int);


		int rounds;
		int DP_iter;
		double node_0_wake_time;
		double node_x_wake_time;
		double del_t;
		int boundTo;


		int dataPktCount; 

		int selfX,selfY;
		int DT_nodeType;
		bool randomGenFlipper;

		int my_DREP_Slot;
		int my_DATA_Slot;

		vector<Node> boundNodes; //Holds the list of Nodes who requested for connection
};

#endif
