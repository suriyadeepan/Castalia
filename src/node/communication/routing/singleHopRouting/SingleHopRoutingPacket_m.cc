//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/singleHopRouting/SingleHopRoutingPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SingleHopRoutingPacket_m.h"

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
    cEnum *e = cEnum::find("singleHopRoutingPacket_Type");
    if (!e) enums.getInstance()->add(e = new cEnum("singleHopRoutingPacket_Type"));
    e->insert(SINGLE_HOP_ROUTING_DATA_PACKET, "SINGLE_HOP_ROUTING_DATA_PACKET");
    e->insert(SINGLE_HOP_ROUTING_HELLO_PACKET, "SINGLE_HOP_ROUTING_HELLO_PACKET");
    e->insert(SINGLE_HOP_ROUTING_ACK_PACKET, "SINGLE_HOP_ROUTING_ACK_PACKET");
    e->insert(SINGLE_HOP_ROUTING_ALLOW_SEND_PACKET, "SINGLE_HOP_ROUTING_ALLOW_SEND_PACKET");
);

Register_Class(SHRoutingPacket);

SHRoutingPacket::SHRoutingPacket(const char *name, int kind) : ::RoutingPacket(name,kind)
{
    this->singleHopRoutingPacketKind_var = 0;
    this->SomeData_var = 0;
}

SHRoutingPacket::SHRoutingPacket(const SHRoutingPacket& other) : ::RoutingPacket(other)
{
    copy(other);
}

SHRoutingPacket::~SHRoutingPacket()
{
}

SHRoutingPacket& SHRoutingPacket::operator=(const SHRoutingPacket& other)
{
    if (this==&other) return *this;
    ::RoutingPacket::operator=(other);
    copy(other);
    return *this;
}

void SHRoutingPacket::copy(const SHRoutingPacket& other)
{
    this->singleHopRoutingPacketKind_var = other.singleHopRoutingPacketKind_var;
    this->SomeData_var = other.SomeData_var;
}

void SHRoutingPacket::parsimPack(cCommBuffer *b)
{
    ::RoutingPacket::parsimPack(b);
    doPacking(b,this->singleHopRoutingPacketKind_var);
    doPacking(b,this->SomeData_var);
}

void SHRoutingPacket::parsimUnpack(cCommBuffer *b)
{
    ::RoutingPacket::parsimUnpack(b);
    doUnpacking(b,this->singleHopRoutingPacketKind_var);
    doUnpacking(b,this->SomeData_var);
}

int SHRoutingPacket::getSingleHopRoutingPacketKind() const
{
    return singleHopRoutingPacketKind_var;
}

void SHRoutingPacket::setSingleHopRoutingPacketKind(int singleHopRoutingPacketKind)
{
    this->singleHopRoutingPacketKind_var = singleHopRoutingPacketKind;
}

int SHRoutingPacket::getSomeData() const
{
    return SomeData_var;
}

void SHRoutingPacket::setSomeData(int SomeData)
{
    this->SomeData_var = SomeData;
}

class SHRoutingPacketDescriptor : public cClassDescriptor
{
  public:
    SHRoutingPacketDescriptor();
    virtual ~SHRoutingPacketDescriptor();

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

Register_ClassDescriptor(SHRoutingPacketDescriptor);

SHRoutingPacketDescriptor::SHRoutingPacketDescriptor() : cClassDescriptor("SHRoutingPacket", "RoutingPacket")
{
}

SHRoutingPacketDescriptor::~SHRoutingPacketDescriptor()
{
}

bool SHRoutingPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SHRoutingPacket *>(obj)!=NULL;
}

const char *SHRoutingPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SHRoutingPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int SHRoutingPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SHRoutingPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "singleHopRoutingPacketKind",
        "SomeData",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int SHRoutingPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "singleHopRoutingPacketKind")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SomeData")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SHRoutingPacketDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *SHRoutingPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "singleHopRoutingPacket_Type";
            return NULL;
        default: return NULL;
    }
}

int SHRoutingPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SHRoutingPacket *pp = (SHRoutingPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SHRoutingPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SHRoutingPacket *pp = (SHRoutingPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSingleHopRoutingPacketKind());
        case 1: return long2string(pp->getSomeData());
        default: return "";
    }
}

bool SHRoutingPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SHRoutingPacket *pp = (SHRoutingPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSingleHopRoutingPacketKind(string2long(value)); return true;
        case 1: pp->setSomeData(string2long(value)); return true;
        default: return false;
    }
}

const char *SHRoutingPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *SHRoutingPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SHRoutingPacket *pp = (SHRoutingPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


