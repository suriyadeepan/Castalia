//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/mac/ourProt/CPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "CPacket_m.h"

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

Register_Class(CPacket);

CPacket::CPacket(const char *name, int kind) : ::MacPacket(name,kind)
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
    this->time_val_var = 0;
    this->del_t_var = 0;
}

CPacket::CPacket(const CPacket& other) : ::MacPacket(other)
{
    copy(other);
}

CPacket::~CPacket()
{
}

CPacket& CPacket::operator=(const CPacket& other)
{
    if (this==&other) return *this;
    ::MacPacket::operator=(other);
    copy(other);
    return *this;
}

void CPacket::copy(const CPacket& other)
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
    this->time_val_var = other.time_val_var;
    this->del_t_var = other.del_t_var;
}

void CPacket::parsimPack(cCommBuffer *b)
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
    doPacking(b,this->time_val_var);
    doPacking(b,this->del_t_var);
}

void CPacket::parsimUnpack(cCommBuffer *b)
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
    doUnpacking(b,this->time_val_var);
    doUnpacking(b,this->del_t_var);
}

int CPacket::getPtype() const
{
    return ptype_var;
}

void CPacket::setPtype(int ptype)
{
    this->ptype_var = ptype;
}

int CPacket::getAdst() const
{
    return adst_var;
}

void CPacket::setAdst(int adst)
{
    this->adst_var = adst;
}

int CPacket::getFdst() const
{
    return fdst_var;
}

void CPacket::setFdst(int fdst)
{
    this->fdst_var = fdst;
}

int CPacket::getSourceX() const
{
    return sourceX_var;
}

void CPacket::setSourceX(int sourceX)
{
    this->sourceX_var = sourceX;
}

int CPacket::getSourceY() const
{
    return sourceY_var;
}

void CPacket::setSourceY(int sourceY)
{
    this->sourceY_var = sourceY;
}

int CPacket::getDestX() const
{
    return destX_var;
}

void CPacket::setDestX(int destX)
{
    this->destX_var = destX;
}

int CPacket::getDestY() const
{
    return destY_var;
}

void CPacket::setDestY(int destY)
{
    this->destY_var = destY;
}

int CPacket::getMyX() const
{
    return myX_var;
}

void CPacket::setMyX(int myX)
{
    this->myX_var = myX;
}

int CPacket::getMyY() const
{
    return myY_var;
}

void CPacket::setMyY(int myY)
{
    this->myY_var = myY;
}

int CPacket::getSlots() const
{
    return slots_var;
}

void CPacket::setSlots(int slots)
{
    this->slots_var = slots;
}

unsigned int CPacket::getSlot_infoArraySize() const
{
    return 10;
}

int CPacket::getSlot_info(unsigned int k) const
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    return slot_info_var[k];
}

void CPacket::setSlot_info(unsigned int k, int slot_info)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    this->slot_info_var[k] = slot_info;
}

unsigned int CPacket::getNode_idArraySize() const
{
    return 10;
}

int CPacket::getNode_id(unsigned int k) const
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    return node_id_var[k];
}

void CPacket::setNode_id(unsigned int k, int node_id)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    this->node_id_var[k] = node_id;
}

double CPacket::getTime_val() const
{
    return time_val_var;
}

void CPacket::setTime_val(double time_val)
{
    this->time_val_var = time_val;
}

double CPacket::getDel_t() const
{
    return del_t_var;
}

void CPacket::setDel_t(double del_t)
{
    this->del_t_var = del_t;
}

class CPacketDescriptor : public cClassDescriptor
{
  public:
    CPacketDescriptor();
    virtual ~CPacketDescriptor();

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

Register_ClassDescriptor(CPacketDescriptor);

CPacketDescriptor::CPacketDescriptor() : cClassDescriptor("CPacket", "MacPacket")
{
}

CPacketDescriptor::~CPacketDescriptor()
{
}

bool CPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<CPacket *>(obj)!=NULL;
}

const char *CPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount(object) : 14;
}

unsigned int CPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<14) ? fieldTypeFlags[field] : 0;
}

const char *CPacketDescriptor::getFieldName(void *object, int field) const
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
        "time_val",
        "del_t",
    };
    return (field>=0 && field<14) ? fieldNames[field] : NULL;
}

int CPacketDescriptor::findField(void *object, const char *fieldName) const
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
    if (fieldName[0]=='t' && strcmp(fieldName, "time_val")==0) return base+12;
    if (fieldName[0]=='d' && strcmp(fieldName, "del_t")==0) return base+13;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CPacketDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
        "double",
    };
    return (field>=0 && field<14) ? fieldTypeStrings[field] : NULL;
}

const char *CPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int CPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    CPacket *pp = (CPacket *)object; (void)pp;
    switch (field) {
        case 10: return 10;
        case 11: return 10;
        default: return 0;
    }
}

std::string CPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    CPacket *pp = (CPacket *)object; (void)pp;
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
        case 10: return long2string(pp->getSlot_info(i));
        case 11: return long2string(pp->getNode_id(i));
        case 12: return double2string(pp->getTime_val());
        case 13: return double2string(pp->getDel_t());
        default: return "";
    }
}

bool CPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    CPacket *pp = (CPacket *)object; (void)pp;
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
        case 10: pp->setSlot_info(i,string2long(value)); return true;
        case 11: pp->setNode_id(i,string2long(value)); return true;
        case 12: pp->setTime_val(string2double(value)); return true;
        case 13: pp->setDel_t(string2double(value)); return true;
        default: return false;
    }
}

const char *CPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *CPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    CPacket *pp = (CPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


