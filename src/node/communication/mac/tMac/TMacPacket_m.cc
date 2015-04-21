//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/mac/tMac/TMacPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "TMacPacket_m.h"

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
    cEnum *e = cEnum::find("TmacPacket_type");
    if (!e) enums.getInstance()->add(e = new cEnum("TmacPacket_type"));
    e->insert(SYNC_TMAC_PACKET, "SYNC_TMAC_PACKET");
    e->insert(RTS_TMAC_PACKET, "RTS_TMAC_PACKET");
    e->insert(CTS_TMAC_PACKET, "CTS_TMAC_PACKET");
    e->insert(DS_TMAC_PACKET, "DS_TMAC_PACKET");
    e->insert(FRTS_TMAC_PACKET, "FRTS_TMAC_PACKET");
    e->insert(DATA_TMAC_PACKET, "DATA_TMAC_PACKET");
    e->insert(ACK_TMAC_PACKET, "ACK_TMAC_PACKET");
);

Register_Class(TMacPacket);

TMacPacket::TMacPacket(const char *name, int kind) : ::MacPacket(name,kind)
{
    this->type_var = 0;
    this->nav_var = 0;
    this->sync_var = 0;
    this->syncId_var = 0;
}

TMacPacket::TMacPacket(const TMacPacket& other) : ::MacPacket(other)
{
    copy(other);
}

TMacPacket::~TMacPacket()
{
}

TMacPacket& TMacPacket::operator=(const TMacPacket& other)
{
    if (this==&other) return *this;
    ::MacPacket::operator=(other);
    copy(other);
    return *this;
}

void TMacPacket::copy(const TMacPacket& other)
{
    this->type_var = other.type_var;
    this->nav_var = other.nav_var;
    this->sync_var = other.sync_var;
    this->syncId_var = other.syncId_var;
}

void TMacPacket::parsimPack(cCommBuffer *b)
{
    ::MacPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->nav_var);
    doPacking(b,this->sync_var);
    doPacking(b,this->syncId_var);
}

void TMacPacket::parsimUnpack(cCommBuffer *b)
{
    ::MacPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->nav_var);
    doUnpacking(b,this->sync_var);
    doUnpacking(b,this->syncId_var);
}

int TMacPacket::getType() const
{
    return type_var;
}

void TMacPacket::setType(int type)
{
    this->type_var = type;
}

simtime_t TMacPacket::getNav() const
{
    return nav_var;
}

void TMacPacket::setNav(simtime_t nav)
{
    this->nav_var = nav;
}

simtime_t TMacPacket::getSync() const
{
    return sync_var;
}

void TMacPacket::setSync(simtime_t sync)
{
    this->sync_var = sync;
}

int TMacPacket::getSyncId() const
{
    return syncId_var;
}

void TMacPacket::setSyncId(int syncId)
{
    this->syncId_var = syncId;
}

class TMacPacketDescriptor : public cClassDescriptor
{
  public:
    TMacPacketDescriptor();
    virtual ~TMacPacketDescriptor();

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

Register_ClassDescriptor(TMacPacketDescriptor);

TMacPacketDescriptor::TMacPacketDescriptor() : cClassDescriptor("TMacPacket", "MacPacket")
{
}

TMacPacketDescriptor::~TMacPacketDescriptor()
{
}

bool TMacPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<TMacPacket *>(obj)!=NULL;
}

const char *TMacPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int TMacPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int TMacPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *TMacPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "nav",
        "sync",
        "syncId",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int TMacPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nav")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sync")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "syncId")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *TMacPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "simtime_t",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *TMacPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "TmacPacket_type";
            return NULL;
        default: return NULL;
    }
}

int TMacPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    TMacPacket *pp = (TMacPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string TMacPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    TMacPacket *pp = (TMacPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return double2string(pp->getNav());
        case 2: return double2string(pp->getSync());
        case 3: return long2string(pp->getSyncId());
        default: return "";
    }
}

bool TMacPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    TMacPacket *pp = (TMacPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setNav(string2double(value)); return true;
        case 2: pp->setSync(string2double(value)); return true;
        case 3: pp->setSyncId(string2long(value)); return true;
        default: return false;
    }
}

const char *TMacPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *TMacPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    TMacPacket *pp = (TMacPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


