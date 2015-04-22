cplusplus {{
	#include "MacPacket_m.h"
}}
class MacPacket;
packet MaftPacket extends MacPacket {

	int ptype; 

	int pair_count;
	int txer[5];
	int rxer[5];
	int channel[5];

	int x;
	int y;
	double v;
	double angle;

	double time_val;
	double del_t;
}


