//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/aodvRouting/AodvRoutingPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "AodvRoutingPacket_m.h"

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

Register_Class(AodvRREQPacket);

AodvRREQPacket::AodvRREQPacket(const char *name, int kind) : ::PacketId(name,kind)
{
    this->flagJ_var = 0;
    this->flagR_var = 0;
    this->flagG_var = 0;
    this->flagD_var = 0;
    this->flagU_var = 0;
    this->hopCount_var = 0;
    this->rreqID_var = 0;
    this->sourceAodv_var = 0;
    this->sourceSeqNum_var = 0;
    this->destinationSeqNum_var = 0;
    this->destinationAodv_var = 0;
}

AodvRREQPacket::AodvRREQPacket(const AodvRREQPacket& other) : ::PacketId(other)
{
    copy(other);
}

AodvRREQPacket::~AodvRREQPacket()
{
}

AodvRREQPacket& AodvRREQPacket::operator=(const AodvRREQPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRREQPacket::copy(const AodvRREQPacket& other)
{
    this->flagJ_var = other.flagJ_var;
    this->flagR_var = other.flagR_var;
    this->flagG_var = other.flagG_var;
    this->flagD_var = other.flagD_var;
    this->flagU_var = other.flagU_var;
    this->hopCount_var = other.hopCount_var;
    this->rreqID_var = other.rreqID_var;
    this->sourceAodv_var = other.sourceAodv_var;
    this->sourceSeqNum_var = other.sourceSeqNum_var;
    this->destinationSeqNum_var = other.destinationSeqNum_var;
    this->destinationAodv_var = other.destinationAodv_var;
}

void AodvRREQPacket::parsimPack(cCommBuffer *b)
{
    ::PacketId::parsimPack(b);
    doPacking(b,this->flagJ_var);
    doPacking(b,this->flagR_var);
    doPacking(b,this->flagG_var);
    doPacking(b,this->flagD_var);
    doPacking(b,this->flagU_var);
    doPacking(b,this->hopCount_var);
    doPacking(b,this->rreqID_var);
    doPacking(b,this->sourceAodv_var);
    doPacking(b,this->sourceSeqNum_var);
    doPacking(b,this->destinationSeqNum_var);
    doPacking(b,this->destinationAodv_var);
}

void AodvRREQPacket::parsimUnpack(cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
    doUnpacking(b,this->flagJ_var);
    doUnpacking(b,this->flagR_var);
    doUnpacking(b,this->flagG_var);
    doUnpacking(b,this->flagD_var);
    doUnpacking(b,this->flagU_var);
    doUnpacking(b,this->hopCount_var);
    doUnpacking(b,this->rreqID_var);
    doUnpacking(b,this->sourceAodv_var);
    doUnpacking(b,this->sourceSeqNum_var);
    doUnpacking(b,this->destinationSeqNum_var);
    doUnpacking(b,this->destinationAodv_var);
}

bool AodvRREQPacket::getFlagJ() const
{
    return flagJ_var;
}

void AodvRREQPacket::setFlagJ(bool flagJ)
{
    this->flagJ_var = flagJ;
}

bool AodvRREQPacket::getFlagR() const
{
    return flagR_var;
}

void AodvRREQPacket::setFlagR(bool flagR)
{
    this->flagR_var = flagR;
}

bool AodvRREQPacket::getFlagG() const
{
    return flagG_var;
}

void AodvRREQPacket::setFlagG(bool flagG)
{
    this->flagG_var = flagG;
}

bool AodvRREQPacket::getFlagD() const
{
    return flagD_var;
}

void AodvRREQPacket::setFlagD(bool flagD)
{
    this->flagD_var = flagD;
}

bool AodvRREQPacket::getFlagU() const
{
    return flagU_var;
}

void AodvRREQPacket::setFlagU(bool flagU)
{
    this->flagU_var = flagU;
}

int AodvRREQPacket::getHopCount() const
{
    return hopCount_var;
}

void AodvRREQPacket::setHopCount(int hopCount)
{
    this->hopCount_var = hopCount;
}

int AodvRREQPacket::getRreqID() const
{
    return rreqID_var;
}

void AodvRREQPacket::setRreqID(int rreqID)
{
    this->rreqID_var = rreqID;
}

const char * AodvRREQPacket::getSourceAodv() const
{
    return sourceAodv_var.c_str();
}

void AodvRREQPacket::setSourceAodv(const char * sourceAodv)
{
    this->sourceAodv_var = sourceAodv;
}

unsigned long AodvRREQPacket::getSourceSeqNum() const
{
    return sourceSeqNum_var;
}

void AodvRREQPacket::setSourceSeqNum(unsigned long sourceSeqNum)
{
    this->sourceSeqNum_var = sourceSeqNum;
}

unsigned long AodvRREQPacket::getDestinationSeqNum() const
{
    return destinationSeqNum_var;
}

void AodvRREQPacket::setDestinationSeqNum(unsigned long destinationSeqNum)
{
    this->destinationSeqNum_var = destinationSeqNum;
}

const char * AodvRREQPacket::getDestinationAodv() const
{
    return destinationAodv_var.c_str();
}

void AodvRREQPacket::setDestinationAodv(const char * destinationAodv)
{
    this->destinationAodv_var = destinationAodv;
}

class AodvRREQPacketDescriptor : public cClassDescriptor
{
  public:
    AodvRREQPacketDescriptor();
    virtual ~AodvRREQPacketDescriptor();

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

Register_ClassDescriptor(AodvRREQPacketDescriptor);

AodvRREQPacketDescriptor::AodvRREQPacketDescriptor() : cClassDescriptor("AodvRREQPacket", "PacketId")
{
}

AodvRREQPacketDescriptor::~AodvRREQPacketDescriptor()
{
}

bool AodvRREQPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AodvRREQPacket *>(obj)!=NULL;
}

const char *AodvRREQPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AodvRREQPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int AodvRREQPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *AodvRREQPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "flagJ",
        "flagR",
        "flagG",
        "flagD",
        "flagU",
        "hopCount",
        "rreqID",
        "sourceAodv",
        "sourceSeqNum",
        "destinationSeqNum",
        "destinationAodv",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int AodvRREQPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagJ")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagR")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagG")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagD")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagU")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "rreqID")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAodv")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceSeqNum")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationSeqNum")==0) return base+9;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAodv")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AodvRREQPacketDescriptor::getFieldTypeString(void *object, int field) const
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
        "bool",
        "bool",
        "bool",
        "int",
        "int",
        "string",
        "unsigned long",
        "unsigned long",
        "string",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *AodvRREQPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AodvRREQPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AodvRREQPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getFlagJ());
        case 1: return bool2string(pp->getFlagR());
        case 2: return bool2string(pp->getFlagG());
        case 3: return bool2string(pp->getFlagD());
        case 4: return bool2string(pp->getFlagU());
        case 5: return long2string(pp->getHopCount());
        case 6: return long2string(pp->getRreqID());
        case 7: return oppstring2string(pp->getSourceAodv());
        case 8: return ulong2string(pp->getSourceSeqNum());
        case 9: return ulong2string(pp->getDestinationSeqNum());
        case 10: return oppstring2string(pp->getDestinationAodv());
        default: return "";
    }
}

