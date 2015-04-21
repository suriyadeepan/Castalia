//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/mac/baselineBanMac/BaselineMacPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BaselineMacPacket_m.h"

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
    cEnum *e = cEnum::find("SecurityLevel_type");
    if (!e) enums.getInstance()->add(e = new cEnum("SecurityLevel_type"));
    e->insert(NOT_SECURED, "NOT_SECURED");
    e->insert(AUTHENTICATED_NOT_ENCRYPTED, "AUTHENTICATED_NOT_ENCRYPTED");
    e->insert(AUTHENTICATED_AND_ENCRYPTED, "AUTHENTICATED_AND_ENCRYPTED");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("AcknowledgementPolicy_type");
    if (!e) enums.getInstance()->add(e = new cEnum("AcknowledgementPolicy_type"));
    e->insert(N_ACK_POLICY, "N_ACK_POLICY");
    e->insert(I_ACK_POLICY, "I_ACK_POLICY");
    e->insert(L_ACK_POLICY, "L_ACK_POLICY");
    e->insert(B_ACK_POLICY, "B_ACK_POLICY");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("Frame_type");
    if (!e) enums.getInstance()->add(e = new cEnum("Frame_type"));
    e->insert(MANAGEMENT, "MANAGEMENT");
    e->insert(CONTROL, "CONTROL");
    e->insert(DATA, "DATA");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("Frame_subtype");
    if (!e) enums.getInstance()->add(e = new cEnum("Frame_subtype"));
    e->insert(RESERVED, "RESERVED");
    e->insert(BEACON, "BEACON");
    e->insert(ASSOCIATION, "ASSOCIATION");
    e->insert(DISASSOCIATION, "DISASSOCIATION");
    e->insert(PTK, "PTK");
    e->insert(GTK, "GTK");
    e->insert(CONNECTION_REQUEST, "CONNECTION_REQUEST");
    e->insert(CONNECTION_ASSIGNMENT, "CONNECTION_ASSIGNMENT");
    e->insert(DISCONNECTION, "DISCONNECTION");
    e->insert(I_ACK, "I_ACK");
    e->insert(B_ACK, "B_ACK");
    e->insert(I_ACK_POLL, "I_ACK_POLL");
    e->insert(B_ACK_POLL, "B_ACK_POLL");
    e->insert(POLL, "POLL");
    e->insert(T_POLL, "T_POLL");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("statusCode_type");
    if (!e) enums.getInstance()->add(e = new cEnum("statusCode_type"));
    e->insert(ACCEPTED, "ACCEPTED");
    e->insert(REJ_NO_BANDWIDTH, "REJ_NO_BANDWIDTH");
    e->insert(REJ_NO_NID, "REJ_NO_NID");
    e->insert(REJ_NO_RESOURCES, "REJ_NO_RESOURCES");
    e->insert(REJ_NO_HIGH_SECURITY, "REJ_NO_HIGH_SECURITY");
    e->insert(REJ_NO_LOW_SECURITY, "REJ_NO_LOW_SECURITY");
    e->insert(REJ_NO_REASON, "REJ_NO_REASON");
    e->insert(MODIFIED, "MODIFIED");
);

Register_Class(BaselineMacPacket);

BaselineMacPacket::BaselineMacPacket(const char *name, int kind) : ::MacPacket(name,kind)
{
    this->HID_var = 0;
    this->NID_var = 0;
    this->protocolVersion_var = 0;
    this->securityLevel_var = 0;
    this->TKindex_var = 0;
    this->retry_var = 0;
    this->ackPolicy_var = 0;
    this->frameType_var = 0;
    this->frameSubtype_var = 0;
    this->moreData_var = 0;
    this->firstFrame_var = 0;
    this->sequenceNum_var = 0;
    this->fragmentNumber_var = 0;
}

BaselineMacPacket::BaselineMacPacket(const BaselineMacPacket& other) : ::MacPacket(other)
{
    copy(other);
}

BaselineMacPacket::~BaselineMacPacket()
{
}

BaselineMacPacket& BaselineMacPacket::operator=(const BaselineMacPacket& other)
{
    if (this==&other) return *this;
    ::MacPacket::operator=(other);
    copy(other);
    return *this;
}

void BaselineMacPacket::copy(const BaselineMacPacket& other)
{
    this->HID_var = other.HID_var;
    this->NID_var = other.NID_var;
    this->protocolVersion_var = other.protocolVersion_var;
    this->securityLevel_var = other.securityLevel_var;
    this->TKindex_var = other.TKindex_var;
    this->retry_var = other.retry_var;
    this->ackPolicy_var = other.ackPolicy_var;
    this->frameType_var = other.frameType_var;
    this->frameSubtype_var = other.frameSubtype_var;
    this->moreData_var = other.moreData_var;
    this->firstFrame_var = other.firstFrame_var;
    this->sequenceNum_var = other.sequenceNum_var;
    this->fragmentNumber_var = other.fragmentNumber_var;
}

void BaselineMacPacket::parsimPack(cCommBuffer *b)
{
    ::MacPacket::parsimPack(b);
    doPacking(b,this->HID_var);
    doPacking(b,this->NID_var);
    doPacking(b,this->protocolVersion_var);
    doPacking(b,this->securityLevel_var);
    doPacking(b,this->TKindex_var);
    doPacking(b,this->retry_var);
    doPacking(b,this->ackPolicy_var);
    doPacking(b,this->frameType_var);
    doPacking(b,this->frameSubtype_var);
    doPacking(b,this->moreData_var);
    doPacking(b,this->firstFrame_var);
    doPacking(b,this->sequenceNum_var);
    doPacking(b,this->fragmentNumber_var);
}

void BaselineMacPacket::parsimUnpack(cCommBuffer *b)
{
    ::MacPacket::parsimUnpack(b);
    doUnpacking(b,this->HID_var);
    doUnpacking(b,this->NID_var);
    doUnpacking(b,this->protocolVersion_var);
    doUnpacking(b,this->securityLevel_var);
    doUnpacking(b,this->TKindex_var);
    doUnpacking(b,this->retry_var);
    doUnpacking(b,this->ackPolicy_var);
    doUnpacking(b,this->frameType_var);
    doUnpacking(b,this->frameSubtype_var);
    doUnpacking(b,this->moreData_var);
    doUnpacking(b,this->firstFrame_var);
    doUnpacking(b,this->sequenceNum_var);
    doUnpacking(b,this->fragmentNumber_var);
}

int BaselineMacPacket::getHID() const
{
    return HID_var;
}

void BaselineMacPacket::setHID(int HID)
{
    this->HID_var = HID;
}

int BaselineMacPacket::getNID() const
{
    return NID_var;
}

