//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/mac/tunableMac/TunableMacControl.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "TunableMacControl_m.h"

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
    cEnum *e = cEnum::find("TunableMacCommandDef");
    if (!e) enums.getInstance()->add(e = new cEnum("TunableMacCommandDef"));
    e->insert(SET_DUTY_CYCLE, "SET_DUTY_CYCLE");
    e->insert(SET_LISTEN_INTERVAL, "SET_LISTEN_INTERVAL");
    e->insert(SET_BEACON_INTERVAL_FRACTION, "SET_BEACON_INTERVAL_FRACTION");
    e->insert(SET_PROB_TX, "SET_PROB_TX");
    e->insert(SET_NUM_TX, "SET_NUM_TX");
    e->insert(SET_RANDOM_TX_OFFSET, "SET_RANDOM_TX_OFFSET");
    e->insert(SET_RETX_INTERVAL, "SET_RETX_INTERVAL");
    e->insert(SET_BACKOFF_TYPE, "SET_BACKOFF_TYPE");
    e->insert(SET_BACKOFF_BASE_VALUE, "SET_BACKOFF_BASE_VALUE");
);

Register_Class(TunableMacControlCommand);

TunableMacControlCommand::TunableMacControlCommand(const char *name, int kind) : ::cMessage(name,kind)
{
    this->tunableMacCommandKind_var = 0;
    this->parameter_var = 0;
}

TunableMacControlCommand::TunableMacControlCommand(const TunableMacControlCommand& other) : ::cMessage(other)
{
    copy(other);
}

TunableMacControlCommand::~TunableMacControlCommand()
{
}

TunableMacControlCommand& TunableMacControlCommand::operator=(const TunableMacControlCommand& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TunableMacControlCommand::copy(const TunableMacControlCommand& other)
{
    this->tunableMacCommandKind_var = other.tunableMacCommandKind_var;
    this->parameter_var = other.parameter_var;
}

void TunableMacControlCommand::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->tunableMacCommandKind_var);
    doPacking(b,this->parameter_var);
}

void TunableMacControlCommand::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->tunableMacCommandKind_var);
    doUnpacking(b,this->parameter_var);
}

int TunableMacControlCommand::getTunableMacCommandKind() const
{
    return tunableMacCommandKind_var;
}

void TunableMacControlCommand::setTunableMacCommandKind(int tunableMacCommandKind)
{
    this->tunableMacCommandKind_var = tunableMacCommandKind;
}

double TunableMacControlCommand::getParameter() const
{
    return parameter_var;
}

void TunableMacControlCommand::setParameter(double parameter)
{
    this->parameter_var = parameter;
}

class TunableMacControlCommandDescriptor : public cClassDescriptor
{
  public:
    TunableMacControlCommandDescriptor();
    virtual ~TunableMacControlCommandDescriptor();

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

Register_ClassDescriptor(TunableMacControlCommandDescriptor);

TunableMacControlCommandDescriptor::TunableMacControlCommandDescriptor() : cClassDescriptor("TunableMacControlCommand", "cMessage")
{
}

TunableMacControlCommandDescriptor::~TunableMacControlCommandDescriptor()
{
}

bool TunableMacControlCommandDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<TunableMacControlCommand *>(obj)!=NULL;
}

const char *TunableMacControlCommandDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int TunableMacControlCommandDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int TunableMacControlCommandDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *TunableMacControlCommandDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "tunableMacCommandKind",
        "parameter",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int TunableMacControlCommandDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tunableMacCommandKind")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameter")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *TunableMacControlCommandDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *TunableMacControlCommandDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "TunableMacCommandDef";
            return NULL;
        default: return NULL;
    }
}

int TunableMacControlCommandDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    TunableMacControlCommand *pp = (TunableMacControlCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string TunableMacControlCommandDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    TunableMacControlCommand *pp = (TunableMacControlCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTunableMacCommandKind());
        case 1: return double2string(pp->getParameter());
        default: return "";
    }
}

bool TunableMacControlCommandDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    TunableMacControlCommand *pp = (TunableMacControlCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setTunableMacCommandKind(string2long(value)); return true;
        case 1: pp->setParameter(string2double(value)); return true;
        default: return false;
    }
}

const char *TunableMacControlCommandDescriptor::getFieldStructName(void *object, int field) const
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

void *TunableMacControlCommandDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    TunableMacControlCommand *pp = (TunableMacControlCommand *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


