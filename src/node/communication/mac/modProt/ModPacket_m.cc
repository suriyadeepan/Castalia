//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/mac/modProt/ModPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ModPacket_m.h"

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

Register_Class(ModPacket);

ModPacket::ModPacket(const char *name, int kind) : ::MacPacket(name,kind)
{
    this->ptype_var = 0;
    this->adst_var = 0;
    this->fdst_var = 5;
    this->sourceX_var = 0;
    this->sourceY_var = 0;
    this->destX_var = 0;
    this->destY_var = 0;
    this->myX_var = 0;
    this->myY_var = 0;
    this->slots_var = 0;
    for (unsigned int i=0; i<10; i++)
        this->slot_info_var[i] = 0;
    for (unsigned int i=0; i<10; i++)
        this->node_id_var[i] = 0;
    this->sleep_time_var = 0;
}

ModPacket::ModPacket(const ModPacket& other) : ::MacPacket(other)
{
    copy(other);
}

ModPacket::~ModPacket()
{
}

ModPacket& ModPacket::operator=(const ModPacket& other)
{
    if (this==&other) return *this;
    ::MacPacket::operator=(other);
    copy(other);
    return *this;
}

void ModPacket::copy(const ModPacket& other)
{
    this->ptype_var = other.ptype_var;
    this->adst_var = other.adst_var;
    this->fdst_var = other.fdst_var;
    this->sourceX_var = other.sourceX_var;
    this->sourceY_var = other.sourceY_var;
    this->destX_var = other.destX_var;
    this->destY_var = other.destY_var;
    this->myX_var = other.myX_var;
    this->myY_var = other.myY_var;
    this->slots_var = other.slots_var;
    for (unsigned int i=0; i<10; i++)
        this->slot_info_var[i] = other.slot_info_var[i];
    for (unsigned int i=0; i<10; i++)
        this->node_id_var[i] = other.node_id_var[i];
    this->sleep_time_var = other.sleep_time_var;
}

void ModPacket::parsimPack(cCommBuffer *b)
{
    ::MacPacket::parsimPack(b);
    doPacking(b,this->ptype_var);
    doPacking(b,this->adst_var);
    doPacking(b,this->fdst_var);
    doPacking(b,this->sourceX_var);
    doPacking(b,this->sourceY_var);
    doPacking(b,this->destX_var);
    doPacking(b,this->destY_var);
    doPacking(b,this->myX_var);
    doPacking(b,this->myY_var);
    doPacking(b,this->slots_var);
    doPacking(b,this->slot_info_var,10);
    doPacking(b,this->node_id_var,10);
    doPacking(b,this->sleep_time_var);
}

void ModPacket::parsimUnpack(cCommBuffer *b)
{
    ::MacPacket::parsimUnpack(b);
    doUnpacking(b,this->ptype_var);
    doUnpacking(b,this->adst_var);
    doUnpacking(b,this->fdst_var);
    doUnpacking(b,this->sourceX_var);
    doUnpacking(b,this->sourceY_var);
    doUnpacking(b,this->destX_var);
    doUnpacking(b,this->destY_var);
    doUnpacking(b,this->myX_var);
    doUnpacking(b,this->myY_var);
    doUnpacking(b,this->slots_var);
    doUnpacking(b,this->slot_info_var,10);
    doUnpacking(b,this->node_id_var,10);
    doUnpacking(b,this->sleep_time_var);
}

int ModPacket::getPtype() const
{
    return ptype_var;
}

void ModPacket::setPtype(int ptype)
{
    this->ptype_var = ptype;
}

int ModPacket::getAdst() const
{
    return adst_var;
}

void ModPacket::setAdst(int adst)
{
    this->adst_var = adst;
}

int ModPacket::getFdst() const
{
    return fdst_var;
}

void ModPacket::setFdst(int fdst)
{
    this->fdst_var = fdst;
}

int ModPacket::getSourceX() const
{
    return sourceX_var;
}

void ModPacket::setSourceX(int sourceX)
{
    this->sourceX_var = sourceX;
}

int ModPacket::getSourceY() const
{
    return sourceY_var;
}

void ModPacket::setSourceY(int sourceY)
{
    this->sourceY_var = sourceY;
}

int ModPacket::getDestX() const
{
    return destX_var;
}

void ModPacket::setDestX(int destX)
{
    this->destX_var = destX;
}

int ModPacket::getDestY() const
{
    return destY_var;
}

