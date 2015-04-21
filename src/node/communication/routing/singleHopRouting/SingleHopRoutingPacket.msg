
cplusplus {{
#include "RoutingPacket_m.h"
}}

class RoutingPacket;


enum singleHopRoutingPacket_Type
{		
	SINGLE_HOP_ROUTING_DATA_PACKET 	= 1;
	SINGLE_HOP_ROUTING_HELLO_PACKET = 2;
	SINGLE_HOP_ROUTING_ACK_PACKET 	= 3;
	SINGLE_HOP_ROUTING_ALLOW_SEND_PACKET = 4;
};

packet SHRoutingPacket extends RoutingPacket
{	
	int singleHopRoutingPacketKind enum (singleHopRoutingPacket_Type);  
	int SomeData; 	
};