void BaselineMacPacket::setNID(int NID)
{
    this->NID_var = NID;
}

int BaselineMacPacket::getProtocolVersion() const
{
    return protocolVersion_var;
}

void BaselineMacPacket::setProtocolVersion(int protocolVersion)
{
    this->protocolVersion_var = protocolVersion;
}

int BaselineMacPacket::getSecurityLevel() const
{
    return securityLevel_var;
}

void BaselineMacPacket::setSecurityLevel(int securityLevel)
{
    this->securityLevel_var = securityLevel;
}

int BaselineMacPacket::getTKindex() const
{
    return TKindex_var;
}

void BaselineMacPacket::setTKindex(int TKindex)
{
    this->TKindex_var = TKindex;
}

int BaselineMacPacket::getRetry() const
{
    return retry_var;
}

void BaselineMacPacket::setRetry(int retry)
{
    this->retry_var = retry;
}

int BaselineMacPacket::getAckPolicy() const
{
    return ackPolicy_var;
}

void BaselineMacPacket::setAckPolicy(int ackPolicy)
{
    this->ackPolicy_var = ackPolicy;
}

int BaselineMacPacket::getFrameType() const
{
    return frameType_var;
}

void BaselineMacPacket::setFrameType(int frameType)
{
    this->frameType_var = frameType;
}

int BaselineMacPacket::getFrameSubtype() const
{
    return frameSubtype_var;
}

void BaselineMacPacket::setFrameSubtype(int frameSubtype)
{
    this->frameSubtype_var = frameSubtype;
}

int BaselineMacPacket::getMoreData() const
{
    return moreData_var;
}

void BaselineMacPacket::setMoreData(int moreData)
{
    this->moreData_var = moreData;
}

int BaselineMacPacket::getFirstFrame() const
{
    return firstFrame_var;
}

void BaselineMacPacket::setFirstFrame(int firstFrame)
{
    this->firstFrame_var = firstFrame;
}

int BaselineMacPacket::getSequenceNum() const
{
    return sequenceNum_var;
}

void BaselineMacPacket::setSequenceNum(int sequenceNum)
{
    this->sequenceNum_var = sequenceNum;
}

int BaselineMacPacket::getFragmentNumber() const
{
    return fragmentNumber_var;
}

void BaselineMacPacket::setFragmentNumber(int fragmentNumber)
{
    this->fragmentNumber_var = fragmentNumber;
}

class BaselineMacPacketDescriptor : public cClassDescriptor
{
  public:
    BaselineMacPacketDescriptor();
    virtual ~BaselineMacPacketDescriptor();

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

Register_ClassDescriptor(BaselineMacPacketDescriptor);

BaselineMacPacketDescriptor::BaselineMacPacketDescriptor() : cClassDescriptor("BaselineMacPacket", "MacPacket")
{
}

BaselineMacPacketDescriptor::~BaselineMacPacketDescriptor()
{
}

bool BaselineMacPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BaselineMacPacket *>(obj)!=NULL;
}

const char *BaselineMacPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BaselineMacPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount(object) : 13;
}

unsigned int BaselineMacPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *BaselineMacPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "HID",
        "NID",
        "protocolVersion",
        "securityLevel",
        "TKindex",
        "retry",
        "ackPolicy",
        "frameType",
        "frameSubtype",
        "moreData",
        "firstFrame",
        "sequenceNum",
        "fragmentNumber",
    };
    return (field>=0 && field<13) ? fieldNames[field] : NULL;
}

int BaselineMacPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='H' && strcmp(fieldName, "HID")==0) return base+0;
    if (fieldName[0]=='N' && strcmp(fieldName, "NID")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocolVersion")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "securityLevel")==0) return base+3;
    if (fieldName[0]=='T' && strcmp(fieldName, "TKindex")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "retry")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackPolicy")==0) return base+6;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameType")==0) return base+7;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameSubtype")==0) return base+8;
    if (fieldName[0]=='m' && strcmp(fieldName, "moreData")==0) return base+9;
    if (fieldName[0]=='f' && strcmp(fieldName, "firstFrame")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNum")==0) return base+11;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentNumber")==0) return base+12;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BaselineMacPacketDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : NULL;
}

const char *BaselineMacPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3:
            if (!strcmp(propertyname,"enum")) return "SecurityLevel_type";
            return NULL;
        case 6:
            if (!strcmp(propertyname,"enum")) return "AcknowledgementPolicy_type";
            return NULL;
        case 7:
            if (!strcmp(propertyname,"enum")) return "Frame_type";
            return NULL;
        case 8:
            if (!strcmp(propertyname,"enum")) return "Frame_subtype";
            return NULL;
        default: return NULL;
    }
}

int BaselineMacPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BaselineMacPacket *pp = (BaselineMacPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BaselineMacPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineMacPacket *pp = (BaselineMacPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getHID());
        case 1: return long2string(pp->getNID());
        case 2: return long2string(pp->getProtocolVersion());
        case 3: return long2string(pp->getSecurityLevel());
        case 4: return long2string(pp->getTKindex());
        case 5: return long2string(pp->getRetry());
        case 6: return long2string(pp->getAckPolicy());
        case 7: return long2string(pp->getFrameType());
        case 8: return long2string(pp->getFrameSubtype());
        case 9: return long2string(pp->getMoreData());
        case 10: return long2string(pp->getFirstFrame());
        case 11: return long2string(pp->getSequenceNum());
        case 12: return long2string(pp->getFragmentNumber());
        default: return "";
    }
}