void ModPacket::setDestY(int destY)
{
    this->destY_var = destY;
}

int ModPacket::getMyX() const
{
    return myX_var;
}

void ModPacket::setMyX(int myX)
{
    this->myX_var = myX;
}

int ModPacket::getMyY() const
{
    return myY_var;
}

void ModPacket::setMyY(int myY)
{
    this->myY_var = myY;
}

int ModPacket::getSlots() const
{
    return slots_var;
}

void ModPacket::setSlots(int slots)
{
    this->slots_var = slots;
}

unsigned int ModPacket::getSlot_infoArraySize() const
{
    return 10;
}

double ModPacket::getSlot_info(unsigned int k) const
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    return slot_info_var[k];
}

void ModPacket::setSlot_info(unsigned int k, double slot_info)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    this->slot_info_var[k] = slot_info;
}

unsigned int ModPacket::getNode_idArraySize() const
{
    return 10;
}

int ModPacket::getNode_id(unsigned int k) const
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    return node_id_var[k];
}

void ModPacket::setNode_id(unsigned int k, int node_id)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    this->node_id_var[k] = node_id;
}

double ModPacket::getSleep_time() const
{
    return sleep_time_var;
}

void ModPacket::setSleep_time(double sleep_time)
{
    this->sleep_time_var = sleep_time;
}

class ModPacketDescriptor : public cClassDescriptor
{
  public:
    ModPacketDescriptor();
    virtual ~ModPacketDescriptor();

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

Register_ClassDescriptor(ModPacketDescriptor);

ModPacketDescriptor::ModPacketDescriptor() : cClassDescriptor("ModPacket", "MacPacket")
{
}

ModPacketDescriptor::~ModPacketDescriptor()
{
}

bool ModPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ModPacket *>(obj)!=NULL;
}

const char *ModPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ModPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount(object) : 13;
}

unsigned int ModPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *ModPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "ptype",
        "adst",
        "fdst",
        "sourceX",
        "sourceY",
        "destX",
        "destY",
        "myX",
        "myY",
        "slots",
        "slot_info",
        "node_id",
        "sleep_time",
    };
    return (field>=0 && field<13) ? fieldNames[field] : NULL;
}

int ModPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "ptype")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "adst")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fdst")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceX")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceY")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destX")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destY")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "myX")==0) return base+7;
    if (fieldName[0]=='m' && strcmp(fieldName, "myY")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "slots")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "slot_info")==0) return base+10;
    if (fieldName[0]=='n' && strcmp(fieldName, "node_id")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "sleep_time")==0) return base+12;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ModPacketDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
        "int",
        "double",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : NULL;
}

const char *ModPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ModPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ModPacket *pp = (ModPacket *)object; (void)pp;
    switch (field) {
        case 10: return 10;
        case 11: return 10;
        default: return 0;
    }
}

std::string ModPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ModPacket *pp = (ModPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPtype());
        case 1: return long2string(pp->getAdst());
        case 2: return long2string(pp->getFdst());
        case 3: return long2string(pp->getSourceX());
        case 4: return long2string(pp->getSourceY());
        case 5: return long2string(pp->getDestX());
        case 6: return long2string(pp->getDestY());
        case 7: return long2string(pp->getMyX());
        case 8: return long2string(pp->getMyY());
        case 9: return long2string(pp->getSlots());
        case 10: return double2string(pp->getSlot_info(i));
        case 11: return long2string(pp->getNode_id(i));
        case 12: return double2string(pp->getSleep_time());
        default: return "";
    }
}

bool ModPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ModPacket *pp = (ModPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setPtype(string2long(value)); return true;
        case 1: pp->setAdst(string2long(value)); return true;
        case 2: pp->setFdst(string2long(value)); return true;
        case 3: pp->setSourceX(string2long(value)); return true;
        case 4: pp->setSourceY(string2long(value)); return true;
        case 5: pp->setDestX(string2long(value)); return true;
        case 6: pp->setDestY(string2long(value)); return true;
        case 7: pp->setMyX(string2long(value)); return true;
        case 8: pp->setMyY(string2long(value)); return true;
        case 9: pp->setSlots(string2long(value)); return true;
        case 10: pp->setSlot_info(i,string2double(value)); return true;
        case 11: pp->setNode_id(i,string2long(value)); return true;
        case 12: pp->setSleep_time(string2double(value)); return true;
        default: return false;
    }
}

const char *ModPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *ModPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ModPacket *pp = (ModPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


