cplusplus {{
	#include "MacPacket_m.h"
}}
class MacPacket;
packet MaftPacket extends MacPacket {

	int ptype; 

	int pair_count;
	int node[5];
	int pair[5];
	int channel[5];

	int x;
	int y;
	double v;
	double angle;

	bool hasData;
	int dataSize;

	bool EOT;

	int newCH;

	double time_val;
	double del_t;
}