bool BaselineMacPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BaselineMacPacket *pp = (BaselineMacPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setHID(string2long(value)); return true;
        case 1: pp->setNID(string2long(value)); return true;
        case 2: pp->setProtocolVersion(string2long(value)); return true;
        case 3: pp->setSecurityLevel(string2long(value)); return true;
        case 4: pp->setTKindex(string2long(value)); return true;
        case 5: pp->setRetry(string2long(value)); return true;
        case 6: pp->setAckPolicy(string2long(value)); return true;
        case 7: pp->setFrameType(string2long(value)); return true;
        case 8: pp->setFrameSubtype(string2long(value)); return true;
        case 9: pp->setMoreData(string2long(value)); return true;
        case 10: pp->setFirstFrame(string2long(value)); return true;
        case 11: pp->setSequenceNum(string2long(value)); return true;
        case 12: pp->setFragmentNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *BaselineMacPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *BaselineMacPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineMacPacket *pp = (BaselineMacPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BaselineBeaconPacket);

BaselineBeaconPacket::BaselineBeaconPacket(const char *name, int kind) : ::BaselineMacPacket(name,kind)
{
    this->senderAddress_var = 0;
    this->beaconShiftingSequenceIndex_var = 0;
    this->beaconShiftingSequencePhase_var = 0;
    this->beaconPeriodLength_var = 0;
    this->allocationSlotLength_var = 0;
    this->RAP1Length_var = 0;
    this->RAP2Length_var = 0;
}

BaselineBeaconPacket::BaselineBeaconPacket(const BaselineBeaconPacket& other) : ::BaselineMacPacket(other)
{
    copy(other);
}

BaselineBeaconPacket::~BaselineBeaconPacket()
{
}

BaselineBeaconPacket& BaselineBeaconPacket::operator=(const BaselineBeaconPacket& other)
{
    if (this==&other) return *this;
    ::BaselineMacPacket::operator=(other);
    copy(other);
    return *this;
}

void BaselineBeaconPacket::copy(const BaselineBeaconPacket& other)
{
    this->senderAddress_var = other.senderAddress_var;
    this->beaconShiftingSequenceIndex_var = other.beaconShiftingSequenceIndex_var;
    this->beaconShiftingSequencePhase_var = other.beaconShiftingSequencePhase_var;
    this->beaconPeriodLength_var = other.beaconPeriodLength_var;
    this->allocationSlotLength_var = other.allocationSlotLength_var;
    this->RAP1Length_var = other.RAP1Length_var;
    this->RAP2Length_var = other.RAP2Length_var;
}

void BaselineBeaconPacket::parsimPack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimPack(b);
    doPacking(b,this->senderAddress_var);
    doPacking(b,this->beaconShiftingSequenceIndex_var);
    doPacking(b,this->beaconShiftingSequencePhase_var);
    doPacking(b,this->beaconPeriodLength_var);
    doPacking(b,this->allocationSlotLength_var);
    doPacking(b,this->RAP1Length_var);
    doPacking(b,this->RAP2Length_var);
}

void BaselineBeaconPacket::parsimUnpack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimUnpack(b);
    doUnpacking(b,this->senderAddress_var);
    doUnpacking(b,this->beaconShiftingSequenceIndex_var);
    doUnpacking(b,this->beaconShiftingSequencePhase_var);
    doUnpacking(b,this->beaconPeriodLength_var);
    doUnpacking(b,this->allocationSlotLength_var);
    doUnpacking(b,this->RAP1Length_var);
    doUnpacking(b,this->RAP2Length_var);
}

int BaselineBeaconPacket::getSenderAddress() const
{
    return senderAddress_var;
}

void BaselineBeaconPacket::setSenderAddress(int senderAddress)
{
    this->senderAddress_var = senderAddress;
}

int BaselineBeaconPacket::getBeaconShiftingSequenceIndex() const
{
    return beaconShiftingSequenceIndex_var;
}

void BaselineBeaconPacket::setBeaconShiftingSequenceIndex(int beaconShiftingSequenceIndex)
{
    this->beaconShiftingSequenceIndex_var = beaconShiftingSequenceIndex;
}

int BaselineBeaconPacket::getBeaconShiftingSequencePhase() const
{
    return beaconShiftingSequencePhase_var;
}

void BaselineBeaconPacket::setBeaconShiftingSequencePhase(int beaconShiftingSequencePhase)
{
    this->beaconShiftingSequencePhase_var = beaconShiftingSequencePhase;
}

int BaselineBeaconPacket::getBeaconPeriodLength() const
{
    return beaconPeriodLength_var;
}

void BaselineBeaconPacket::setBeaconPeriodLength(int beaconPeriodLength)
{
    this->beaconPeriodLength_var = beaconPeriodLength;
}

int BaselineBeaconPacket::getAllocationSlotLength() const
{
    return allocationSlotLength_var;
}

void BaselineBeaconPacket::setAllocationSlotLength(int allocationSlotLength)
{
    this->allocationSlotLength_var = allocationSlotLength;
}

int BaselineBeaconPacket::getRAP1Length() const
{
    return RAP1Length_var;
}

void BaselineBeaconPacket::setRAP1Length(int RAP1Length)
{
    this->RAP1Length_var = RAP1Length;
}

int BaselineBeaconPacket::getRAP2Length() const
{
    return RAP2Length_var;
}

void BaselineBeaconPacket::setRAP2Length(int RAP2Length)
{
    this->RAP2Length_var = RAP2Length;
}

class BaselineBeaconPacketDescriptor : public cClassDescriptor
{
  public:
    BaselineBeaconPacketDescriptor();
    virtual ~BaselineBeaconPacketDescriptor();

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

Register_ClassDescriptor(BaselineBeaconPacketDescriptor);

BaselineBeaconPacketDescriptor::BaselineBeaconPacketDescriptor() : cClassDescriptor("BaselineBeaconPacket", "BaselineMacPacket")
{
}

BaselineBeaconPacketDescriptor::~BaselineBeaconPacketDescriptor()
{
}

bool BaselineBeaconPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BaselineBeaconPacket *>(obj)!=NULL;
}

const char *BaselineBeaconPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BaselineBeaconPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int BaselineBeaconPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *BaselineBeaconPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "senderAddress",
        "beaconShiftingSequenceIndex",
        "beaconShiftingSequencePhase",
        "beaconPeriodLength",
        "allocationSlotLength",
        "RAP1Length",
        "RAP2Length",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int BaselineBeaconPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderAddress")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconShiftingSequenceIndex")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconShiftingSequencePhase")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconPeriodLength")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "allocationSlotLength")==0) return base+4;
    if (fieldName[0]=='R' && strcmp(fieldName, "RAP1Length")==0) return base+5;
    if (fieldName[0]=='R' && strcmp(fieldName, "RAP2Length")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BaselineBeaconPacketDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *BaselineBeaconPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BaselineBeaconPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBeaconPacket *pp = (BaselineBeaconPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BaselineBeaconPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBeaconPacket *pp = (BaselineBeaconPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSenderAddress());
        case 1: return long2string(pp->getBeaconShiftingSequenceIndex());
        case 2: return long2string(pp->getBeaconShiftingSequencePhase());
        case 3: return long2string(pp->getBeaconPeriodLength());
        case 4: return long2string(pp->getAllocationSlotLength());
        case 5: return long2string(pp->getRAP1Length());
        case 6: return long2string(pp->getRAP2Length());
        default: return "";
    }
}