bool AodvRREQPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlagJ(string2bool(value)); return true;
        case 1: pp->setFlagR(string2bool(value)); return true;
        case 2: pp->setFlagG(string2bool(value)); return true;
        case 3: pp->setFlagD(string2bool(value)); return true;
        case 4: pp->setFlagU(string2bool(value)); return true;
        case 5: pp->setHopCount(string2long(value)); return true;
        case 6: pp->setRreqID(string2long(value)); return true;
        case 7: pp->setSourceAodv((value)); return true;
        case 8: pp->setSourceSeqNum(string2ulong(value)); return true;
        case 9: pp->setDestinationSeqNum(string2ulong(value)); return true;
        case 10: pp->setDestinationAodv((value)); return true;
        default: return false;
    }
}

const char *AodvRREQPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *AodvRREQPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREQPacket *pp = (AodvRREQPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(AodvHelloMessage);

AodvHelloMessage::AodvHelloMessage(const char *name, int kind) : ::PacketId(name,kind)
{
}

AodvHelloMessage::AodvHelloMessage(const AodvHelloMessage& other) : ::PacketId(other)
{
    copy(other);
}

AodvHelloMessage::~AodvHelloMessage()
{
}

AodvHelloMessage& AodvHelloMessage::operator=(const AodvHelloMessage& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvHelloMessage::copy(const AodvHelloMessage& other)
{
}

void AodvHelloMessage::parsimPack(cCommBuffer *b)
{
    ::PacketId::parsimPack(b);
}

void AodvHelloMessage::parsimUnpack(cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
}

class AodvHelloMessageDescriptor : public cClassDescriptor
{
  public:
    AodvHelloMessageDescriptor();
    virtual ~AodvHelloMessageDescriptor();

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

Register_ClassDescriptor(AodvHelloMessageDescriptor);

AodvHelloMessageDescriptor::AodvHelloMessageDescriptor() : cClassDescriptor("AodvHelloMessage", "PacketId")
{
}

AodvHelloMessageDescriptor::~AodvHelloMessageDescriptor()
{
}

bool AodvHelloMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AodvHelloMessage *>(obj)!=NULL;
}

const char *AodvHelloMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AodvHelloMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int AodvHelloMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *AodvHelloMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int AodvHelloMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AodvHelloMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *AodvHelloMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AodvHelloMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AodvHelloMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool AodvHelloMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *AodvHelloMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *AodvHelloMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AodvHelloMessage *pp = (AodvHelloMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(AodvRREPAckPacket);

AodvRREPAckPacket::AodvRREPAckPacket(const char *name, int kind) : ::PacketId(name,kind)
{
}

AodvRREPAckPacket::AodvRREPAckPacket(const AodvRREPAckPacket& other) : ::PacketId(other)
{
    copy(other);
}

AodvRREPAckPacket::~AodvRREPAckPacket()
{
}

AodvRREPAckPacket& AodvRREPAckPacket::operator=(const AodvRREPAckPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRREPAckPacket::copy(const AodvRREPAckPacket& other)
{
}

void AodvRREPAckPacket::parsimPack(cCommBuffer *b)
{
    ::PacketId::parsimPack(b);
}

void AodvRREPAckPacket::parsimUnpack(cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
}

class AodvRREPAckPacketDescriptor : public cClassDescriptor
{
  public:
    AodvRREPAckPacketDescriptor();
    virtual ~AodvRREPAckPacketDescriptor();

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

Register_ClassDescriptor(AodvRREPAckPacketDescriptor);

AodvRREPAckPacketDescriptor::AodvRREPAckPacketDescriptor() : cClassDescriptor("AodvRREPAckPacket", "PacketId")
{
}

AodvRREPAckPacketDescriptor::~AodvRREPAckPacketDescriptor()
{
}

bool AodvRREPAckPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AodvRREPAckPacket *>(obj)!=NULL;
}

const char *AodvRREPAckPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AodvRREPAckPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int AodvRREPAckPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *AodvRREPAckPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int AodvRREPAckPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AodvRREPAckPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *AodvRREPAckPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AodvRREPAckPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AodvRREPAckPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool AodvRREPAckPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *AodvRREPAckPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *AodvRREPAckPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRREPAckPacket *pp = (AodvRREPAckPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(AodvRERRPacket);

AodvRERRPacket::AodvRERRPacket(const char *name, int kind) : ::PacketId(name,kind)
{
    this->flagN_var = 0;
    this->destCount_var = 0;
    unreachableDestAddr_arraysize = 0;
    this->unreachableDestAddr_var = 0;
    unreachableDestSeqNum_arraysize = 0;
    this->unreachableDestSeqNum_var = 0;
}

AodvRERRPacket::AodvRERRPacket(const AodvRERRPacket& other) : ::PacketId(other)
{
    unreachableDestAddr_arraysize = 0;
    this->unreachableDestAddr_var = 0;
    unreachableDestSeqNum_arraysize = 0;
    this->unreachableDestSeqNum_var = 0;
    copy(other);
}

AodvRERRPacket::~AodvRERRPacket()
{
    delete [] unreachableDestAddr_var;
    delete [] unreachableDestSeqNum_var;
}

AodvRERRPacket& AodvRERRPacket::operator=(const AodvRERRPacket& other)
{
    if (this==&other) return *this;
    ::PacketId::operator=(other);
    copy(other);
    return *this;
}

void AodvRERRPacket::copy(const AodvRERRPacket& other)
{
    this->flagN_var = other.flagN_var;
    this->destCount_var = other.destCount_var;
    delete [] this->unreachableDestAddr_var;
    this->unreachableDestAddr_var = (other.unreachableDestAddr_arraysize==0) ? NULL : new opp_string[other.unreachableDestAddr_arraysize];
    unreachableDestAddr_arraysize = other.unreachableDestAddr_arraysize;
    for (unsigned int i=0; i<unreachableDestAddr_arraysize; i++)
        this->unreachableDestAddr_var[i] = other.unreachableDestAddr_var[i];
    delete [] this->unreachableDestSeqNum_var;
    this->unreachableDestSeqNum_var = (other.unreachableDestSeqNum_arraysize==0) ? NULL : new unsigned long[other.unreachableDestSeqNum_arraysize];
    unreachableDestSeqNum_arraysize = other.unreachableDestSeqNum_arraysize;
    for (unsigned int i=0; i<unreachableDestSeqNum_arraysize; i++)
        this->unreachableDestSeqNum_var[i] = other.unreachableDestSeqNum_var[i];
}

void AodvRERRPacket::parsimPack(cCommBuffer *b)
{
    ::PacketId::parsimPack(b);
    doPacking(b,this->flagN_var);
    doPacking(b,this->destCount_var);
    b->pack(unreachableDestAddr_arraysize);
    doPacking(b,this->unreachableDestAddr_var,unreachableDestAddr_arraysize);
    b->pack(unreachableDestSeqNum_arraysize);
    doPacking(b,this->unreachableDestSeqNum_var,unreachableDestSeqNum_arraysize);
}

void AodvRERRPacket::parsimUnpack(cCommBuffer *b)
{
    ::PacketId::parsimUnpack(b);
    doUnpacking(b,this->flagN_var);
    doUnpacking(b,this->destCount_var);
    delete [] this->unreachableDestAddr_var;
    b->unpack(unreachableDestAddr_arraysize);
    if (unreachableDestAddr_arraysize==0) {
        this->unreachableDestAddr_var = 0;
    } else {
        this->unreachableDestAddr_var = new opp_string[unreachableDestAddr_arraysize];
        doUnpacking(b,this->unreachableDestAddr_var,unreachableDestAddr_arraysize);
    }
    delete [] this->unreachableDestSeqNum_var;
    b->unpack(unreachableDestSeqNum_arraysize);
    if (unreachableDestSeqNum_arraysize==0) {
        this->unreachableDestSeqNum_var = 0;
    } else {
        this->unreachableDestSeqNum_var = new unsigned long[unreachableDestSeqNum_arraysize];
        doUnpacking(b,this->unreachableDestSeqNum_var,unreachableDestSeqNum_arraysize);
    }
}

bool AodvRERRPacket::getFlagN() const
{
    return flagN_var;
}

void AodvRERRPacket::setFlagN(bool flagN)
{
    this->flagN_var = flagN;
}

int AodvRERRPacket::getDestCount() const
{
    return destCount_var;
}

void AodvRERRPacket::setDestCount(int destCount)
{
    this->destCount_var = destCount;
}

void AodvRERRPacket::setUnreachableDestAddrArraySize(unsigned int size)
{
    opp_string *unreachableDestAddr_var2 = (size==0) ? NULL : new opp_string[size];
    unsigned int sz = unreachableDestAddr_arraysize < size ? unreachableDestAddr_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableDestAddr_var2[i] = this->unreachableDestAddr_var[i];
    for (unsigned int i=sz; i<size; i++)
        unreachableDestAddr_var2[i] = 0;
    unreachableDestAddr_arraysize = size;
    delete [] this->unreachableDestAddr_var;
    this->unreachableDestAddr_var = unreachableDestAddr_var2;
}

unsigned int AodvRERRPacket::getUnreachableDestAddrArraySize() const
{
    return unreachableDestAddr_arraysize;
}

const char * AodvRERRPacket::getUnreachableDestAddr(unsigned int k) const
{
    if (k>=unreachableDestAddr_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unreachableDestAddr_arraysize, k);
    return unreachableDestAddr_var[k].c_str();
}

void AodvRERRPacket::setUnreachableDestAddr(unsigned int k, const char * unreachableDestAddr)
{
    if (k>=unreachableDestAddr_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unreachableDestAddr_arraysize, k);
    this->unreachableDestAddr_var[k] = unreachableDestAddr;
}

void AodvRERRPacket::setUnreachableDestSeqNumArraySize(unsigned int size)
{
    unsigned long *unreachableDestSeqNum_var2 = (size==0) ? NULL : new unsigned long[size];
    unsigned int sz = unreachableDestSeqNum_arraysize < size ? unreachableDestSeqNum_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unreachableDestSeqNum_var2[i] = this->unreachableDestSeqNum_var[i];
    for (unsigned int i=sz; i<size; i++)
        unreachableDestSeqNum_var2[i] = 0;
    unreachableDestSeqNum_arraysize = size;
    delete [] this->unreachableDestSeqNum_var;
    this->unreachableDestSeqNum_var = unreachableDestSeqNum_var2;
}

unsigned int AodvRERRPacket::getUnreachableDestSeqNumArraySize() const
{
    return unreachableDestSeqNum_arraysize;
}

unsigned long AodvRERRPacket::getUnreachableDestSeqNum(unsigned int k) const
{
    if (k>=unreachableDestSeqNum_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unreachableDestSeqNum_arraysize, k);
    return unreachableDestSeqNum_var[k];
}

void AodvRERRPacket::setUnreachableDestSeqNum(unsigned int k, unsigned long unreachableDestSeqNum)
{
    if (k>=unreachableDestSeqNum_arraysize) throw cRuntimeError("Array of size %d indexed by %d", unreachableDestSeqNum_arraysize, k);
    this->unreachableDestSeqNum_var[k] = unreachableDestSeqNum;
}

class AodvRERRPacketDescriptor : public cClassDescriptor
{
  public:
    AodvRERRPacketDescriptor();
    virtual ~AodvRERRPacketDescriptor();

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

Register_ClassDescriptor(AodvRERRPacketDescriptor);

AodvRERRPacketDescriptor::AodvRERRPacketDescriptor() : cClassDescriptor("AodvRERRPacket", "PacketId")
{
}

AodvRERRPacketDescriptor::~AodvRERRPacketDescriptor()
{
}

bool AodvRERRPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AodvRERRPacket *>(obj)!=NULL;
}

const char *AodvRERRPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AodvRERRPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int AodvRERRPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *AodvRERRPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "flagN",
        "destCount",
        "unreachableDestAddr",
        "unreachableDestSeqNum",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int AodvRERRPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flagN")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destCount")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableDestAddr")==0) return base+2;
    if (fieldName[0]=='u' && strcmp(fieldName, "unreachableDestSeqNum")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AodvRERRPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "string",
        "unsigned long",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *AodvRERRPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AodvRERRPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        case 2: return pp->getUnreachableDestAddrArraySize();
        case 3: return pp->getUnreachableDestSeqNumArraySize();
        default: return 0;
    }
}

std::string AodvRERRPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getFlagN());
        case 1: return long2string(pp->getDestCount());
        case 2: return oppstring2string(pp->getUnreachableDestAddr(i));
        case 3: return ulong2string(pp->getUnreachableDestSeqNum(i));
        default: return "";
    }
}

bool AodvRERRPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlagN(string2bool(value)); return true;
        case 1: pp->setDestCount(string2long(value)); return true;
        case 2: pp->setUnreachableDestAddr(i,(value)); return true;
        case 3: pp->setUnreachableDestSeqNum(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *AodvRERRPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *AodvRERRPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AodvRERRPacket *pp = (AodvRERRPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


