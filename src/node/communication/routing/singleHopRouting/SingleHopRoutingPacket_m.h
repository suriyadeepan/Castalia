//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/singleHopRouting/SingleHopRoutingPacket.msg.
//

#ifndef _SINGLEHOPROUTINGPACKET_M_H_
#define _SINGLEHOPROUTINGPACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "RoutingPacket_m.h"
// }}

/**
 * Enum generated from <tt>src/node/communication/routing/singleHopRouting/SingleHopRoutingPacket.msg:10</tt> by nedtool.
 * <pre>
 * enum singleHopRoutingPacket_Type
 * {
 * 
 *     SINGLE_HOP_ROUTING_DATA_PACKET = 1;
 *     SINGLE_HOP_ROUTING_HELLO_PACKET = 2;
 *     SINGLE_HOP_ROUTING_ACK_PACKET = 3;
 *     SINGLE_HOP_ROUTING_ALLOW_SEND_PACKET = 4;
 * }
 * </pre>
 */
enum singleHopRoutingPacket_Type {
    SINGLE_HOP_ROUTING_DATA_PACKET = 1,
    SINGLE_HOP_ROUTING_HELLO_PACKET = 2,
    SINGLE_HOP_ROUTING_ACK_PACKET = 3,
    SINGLE_HOP_ROUTING_ALLOW_SEND_PACKET = 4
};

/**
 * Class generated from <tt>src/node/communication/routing/singleHopRouting/SingleHopRoutingPacket.msg:18</tt> by nedtool.
 * <pre>
 * packet SHRoutingPacket extends RoutingPacket
 * {
 *     int singleHopRoutingPacketKind @enum(singleHopRoutingPacket_Type);
 *     int SomeData;
 * }
 * </pre>
 */
class SHRoutingPacket : public ::RoutingPacket
{
  protected:
    int singleHopRoutingPacketKind_var;
    int SomeData_var;

  private:
    void copy(const SHRoutingPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SHRoutingPacket&);

  public:
    SHRoutingPacket(const char *name=NULL, int kind=0);
    SHRoutingPacket(const SHRoutingPacket& other);
    virtual ~SHRoutingPacket();
    SHRoutingPacket& operator=(const SHRoutingPacket& other);
    virtual SHRoutingPacket *dup() const {return new SHRoutingPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSingleHopRoutingPacketKind() const;
    virtual void setSingleHopRoutingPacketKind(int singleHopRoutingPacketKind);
    virtual int getSomeData() const;
    virtual void setSomeData(int SomeData);
};

inline void doPacking(cCommBuffer *b, SHRoutingPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SHRoutingPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef _SINGLEHOPROUTINGPACKET_M_H_