bool BaselineBeaconPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBeaconPacket *pp = (BaselineBeaconPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSenderAddress(string2long(value)); return true;
        case 1: pp->setBeaconShiftingSequenceIndex(string2long(value)); return true;
        case 2: pp->setBeaconShiftingSequencePhase(string2long(value)); return true;
        case 3: pp->setBeaconPeriodLength(string2long(value)); return true;
        case 4: pp->setAllocationSlotLength(string2long(value)); return true;
        case 5: pp->setRAP1Length(string2long(value)); return true;
        case 6: pp->setRAP2Length(string2long(value)); return true;
        default: return false;
    }
}

const char *BaselineBeaconPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *BaselineBeaconPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBeaconPacket *pp = (BaselineBeaconPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BaselineConnectionRequestPacket);

BaselineConnectionRequestPacket::BaselineConnectionRequestPacket(const char *name, int kind) : ::BaselineMacPacket(name,kind)
{
    this->recipientAddress_var = 0;
    this->senderAddress_var = 0;
    this->formerHubAddress_var = 0;
    this->changeIndication_var = 0;
    this->nextWakeup_var = 0;
    this->wakeupInterval_var = 0;
    this->uplinkRequest_var = 0;
    this->downlinkRequest_var = 0;
    this->bilinkRequest_var = 0;
}

BaselineConnectionRequestPacket::BaselineConnectionRequestPacket(const BaselineConnectionRequestPacket& other) : ::BaselineMacPacket(other)
{
    copy(other);
}

BaselineConnectionRequestPacket::~BaselineConnectionRequestPacket()
{
}

BaselineConnectionRequestPacket& BaselineConnectionRequestPacket::operator=(const BaselineConnectionRequestPacket& other)
{
    if (this==&other) return *this;
    ::BaselineMacPacket::operator=(other);
    copy(other);
    return *this;
}

void BaselineConnectionRequestPacket::copy(const BaselineConnectionRequestPacket& other)
{
    this->recipientAddress_var = other.recipientAddress_var;
    this->senderAddress_var = other.senderAddress_var;
    this->formerHubAddress_var = other.formerHubAddress_var;
    this->changeIndication_var = other.changeIndication_var;
    this->nextWakeup_var = other.nextWakeup_var;
    this->wakeupInterval_var = other.wakeupInterval_var;
    this->uplinkRequest_var = other.uplinkRequest_var;
    this->downlinkRequest_var = other.downlinkRequest_var;
    this->bilinkRequest_var = other.bilinkRequest_var;
}

void BaselineConnectionRequestPacket::parsimPack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimPack(b);
    doPacking(b,this->recipientAddress_var);
    doPacking(b,this->senderAddress_var);
    doPacking(b,this->formerHubAddress_var);
    doPacking(b,this->changeIndication_var);
    doPacking(b,this->nextWakeup_var);
    doPacking(b,this->wakeupInterval_var);
    doPacking(b,this->uplinkRequest_var);
    doPacking(b,this->downlinkRequest_var);
    doPacking(b,this->bilinkRequest_var);
}

void BaselineConnectionRequestPacket::parsimUnpack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimUnpack(b);
    doUnpacking(b,this->recipientAddress_var);
    doUnpacking(b,this->senderAddress_var);
    doUnpacking(b,this->formerHubAddress_var);
    doUnpacking(b,this->changeIndication_var);
    doUnpacking(b,this->nextWakeup_var);
    doUnpacking(b,this->wakeupInterval_var);
    doUnpacking(b,this->uplinkRequest_var);
    doUnpacking(b,this->downlinkRequest_var);
    doUnpacking(b,this->bilinkRequest_var);
}

int BaselineConnectionRequestPacket::getRecipientAddress() const
{
    return recipientAddress_var;
}

void BaselineConnectionRequestPacket::setRecipientAddress(int recipientAddress)
{
    this->recipientAddress_var = recipientAddress;
}

int BaselineConnectionRequestPacket::getSenderAddress() const
{
    return senderAddress_var;
}

void BaselineConnectionRequestPacket::setSenderAddress(int senderAddress)
{
    this->senderAddress_var = senderAddress;
}

int BaselineConnectionRequestPacket::getFormerHubAddress() const
{
    return formerHubAddress_var;
}

void BaselineConnectionRequestPacket::setFormerHubAddress(int formerHubAddress)
{
    this->formerHubAddress_var = formerHubAddress;
}

int BaselineConnectionRequestPacket::getChangeIndication() const
{
    return changeIndication_var;
}

void BaselineConnectionRequestPacket::setChangeIndication(int changeIndication)
{
    this->changeIndication_var = changeIndication;
}

int BaselineConnectionRequestPacket::getNextWakeup() const
{
    return nextWakeup_var;
}

void BaselineConnectionRequestPacket::setNextWakeup(int nextWakeup)
{
    this->nextWakeup_var = nextWakeup;
}

int BaselineConnectionRequestPacket::getWakeupInterval() const
{
    return wakeupInterval_var;
}

void BaselineConnectionRequestPacket::setWakeupInterval(int wakeupInterval)
{
    this->wakeupInterval_var = wakeupInterval;
}

int BaselineConnectionRequestPacket::getUplinkRequest() const
{
    return uplinkRequest_var;
}

void BaselineConnectionRequestPacket::setUplinkRequest(int uplinkRequest)
{
    this->uplinkRequest_var = uplinkRequest;
}

int BaselineConnectionRequestPacket::getDownlinkRequest() const
{
    return downlinkRequest_var;
}

void BaselineConnectionRequestPacket::setDownlinkRequest(int downlinkRequest)
{
    this->downlinkRequest_var = downlinkRequest;
}

int BaselineConnectionRequestPacket::getBilinkRequest() const
{
    return bilinkRequest_var;
}

void BaselineConnectionRequestPacket::setBilinkRequest(int bilinkRequest)
{
    this->bilinkRequest_var = bilinkRequest;
}

class BaselineConnectionRequestPacketDescriptor : public cClassDescriptor
{
  public:
    BaselineConnectionRequestPacketDescriptor();
    virtual ~BaselineConnectionRequestPacketDescriptor();

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

Register_ClassDescriptor(BaselineConnectionRequestPacketDescriptor);

BaselineConnectionRequestPacketDescriptor::BaselineConnectionRequestPacketDescriptor() : cClassDescriptor("BaselineConnectionRequestPacket", "BaselineMacPacket")
{
}

BaselineConnectionRequestPacketDescriptor::~BaselineConnectionRequestPacketDescriptor()
{
}

bool BaselineConnectionRequestPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BaselineConnectionRequestPacket *>(obj)!=NULL;
}

