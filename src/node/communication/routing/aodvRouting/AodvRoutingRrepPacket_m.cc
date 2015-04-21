//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/aodvRouting/AodvRoutingRrepPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "AodvRoutingRrepPacket_m.h"

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

Register_Class(AodvRREPPacket);

AodvRREPPacket::AodvRREPPacket(const char *name, int kind) : ::PacketId(name,kind)
{
    this->flagR_var = 0;
    this->flagA_var = 0;
    this->prefixSz_var = 0;
    this->hopCount_var = 0;
    this->originator_var = 0;
    this->destinationSeqNum_var = 0;
    this->destinationAodv_var = 0;
    this->lifetime_var = 0;
}

AodvRREPPacket::AodvRREPPacket(const AodvRREPPacket& other) : ::PacketId(other)
{
    copy(other);
}

AodvRREPPacket::~AodvRREPPacket()
{
}

AodvRREPPacket& AodvRREPPacket::operator=(const AodvRREPPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRREPPacket::copy(const AodvRREPPacket& other)
{
    this->flagR_var = other.flagR_var;
    this->flagA_var = other.flagA_var;
    this->prefixSz_var = other.prefixSz_var;
    this->hopCount_var = other.hopCount_var;
    this->originator_var = other.originator_var;
    this->destinationSeqNum_var = other.destinationSeqNum_var;
    this->destinationAodv_var = other.destinationAodv_var;
    this->lifetime_var = other.lifetime_var;
}

void AodvRREPPacket::parsimPack(cCommBuffer *b)
{
    ::PacketId::parsimPack(b);
    doPacking(b,this->flagR_var);
    doPacking(b,this->flagA_var);
    doPacking(b,this->prefixSz_var);
    doPacking(b,this->hopCount_var);
    doPacking(b,this->originator_var);
    doPacking(b,this->destinationSeqNum_var);
    doPacking(b,this->destinationAodv_var);
    doPacking(b,this->lifetime_var);
}

void AodvRREPPacket::parsimUnpack(cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
    doUnpacking(b,this->flagR_var);
    doUnpacking(b,this->flagA_var);
    doUnpacking(b,this->prefixSz_var);
    doUnpacking(b,this->hopCount_var);
    doUnpacking(b,this->originator_var);
    doUnpacking(b,this->destinationSeqNum_var);
    doUnpacking(b,this->destinationAodv_var);
    doUnpacking(b,this->lifetime_var);
}

bool AodvRREPPacket::getFlagR() const
{
    return flagR_var;
}

void AodvRREPPacket::setFlagR(bool flagR)
{
    this->flagR_var = flagR;
}

bool AodvRREPPacket::getFlagA() const
{
    return flagA_var;
}

void AodvRREPPacket::setFlagA(bool flagA)
{
    this->flagA_var = flagA;
}

int AodvRREPPacket::getPrefixSz() const
{
    return prefixSz_var;
}

void AodvRREPPacket::setPrefixSz(int prefixSz)
{
    this->prefixSz_var = prefixSz;
}

int AodvRREPPacket::getHopCount() const
{
    return hopCount_var;
}

void AodvRREPPacket::setHopCount(int hopCount)
{
    this->hopCount_var = hopCount;
}

const char * AodvRREPPacket::getOriginator() const
{
    return originator_var.c_str();
}

void AodvRREPPacket::setOriginator(const char * originator)
{
    this->originator_var = originator;
}

unsigned long AodvRREPPacket::getDestinationSeqNum() const
{
    return destinationSeqNum_var;
}

void AodvRREPPacket::setDestinationSeqNum(unsigned long destinationSeqNum)
{
    this->destinationSeqNum_var = destinationSeqNum;
}

const char * AodvRREPPacket::getDestinationAodv() const
{
    return destinationAodv_var.c_str();
}

void AodvRREPPacket::setDestinationAodv(const char * destinationAodv)
{
    this->destinationAodv_var = destinationAodv;
}

double AodvRREPPacket::getLifetime() const
{
    return lifetime_var;
}

void AodvRREPPacket::setLifetime(double lifetime)
{
    this->lifetime_var = lifetime;
}

class AodvRREPPacketDescriptor : public cClassDescriptor
{
  public:
    AodvRREPPacketDescriptor();
    virtual ~AodvRREPPacketDescriptor();

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

Register_ClassDescriptor(AodvRREPPacketDescriptor);

AodvRREPPacketDescriptor::AodvRREPPacketDescriptor() : cClassDescriptor("AodvRREPPacket", "PacketId")
{
}

AodvRREPPacketDescriptor::~AodvRREPPacketDescriptor()
{
}

bool AodvRREPPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AodvRREPPacket *>(obj)!=NULL;
}

const char *AodvRREPPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AodvRREPPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int AodvRREPPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *AodvRREPPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "flagR",
        "flagA",
        "prefixSz",
        "hopCount",
        "originator",
        "destinationSeqNum",
        "destinationAodv",
        "lifetime",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int AodvRREPPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagR")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagA")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixSz")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+3;
    if (fieldName[0]=='o' && strcmp(fieldName, "originator")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationSeqNum")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAodv")==0) return base+6;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifetime")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AodvRREPPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "int",
        "int",
        "string",
        "unsigned long",
        "string",
        "double",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *AodvRREPPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AodvRREPPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AodvRREPPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getFlagR());
        case 1: return bool2string(pp->getFlagA());
        case 2: return long2string(pp->getPrefixSz());
        case 3: return long2string(pp->getHopCount());
        case 4: return oppstring2string(pp->getOriginator());
        case 5: return ulong2string(pp->getDestinationSeqNum());
        case 6: return oppstring2string(pp->getDestinationAodv());
        case 7: return double2string(pp->getLifetime());
        default: return "";
    }
}

bool AodvRREPPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlagR(string2bool(value)); return true;
        case 1: pp->setFlagA(string2bool(value)); return true;
        case 2: pp->setPrefixSz(string2long(value)); return true;
        case 3: pp->setHopCount(string2long(value)); return true;
        case 4: pp->setOriginator((value)); return true;
        case 5: pp->setDestinationSeqNum(string2ulong(value)); return true;
        case 6: pp->setDestinationAodv((value)); return true;
        case 7: pp->setLifetime(string2double(value)); return true;
        default: return false;
    }
}

const char *AodvRREPPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *AodvRREPPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPPacket *pp = (AodvRREPPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


