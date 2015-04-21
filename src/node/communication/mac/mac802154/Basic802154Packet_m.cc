//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/mac/mac802154/Basic802154Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Basic802154Packet_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("Mac802154Packet_type");
    if (!e) enums.getInstance()->add(e = new cEnum("Mac802154Packet_type"));
    e->insert(MAC_802154_BEACON_PACKET, "MAC_802154_BEACON_PACKET");
    e->insert(MAC_802154_ASSOCIATE_PACKET, "MAC_802154_ASSOCIATE_PACKET");
    e->insert(MAC_802154_DATA_PACKET, "MAC_802154_DATA_PACKET");
    e->insert(MAC_802154_ACK_PACKET, "MAC_802154_ACK_PACKET");
    e->insert(MAC_802154_GTS_REQUEST_PACKET, "MAC_802154_GTS_REQUEST_PACKET");
);

Basic802154GTSspec::Basic802154GTSspec()
{
    owner = 0;
    start = 0;
    length = 0;
}

void doPacking(cCommBuffer *b, Basic802154GTSspec& a)
{
    doPacking(b,a.owner);
    doPacking(b,a.start);
    doPacking(b,a.length);
}

void doUnpacking(cCommBuffer *b, Basic802154GTSspec& a)
{
    doUnpacking(b,a.owner);
    doUnpacking(b,a.start);
    doUnpacking(b,a.length);
}

class Basic802154GTSspecDescriptor : public cClassDescriptor
{
  public:
    Basic802154GTSspecDescriptor();
    virtual ~Basic802154GTSspecDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(Basic802154GTSspecDescriptor);

Basic802154GTSspecDescriptor::Basic802154GTSspecDescriptor() : cClassDescriptor("Basic802154GTSspec", "")
{
}

Basic802154GTSspecDescriptor::~Basic802154GTSspecDescriptor()
{
}

bool Basic802154GTSspecDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Basic802154GTSspec *>(obj)!=NULL;
}

const char *Basic802154GTSspecDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Basic802154GTSspecDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int Basic802154GTSspecDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *Basic802154GTSspecDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "owner",
        "start",
        "length",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int Basic802154GTSspecDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "owner")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "start")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *Basic802154GTSspecDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *Basic802154GTSspecDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int Basic802154GTSspecDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Basic802154GTSspecDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->owner);
        case 1: return long2string(pp->start);
        case 2: return long2string(pp->length);
        default: return "";
    }
}

bool Basic802154GTSspecDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        case 0: pp->owner = string2long(value); return true;
        case 1: pp->start = string2long(value); return true;
        case 2: pp->length = string2long(value); return true;
        default: return false;
    }
}