const char *BaselineConnectionRequestPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BaselineConnectionRequestPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int BaselineConnectionRequestPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *BaselineConnectionRequestPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "recipientAddress",
        "senderAddress",
        "formerHubAddress",
        "changeIndication",
        "nextWakeup",
        "wakeupInterval",
        "uplinkRequest",
        "downlinkRequest",
        "bilinkRequest",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int BaselineConnectionRequestPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "recipientAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderAddress")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "formerHubAddress")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "changeIndication")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextWakeup")==0) return base+4;
    if (fieldName[0]=='w' && strcmp(fieldName, "wakeupInterval")==0) return base+5;
    if (fieldName[0]=='u' && strcmp(fieldName, "uplinkRequest")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "downlinkRequest")==0) return base+7;
    if (fieldName[0]=='b' && strcmp(fieldName, "bilinkRequest")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BaselineConnectionRequestPacketDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *BaselineConnectionRequestPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BaselineConnectionRequestPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionRequestPacket *pp = (BaselineConnectionRequestPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BaselineConnectionRequestPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionRequestPacket *pp = (BaselineConnectionRequestPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getRecipientAddress());
        case 1: return long2string(pp->getSenderAddress());
        case 2: return long2string(pp->getFormerHubAddress());
        case 3: return long2string(pp->getChangeIndication());
        case 4: return long2string(pp->getNextWakeup());
        case 5: return long2string(pp->getWakeupInterval());
        case 6: return long2string(pp->getUplinkRequest());
        case 7: return long2string(pp->getDownlinkRequest());
        case 8: return long2string(pp->getBilinkRequest());
        default: return "";
    }
}

bool BaselineConnectionRequestPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionRequestPacket *pp = (BaselineConnectionRequestPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setRecipientAddress(string2long(value)); return true;
        case 1: pp->setSenderAddress(string2long(value)); return true;
        case 2: pp->setFormerHubAddress(string2long(value)); return true;
        case 3: pp->setChangeIndication(string2long(value)); return true;
        case 4: pp->setNextWakeup(string2long(value)); return true;
        case 5: pp->setWakeupInterval(string2long(value)); return true;
        case 6: pp->setUplinkRequest(string2long(value)); return true;
        case 7: pp->setDownlinkRequest(string2long(value)); return true;
        case 8: pp->setBilinkRequest(string2long(value)); return true;
        default: return false;
    }
}

const char *BaselineConnectionRequestPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *BaselineConnectionRequestPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionRequestPacket *pp = (BaselineConnectionRequestPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BaselineConnectionAssignmentPacket);

BaselineConnectionAssignmentPacket::BaselineConnectionAssignmentPacket(const char *name, int kind) : ::BaselineMacPacket(name,kind)
{
    this->recipientAddress_var = 0;
    this->senderAddress_var = 0;
    this->channelDwellLength_var = 0;
    this->channelDwellPhase_var = 0;
    this->minRAPlength_var = 0;
    this->statusCode_var = 0;
    this->assignedNID_var = 0;
    this->changeIndication_var = 0;
    this->nextWakeup_var = 0;
    this->wakeupinterval_var = 0;
    this->uplinkRequestStart_var = 0;
    this->uplinkRequestEnd_var = 0;
    this->downlinkRequestStart_var = 0;
    this->downlinkRequestEnd_var = 0;
    this->bilinkRequestStart_var = 0;
    this->bilinkRequestEnd_var = 0;
}

BaselineConnectionAssignmentPacket::BaselineConnectionAssignmentPacket(const BaselineConnectionAssignmentPacket& other) : ::BaselineMacPacket(other)
{
    copy(other);
}

BaselineConnectionAssignmentPacket::~BaselineConnectionAssignmentPacket()
{
}

BaselineConnectionAssignmentPacket& BaselineConnectionAssignmentPacket::operator=(const BaselineConnectionAssignmentPacket& other)
{
    if (this==&other) return *this;
    ::BaselineMacPacket::operator=(other);
    copy(other);
    return *this;
}

void BaselineConnectionAssignmentPacket::copy(const BaselineConnectionAssignmentPacket& other)
{
    this->recipientAddress_var = other.recipientAddress_var;
    this->senderAddress_var = other.senderAddress_var;
    this->channelDwellLength_var = other.channelDwellLength_var;
    this->channelDwellPhase_var = other.channelDwellPhase_var;
    this->minRAPlength_var = other.minRAPlength_var;
    this->statusCode_var = other.statusCode_var;
    this->assignedNID_var = other.assignedNID_var;
    this->changeIndication_var = other.changeIndication_var;
    this->nextWakeup_var = other.nextWakeup_var;
    this->wakeupinterval_var = other.wakeupinterval_var;
    this->uplinkRequestStart_var = other.uplinkRequestStart_var;
    this->uplinkRequestEnd_var = other.uplinkRequestEnd_var;
    this->downlinkRequestStart_var = other.downlinkRequestStart_var;
    this->downlinkRequestEnd_var = other.downlinkRequestEnd_var;
    this->bilinkRequestStart_var = other.bilinkRequestStart_var;
    this->bilinkRequestEnd_var = other.bilinkRequestEnd_var;
}

void BaselineConnectionAssignmentPacket::parsimPack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimPack(b);
    doPacking(b,this->recipientAddress_var);
    doPacking(b,this->senderAddress_var);
    doPacking(b,this->channelDwellLength_var);
    doPacking(b,this->channelDwellPhase_var);
    doPacking(b,this->minRAPlength_var);
    doPacking(b,this->statusCode_var);
    doPacking(b,this->assignedNID_var);
    doPacking(b,this->changeIndication_var);
    doPacking(b,this->nextWakeup_var);
    doPacking(b,this->wakeupinterval_var);
    doPacking(b,this->uplinkRequestStart_var);
    doPacking(b,this->uplinkRequestEnd_var);
    doPacking(b,this->downlinkRequestStart_var);
    doPacking(b,this->downlinkRequestEnd_var);
    doPacking(b,this->bilinkRequestStart_var);
    doPacking(b,this->bilinkRequestEnd_var);
}

void BaselineConnectionAssignmentPacket::parsimUnpack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimUnpack(b);
    doUnpacking(b,this->recipientAddress_var);
    doUnpacking(b,this->senderAddress_var);
    doUnpacking(b,this->channelDwellLength_var);
    doUnpacking(b,this->channelDwellPhase_var);
    doUnpacking(b,this->minRAPlength_var);
    doUnpacking(b,this->statusCode_var);
    doUnpacking(b,this->assignedNID_var);
    doUnpacking(b,this->changeIndication_var);
    doUnpacking(b,this->nextWakeup_var);
    doUnpacking(b,this->wakeupinterval_var);
    doUnpacking(b,this->uplinkRequestStart_var);
    doUnpacking(b,this->uplinkRequestEnd_var);
    doUnpacking(b,this->downlinkRequestStart_var);
    doUnpacking(b,this->downlinkRequestEnd_var);
    doUnpacking(b,this->bilinkRequestStart_var);
    doUnpacking(b,this->bilinkRequestEnd_var);
}

