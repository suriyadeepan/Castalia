cplusplus {{
	#include "MacPacket_m.h"
}}
class MacPacket;
packet ModPacket extends MacPacket {
	int ptype; // 3 = REPLY Packet
	int adst; // actual destination
	int fdst = 5; //final destination
	int sourceX;
	int sourceY; 
	int destX;
	int destY;
	int myX;
	int myY;

	int slots;
	double slot_info[10];
	int node_id[10];


	double sleep_time;
}