const char *Basic802154GTSspecDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *Basic802154GTSspecDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154GTSspec *pp = (Basic802154GTSspec *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(Basic802154Packet);

Basic802154Packet::Basic802154Packet(const char *name, int kind) : ::MacPacket(name,kind)
{
    this->Mac802154PacketType_var = 0;
    this->PANid_var = 0;
    this->srcID_var = 0;
    this->dstID_var = 0;
    this->seqNum_var = 0;
    this->beaconOrder_var = 0;
    this->frameOrder_var = 0;
    this->BSN_var = 0;
    this->CAPlength_var = 0;
    this->GTSlength_var = 0;
    GTSlist_arraysize = 0;
    this->GTSlist_var = 0;
}

Basic802154Packet::Basic802154Packet(const Basic802154Packet& other) : ::MacPacket(other)
{
    GTSlist_arraysize = 0;
    this->GTSlist_var = 0;
    copy(other);
}

Basic802154Packet::~Basic802154Packet()
{
    delete [] GTSlist_var;
}

Basic802154Packet& Basic802154Packet::operator=(const Basic802154Packet& other)
{
    if (this==&other) return *this;
    ::MacPacket::operator=(other);
    copy(other);
    return *this;
}

void Basic802154Packet::copy(const Basic802154Packet& other)
{
    this->Mac802154PacketType_var = other.Mac802154PacketType_var;
    this->PANid_var = other.PANid_var;
    this->srcID_var = other.srcID_var;
    this->dstID_var = other.dstID_var;
    this->seqNum_var = other.seqNum_var;
    this->beaconOrder_var = other.beaconOrder_var;
    this->frameOrder_var = other.frameOrder_var;
    this->BSN_var = other.BSN_var;
    this->CAPlength_var = other.CAPlength_var;
    this->GTSlength_var = other.GTSlength_var;
    delete [] this->GTSlist_var;
    this->GTSlist_var = (other.GTSlist_arraysize==0) ? NULL : new Basic802154GTSspec[other.GTSlist_arraysize];
    GTSlist_arraysize = other.GTSlist_arraysize;
    for (unsigned int i=0; i<GTSlist_arraysize; i++)
        this->GTSlist_var[i] = other.GTSlist_var[i];
}

void Basic802154Packet::parsimPack(cCommBuffer *b)
{
    ::MacPacket::parsimPack(b);
    doPacking(b,this->Mac802154PacketType_var);
    doPacking(b,this->PANid_var);
    doPacking(b,this->srcID_var);
    doPacking(b,this->dstID_var);
    doPacking(b,this->seqNum_var);
    doPacking(b,this->beaconOrder_var);
    doPacking(b,this->frameOrder_var);
    doPacking(b,this->BSN_var);
    doPacking(b,this->CAPlength_var);
    doPacking(b,this->GTSlength_var);
    b->pack(GTSlist_arraysize);
    doPacking(b,this->GTSlist_var,GTSlist_arraysize);
}

void Basic802154Packet::parsimUnpack(cCommBuffer *b)
{
    ::MacPacket::parsimUnpack(b);
    doUnpacking(b,this->Mac802154PacketType_var);
    doUnpacking(b,this->PANid_var);
    doUnpacking(b,this->srcID_var);
    doUnpacking(b,this->dstID_var);
    doUnpacking(b,this->seqNum_var);
    doUnpacking(b,this->beaconOrder_var);
    doUnpacking(b,this->frameOrder_var);
    doUnpacking(b,this->BSN_var);
    doUnpacking(b,this->CAPlength_var);
    doUnpacking(b,this->GTSlength_var);
    delete [] this->GTSlist_var;
    b->unpack(GTSlist_arraysize);
    if (GTSlist_arraysize==0) {
        this->GTSlist_var = 0;
    } else {
        this->GTSlist_var = new Basic802154GTSspec[GTSlist_arraysize];
        doUnpacking(b,this->GTSlist_var,GTSlist_arraysize);
    }
}

int Basic802154Packet::getMac802154PacketType() const
{
    return Mac802154PacketType_var;
}

void Basic802154Packet::setMac802154PacketType(int Mac802154PacketType)
{
    this->Mac802154PacketType_var = Mac802154PacketType;
}

int Basic802154Packet::getPANid() const
{
    return PANid_var;
}

void Basic802154Packet::setPANid(int PANid)
{
    this->PANid_var = PANid;
}

int Basic802154Packet::getSrcID() const
{
    return srcID_var;
}

void Basic802154Packet::setSrcID(int srcID)
{
    this->srcID_var = srcID;
}

int Basic802154Packet::getDstID() const
{
    return dstID_var;
}

void Basic802154Packet::setDstID(int dstID)
{
    this->dstID_var = dstID;
}

int Basic802154Packet::getSeqNum() const
{
    return seqNum_var;
}

void Basic802154Packet::setSeqNum(int seqNum)
{
    this->seqNum_var = seqNum;
}

int Basic802154Packet::getBeaconOrder() const
{
    return beaconOrder_var;
}

void Basic802154Packet::setBeaconOrder(int beaconOrder)
{
    this->beaconOrder_var = beaconOrder;
}

int Basic802154Packet::getFrameOrder() const
{
    return frameOrder_var;
}

void Basic802154Packet::setFrameOrder(int frameOrder)
{
    this->frameOrder_var = frameOrder;
}

int Basic802154Packet::getBSN() const
{
    return BSN_var;
}

void Basic802154Packet::setBSN(int BSN)
{
    this->BSN_var = BSN;
}

int Basic802154Packet::getCAPlength() const
{
    return CAPlength_var;
}

void Basic802154Packet::setCAPlength(int CAPlength)
{
    this->CAPlength_var = CAPlength;
}

int Basic802154Packet::getGTSlength() const
{
    return GTSlength_var;
}

void Basic802154Packet::setGTSlength(int GTSlength)
{
    this->GTSlength_var = GTSlength;
}

void Basic802154Packet::setGTSlistArraySize(unsigned int size)
{
    Basic802154GTSspec *GTSlist_var2 = (size==0) ? NULL : new Basic802154GTSspec[size];
    unsigned int sz = GTSlist_arraysize < size ? GTSlist_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        GTSlist_var2[i] = this->GTSlist_var[i];
    GTSlist_arraysize = size;
    delete [] this->GTSlist_var;
    this->GTSlist_var = GTSlist_var2;
}

unsigned int Basic802154Packet::getGTSlistArraySize() const
{
    return GTSlist_arraysize;
}

Basic802154GTSspec& Basic802154Packet::getGTSlist(unsigned int k)
{
    if (k>=GTSlist_arraysize) throw cRuntimeError("Array of size %d indexed by %d", GTSlist_arraysize, k);
    return GTSlist_var[k];
}

void Basic802154Packet::setGTSlist(unsigned int k, const Basic802154GTSspec& GTSlist)
{
    if (k>=GTSlist_arraysize) throw cRuntimeError("Array of size %d indexed by %d", GTSlist_arraysize, k);
    this->GTSlist_var[k] = GTSlist;
}

class Basic802154PacketDescriptor : public cClassDescriptor
{
  public:
    Basic802154PacketDescriptor();
    virtual ~Basic802154PacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(Basic802154PacketDescriptor);

Basic802154PacketDescriptor::Basic802154PacketDescriptor() : cClassDescriptor("Basic802154Packet", "MacPacket")
{
}

Basic802154PacketDescriptor::~Basic802154PacketDescriptor()
{
}

bool Basic802154PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Basic802154Packet *>(obj)!=NULL;
}

const char *Basic802154PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Basic802154PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int Basic802154PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *Basic802154PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Mac802154PacketType",
        "PANid",
        "srcID",
        "dstID",
        "seqNum",
        "beaconOrder",
        "frameOrder",
        "BSN",
        "CAPlength",
        "GTSlength",
        "GTSlist",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int Basic802154PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='M' && strcmp(fieldName, "Mac802154PacketType")==0) return base+0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PANid")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcID")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstID")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+4;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconOrder")==0) return base+5;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameOrder")==0) return base+6;
    if (fieldName[0]=='B' && strcmp(fieldName, "BSN")==0) return base+7;
    if (fieldName[0]=='C' && strcmp(fieldName, "CAPlength")==0) return base+8;
    if (fieldName[0]=='G' && strcmp(fieldName, "GTSlength")==0) return base+9;
    if (fieldName[0]=='G' && strcmp(fieldName, "GTSlist")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *Basic802154PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "Basic802154GTSspec",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *Basic802154PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "Mac802154Packet_type";
            return NULL;
        default: return NULL;
    }
}