int BaselineConnectionAssignmentPacket::getRecipientAddress() const
{
    return recipientAddress_var;
}

void BaselineConnectionAssignmentPacket::setRecipientAddress(int recipientAddress)
{
    this->recipientAddress_var = recipientAddress;
}

int BaselineConnectionAssignmentPacket::getSenderAddress() const
{
    return senderAddress_var;
}

void BaselineConnectionAssignmentPacket::setSenderAddress(int senderAddress)
{
    this->senderAddress_var = senderAddress;
}

int BaselineConnectionAssignmentPacket::getChannelDwellLength() const
{
    return channelDwellLength_var;
}

void BaselineConnectionAssignmentPacket::setChannelDwellLength(int channelDwellLength)
{
    this->channelDwellLength_var = channelDwellLength;
}

int BaselineConnectionAssignmentPacket::getChannelDwellPhase() const
{
    return channelDwellPhase_var;
}

void BaselineConnectionAssignmentPacket::setChannelDwellPhase(int channelDwellPhase)
{
    this->channelDwellPhase_var = channelDwellPhase;
}

int BaselineConnectionAssignmentPacket::getMinRAPlength() const
{
    return minRAPlength_var;
}

void BaselineConnectionAssignmentPacket::setMinRAPlength(int minRAPlength)
{
    this->minRAPlength_var = minRAPlength;
}

int BaselineConnectionAssignmentPacket::getStatusCode() const
{
    return statusCode_var;
}

void BaselineConnectionAssignmentPacket::setStatusCode(int statusCode)
{
    this->statusCode_var = statusCode;
}

int BaselineConnectionAssignmentPacket::getAssignedNID() const
{
    return assignedNID_var;
}

void BaselineConnectionAssignmentPacket::setAssignedNID(int assignedNID)
{
    this->assignedNID_var = assignedNID;
}

int BaselineConnectionAssignmentPacket::getChangeIndication() const
{
    return changeIndication_var;
}

void BaselineConnectionAssignmentPacket::setChangeIndication(int changeIndication)
{
    this->changeIndication_var = changeIndication;
}

int BaselineConnectionAssignmentPacket::getNextWakeup() const
{
    return nextWakeup_var;
}

void BaselineConnectionAssignmentPacket::setNextWakeup(int nextWakeup)
{
    this->nextWakeup_var = nextWakeup;
}

int BaselineConnectionAssignmentPacket::getWakeupinterval() const
{
    return wakeupinterval_var;
}

void BaselineConnectionAssignmentPacket::setWakeupinterval(int wakeupinterval)
{
    this->wakeupinterval_var = wakeupinterval;
}

int BaselineConnectionAssignmentPacket::getUplinkRequestStart() const
{
    return uplinkRequestStart_var;
}

void BaselineConnectionAssignmentPacket::setUplinkRequestStart(int uplinkRequestStart)
{
    this->uplinkRequestStart_var = uplinkRequestStart;
}

int BaselineConnectionAssignmentPacket::getUplinkRequestEnd() const
{
    return uplinkRequestEnd_var;
}

void BaselineConnectionAssignmentPacket::setUplinkRequestEnd(int uplinkRequestEnd)
{
    this->uplinkRequestEnd_var = uplinkRequestEnd;
}

int BaselineConnectionAssignmentPacket::getDownlinkRequestStart() const
{
    return downlinkRequestStart_var;
}

void BaselineConnectionAssignmentPacket::setDownlinkRequestStart(int downlinkRequestStart)
{
    this->downlinkRequestStart_var = downlinkRequestStart;
}

int BaselineConnectionAssignmentPacket::getDownlinkRequestEnd() const
{
    return downlinkRequestEnd_var;
}

void BaselineConnectionAssignmentPacket::setDownlinkRequestEnd(int downlinkRequestEnd)
{
    this->downlinkRequestEnd_var = downlinkRequestEnd;
}

int BaselineConnectionAssignmentPacket::getBilinkRequestStart() const
{
    return bilinkRequestStart_var;
}

void BaselineConnectionAssignmentPacket::setBilinkRequestStart(int bilinkRequestStart)
{
    this->bilinkRequestStart_var = bilinkRequestStart;
}

int BaselineConnectionAssignmentPacket::getBilinkRequestEnd() const
{
    return bilinkRequestEnd_var;
}

void BaselineConnectionAssignmentPacket::setBilinkRequestEnd(int bilinkRequestEnd)
{
    this->bilinkRequestEnd_var = bilinkRequestEnd;
}

class BaselineConnectionAssignmentPacketDescriptor : public cClassDescriptor
{
  public:
    BaselineConnectionAssignmentPacketDescriptor();
    virtual ~BaselineConnectionAssignmentPacketDescriptor();

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

Register_ClassDescriptor(BaselineConnectionAssignmentPacketDescriptor);

BaselineConnectionAssignmentPacketDescriptor::BaselineConnectionAssignmentPacketDescriptor() : cClassDescriptor("BaselineConnectionAssignmentPacket", "BaselineMacPacket")
{
}

BaselineConnectionAssignmentPacketDescriptor::~BaselineConnectionAssignmentPacketDescriptor()
{
}

bool BaselineConnectionAssignmentPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BaselineConnectionAssignmentPacket *>(obj)!=NULL;
}

const char *BaselineConnectionAssignmentPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BaselineConnectionAssignmentPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount(object) : 16;
}

unsigned int BaselineConnectionAssignmentPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<16) ? fieldTypeFlags[field] : 0;
}

const char *BaselineConnectionAssignmentPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "recipientAddress",
        "senderAddress",
        "channelDwellLength",
        "channelDwellPhase",
        "minRAPlength",
        "statusCode",
        "assignedNID",
        "changeIndication",
        "nextWakeup",
        "wakeupinterval",
        "uplinkRequestStart",
        "uplinkRequestEnd",
        "downlinkRequestStart",
        "downlinkRequestEnd",
        "bilinkRequestStart",
        "bilinkRequestEnd",
    };
    return (field>=0 && field<16) ? fieldNames[field] : NULL;
}

int BaselineConnectionAssignmentPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "recipientAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderAddress")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelDwellLength")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelDwellPhase")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "minRAPlength")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "statusCode")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "assignedNID")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "changeIndication")==0) return base+7;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextWakeup")==0) return base+8;
    if (fieldName[0]=='w' && strcmp(fieldName, "wakeupinterval")==0) return base+9;
    if (fieldName[0]=='u' && strcmp(fieldName, "uplinkRequestStart")==0) return base+10;
    if (fieldName[0]=='u' && strcmp(fieldName, "uplinkRequestEnd")==0) return base+11;
    if (fieldName[0]=='d' && strcmp(fieldName, "downlinkRequestStart")==0) return base+12;
    if (fieldName[0]=='d' && strcmp(fieldName, "downlinkRequestEnd")==0) return base+13;
    if (fieldName[0]=='b' && strcmp(fieldName, "bilinkRequestStart")==0) return base+14;
    if (fieldName[0]=='b' && strcmp(fieldName, "bilinkRequestEnd")==0) return base+15;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BaselineConnectionAssignmentPacketDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<16) ? fieldTypeStrings[field] : NULL;
}

const char *BaselineConnectionAssignmentPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 5:
            if (!strcmp(propertyname,"enum")) return "statusCode_type";
            return NULL;
        default: return NULL;
    }
}

int BaselineConnectionAssignmentPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionAssignmentPacket *pp = (BaselineConnectionAssignmentPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BaselineConnectionAssignmentPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionAssignmentPacket *pp = (BaselineConnectionAssignmentPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getRecipientAddress());
        case 1: return long2string(pp->getSenderAddress());
        case 2: return long2string(pp->getChannelDwellLength());
        case 3: return long2string(pp->getChannelDwellPhase());
        case 4: return long2string(pp->getMinRAPlength());
        case 5: return long2string(pp->getStatusCode());
        case 6: return long2string(pp->getAssignedNID());
        case 7: return long2string(pp->getChangeIndication());
        case 8: return long2string(pp->getNextWakeup());
        case 9: return long2string(pp->getWakeupinterval());
        case 10: return long2string(pp->getUplinkRequestStart());
        case 11: return long2string(pp->getUplinkRequestEnd());
        case 12: return long2string(pp->getDownlinkRequestStart());
        case 13: return long2string(pp->getDownlinkRequestEnd());
        case 14: return long2string(pp->getBilinkRequestStart());
        case 15: return long2string(pp->getBilinkRequestEnd());
        default: return "";
    }
}

bool BaselineConnectionAssignmentPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionAssignmentPacket *pp = (BaselineConnectionAssignmentPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setRecipientAddress(string2long(value)); return true;
        case 1: pp->setSenderAddress(string2long(value)); return true;
        case 2: pp->setChannelDwellLength(string2long(value)); return true;
        case 3: pp->setChannelDwellPhase(string2long(value)); return true;
        case 4: pp->setMinRAPlength(string2long(value)); return true;
        case 5: pp->setStatusCode(string2long(value)); return true;
        case 6: pp->setAssignedNID(string2long(value)); return true;
        case 7: pp->setChangeIndication(string2long(value)); return true;
        case 8: pp->setNextWakeup(string2long(value)); return true;
        case 9: pp->setWakeupinterval(string2long(value)); return true;
        case 10: pp->setUplinkRequestStart(string2long(value)); return true;
        case 11: pp->setUplinkRequestEnd(string2long(value)); return true;
        case 12: pp->setDownlinkRequestStart(string2long(value)); return true;
        case 13: pp->setDownlinkRequestEnd(string2long(value)); return true;
        case 14: pp->setBilinkRequestStart(string2long(value)); return true;
        case 15: pp->setBilinkRequestEnd(string2long(value)); return true;
        default: return false;
    }
}

const char *BaselineConnectionAssignmentPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *BaselineConnectionAssignmentPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineConnectionAssignmentPacket *pp = (BaselineConnectionAssignmentPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BaselineBAckPacket);

BaselineBAckPacket::BaselineBAckPacket(const char *name, int kind) : ::BaselineMacPacket(name,kind)
{
    this->nextBlockSize_var = 0;
    this->oldestFrameExpected_var = 0;
    this->frameStatusBitmap_var = 0;
}

BaselineBAckPacket::BaselineBAckPacket(const BaselineBAckPacket& other) : ::BaselineMacPacket(other)
{
    copy(other);
}

BaselineBAckPacket::~BaselineBAckPacket()
{
}

BaselineBAckPacket& BaselineBAckPacket::operator=(const BaselineBAckPacket& other)
{
    if (this==&other) return *this;
    ::BaselineMacPacket::operator=(other);
    copy(other);
    return *this;
}

void BaselineBAckPacket::copy(const BaselineBAckPacket& other)
{
    this->nextBlockSize_var = other.nextBlockSize_var;
    this->oldestFrameExpected_var = other.oldestFrameExpected_var;
    this->frameStatusBitmap_var = other.frameStatusBitmap_var;
}

void BaselineBAckPacket::parsimPack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimPack(b);
    doPacking(b,this->nextBlockSize_var);
    doPacking(b,this->oldestFrameExpected_var);
    doPacking(b,this->frameStatusBitmap_var);
}

void BaselineBAckPacket::parsimUnpack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimUnpack(b);
    doUnpacking(b,this->nextBlockSize_var);
    doUnpacking(b,this->oldestFrameExpected_var);
    doUnpacking(b,this->frameStatusBitmap_var);
}

int BaselineBAckPacket::getNextBlockSize() const
{
    return nextBlockSize_var;
}

void BaselineBAckPacket::setNextBlockSize(int nextBlockSize)
{
    this->nextBlockSize_var = nextBlockSize;
}

int BaselineBAckPacket::getOldestFrameExpected() const
{
    return oldestFrameExpected_var;
}

void BaselineBAckPacket::setOldestFrameExpected(int oldestFrameExpected)
{
    this->oldestFrameExpected_var = oldestFrameExpected;
}

int BaselineBAckPacket::getFrameStatusBitmap() const
{
    return frameStatusBitmap_var;
}

void BaselineBAckPacket::setFrameStatusBitmap(int frameStatusBitmap)
{
    this->frameStatusBitmap_var = frameStatusBitmap;
}

class BaselineBAckPacketDescriptor : public cClassDescriptor
{
  public:
    BaselineBAckPacketDescriptor();
    virtual ~BaselineBAckPacketDescriptor();

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

Register_ClassDescriptor(BaselineBAckPacketDescriptor);

BaselineBAckPacketDescriptor::BaselineBAckPacketDescriptor() : cClassDescriptor("BaselineBAckPacket", "BaselineMacPacket")
{
}

BaselineBAckPacketDescriptor::~BaselineBAckPacketDescriptor()
{
}

bool BaselineBAckPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BaselineBAckPacket *>(obj)!=NULL;
}