int Basic802154PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 10: return pp->getGTSlistArraySize();
        default: return 0;
    }
}

std::string Basic802154PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMac802154PacketType());
        case 1: return long2string(pp->getPANid());
        case 2: return long2string(pp->getSrcID());
        case 3: return long2string(pp->getDstID());
        case 4: return long2string(pp->getSeqNum());
        case 5: return long2string(pp->getBeaconOrder());
        case 6: return long2string(pp->getFrameOrder());
        case 7: return long2string(pp->getBSN());
        case 8: return long2string(pp->getCAPlength());
        case 9: return long2string(pp->getGTSlength());
        case 10: {std::stringstream out; out << pp->getGTSlist(i); return out.str();}
        default: return "";
    }
}

bool Basic802154PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setMac802154PacketType(string2long(value)); return true;
        case 1: pp->setPANid(string2long(value)); return true;
        case 2: pp->setSrcID(string2long(value)); return true;
        case 3: pp->setDstID(string2long(value)); return true;
        case 4: pp->setSeqNum(string2long(value)); return true;
        case 5: pp->setBeaconOrder(string2long(value)); return true;
        case 6: pp->setFrameOrder(string2long(value)); return true;
        case 7: pp->setBSN(string2long(value)); return true;
        case 8: pp->setCAPlength(string2long(value)); return true;
        case 9: pp->setGTSlength(string2long(value)); return true;
        default: return false;
    }
}

const char *Basic802154PacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 10: return opp_typename(typeid(Basic802154GTSspec));
        default: return NULL;
    };
}

void *Basic802154PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Basic802154Packet *pp = (Basic802154Packet *)object; (void)pp;
    switch (field) {
        case 10: return (void *)(&pp->getGTSlist(i)); break;
        default: return NULL;
    }
}