const char *BaselineBAckPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BaselineBAckPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int BaselineBAckPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *BaselineBAckPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "nextBlockSize",
        "oldestFrameExpected",
        "frameStatusBitmap",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int BaselineBAckPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextBlockSize")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "oldestFrameExpected")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameStatusBitmap")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BaselineBAckPacketDescriptor::getFieldTypeString(void *object, int field) const
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

const char *BaselineBAckPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BaselineBAckPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBAckPacket *pp = (BaselineBAckPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BaselineBAckPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBAckPacket *pp = (BaselineBAckPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNextBlockSize());
        case 1: return long2string(pp->getOldestFrameExpected());
        case 2: return long2string(pp->getFrameStatusBitmap());
        default: return "";
    }
}

bool BaselineBAckPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBAckPacket *pp = (BaselineBAckPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setNextBlockSize(string2long(value)); return true;
        case 1: pp->setOldestFrameExpected(string2long(value)); return true;
        case 2: pp->setFrameStatusBitmap(string2long(value)); return true;
        default: return false;
    }
}

const char *BaselineBAckPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *BaselineBAckPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineBAckPacket *pp = (BaselineBAckPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BaselineTPollPacket);

BaselineTPollPacket::BaselineTPollPacket(const char *name, int kind) : ::BaselineMacPacket(name,kind)
{
    this->currentBeaconPeriod_var = 0;
    this->currentAllocationSlot_var = 0;
    this->currentSlotOffset_var = 0;
    this->beaconPeriodLength_var = 0;
    this->allocationSlotLength_var = 0;
}

BaselineTPollPacket::BaselineTPollPacket(const BaselineTPollPacket& other) : ::BaselineMacPacket(other)
{
    copy(other);
}

BaselineTPollPacket::~BaselineTPollPacket()
{
}

BaselineTPollPacket& BaselineTPollPacket::operator=(const BaselineTPollPacket& other)
{
    if (this==&other) return *this;
    ::BaselineMacPacket::operator=(other);
    copy(other);
    return *this;
}

void BaselineTPollPacket::copy(const BaselineTPollPacket& other)
{
    this->currentBeaconPeriod_var = other.currentBeaconPeriod_var;
    this->currentAllocationSlot_var = other.currentAllocationSlot_var;
    this->currentSlotOffset_var = other.currentSlotOffset_var;
    this->beaconPeriodLength_var = other.beaconPeriodLength_var;
    this->allocationSlotLength_var = other.allocationSlotLength_var;
}

void BaselineTPollPacket::parsimPack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimPack(b);
    doPacking(b,this->currentBeaconPeriod_var);
    doPacking(b,this->currentAllocationSlot_var);
    doPacking(b,this->currentSlotOffset_var);
    doPacking(b,this->beaconPeriodLength_var);
    doPacking(b,this->allocationSlotLength_var);
}

void BaselineTPollPacket::parsimUnpack(cCommBuffer *b)
{
    ::BaselineMacPacket::parsimUnpack(b);
    doUnpacking(b,this->currentBeaconPeriod_var);
    doUnpacking(b,this->currentAllocationSlot_var);
    doUnpacking(b,this->currentSlotOffset_var);
    doUnpacking(b,this->beaconPeriodLength_var);
    doUnpacking(b,this->allocationSlotLength_var);
}

int BaselineTPollPacket::getCurrentBeaconPeriod() const
{
    return currentBeaconPeriod_var;
}

void BaselineTPollPacket::setCurrentBeaconPeriod(int currentBeaconPeriod)
{
    this->currentBeaconPeriod_var = currentBeaconPeriod;
}

int BaselineTPollPacket::getCurrentAllocationSlot() const
{
    return currentAllocationSlot_var;
}

void BaselineTPollPacket::setCurrentAllocationSlot(int currentAllocationSlot)
{
    this->currentAllocationSlot_var = currentAllocationSlot;
}

int BaselineTPollPacket::getCurrentSlotOffset() const
{
    return currentSlotOffset_var;
}

void BaselineTPollPacket::setCurrentSlotOffset(int currentSlotOffset)
{
    this->currentSlotOffset_var = currentSlotOffset;
}

int BaselineTPollPacket::getBeaconPeriodLength() const
{
    return beaconPeriodLength_var;
}

void BaselineTPollPacket::setBeaconPeriodLength(int beaconPeriodLength)
{
    this->beaconPeriodLength_var = beaconPeriodLength;
}

int BaselineTPollPacket::getAllocationSlotLength() const
{
    return allocationSlotLength_var;
}

void BaselineTPollPacket::setAllocationSlotLength(int allocationSlotLength)
{
    this->allocationSlotLength_var = allocationSlotLength;
}

class BaselineTPollPacketDescriptor : public cClassDescriptor
{
  public:
    BaselineTPollPacketDescriptor();
    virtual ~BaselineTPollPacketDescriptor();

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

Register_ClassDescriptor(BaselineTPollPacketDescriptor);

BaselineTPollPacketDescriptor::BaselineTPollPacketDescriptor() : cClassDescriptor("BaselineTPollPacket", "BaselineMacPacket")
{
}

BaselineTPollPacketDescriptor::~BaselineTPollPacketDescriptor()
{
}

bool BaselineTPollPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BaselineTPollPacket *>(obj)!=NULL;
}

const char *BaselineTPollPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BaselineTPollPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int BaselineTPollPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *BaselineTPollPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "currentBeaconPeriod",
        "currentAllocationSlot",
        "currentSlotOffset",
        "beaconPeriodLength",
        "allocationSlotLength",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int BaselineTPollPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentBeaconPeriod")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentAllocationSlot")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentSlotOffset")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconPeriodLength")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "allocationSlotLength")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BaselineTPollPacketDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *BaselineTPollPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BaselineTPollPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BaselineTPollPacket *pp = (BaselineTPollPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BaselineTPollPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineTPollPacket *pp = (BaselineTPollPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCurrentBeaconPeriod());
        case 1: return long2string(pp->getCurrentAllocationSlot());
        case 2: return long2string(pp->getCurrentSlotOffset());
        case 3: return long2string(pp->getBeaconPeriodLength());
        case 4: return long2string(pp->getAllocationSlotLength());
        default: return "";
    }
}

bool BaselineTPollPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BaselineTPollPacket *pp = (BaselineTPollPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setCurrentBeaconPeriod(string2long(value)); return true;
        case 1: pp->setCurrentAllocationSlot(string2long(value)); return true;
        case 2: pp->setCurrentSlotOffset(string2long(value)); return true;
        case 3: pp->setBeaconPeriodLength(string2long(value)); return true;
        case 4: pp->setAllocationSlotLength(string2long(value)); return true;
        default: return false;
    }
}

const char *BaselineTPollPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *BaselineTPollPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BaselineTPollPacket *pp = (BaselineTPollPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


