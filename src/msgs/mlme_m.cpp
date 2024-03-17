//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/mlme.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "mlme_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(MLMEAssociateRequest)

MLMEAssociateRequest::MLMEAssociateRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEAssociateRequest::MLMEAssociateRequest(const MLMEAssociateRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEAssociateRequest::~MLMEAssociateRequest()
{
}

MLMEAssociateRequest& MLMEAssociateRequest::operator=(const MLMEAssociateRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEAssociateRequest::copy(const MLMEAssociateRequest& other)
{
    this->logicalChannel = other.logicalChannel;
    this->coordAddrMode = other.coordAddrMode;
    this->coordOWPANId = other.coordOWPANId;
    this->coordAddress = other.coordAddress;
    this->capabilityInformation = other.capabilityInformation;
    this->securityLevel = other.securityLevel;
    this->colorAssoc = other.colorAssoc;
}

void MLMEAssociateRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->logicalChannel);
    doParsimPacking(b,this->coordAddrMode);
    doParsimPacking(b,this->coordOWPANId);
    doParsimPacking(b,this->coordAddress);
    doParsimPacking(b,this->capabilityInformation);
    doParsimPacking(b,this->securityLevel);
    doParsimPacking(b,this->colorAssoc);
}

void MLMEAssociateRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->logicalChannel);
    doParsimUnpacking(b,this->coordAddrMode);
    doParsimUnpacking(b,this->coordOWPANId);
    doParsimUnpacking(b,this->coordAddress);
    doParsimUnpacking(b,this->capabilityInformation);
    doParsimUnpacking(b,this->securityLevel);
    doParsimUnpacking(b,this->colorAssoc);
}

opticalChannel_t MLMEAssociateRequest::getLogicalChannel() const
{
    return this->logicalChannel;
}

void MLMEAssociateRequest::setLogicalChannel(opticalChannel_t logicalChannel)
{
    this->logicalChannel = logicalChannel;
}

addressingMode_t MLMEAssociateRequest::getCoordAddrMode() const
{
    return this->coordAddrMode;
}

void MLMEAssociateRequest::setCoordAddrMode(addressingMode_t coordAddrMode)
{
    this->coordAddrMode = coordAddrMode;
}

uint16_t MLMEAssociateRequest::getCoordOWPANId() const
{
    return this->coordOWPANId;
}

void MLMEAssociateRequest::setCoordOWPANId(uint16_t coordOWPANId)
{
    this->coordOWPANId = coordOWPANId;
}

uint64_t MLMEAssociateRequest::getCoordAddress() const
{
    return this->coordAddress;
}

void MLMEAssociateRequest::setCoordAddress(uint64_t coordAddress)
{
    this->coordAddress = coordAddress;
}

const capabilityInformation_t& MLMEAssociateRequest::getCapabilityInformation() const
{
    return this->capabilityInformation;
}

void MLMEAssociateRequest::setCapabilityInformation(const capabilityInformation_t& capabilityInformation)
{
    this->capabilityInformation = capabilityInformation;
}

uint8_t MLMEAssociateRequest::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEAssociateRequest::setSecurityLevel(uint8_t securityLevel)
{
    this->securityLevel = securityLevel;
}

bool MLMEAssociateRequest::getColorAssoc() const
{
    return this->colorAssoc;
}

void MLMEAssociateRequest::setColorAssoc(bool colorAssoc)
{
    this->colorAssoc = colorAssoc;
}

class MLMEAssociateRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_logicalChannel,
        FIELD_coordAddrMode,
        FIELD_coordOWPANId,
        FIELD_coordAddress,
        FIELD_capabilityInformation,
        FIELD_securityLevel,
        FIELD_colorAssoc,
    };
  public:
    MLMEAssociateRequestDescriptor();
    virtual ~MLMEAssociateRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEAssociateRequestDescriptor)

MLMEAssociateRequestDescriptor::MLMEAssociateRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEAssociateRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEAssociateRequestDescriptor::~MLMEAssociateRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEAssociateRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEAssociateRequest *>(obj)!=nullptr;
}

const char **MLMEAssociateRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEAssociateRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEAssociateRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int MLMEAssociateRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_logicalChannel
        FD_ISEDITABLE,    // FIELD_coordAddrMode
        FD_ISEDITABLE,    // FIELD_coordOWPANId
        FD_ISEDITABLE,    // FIELD_coordAddress
        FD_ISCOMPOUND,    // FIELD_capabilityInformation
        FD_ISEDITABLE,    // FIELD_securityLevel
        FD_ISEDITABLE,    // FIELD_colorAssoc
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *MLMEAssociateRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "logicalChannel",
        "coordAddrMode",
        "coordOWPANId",
        "coordAddress",
        "capabilityInformation",
        "securityLevel",
        "colorAssoc",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int MLMEAssociateRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "logicalChannel") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "coordAddrMode") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "coordOWPANId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "coordAddress") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "capabilityInformation") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "colorAssoc") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEAssociateRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "opticalChannel_t",    // FIELD_logicalChannel
        "addressingMode_t",    // FIELD_coordAddrMode
        "uint16_t",    // FIELD_coordOWPANId
        "uint64_t",    // FIELD_coordAddress
        "capabilityInformation_t",    // FIELD_capabilityInformation
        "uint8_t",    // FIELD_securityLevel
        "bool",    // FIELD_colorAssoc
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEAssociateRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_logicalChannel: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_coordAddrMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEAssociateRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_logicalChannel:
            if (!strcmp(propertyName, "enum")) return "opticalChannel_t";
            return nullptr;
        case FIELD_coordAddrMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEAssociateRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEAssociateRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEAssociateRequest'", field);
    }
}

const char *MLMEAssociateRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEAssociateRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: return enum2string(pp->getLogicalChannel(), "opticalChannel_t");
        case FIELD_coordAddrMode: return enum2string(pp->getCoordAddrMode(), "addressingMode_t");
        case FIELD_coordOWPANId: return ulong2string(pp->getCoordOWPANId());
        case FIELD_coordAddress: return uint642string(pp->getCoordAddress());
        case FIELD_capabilityInformation: return "";
        case FIELD_securityLevel: return ulong2string(pp->getSecurityLevel());
        case FIELD_colorAssoc: return bool2string(pp->getColorAssoc());
        default: return "";
    }
}

void MLMEAssociateRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: pp->setLogicalChannel((opticalChannel_t)string2enum(value, "opticalChannel_t")); break;
        case FIELD_coordAddrMode: pp->setCoordAddrMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_coordOWPANId: pp->setCoordOWPANId(string2ulong(value)); break;
        case FIELD_coordAddress: pp->setCoordAddress(string2uint64(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2ulong(value)); break;
        case FIELD_colorAssoc: pp->setColorAssoc(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateRequest'", field);
    }
}

omnetpp::cValue MLMEAssociateRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: return static_cast<int>(pp->getLogicalChannel());
        case FIELD_coordAddrMode: return static_cast<int>(pp->getCoordAddrMode());
        case FIELD_coordOWPANId: return (omnetpp::intval_t)(pp->getCoordOWPANId());
        case FIELD_coordAddress: return (omnetpp::intval_t)(pp->getCoordAddress());
        case FIELD_capabilityInformation: return omnetpp::toAnyPtr(&pp->getCapabilityInformation()); break;
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->getSecurityLevel());
        case FIELD_colorAssoc: return pp->getColorAssoc();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEAssociateRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEAssociateRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: pp->setLogicalChannel(static_cast<opticalChannel_t>(value.intValue())); break;
        case FIELD_coordAddrMode: pp->setCoordAddrMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_coordOWPANId: pp->setCoordOWPANId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_coordAddress: pp->setCoordAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_colorAssoc: pp->setColorAssoc(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateRequest'", field);
    }
}

const char *MLMEAssociateRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_capabilityInformation: return omnetpp::opp_typename(typeid(capabilityInformation_t));
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEAssociateRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_capabilityInformation: return omnetpp::toAnyPtr(&pp->getCapabilityInformation()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEAssociateRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateRequest *pp = omnetpp::fromAnyPtr<MLMEAssociateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateRequest'", field);
    }
}

Register_Class(MLMEAssociateConfirm)

MLMEAssociateConfirm::MLMEAssociateConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEAssociateConfirm::MLMEAssociateConfirm(const MLMEAssociateConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEAssociateConfirm::~MLMEAssociateConfirm()
{
}

MLMEAssociateConfirm& MLMEAssociateConfirm::operator=(const MLMEAssociateConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEAssociateConfirm::copy(const MLMEAssociateConfirm& other)
{
    this->assocShortAddress = other.assocShortAddress;
    this->status = other.status;
    this->capabilityNegotiationResponse = other.capabilityNegotiationResponse;
    this->securityLevel = other.securityLevel;
}

void MLMEAssociateConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->assocShortAddress);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->capabilityNegotiationResponse);
    doParsimPacking(b,this->securityLevel);
}

void MLMEAssociateConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->assocShortAddress);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->capabilityNegotiationResponse);
    doParsimUnpacking(b,this->securityLevel);
}

uint16_t MLMEAssociateConfirm::getAssocShortAddress() const
{
    return this->assocShortAddress;
}

void MLMEAssociateConfirm::setAssocShortAddress(uint16_t assocShortAddress)
{
    this->assocShortAddress = assocShortAddress;
}

macStatus_t MLMEAssociateConfirm::getStatus() const
{
    return this->status;
}

void MLMEAssociateConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

colorStabilizationScheme_t MLMEAssociateConfirm::getCapabilityNegotiationResponse() const
{
    return this->capabilityNegotiationResponse;
}

void MLMEAssociateConfirm::setCapabilityNegotiationResponse(colorStabilizationScheme_t capabilityNegotiationResponse)
{
    this->capabilityNegotiationResponse = capabilityNegotiationResponse;
}

uint8_t MLMEAssociateConfirm::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEAssociateConfirm::setSecurityLevel(uint8_t securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMEAssociateConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_assocShortAddress,
        FIELD_status,
        FIELD_capabilityNegotiationResponse,
        FIELD_securityLevel,
    };
  public:
    MLMEAssociateConfirmDescriptor();
    virtual ~MLMEAssociateConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEAssociateConfirmDescriptor)

MLMEAssociateConfirmDescriptor::MLMEAssociateConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEAssociateConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEAssociateConfirmDescriptor::~MLMEAssociateConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEAssociateConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEAssociateConfirm *>(obj)!=nullptr;
}

const char **MLMEAssociateConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEAssociateConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEAssociateConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int MLMEAssociateConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_assocShortAddress
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_capabilityNegotiationResponse
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MLMEAssociateConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "assocShortAddress",
        "status",
        "capabilityNegotiationResponse",
        "securityLevel",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MLMEAssociateConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "assocShortAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "capabilityNegotiationResponse") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEAssociateConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_assocShortAddress
        "macStatus_t",    // FIELD_status
        "colorStabilizationScheme_t",    // FIELD_capabilityNegotiationResponse
        "uint8_t",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEAssociateConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_capabilityNegotiationResponse: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEAssociateConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        case FIELD_capabilityNegotiationResponse:
            if (!strcmp(propertyName, "enum")) return "colorStabilizationScheme_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEAssociateConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEAssociateConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEAssociateConfirm'", field);
    }
}

const char *MLMEAssociateConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEAssociateConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_assocShortAddress: return ulong2string(pp->getAssocShortAddress());
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        case FIELD_capabilityNegotiationResponse: return enum2string(pp->getCapabilityNegotiationResponse(), "colorStabilizationScheme_t");
        case FIELD_securityLevel: return ulong2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMEAssociateConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_assocShortAddress: pp->setAssocShortAddress(string2ulong(value)); break;
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        case FIELD_capabilityNegotiationResponse: pp->setCapabilityNegotiationResponse((colorStabilizationScheme_t)string2enum(value, "colorStabilizationScheme_t")); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateConfirm'", field);
    }
}

omnetpp::cValue MLMEAssociateConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_assocShortAddress: return (omnetpp::intval_t)(pp->getAssocShortAddress());
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_capabilityNegotiationResponse: return static_cast<int>(pp->getCapabilityNegotiationResponse());
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->getSecurityLevel());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEAssociateConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEAssociateConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_assocShortAddress: pp->setAssocShortAddress(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        case FIELD_capabilityNegotiationResponse: pp->setCapabilityNegotiationResponse(static_cast<colorStabilizationScheme_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateConfirm'", field);
    }
}

const char *MLMEAssociateConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEAssociateConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEAssociateConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateConfirm *pp = omnetpp::fromAnyPtr<MLMEAssociateConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateConfirm'", field);
    }
}

Register_Class(MLMEAssociateResponse)

MLMEAssociateResponse::MLMEAssociateResponse(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEAssociateResponse::MLMEAssociateResponse(const MLMEAssociateResponse& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEAssociateResponse::~MLMEAssociateResponse()
{
}

MLMEAssociateResponse& MLMEAssociateResponse::operator=(const MLMEAssociateResponse& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEAssociateResponse::copy(const MLMEAssociateResponse& other)
{
    this->deviceAddress = other.deviceAddress;
    this->assocShortAddress = other.assocShortAddress;
    this->status = other.status;
    this->capabilityNegotationResponse = other.capabilityNegotationResponse;
    this->securityLevel = other.securityLevel;
}

void MLMEAssociateResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->deviceAddress);
    doParsimPacking(b,this->assocShortAddress);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->capabilityNegotationResponse);
    doParsimPacking(b,this->securityLevel);
}

void MLMEAssociateResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->deviceAddress);
    doParsimUnpacking(b,this->assocShortAddress);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->capabilityNegotationResponse);
    doParsimUnpacking(b,this->securityLevel);
}

uint64_t MLMEAssociateResponse::getDeviceAddress() const
{
    return this->deviceAddress;
}

void MLMEAssociateResponse::setDeviceAddress(uint64_t deviceAddress)
{
    this->deviceAddress = deviceAddress;
}

int MLMEAssociateResponse::getAssocShortAddress() const
{
    return this->assocShortAddress;
}

void MLMEAssociateResponse::setAssocShortAddress(int assocShortAddress)
{
    this->assocShortAddress = assocShortAddress;
}

uint8_t MLMEAssociateResponse::getStatus() const
{
    return this->status;
}

void MLMEAssociateResponse::setStatus(uint8_t status)
{
    this->status = status;
}

int MLMEAssociateResponse::getCapabilityNegotationResponse() const
{
    return this->capabilityNegotationResponse;
}

void MLMEAssociateResponse::setCapabilityNegotationResponse(int capabilityNegotationResponse)
{
    this->capabilityNegotationResponse = capabilityNegotationResponse;
}

int MLMEAssociateResponse::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEAssociateResponse::setSecurityLevel(int securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMEAssociateResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deviceAddress,
        FIELD_assocShortAddress,
        FIELD_status,
        FIELD_capabilityNegotationResponse,
        FIELD_securityLevel,
    };
  public:
    MLMEAssociateResponseDescriptor();
    virtual ~MLMEAssociateResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEAssociateResponseDescriptor)

MLMEAssociateResponseDescriptor::MLMEAssociateResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEAssociateResponse)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEAssociateResponseDescriptor::~MLMEAssociateResponseDescriptor()
{
    delete[] propertyNames;
}

bool MLMEAssociateResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEAssociateResponse *>(obj)!=nullptr;
}

const char **MLMEAssociateResponseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEAssociateResponseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEAssociateResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int MLMEAssociateResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_deviceAddress
        FD_ISEDITABLE,    // FIELD_assocShortAddress
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_capabilityNegotationResponse
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *MLMEAssociateResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deviceAddress",
        "assocShortAddress",
        "status",
        "capabilityNegotationResponse",
        "securityLevel",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int MLMEAssociateResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deviceAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "assocShortAddress") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "capabilityNegotationResponse") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEAssociateResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",    // FIELD_deviceAddress
        "int",    // FIELD_assocShortAddress
        "uint8_t",    // FIELD_status
        "int",    // FIELD_capabilityNegotationResponse
        "int",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEAssociateResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMEAssociateResponseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMEAssociateResponseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEAssociateResponseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEAssociateResponse'", field);
    }
}

const char *MLMEAssociateResponseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEAssociateResponseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return uint642string(pp->getDeviceAddress());
        case FIELD_assocShortAddress: return long2string(pp->getAssocShortAddress());
        case FIELD_status: return ulong2string(pp->getStatus());
        case FIELD_capabilityNegotationResponse: return long2string(pp->getCapabilityNegotationResponse());
        case FIELD_securityLevel: return long2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMEAssociateResponseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(string2uint64(value)); break;
        case FIELD_assocShortAddress: pp->setAssocShortAddress(string2long(value)); break;
        case FIELD_status: pp->setStatus(string2ulong(value)); break;
        case FIELD_capabilityNegotationResponse: pp->setCapabilityNegotationResponse(string2long(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateResponse'", field);
    }
}

omnetpp::cValue MLMEAssociateResponseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return (omnetpp::intval_t)(pp->getDeviceAddress());
        case FIELD_assocShortAddress: return pp->getAssocShortAddress();
        case FIELD_status: return (omnetpp::intval_t)(pp->getStatus());
        case FIELD_capabilityNegotationResponse: return pp->getCapabilityNegotationResponse();
        case FIELD_securityLevel: return pp->getSecurityLevel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEAssociateResponse' as cValue -- field index out of range?", field);
    }
}

void MLMEAssociateResponseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_assocShortAddress: pp->setAssocShortAddress(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_status: pp->setStatus(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_capabilityNegotationResponse: pp->setCapabilityNegotationResponse(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateResponse'", field);
    }
}

const char *MLMEAssociateResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEAssociateResponseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEAssociateResponseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateResponse *pp = omnetpp::fromAnyPtr<MLMEAssociateResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateResponse'", field);
    }
}

Register_Class(MLMEAssociateIndication)

MLMEAssociateIndication::MLMEAssociateIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEAssociateIndication::MLMEAssociateIndication(const MLMEAssociateIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEAssociateIndication::~MLMEAssociateIndication()
{
}

MLMEAssociateIndication& MLMEAssociateIndication::operator=(const MLMEAssociateIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEAssociateIndication::copy(const MLMEAssociateIndication& other)
{
    this->deviceAddress = other.deviceAddress;
    this->capabilityInformation = other.capabilityInformation;
    this->securityLevel = other.securityLevel;
}

void MLMEAssociateIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->deviceAddress);
    doParsimPacking(b,this->capabilityInformation);
    doParsimPacking(b,this->securityLevel);
}

void MLMEAssociateIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->deviceAddress);
    doParsimUnpacking(b,this->capabilityInformation);
    doParsimUnpacking(b,this->securityLevel);
}

uint64_t MLMEAssociateIndication::getDeviceAddress() const
{
    return this->deviceAddress;
}

void MLMEAssociateIndication::setDeviceAddress(uint64_t deviceAddress)
{
    this->deviceAddress = deviceAddress;
}

uint64_t MLMEAssociateIndication::getCapabilityInformation() const
{
    return this->capabilityInformation;
}

void MLMEAssociateIndication::setCapabilityInformation(uint64_t capabilityInformation)
{
    this->capabilityInformation = capabilityInformation;
}

int MLMEAssociateIndication::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEAssociateIndication::setSecurityLevel(int securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMEAssociateIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deviceAddress,
        FIELD_capabilityInformation,
        FIELD_securityLevel,
    };
  public:
    MLMEAssociateIndicationDescriptor();
    virtual ~MLMEAssociateIndicationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEAssociateIndicationDescriptor)

MLMEAssociateIndicationDescriptor::MLMEAssociateIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEAssociateIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEAssociateIndicationDescriptor::~MLMEAssociateIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MLMEAssociateIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEAssociateIndication *>(obj)!=nullptr;
}

const char **MLMEAssociateIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEAssociateIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEAssociateIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MLMEAssociateIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_deviceAddress
        FD_ISEDITABLE,    // FIELD_capabilityInformation
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MLMEAssociateIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deviceAddress",
        "capabilityInformation",
        "securityLevel",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MLMEAssociateIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deviceAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "capabilityInformation") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEAssociateIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",    // FIELD_deviceAddress
        "uint64_t",    // FIELD_capabilityInformation
        "int",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEAssociateIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMEAssociateIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMEAssociateIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEAssociateIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEAssociateIndication'", field);
    }
}

const char *MLMEAssociateIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEAssociateIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return uint642string(pp->getDeviceAddress());
        case FIELD_capabilityInformation: return uint642string(pp->getCapabilityInformation());
        case FIELD_securityLevel: return long2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMEAssociateIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(string2uint64(value)); break;
        case FIELD_capabilityInformation: pp->setCapabilityInformation(string2uint64(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateIndication'", field);
    }
}

omnetpp::cValue MLMEAssociateIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return (omnetpp::intval_t)(pp->getDeviceAddress());
        case FIELD_capabilityInformation: return (omnetpp::intval_t)(pp->getCapabilityInformation());
        case FIELD_securityLevel: return pp->getSecurityLevel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEAssociateIndication' as cValue -- field index out of range?", field);
    }
}

void MLMEAssociateIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_capabilityInformation: pp->setCapabilityInformation(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateIndication'", field);
    }
}

const char *MLMEAssociateIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEAssociateIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEAssociateIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEAssociateIndication *pp = omnetpp::fromAnyPtr<MLMEAssociateIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEAssociateIndication'", field);
    }
}

Register_Class(MLMEBeaconNotifyIndication)

MLMEBeaconNotifyIndication::MLMEBeaconNotifyIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEBeaconNotifyIndication::MLMEBeaconNotifyIndication(const MLMEBeaconNotifyIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEBeaconNotifyIndication::~MLMEBeaconNotifyIndication()
{
    delete [] this->addrList;
    delete [] this->sdu;
}

MLMEBeaconNotifyIndication& MLMEBeaconNotifyIndication::operator=(const MLMEBeaconNotifyIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEBeaconNotifyIndication::copy(const MLMEBeaconNotifyIndication& other)
{
    this->BSN = other.BSN;
    this->OWPANDescriptor = other.OWPANDescriptor;
    this->pendAddrSpec = other.pendAddrSpec;
    delete [] this->addrList;
    this->addrList = (other.addrList_arraysize==0) ? nullptr : new uint8_t[other.addrList_arraysize];
    addrList_arraysize = other.addrList_arraysize;
    for (size_t i = 0; i < addrList_arraysize; i++) {
        this->addrList[i] = other.addrList[i];
    }
    this->sduLength = other.sduLength;
    delete [] this->sdu;
    this->sdu = (other.sdu_arraysize==0) ? nullptr : new uint8_t[other.sdu_arraysize];
    sdu_arraysize = other.sdu_arraysize;
    for (size_t i = 0; i < sdu_arraysize; i++) {
        this->sdu[i] = other.sdu[i];
    }
}

void MLMEBeaconNotifyIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->BSN);
    doParsimPacking(b,this->OWPANDescriptor);
    doParsimPacking(b,this->pendAddrSpec);
    b->pack(addrList_arraysize);
    doParsimArrayPacking(b,this->addrList,addrList_arraysize);
    doParsimPacking(b,this->sduLength);
    b->pack(sdu_arraysize);
    doParsimArrayPacking(b,this->sdu,sdu_arraysize);
}

void MLMEBeaconNotifyIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->BSN);
    doParsimUnpacking(b,this->OWPANDescriptor);
    doParsimUnpacking(b,this->pendAddrSpec);
    delete [] this->addrList;
    b->unpack(addrList_arraysize);
    if (addrList_arraysize == 0) {
        this->addrList = nullptr;
    } else {
        this->addrList = new uint8_t[addrList_arraysize];
        doParsimArrayUnpacking(b,this->addrList,addrList_arraysize);
    }
    doParsimUnpacking(b,this->sduLength);
    delete [] this->sdu;
    b->unpack(sdu_arraysize);
    if (sdu_arraysize == 0) {
        this->sdu = nullptr;
    } else {
        this->sdu = new uint8_t[sdu_arraysize];
        doParsimArrayUnpacking(b,this->sdu,sdu_arraysize);
    }
}

int MLMEBeaconNotifyIndication::getBSN() const
{
    return this->BSN;
}

void MLMEBeaconNotifyIndication::setBSN(int BSN)
{
    this->BSN = BSN;
}

uint8_t MLMEBeaconNotifyIndication::getOWPANDescriptor() const
{
    return this->OWPANDescriptor;
}

void MLMEBeaconNotifyIndication::setOWPANDescriptor(uint8_t OWPANDescriptor)
{
    this->OWPANDescriptor = OWPANDescriptor;
}

uint8_t MLMEBeaconNotifyIndication::getPendAddrSpec() const
{
    return this->pendAddrSpec;
}

void MLMEBeaconNotifyIndication::setPendAddrSpec(uint8_t pendAddrSpec)
{
    this->pendAddrSpec = pendAddrSpec;
}

size_t MLMEBeaconNotifyIndication::getAddrListArraySize() const
{
    return addrList_arraysize;
}

uint8_t MLMEBeaconNotifyIndication::getAddrList(size_t k) const
{
    if (k >= addrList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addrList_arraysize, (unsigned long)k);
    return this->addrList[k];
}

void MLMEBeaconNotifyIndication::setAddrListArraySize(size_t newSize)
{
    uint8_t *addrList2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = addrList_arraysize < newSize ? addrList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        addrList2[i] = this->addrList[i];
    for (size_t i = minSize; i < newSize; i++)
        addrList2[i] = 0;
    delete [] this->addrList;
    this->addrList = addrList2;
    addrList_arraysize = newSize;
}

void MLMEBeaconNotifyIndication::setAddrList(size_t k, uint8_t addrList)
{
    if (k >= addrList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addrList_arraysize, (unsigned long)k);
    this->addrList[k] = addrList;
}

void MLMEBeaconNotifyIndication::insertAddrList(size_t k, uint8_t addrList)
{
    if (k > addrList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addrList_arraysize, (unsigned long)k);
    size_t newSize = addrList_arraysize + 1;
    uint8_t *addrList2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addrList2[i] = this->addrList[i];
    addrList2[k] = addrList;
    for (i = k + 1; i < newSize; i++)
        addrList2[i] = this->addrList[i-1];
    delete [] this->addrList;
    this->addrList = addrList2;
    addrList_arraysize = newSize;
}

void MLMEBeaconNotifyIndication::appendAddrList(uint8_t addrList)
{
    insertAddrList(addrList_arraysize, addrList);
}

void MLMEBeaconNotifyIndication::eraseAddrList(size_t k)
{
    if (k >= addrList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)addrList_arraysize, (unsigned long)k);
    size_t newSize = addrList_arraysize - 1;
    uint8_t *addrList2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        addrList2[i] = this->addrList[i];
    for (i = k; i < newSize; i++)
        addrList2[i] = this->addrList[i+1];
    delete [] this->addrList;
    this->addrList = addrList2;
    addrList_arraysize = newSize;
}

int MLMEBeaconNotifyIndication::getSduLength() const
{
    return this->sduLength;
}

void MLMEBeaconNotifyIndication::setSduLength(int sduLength)
{
    this->sduLength = sduLength;
}

size_t MLMEBeaconNotifyIndication::getSduArraySize() const
{
    return sdu_arraysize;
}

uint8_t MLMEBeaconNotifyIndication::getSdu(size_t k) const
{
    if (k >= sdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sdu_arraysize, (unsigned long)k);
    return this->sdu[k];
}

void MLMEBeaconNotifyIndication::setSduArraySize(size_t newSize)
{
    uint8_t *sdu2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = sdu_arraysize < newSize ? sdu_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        sdu2[i] = this->sdu[i];
    for (size_t i = minSize; i < newSize; i++)
        sdu2[i] = 0;
    delete [] this->sdu;
    this->sdu = sdu2;
    sdu_arraysize = newSize;
}

void MLMEBeaconNotifyIndication::setSdu(size_t k, uint8_t sdu)
{
    if (k >= sdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sdu_arraysize, (unsigned long)k);
    this->sdu[k] = sdu;
}

void MLMEBeaconNotifyIndication::insertSdu(size_t k, uint8_t sdu)
{
    if (k > sdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sdu_arraysize, (unsigned long)k);
    size_t newSize = sdu_arraysize + 1;
    uint8_t *sdu2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sdu2[i] = this->sdu[i];
    sdu2[k] = sdu;
    for (i = k + 1; i < newSize; i++)
        sdu2[i] = this->sdu[i-1];
    delete [] this->sdu;
    this->sdu = sdu2;
    sdu_arraysize = newSize;
}

void MLMEBeaconNotifyIndication::appendSdu(uint8_t sdu)
{
    insertSdu(sdu_arraysize, sdu);
}

void MLMEBeaconNotifyIndication::eraseSdu(size_t k)
{
    if (k >= sdu_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)sdu_arraysize, (unsigned long)k);
    size_t newSize = sdu_arraysize - 1;
    uint8_t *sdu2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        sdu2[i] = this->sdu[i];
    for (i = k; i < newSize; i++)
        sdu2[i] = this->sdu[i+1];
    delete [] this->sdu;
    this->sdu = sdu2;
    sdu_arraysize = newSize;
}

class MLMEBeaconNotifyIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_BSN,
        FIELD_OWPANDescriptor,
        FIELD_pendAddrSpec,
        FIELD_addrList,
        FIELD_sduLength,
        FIELD_sdu,
    };
  public:
    MLMEBeaconNotifyIndicationDescriptor();
    virtual ~MLMEBeaconNotifyIndicationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEBeaconNotifyIndicationDescriptor)

MLMEBeaconNotifyIndicationDescriptor::MLMEBeaconNotifyIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEBeaconNotifyIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEBeaconNotifyIndicationDescriptor::~MLMEBeaconNotifyIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MLMEBeaconNotifyIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEBeaconNotifyIndication *>(obj)!=nullptr;
}

const char **MLMEBeaconNotifyIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEBeaconNotifyIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEBeaconNotifyIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int MLMEBeaconNotifyIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_BSN
        FD_ISEDITABLE,    // FIELD_OWPANDescriptor
        FD_ISEDITABLE,    // FIELD_pendAddrSpec
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_addrList
        FD_ISEDITABLE,    // FIELD_sduLength
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_sdu
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *MLMEBeaconNotifyIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "BSN",
        "OWPANDescriptor",
        "pendAddrSpec",
        "addrList",
        "sduLength",
        "sdu",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int MLMEBeaconNotifyIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "BSN") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "OWPANDescriptor") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "pendAddrSpec") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "addrList") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sduLength") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "sdu") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEBeaconNotifyIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_BSN
        "uint8_t",    // FIELD_OWPANDescriptor
        "uint8_t",    // FIELD_pendAddrSpec
        "uint8_t",    // FIELD_addrList
        "int",    // FIELD_sduLength
        "uint8_t",    // FIELD_sdu
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEBeaconNotifyIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMEBeaconNotifyIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMEBeaconNotifyIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        case FIELD_addrList: return pp->getAddrListArraySize();
        case FIELD_sdu: return pp->getSduArraySize();
        default: return 0;
    }
}

void MLMEBeaconNotifyIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        case FIELD_addrList: pp->setAddrListArraySize(size); break;
        case FIELD_sdu: pp->setSduArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEBeaconNotifyIndication'", field);
    }
}

const char *MLMEBeaconNotifyIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEBeaconNotifyIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        case FIELD_BSN: return long2string(pp->getBSN());
        case FIELD_OWPANDescriptor: return ulong2string(pp->getOWPANDescriptor());
        case FIELD_pendAddrSpec: return ulong2string(pp->getPendAddrSpec());
        case FIELD_addrList: return ulong2string(pp->getAddrList(i));
        case FIELD_sduLength: return long2string(pp->getSduLength());
        case FIELD_sdu: return ulong2string(pp->getSdu(i));
        default: return "";
    }
}

void MLMEBeaconNotifyIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        case FIELD_BSN: pp->setBSN(string2long(value)); break;
        case FIELD_OWPANDescriptor: pp->setOWPANDescriptor(string2ulong(value)); break;
        case FIELD_pendAddrSpec: pp->setPendAddrSpec(string2ulong(value)); break;
        case FIELD_addrList: pp->setAddrList(i,string2ulong(value)); break;
        case FIELD_sduLength: pp->setSduLength(string2long(value)); break;
        case FIELD_sdu: pp->setSdu(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEBeaconNotifyIndication'", field);
    }
}

omnetpp::cValue MLMEBeaconNotifyIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        case FIELD_BSN: return pp->getBSN();
        case FIELD_OWPANDescriptor: return (omnetpp::intval_t)(pp->getOWPANDescriptor());
        case FIELD_pendAddrSpec: return (omnetpp::intval_t)(pp->getPendAddrSpec());
        case FIELD_addrList: return (omnetpp::intval_t)(pp->getAddrList(i));
        case FIELD_sduLength: return pp->getSduLength();
        case FIELD_sdu: return (omnetpp::intval_t)(pp->getSdu(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEBeaconNotifyIndication' as cValue -- field index out of range?", field);
    }
}

void MLMEBeaconNotifyIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        case FIELD_BSN: pp->setBSN(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_OWPANDescriptor: pp->setOWPANDescriptor(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_pendAddrSpec: pp->setPendAddrSpec(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_addrList: pp->setAddrList(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_sduLength: pp->setSduLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sdu: pp->setSdu(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEBeaconNotifyIndication'", field);
    }
}

const char *MLMEBeaconNotifyIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEBeaconNotifyIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEBeaconNotifyIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEBeaconNotifyIndication *pp = omnetpp::fromAnyPtr<MLMEBeaconNotifyIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEBeaconNotifyIndication'", field);
    }
}

Register_Class(MLMECommStatusIndication)

MLMECommStatusIndication::MLMECommStatusIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMECommStatusIndication::MLMECommStatusIndication(const MLMECommStatusIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMECommStatusIndication::~MLMECommStatusIndication()
{
}

MLMECommStatusIndication& MLMECommStatusIndication::operator=(const MLMECommStatusIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMECommStatusIndication::copy(const MLMECommStatusIndication& other)
{
    this->OWPANId = other.OWPANId;
    this->srcAddrMode = other.srcAddrMode;
    this->srcAddr = other.srcAddr;
    this->dstAddrMode = other.dstAddrMode;
    this->dstAddr = other.dstAddr;
    this->status = other.status;
    this->securityLevel = other.securityLevel;
}

void MLMECommStatusIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->OWPANId);
    doParsimPacking(b,this->srcAddrMode);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->dstAddrMode);
    doParsimPacking(b,this->dstAddr);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->securityLevel);
}

void MLMECommStatusIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->OWPANId);
    doParsimUnpacking(b,this->srcAddrMode);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->dstAddrMode);
    doParsimUnpacking(b,this->dstAddr);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->securityLevel);
}

int MLMECommStatusIndication::getOWPANId() const
{
    return this->OWPANId;
}

void MLMECommStatusIndication::setOWPANId(int OWPANId)
{
    this->OWPANId = OWPANId;
}

int MLMECommStatusIndication::getSrcAddrMode() const
{
    return this->srcAddrMode;
}

void MLMECommStatusIndication::setSrcAddrMode(int srcAddrMode)
{
    this->srcAddrMode = srcAddrMode;
}

uint64_t MLMECommStatusIndication::getSrcAddr() const
{
    return this->srcAddr;
}

void MLMECommStatusIndication::setSrcAddr(uint64_t srcAddr)
{
    this->srcAddr = srcAddr;
}

int MLMECommStatusIndication::getDstAddrMode() const
{
    return this->dstAddrMode;
}

void MLMECommStatusIndication::setDstAddrMode(int dstAddrMode)
{
    this->dstAddrMode = dstAddrMode;
}

uint64_t MLMECommStatusIndication::getDstAddr() const
{
    return this->dstAddr;
}

void MLMECommStatusIndication::setDstAddr(uint64_t dstAddr)
{
    this->dstAddr = dstAddr;
}

uint8_t MLMECommStatusIndication::getStatus() const
{
    return this->status;
}

void MLMECommStatusIndication::setStatus(uint8_t status)
{
    this->status = status;
}

int MLMECommStatusIndication::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMECommStatusIndication::setSecurityLevel(int securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMECommStatusIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_OWPANId,
        FIELD_srcAddrMode,
        FIELD_srcAddr,
        FIELD_dstAddrMode,
        FIELD_dstAddr,
        FIELD_status,
        FIELD_securityLevel,
    };
  public:
    MLMECommStatusIndicationDescriptor();
    virtual ~MLMECommStatusIndicationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMECommStatusIndicationDescriptor)

MLMECommStatusIndicationDescriptor::MLMECommStatusIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMECommStatusIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMECommStatusIndicationDescriptor::~MLMECommStatusIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MLMECommStatusIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMECommStatusIndication *>(obj)!=nullptr;
}

const char **MLMECommStatusIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMECommStatusIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMECommStatusIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int MLMECommStatusIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_OWPANId
        FD_ISEDITABLE,    // FIELD_srcAddrMode
        FD_ISEDITABLE,    // FIELD_srcAddr
        FD_ISEDITABLE,    // FIELD_dstAddrMode
        FD_ISEDITABLE,    // FIELD_dstAddr
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *MLMECommStatusIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "OWPANId",
        "srcAddrMode",
        "srcAddr",
        "dstAddrMode",
        "dstAddr",
        "status",
        "securityLevel",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int MLMECommStatusIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "OWPANId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "srcAddrMode") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "srcAddr") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "dstAddrMode") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "dstAddr") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMECommStatusIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_OWPANId
        "int",    // FIELD_srcAddrMode
        "uint64_t",    // FIELD_srcAddr
        "int",    // FIELD_dstAddrMode
        "uint64_t",    // FIELD_dstAddr
        "uint8_t",    // FIELD_status
        "int",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMECommStatusIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMECommStatusIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMECommStatusIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMECommStatusIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMECommStatusIndication'", field);
    }
}

const char *MLMECommStatusIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMECommStatusIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: return long2string(pp->getOWPANId());
        case FIELD_srcAddrMode: return long2string(pp->getSrcAddrMode());
        case FIELD_srcAddr: return uint642string(pp->getSrcAddr());
        case FIELD_dstAddrMode: return long2string(pp->getDstAddrMode());
        case FIELD_dstAddr: return uint642string(pp->getDstAddr());
        case FIELD_status: return ulong2string(pp->getStatus());
        case FIELD_securityLevel: return long2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMECommStatusIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: pp->setOWPANId(string2long(value)); break;
        case FIELD_srcAddrMode: pp->setSrcAddrMode(string2long(value)); break;
        case FIELD_srcAddr: pp->setSrcAddr(string2uint64(value)); break;
        case FIELD_dstAddrMode: pp->setDstAddrMode(string2long(value)); break;
        case FIELD_dstAddr: pp->setDstAddr(string2uint64(value)); break;
        case FIELD_status: pp->setStatus(string2ulong(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMECommStatusIndication'", field);
    }
}

omnetpp::cValue MLMECommStatusIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: return pp->getOWPANId();
        case FIELD_srcAddrMode: return pp->getSrcAddrMode();
        case FIELD_srcAddr: return (omnetpp::intval_t)(pp->getSrcAddr());
        case FIELD_dstAddrMode: return pp->getDstAddrMode();
        case FIELD_dstAddr: return (omnetpp::intval_t)(pp->getDstAddr());
        case FIELD_status: return (omnetpp::intval_t)(pp->getStatus());
        case FIELD_securityLevel: return pp->getSecurityLevel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMECommStatusIndication' as cValue -- field index out of range?", field);
    }
}

void MLMECommStatusIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: pp->setOWPANId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcAddrMode: pp->setSrcAddrMode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcAddr: pp->setSrcAddr(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_dstAddrMode: pp->setDstAddrMode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dstAddr: pp->setDstAddr(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_status: pp->setStatus(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMECommStatusIndication'", field);
    }
}

const char *MLMECommStatusIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMECommStatusIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMECommStatusIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMECommStatusIndication *pp = omnetpp::fromAnyPtr<MLMECommStatusIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMECommStatusIndication'", field);
    }
}

Register_Class(MLMEDisassociateRequest)

MLMEDisassociateRequest::MLMEDisassociateRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEDisassociateRequest::MLMEDisassociateRequest(const MLMEDisassociateRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEDisassociateRequest::~MLMEDisassociateRequest()
{
}

MLMEDisassociateRequest& MLMEDisassociateRequest::operator=(const MLMEDisassociateRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEDisassociateRequest::copy(const MLMEDisassociateRequest& other)
{
    this->deviceAddrMode = other.deviceAddrMode;
    this->deviceOWPANId = other.deviceOWPANId;
    this->deviceAddress = other.deviceAddress;
    this->disassociateReason = other.disassociateReason;
    this->txIndirect = other.txIndirect;
    this->securityLevel = other.securityLevel;
    this->colorDisAssoc = other.colorDisAssoc;
}

void MLMEDisassociateRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->deviceAddrMode);
    doParsimPacking(b,this->deviceOWPANId);
    doParsimPacking(b,this->deviceAddress);
    doParsimPacking(b,this->disassociateReason);
    doParsimPacking(b,this->txIndirect);
    doParsimPacking(b,this->securityLevel);
    doParsimPacking(b,this->colorDisAssoc);
}

void MLMEDisassociateRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->deviceAddrMode);
    doParsimUnpacking(b,this->deviceOWPANId);
    doParsimUnpacking(b,this->deviceAddress);
    doParsimUnpacking(b,this->disassociateReason);
    doParsimUnpacking(b,this->txIndirect);
    doParsimUnpacking(b,this->securityLevel);
    doParsimUnpacking(b,this->colorDisAssoc);
}

addressingMode_t MLMEDisassociateRequest::getDeviceAddrMode() const
{
    return this->deviceAddrMode;
}

void MLMEDisassociateRequest::setDeviceAddrMode(addressingMode_t deviceAddrMode)
{
    this->deviceAddrMode = deviceAddrMode;
}

uint16_t MLMEDisassociateRequest::getDeviceOWPANId() const
{
    return this->deviceOWPANId;
}

void MLMEDisassociateRequest::setDeviceOWPANId(uint16_t deviceOWPANId)
{
    this->deviceOWPANId = deviceOWPANId;
}

uint64_t MLMEDisassociateRequest::getDeviceAddress() const
{
    return this->deviceAddress;
}

void MLMEDisassociateRequest::setDeviceAddress(uint64_t deviceAddress)
{
    this->deviceAddress = deviceAddress;
}

uint8_t MLMEDisassociateRequest::getDisassociateReason() const
{
    return this->disassociateReason;
}

void MLMEDisassociateRequest::setDisassociateReason(uint8_t disassociateReason)
{
    this->disassociateReason = disassociateReason;
}

bool MLMEDisassociateRequest::getTxIndirect() const
{
    return this->txIndirect;
}

void MLMEDisassociateRequest::setTxIndirect(bool txIndirect)
{
    this->txIndirect = txIndirect;
}

uint8_t MLMEDisassociateRequest::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEDisassociateRequest::setSecurityLevel(uint8_t securityLevel)
{
    this->securityLevel = securityLevel;
}

bool MLMEDisassociateRequest::getColorDisAssoc() const
{
    return this->colorDisAssoc;
}

void MLMEDisassociateRequest::setColorDisAssoc(bool colorDisAssoc)
{
    this->colorDisAssoc = colorDisAssoc;
}

class MLMEDisassociateRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deviceAddrMode,
        FIELD_deviceOWPANId,
        FIELD_deviceAddress,
        FIELD_disassociateReason,
        FIELD_txIndirect,
        FIELD_securityLevel,
        FIELD_colorDisAssoc,
    };
  public:
    MLMEDisassociateRequestDescriptor();
    virtual ~MLMEDisassociateRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEDisassociateRequestDescriptor)

MLMEDisassociateRequestDescriptor::MLMEDisassociateRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEDisassociateRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEDisassociateRequestDescriptor::~MLMEDisassociateRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEDisassociateRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEDisassociateRequest *>(obj)!=nullptr;
}

const char **MLMEDisassociateRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEDisassociateRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEDisassociateRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int MLMEDisassociateRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_deviceAddrMode
        FD_ISEDITABLE,    // FIELD_deviceOWPANId
        FD_ISEDITABLE,    // FIELD_deviceAddress
        FD_ISEDITABLE,    // FIELD_disassociateReason
        FD_ISEDITABLE,    // FIELD_txIndirect
        FD_ISEDITABLE,    // FIELD_securityLevel
        FD_ISEDITABLE,    // FIELD_colorDisAssoc
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *MLMEDisassociateRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deviceAddrMode",
        "deviceOWPANId",
        "deviceAddress",
        "disassociateReason",
        "txIndirect",
        "securityLevel",
        "colorDisAssoc",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int MLMEDisassociateRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deviceAddrMode") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "deviceOWPANId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "deviceAddress") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "disassociateReason") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "txIndirect") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "colorDisAssoc") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEDisassociateRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "addressingMode_t",    // FIELD_deviceAddrMode
        "uint16_t",    // FIELD_deviceOWPANId
        "uint64_t",    // FIELD_deviceAddress
        "uint8_t",    // FIELD_disassociateReason
        "bool",    // FIELD_txIndirect
        "uint8_t",    // FIELD_securityLevel
        "bool",    // FIELD_colorDisAssoc
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEDisassociateRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_deviceAddrMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEDisassociateRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_deviceAddrMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEDisassociateRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEDisassociateRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEDisassociateRequest'", field);
    }
}

const char *MLMEDisassociateRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEDisassociateRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddrMode: return enum2string(pp->getDeviceAddrMode(), "addressingMode_t");
        case FIELD_deviceOWPANId: return ulong2string(pp->getDeviceOWPANId());
        case FIELD_deviceAddress: return uint642string(pp->getDeviceAddress());
        case FIELD_disassociateReason: return ulong2string(pp->getDisassociateReason());
        case FIELD_txIndirect: return bool2string(pp->getTxIndirect());
        case FIELD_securityLevel: return ulong2string(pp->getSecurityLevel());
        case FIELD_colorDisAssoc: return bool2string(pp->getColorDisAssoc());
        default: return "";
    }
}

void MLMEDisassociateRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddrMode: pp->setDeviceAddrMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_deviceOWPANId: pp->setDeviceOWPANId(string2ulong(value)); break;
        case FIELD_deviceAddress: pp->setDeviceAddress(string2uint64(value)); break;
        case FIELD_disassociateReason: pp->setDisassociateReason(string2ulong(value)); break;
        case FIELD_txIndirect: pp->setTxIndirect(string2bool(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2ulong(value)); break;
        case FIELD_colorDisAssoc: pp->setColorDisAssoc(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateRequest'", field);
    }
}

omnetpp::cValue MLMEDisassociateRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddrMode: return static_cast<int>(pp->getDeviceAddrMode());
        case FIELD_deviceOWPANId: return (omnetpp::intval_t)(pp->getDeviceOWPANId());
        case FIELD_deviceAddress: return (omnetpp::intval_t)(pp->getDeviceAddress());
        case FIELD_disassociateReason: return (omnetpp::intval_t)(pp->getDisassociateReason());
        case FIELD_txIndirect: return pp->getTxIndirect();
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->getSecurityLevel());
        case FIELD_colorDisAssoc: return pp->getColorDisAssoc();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEDisassociateRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEDisassociateRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddrMode: pp->setDeviceAddrMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_deviceOWPANId: pp->setDeviceOWPANId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_deviceAddress: pp->setDeviceAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_disassociateReason: pp->setDisassociateReason(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_txIndirect: pp->setTxIndirect(value.boolValue()); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_colorDisAssoc: pp->setColorDisAssoc(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateRequest'", field);
    }
}

const char *MLMEDisassociateRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEDisassociateRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEDisassociateRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateRequest *pp = omnetpp::fromAnyPtr<MLMEDisassociateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateRequest'", field);
    }
}

Register_Class(MLMEDisassociateConfirm)

MLMEDisassociateConfirm::MLMEDisassociateConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEDisassociateConfirm::MLMEDisassociateConfirm(const MLMEDisassociateConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEDisassociateConfirm::~MLMEDisassociateConfirm()
{
}

MLMEDisassociateConfirm& MLMEDisassociateConfirm::operator=(const MLMEDisassociateConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEDisassociateConfirm::copy(const MLMEDisassociateConfirm& other)
{
    this->status = other.status;
    this->deviceAddrMode = other.deviceAddrMode;
    this->deviceOWPANId = other.deviceOWPANId;
    this->deviceAddress = other.deviceAddress;
}

void MLMEDisassociateConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->deviceAddrMode);
    doParsimPacking(b,this->deviceOWPANId);
    doParsimPacking(b,this->deviceAddress);
}

void MLMEDisassociateConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->deviceAddrMode);
    doParsimUnpacking(b,this->deviceOWPANId);
    doParsimUnpacking(b,this->deviceAddress);
}

macStatus_t MLMEDisassociateConfirm::getStatus() const
{
    return this->status;
}

void MLMEDisassociateConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

addressingMode_t MLMEDisassociateConfirm::getDeviceAddrMode() const
{
    return this->deviceAddrMode;
}

void MLMEDisassociateConfirm::setDeviceAddrMode(addressingMode_t deviceAddrMode)
{
    this->deviceAddrMode = deviceAddrMode;
}

uint16_t MLMEDisassociateConfirm::getDeviceOWPANId() const
{
    return this->deviceOWPANId;
}

void MLMEDisassociateConfirm::setDeviceOWPANId(uint16_t deviceOWPANId)
{
    this->deviceOWPANId = deviceOWPANId;
}

uint64_t MLMEDisassociateConfirm::getDeviceAddress() const
{
    return this->deviceAddress;
}

void MLMEDisassociateConfirm::setDeviceAddress(uint64_t deviceAddress)
{
    this->deviceAddress = deviceAddress;
}

class MLMEDisassociateConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
        FIELD_deviceAddrMode,
        FIELD_deviceOWPANId,
        FIELD_deviceAddress,
    };
  public:
    MLMEDisassociateConfirmDescriptor();
    virtual ~MLMEDisassociateConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEDisassociateConfirmDescriptor)

MLMEDisassociateConfirmDescriptor::MLMEDisassociateConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEDisassociateConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEDisassociateConfirmDescriptor::~MLMEDisassociateConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEDisassociateConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEDisassociateConfirm *>(obj)!=nullptr;
}

const char **MLMEDisassociateConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEDisassociateConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEDisassociateConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int MLMEDisassociateConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_deviceAddrMode
        FD_ISEDITABLE,    // FIELD_deviceOWPANId
        FD_ISEDITABLE,    // FIELD_deviceAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MLMEDisassociateConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "deviceAddrMode",
        "deviceOWPANId",
        "deviceAddress",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MLMEDisassociateConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "deviceAddrMode") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "deviceOWPANId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "deviceAddress") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEDisassociateConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
        "addressingMode_t",    // FIELD_deviceAddrMode
        "uint16_t",    // FIELD_deviceOWPANId
        "uint64_t",    // FIELD_deviceAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEDisassociateConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_deviceAddrMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEDisassociateConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        case FIELD_deviceAddrMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEDisassociateConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEDisassociateConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEDisassociateConfirm'", field);
    }
}

const char *MLMEDisassociateConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEDisassociateConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        case FIELD_deviceAddrMode: return enum2string(pp->getDeviceAddrMode(), "addressingMode_t");
        case FIELD_deviceOWPANId: return ulong2string(pp->getDeviceOWPANId());
        case FIELD_deviceAddress: return uint642string(pp->getDeviceAddress());
        default: return "";
    }
}

void MLMEDisassociateConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        case FIELD_deviceAddrMode: pp->setDeviceAddrMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_deviceOWPANId: pp->setDeviceOWPANId(string2ulong(value)); break;
        case FIELD_deviceAddress: pp->setDeviceAddress(string2uint64(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateConfirm'", field);
    }
}

omnetpp::cValue MLMEDisassociateConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_deviceAddrMode: return static_cast<int>(pp->getDeviceAddrMode());
        case FIELD_deviceOWPANId: return (omnetpp::intval_t)(pp->getDeviceOWPANId());
        case FIELD_deviceAddress: return (omnetpp::intval_t)(pp->getDeviceAddress());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEDisassociateConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEDisassociateConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        case FIELD_deviceAddrMode: pp->setDeviceAddrMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_deviceOWPANId: pp->setDeviceOWPANId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_deviceAddress: pp->setDeviceAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateConfirm'", field);
    }
}

const char *MLMEDisassociateConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEDisassociateConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEDisassociateConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateConfirm *pp = omnetpp::fromAnyPtr<MLMEDisassociateConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateConfirm'", field);
    }
}

Register_Class(MLMEDisassociateIndication)

MLMEDisassociateIndication::MLMEDisassociateIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEDisassociateIndication::MLMEDisassociateIndication(const MLMEDisassociateIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEDisassociateIndication::~MLMEDisassociateIndication()
{
}

MLMEDisassociateIndication& MLMEDisassociateIndication::operator=(const MLMEDisassociateIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEDisassociateIndication::copy(const MLMEDisassociateIndication& other)
{
    this->deviceAddress = other.deviceAddress;
    this->disassociateReason = other.disassociateReason;
    this->securityLevel = other.securityLevel;
}

void MLMEDisassociateIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->deviceAddress);
    doParsimPacking(b,this->disassociateReason);
    doParsimPacking(b,this->securityLevel);
}

void MLMEDisassociateIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->deviceAddress);
    doParsimUnpacking(b,this->disassociateReason);
    doParsimUnpacking(b,this->securityLevel);
}

uint64_t MLMEDisassociateIndication::getDeviceAddress() const
{
    return this->deviceAddress;
}

void MLMEDisassociateIndication::setDeviceAddress(uint64_t deviceAddress)
{
    this->deviceAddress = deviceAddress;
}

int MLMEDisassociateIndication::getDisassociateReason() const
{
    return this->disassociateReason;
}

void MLMEDisassociateIndication::setDisassociateReason(int disassociateReason)
{
    this->disassociateReason = disassociateReason;
}

int MLMEDisassociateIndication::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEDisassociateIndication::setSecurityLevel(int securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMEDisassociateIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deviceAddress,
        FIELD_disassociateReason,
        FIELD_securityLevel,
    };
  public:
    MLMEDisassociateIndicationDescriptor();
    virtual ~MLMEDisassociateIndicationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEDisassociateIndicationDescriptor)

MLMEDisassociateIndicationDescriptor::MLMEDisassociateIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEDisassociateIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEDisassociateIndicationDescriptor::~MLMEDisassociateIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MLMEDisassociateIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEDisassociateIndication *>(obj)!=nullptr;
}

const char **MLMEDisassociateIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEDisassociateIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEDisassociateIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MLMEDisassociateIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_deviceAddress
        FD_ISEDITABLE,    // FIELD_disassociateReason
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MLMEDisassociateIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deviceAddress",
        "disassociateReason",
        "securityLevel",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MLMEDisassociateIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deviceAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "disassociateReason") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEDisassociateIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64_t",    // FIELD_deviceAddress
        "int",    // FIELD_disassociateReason
        "int",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEDisassociateIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMEDisassociateIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMEDisassociateIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEDisassociateIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEDisassociateIndication'", field);
    }
}

const char *MLMEDisassociateIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEDisassociateIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return uint642string(pp->getDeviceAddress());
        case FIELD_disassociateReason: return long2string(pp->getDisassociateReason());
        case FIELD_securityLevel: return long2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMEDisassociateIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(string2uint64(value)); break;
        case FIELD_disassociateReason: pp->setDisassociateReason(string2long(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateIndication'", field);
    }
}

omnetpp::cValue MLMEDisassociateIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return (omnetpp::intval_t)(pp->getDeviceAddress());
        case FIELD_disassociateReason: return pp->getDisassociateReason();
        case FIELD_securityLevel: return pp->getSecurityLevel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEDisassociateIndication' as cValue -- field index out of range?", field);
    }
}

void MLMEDisassociateIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_disassociateReason: pp->setDisassociateReason(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateIndication'", field);
    }
}

const char *MLMEDisassociateIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEDisassociateIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEDisassociateIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEDisassociateIndication *pp = omnetpp::fromAnyPtr<MLMEDisassociateIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEDisassociateIndication'", field);
    }
}

Register_Class(MLMEGetRequest)

MLMEGetRequest::MLMEGetRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEGetRequest::MLMEGetRequest(const MLMEGetRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEGetRequest::~MLMEGetRequest()
{
}

MLMEGetRequest& MLMEGetRequest::operator=(const MLMEGetRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEGetRequest::copy(const MLMEGetRequest& other)
{
    this->PIBAttribute = other.PIBAttribute;
    this->PIBAttributeIndex = other.PIBAttributeIndex;
}

void MLMEGetRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->PIBAttribute);
    doParsimPacking(b,this->PIBAttributeIndex);
}

void MLMEGetRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->PIBAttribute);
    doParsimUnpacking(b,this->PIBAttributeIndex);
}

PIBAttribute_t MLMEGetRequest::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void MLMEGetRequest::setPIBAttribute(PIBAttribute_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

uint8_t MLMEGetRequest::getPIBAttributeIndex() const
{
    return this->PIBAttributeIndex;
}

void MLMEGetRequest::setPIBAttributeIndex(uint8_t PIBAttributeIndex)
{
    this->PIBAttributeIndex = PIBAttributeIndex;
}

class MLMEGetRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_PIBAttribute,
        FIELD_PIBAttributeIndex,
    };
  public:
    MLMEGetRequestDescriptor();
    virtual ~MLMEGetRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEGetRequestDescriptor)

MLMEGetRequestDescriptor::MLMEGetRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEGetRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEGetRequestDescriptor::~MLMEGetRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEGetRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEGetRequest *>(obj)!=nullptr;
}

const char **MLMEGetRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEGetRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEGetRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int MLMEGetRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_PIBAttribute
        FD_ISEDITABLE,    // FIELD_PIBAttributeIndex
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MLMEGetRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "PIBAttribute",
        "PIBAttributeIndex",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MLMEGetRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "PIBAttributeIndex") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEGetRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "PIBAttribute_t",    // FIELD_PIBAttribute
        "uint8_t",    // FIELD_PIBAttributeIndex
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEGetRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_PIBAttribute: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEGetRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_PIBAttribute:
            if (!strcmp(propertyName, "enum")) return "PIBAttribute_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEGetRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEGetRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEGetRequest'", field);
    }
}

const char *MLMEGetRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEGetRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return enum2string(pp->getPIBAttribute(), "PIBAttribute_t");
        case FIELD_PIBAttributeIndex: return ulong2string(pp->getPIBAttributeIndex());
        default: return "";
    }
}

void MLMEGetRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute((PIBAttribute_t)string2enum(value, "PIBAttribute_t")); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGetRequest'", field);
    }
}

omnetpp::cValue MLMEGetRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return static_cast<int>(pp->getPIBAttribute());
        case FIELD_PIBAttributeIndex: return (omnetpp::intval_t)(pp->getPIBAttributeIndex());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEGetRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEGetRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute(static_cast<PIBAttribute_t>(value.intValue())); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGetRequest'", field);
    }
}

const char *MLMEGetRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEGetRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEGetRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetRequest *pp = omnetpp::fromAnyPtr<MLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGetRequest'", field);
    }
}

Register_Class(MLMEGetConfirm)

MLMEGetConfirm::MLMEGetConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEGetConfirm::MLMEGetConfirm(const MLMEGetConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEGetConfirm::~MLMEGetConfirm()
{
}

MLMEGetConfirm& MLMEGetConfirm::operator=(const MLMEGetConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEGetConfirm::copy(const MLMEGetConfirm& other)
{
    this->status = other.status;
    this->PIBAttribute = other.PIBAttribute;
    this->PIBAttributeIndex = other.PIBAttributeIndex;
    this->PIBAttributeValue = other.PIBAttributeValue;
}

void MLMEGetConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->PIBAttribute);
    doParsimPacking(b,this->PIBAttributeIndex);
    doParsimPacking(b,this->PIBAttributeValue);
}

void MLMEGetConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->PIBAttribute);
    doParsimUnpacking(b,this->PIBAttributeIndex);
    doParsimUnpacking(b,this->PIBAttributeValue);
}

macStatus_t MLMEGetConfirm::getStatus() const
{
    return this->status;
}

void MLMEGetConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

PIBAttribute_t MLMEGetConfirm::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void MLMEGetConfirm::setPIBAttribute(PIBAttribute_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

uint8_t MLMEGetConfirm::getPIBAttributeIndex() const
{
    return this->PIBAttributeIndex;
}

void MLMEGetConfirm::setPIBAttributeIndex(uint8_t PIBAttributeIndex)
{
    this->PIBAttributeIndex = PIBAttributeIndex;
}

uint64_t MLMEGetConfirm::getPIBAttributeValue() const
{
    return this->PIBAttributeValue;
}

void MLMEGetConfirm::setPIBAttributeValue(uint64_t PIBAttributeValue)
{
    this->PIBAttributeValue = PIBAttributeValue;
}

class MLMEGetConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
        FIELD_PIBAttribute,
        FIELD_PIBAttributeIndex,
        FIELD_PIBAttributeValue,
    };
  public:
    MLMEGetConfirmDescriptor();
    virtual ~MLMEGetConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEGetConfirmDescriptor)

MLMEGetConfirmDescriptor::MLMEGetConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEGetConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEGetConfirmDescriptor::~MLMEGetConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEGetConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEGetConfirm *>(obj)!=nullptr;
}

const char **MLMEGetConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEGetConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEGetConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int MLMEGetConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_PIBAttribute
        FD_ISEDITABLE,    // FIELD_PIBAttributeIndex
        FD_ISEDITABLE,    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MLMEGetConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "PIBAttribute",
        "PIBAttributeIndex",
        "PIBAttributeValue",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MLMEGetConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "PIBAttributeIndex") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "PIBAttributeValue") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEGetConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
        "PIBAttribute_t",    // FIELD_PIBAttribute
        "uint8_t",    // FIELD_PIBAttributeIndex
        "uint64_t",    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEGetConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_PIBAttribute: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEGetConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        case FIELD_PIBAttribute:
            if (!strcmp(propertyName, "enum")) return "PIBAttribute_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEGetConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEGetConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEGetConfirm'", field);
    }
}

const char *MLMEGetConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEGetConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        case FIELD_PIBAttribute: return enum2string(pp->getPIBAttribute(), "PIBAttribute_t");
        case FIELD_PIBAttributeIndex: return ulong2string(pp->getPIBAttributeIndex());
        case FIELD_PIBAttributeValue: return uint642string(pp->getPIBAttributeValue());
        default: return "";
    }
}

void MLMEGetConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute((PIBAttribute_t)string2enum(value, "PIBAttribute_t")); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(string2ulong(value)); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(string2uint64(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGetConfirm'", field);
    }
}

omnetpp::cValue MLMEGetConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_PIBAttribute: return static_cast<int>(pp->getPIBAttribute());
        case FIELD_PIBAttributeIndex: return (omnetpp::intval_t)(pp->getPIBAttributeIndex());
        case FIELD_PIBAttributeValue: return (omnetpp::intval_t)(pp->getPIBAttributeValue());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEGetConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEGetConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute(static_cast<PIBAttribute_t>(value.intValue())); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGetConfirm'", field);
    }
}

const char *MLMEGetConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEGetConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEGetConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGetConfirm *pp = omnetpp::fromAnyPtr<MLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGetConfirm'", field);
    }
}

Register_Class(MLMEGTSRequest)

MLMEGTSRequest::MLMEGTSRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEGTSRequest::MLMEGTSRequest(const MLMEGTSRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEGTSRequest::~MLMEGTSRequest()
{
}

MLMEGTSRequest& MLMEGTSRequest::operator=(const MLMEGTSRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEGTSRequest::copy(const MLMEGTSRequest& other)
{
    this->GTSCharacteristics = other.GTSCharacteristics;
    this->securityLevel = other.securityLevel;
}

void MLMEGTSRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->GTSCharacteristics);
    doParsimPacking(b,this->securityLevel);
}

void MLMEGTSRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->GTSCharacteristics);
    doParsimUnpacking(b,this->securityLevel);
}

uint8_t MLMEGTSRequest::getGTSCharacteristics() const
{
    return this->GTSCharacteristics;
}

void MLMEGTSRequest::setGTSCharacteristics(uint8_t GTSCharacteristics)
{
    this->GTSCharacteristics = GTSCharacteristics;
}

uint8_t MLMEGTSRequest::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEGTSRequest::setSecurityLevel(uint8_t securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMEGTSRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_GTSCharacteristics,
        FIELD_securityLevel,
    };
  public:
    MLMEGTSRequestDescriptor();
    virtual ~MLMEGTSRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEGTSRequestDescriptor)

MLMEGTSRequestDescriptor::MLMEGTSRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEGTSRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEGTSRequestDescriptor::~MLMEGTSRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEGTSRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEGTSRequest *>(obj)!=nullptr;
}

const char **MLMEGTSRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEGTSRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEGTSRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int MLMEGTSRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_GTSCharacteristics
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MLMEGTSRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "GTSCharacteristics",
        "securityLevel",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MLMEGTSRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "GTSCharacteristics") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEGTSRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_GTSCharacteristics
        "uint8_t",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEGTSRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMEGTSRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMEGTSRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEGTSRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEGTSRequest'", field);
    }
}

const char *MLMEGTSRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEGTSRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: return ulong2string(pp->getGTSCharacteristics());
        case FIELD_securityLevel: return ulong2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMEGTSRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: pp->setGTSCharacteristics(string2ulong(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSRequest'", field);
    }
}

omnetpp::cValue MLMEGTSRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: return (omnetpp::intval_t)(pp->getGTSCharacteristics());
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->getSecurityLevel());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEGTSRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEGTSRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: pp->setGTSCharacteristics(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSRequest'", field);
    }
}

const char *MLMEGTSRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEGTSRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEGTSRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSRequest *pp = omnetpp::fromAnyPtr<MLMEGTSRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSRequest'", field);
    }
}

Register_Class(MLMEGTSConfirm)

MLMEGTSConfirm::MLMEGTSConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEGTSConfirm::MLMEGTSConfirm(const MLMEGTSConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEGTSConfirm::~MLMEGTSConfirm()
{
}

MLMEGTSConfirm& MLMEGTSConfirm::operator=(const MLMEGTSConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEGTSConfirm::copy(const MLMEGTSConfirm& other)
{
    this->GTSCharacteristics = other.GTSCharacteristics;
    this->status = other.status;
}

void MLMEGTSConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->GTSCharacteristics);
    doParsimPacking(b,this->status);
}

void MLMEGTSConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->GTSCharacteristics);
    doParsimUnpacking(b,this->status);
}

uint8_t MLMEGTSConfirm::getGTSCharacteristics() const
{
    return this->GTSCharacteristics;
}

void MLMEGTSConfirm::setGTSCharacteristics(uint8_t GTSCharacteristics)
{
    this->GTSCharacteristics = GTSCharacteristics;
}

macStatus_t MLMEGTSConfirm::getStatus() const
{
    return this->status;
}

void MLMEGTSConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

class MLMEGTSConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_GTSCharacteristics,
        FIELD_status,
    };
  public:
    MLMEGTSConfirmDescriptor();
    virtual ~MLMEGTSConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEGTSConfirmDescriptor)

MLMEGTSConfirmDescriptor::MLMEGTSConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEGTSConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEGTSConfirmDescriptor::~MLMEGTSConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEGTSConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEGTSConfirm *>(obj)!=nullptr;
}

const char **MLMEGTSConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEGTSConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEGTSConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int MLMEGTSConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_GTSCharacteristics
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MLMEGTSConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "GTSCharacteristics",
        "status",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MLMEGTSConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "GTSCharacteristics") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEGTSConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_GTSCharacteristics
        "macStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEGTSConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEGTSConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEGTSConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEGTSConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEGTSConfirm'", field);
    }
}

const char *MLMEGTSConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEGTSConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: return ulong2string(pp->getGTSCharacteristics());
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        default: return "";
    }
}

void MLMEGTSConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: pp->setGTSCharacteristics(string2ulong(value)); break;
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSConfirm'", field);
    }
}

omnetpp::cValue MLMEGTSConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: return (omnetpp::intval_t)(pp->getGTSCharacteristics());
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEGTSConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEGTSConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_GTSCharacteristics: pp->setGTSCharacteristics(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSConfirm'", field);
    }
}

const char *MLMEGTSConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEGTSConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEGTSConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSConfirm *pp = omnetpp::fromAnyPtr<MLMEGTSConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSConfirm'", field);
    }
}

Register_Class(MLMEGTSIndication)

MLMEGTSIndication::MLMEGTSIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEGTSIndication::MLMEGTSIndication(const MLMEGTSIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEGTSIndication::~MLMEGTSIndication()
{
}

MLMEGTSIndication& MLMEGTSIndication::operator=(const MLMEGTSIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEGTSIndication::copy(const MLMEGTSIndication& other)
{
    this->deviceAddress = other.deviceAddress;
    this->GTSCharacteristics = other.GTSCharacteristics;
    this->securityLevel = other.securityLevel;
}

void MLMEGTSIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->deviceAddress);
    doParsimPacking(b,this->GTSCharacteristics);
    doParsimPacking(b,this->securityLevel);
}

void MLMEGTSIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->deviceAddress);
    doParsimUnpacking(b,this->GTSCharacteristics);
    doParsimUnpacking(b,this->securityLevel);
}

uint16_t MLMEGTSIndication::getDeviceAddress() const
{
    return this->deviceAddress;
}

void MLMEGTSIndication::setDeviceAddress(uint16_t deviceAddress)
{
    this->deviceAddress = deviceAddress;
}

uint8_t MLMEGTSIndication::getGTSCharacteristics() const
{
    return this->GTSCharacteristics;
}

void MLMEGTSIndication::setGTSCharacteristics(uint8_t GTSCharacteristics)
{
    this->GTSCharacteristics = GTSCharacteristics;
}

int MLMEGTSIndication::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEGTSIndication::setSecurityLevel(int securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMEGTSIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deviceAddress,
        FIELD_GTSCharacteristics,
        FIELD_securityLevel,
    };
  public:
    MLMEGTSIndicationDescriptor();
    virtual ~MLMEGTSIndicationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEGTSIndicationDescriptor)

MLMEGTSIndicationDescriptor::MLMEGTSIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEGTSIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEGTSIndicationDescriptor::~MLMEGTSIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MLMEGTSIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEGTSIndication *>(obj)!=nullptr;
}

const char **MLMEGTSIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEGTSIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEGTSIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MLMEGTSIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_deviceAddress
        FD_ISEDITABLE,    // FIELD_GTSCharacteristics
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MLMEGTSIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deviceAddress",
        "GTSCharacteristics",
        "securityLevel",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MLMEGTSIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deviceAddress") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "GTSCharacteristics") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEGTSIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_deviceAddress
        "uint8_t",    // FIELD_GTSCharacteristics
        "int",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEGTSIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMEGTSIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMEGTSIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEGTSIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEGTSIndication'", field);
    }
}

const char *MLMEGTSIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEGTSIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return ulong2string(pp->getDeviceAddress());
        case FIELD_GTSCharacteristics: return ulong2string(pp->getGTSCharacteristics());
        case FIELD_securityLevel: return long2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMEGTSIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(string2ulong(value)); break;
        case FIELD_GTSCharacteristics: pp->setGTSCharacteristics(string2ulong(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSIndication'", field);
    }
}

omnetpp::cValue MLMEGTSIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: return (omnetpp::intval_t)(pp->getDeviceAddress());
        case FIELD_GTSCharacteristics: return (omnetpp::intval_t)(pp->getGTSCharacteristics());
        case FIELD_securityLevel: return pp->getSecurityLevel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEGTSIndication' as cValue -- field index out of range?", field);
    }
}

void MLMEGTSIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        case FIELD_deviceAddress: pp->setDeviceAddress(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_GTSCharacteristics: pp->setGTSCharacteristics(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSIndication'", field);
    }
}

const char *MLMEGTSIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEGTSIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEGTSIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEGTSIndication *pp = omnetpp::fromAnyPtr<MLMEGTSIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEGTSIndication'", field);
    }
}

Register_Class(MLMEPollRequest)

MLMEPollRequest::MLMEPollRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEPollRequest::MLMEPollRequest(const MLMEPollRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEPollRequest::~MLMEPollRequest()
{
}

MLMEPollRequest& MLMEPollRequest::operator=(const MLMEPollRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEPollRequest::copy(const MLMEPollRequest& other)
{
    this->coordAddrMode = other.coordAddrMode;
    this->coordOWPANId = other.coordOWPANId;
    this->coordAddress = other.coordAddress;
    this->securityLevel = other.securityLevel;
}

void MLMEPollRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->coordAddrMode);
    doParsimPacking(b,this->coordOWPANId);
    doParsimPacking(b,this->coordAddress);
    doParsimPacking(b,this->securityLevel);
}

void MLMEPollRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->coordAddrMode);
    doParsimUnpacking(b,this->coordOWPANId);
    doParsimUnpacking(b,this->coordAddress);
    doParsimUnpacking(b,this->securityLevel);
}

addressingMode_t MLMEPollRequest::getCoordAddrMode() const
{
    return this->coordAddrMode;
}

void MLMEPollRequest::setCoordAddrMode(addressingMode_t coordAddrMode)
{
    this->coordAddrMode = coordAddrMode;
}

uint16_t MLMEPollRequest::getCoordOWPANId() const
{
    return this->coordOWPANId;
}

void MLMEPollRequest::setCoordOWPANId(uint16_t coordOWPANId)
{
    this->coordOWPANId = coordOWPANId;
}

uint64_t MLMEPollRequest::getCoordAddress() const
{
    return this->coordAddress;
}

void MLMEPollRequest::setCoordAddress(uint64_t coordAddress)
{
    this->coordAddress = coordAddress;
}

uint8_t MLMEPollRequest::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEPollRequest::setSecurityLevel(uint8_t securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMEPollRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_coordAddrMode,
        FIELD_coordOWPANId,
        FIELD_coordAddress,
        FIELD_securityLevel,
    };
  public:
    MLMEPollRequestDescriptor();
    virtual ~MLMEPollRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEPollRequestDescriptor)

MLMEPollRequestDescriptor::MLMEPollRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEPollRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEPollRequestDescriptor::~MLMEPollRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEPollRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEPollRequest *>(obj)!=nullptr;
}

const char **MLMEPollRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEPollRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEPollRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int MLMEPollRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_coordAddrMode
        FD_ISEDITABLE,    // FIELD_coordOWPANId
        FD_ISEDITABLE,    // FIELD_coordAddress
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MLMEPollRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "coordAddrMode",
        "coordOWPANId",
        "coordAddress",
        "securityLevel",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MLMEPollRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "coordAddrMode") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "coordOWPANId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "coordAddress") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEPollRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "addressingMode_t",    // FIELD_coordAddrMode
        "uint16_t",    // FIELD_coordOWPANId
        "uint64_t",    // FIELD_coordAddress
        "uint8_t",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEPollRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_coordAddrMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEPollRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_coordAddrMode:
            if (!strcmp(propertyName, "enum")) return "addressingMode_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEPollRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEPollRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEPollRequest'", field);
    }
}

const char *MLMEPollRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEPollRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        case FIELD_coordAddrMode: return enum2string(pp->getCoordAddrMode(), "addressingMode_t");
        case FIELD_coordOWPANId: return ulong2string(pp->getCoordOWPANId());
        case FIELD_coordAddress: return uint642string(pp->getCoordAddress());
        case FIELD_securityLevel: return ulong2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMEPollRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        case FIELD_coordAddrMode: pp->setCoordAddrMode((addressingMode_t)string2enum(value, "addressingMode_t")); break;
        case FIELD_coordOWPANId: pp->setCoordOWPANId(string2ulong(value)); break;
        case FIELD_coordAddress: pp->setCoordAddress(string2uint64(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEPollRequest'", field);
    }
}

omnetpp::cValue MLMEPollRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        case FIELD_coordAddrMode: return static_cast<int>(pp->getCoordAddrMode());
        case FIELD_coordOWPANId: return (omnetpp::intval_t)(pp->getCoordOWPANId());
        case FIELD_coordAddress: return (omnetpp::intval_t)(pp->getCoordAddress());
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->getSecurityLevel());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEPollRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEPollRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        case FIELD_coordAddrMode: pp->setCoordAddrMode(static_cast<addressingMode_t>(value.intValue())); break;
        case FIELD_coordOWPANId: pp->setCoordOWPANId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_coordAddress: pp->setCoordAddress(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEPollRequest'", field);
    }
}

const char *MLMEPollRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEPollRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEPollRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollRequest *pp = omnetpp::fromAnyPtr<MLMEPollRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEPollRequest'", field);
    }
}

Register_Class(MLMEPollConfirm)

MLMEPollConfirm::MLMEPollConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEPollConfirm::MLMEPollConfirm(const MLMEPollConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEPollConfirm::~MLMEPollConfirm()
{
}

MLMEPollConfirm& MLMEPollConfirm::operator=(const MLMEPollConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEPollConfirm::copy(const MLMEPollConfirm& other)
{
    this->status = other.status;
}

void MLMEPollConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void MLMEPollConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

macStatus_t MLMEPollConfirm::getStatus() const
{
    return this->status;
}

void MLMEPollConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

class MLMEPollConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    MLMEPollConfirmDescriptor();
    virtual ~MLMEPollConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEPollConfirmDescriptor)

MLMEPollConfirmDescriptor::MLMEPollConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEPollConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEPollConfirmDescriptor::~MLMEPollConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEPollConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEPollConfirm *>(obj)!=nullptr;
}

const char **MLMEPollConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEPollConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEPollConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int MLMEPollConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MLMEPollConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MLMEPollConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEPollConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEPollConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEPollConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEPollConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEPollConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEPollConfirm'", field);
    }
}

const char *MLMEPollConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEPollConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        default: return "";
    }
}

void MLMEPollConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEPollConfirm'", field);
    }
}

omnetpp::cValue MLMEPollConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEPollConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEPollConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEPollConfirm'", field);
    }
}

const char *MLMEPollConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEPollConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEPollConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEPollConfirm *pp = omnetpp::fromAnyPtr<MLMEPollConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEPollConfirm'", field);
    }
}

Register_Class(MLMEResetRequest)

MLMEResetRequest::MLMEResetRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEResetRequest::MLMEResetRequest(const MLMEResetRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEResetRequest::~MLMEResetRequest()
{
}

MLMEResetRequest& MLMEResetRequest::operator=(const MLMEResetRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEResetRequest::copy(const MLMEResetRequest& other)
{
    this->setDefaultPIB = other.setDefaultPIB;
}

void MLMEResetRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->setDefaultPIB);
}

void MLMEResetRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->setDefaultPIB);
}

bool MLMEResetRequest::getSetDefaultPIB() const
{
    return this->setDefaultPIB;
}

void MLMEResetRequest::setSetDefaultPIB(bool setDefaultPIB)
{
    this->setDefaultPIB = setDefaultPIB;
}

class MLMEResetRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_setDefaultPIB,
    };
  public:
    MLMEResetRequestDescriptor();
    virtual ~MLMEResetRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEResetRequestDescriptor)

MLMEResetRequestDescriptor::MLMEResetRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEResetRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEResetRequestDescriptor::~MLMEResetRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEResetRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEResetRequest *>(obj)!=nullptr;
}

const char **MLMEResetRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEResetRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEResetRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int MLMEResetRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_setDefaultPIB
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MLMEResetRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "setDefaultPIB",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MLMEResetRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "setDefaultPIB") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEResetRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_setDefaultPIB
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEResetRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMEResetRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMEResetRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEResetRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEResetRequest'", field);
    }
}

const char *MLMEResetRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEResetRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_setDefaultPIB: return bool2string(pp->getSetDefaultPIB());
        default: return "";
    }
}

void MLMEResetRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_setDefaultPIB: pp->setSetDefaultPIB(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEResetRequest'", field);
    }
}

omnetpp::cValue MLMEResetRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_setDefaultPIB: return pp->getSetDefaultPIB();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEResetRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEResetRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_setDefaultPIB: pp->setSetDefaultPIB(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEResetRequest'", field);
    }
}

const char *MLMEResetRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEResetRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEResetRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetRequest *pp = omnetpp::fromAnyPtr<MLMEResetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEResetRequest'", field);
    }
}

Register_Class(MLMEResetConfirm)

MLMEResetConfirm::MLMEResetConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEResetConfirm::MLMEResetConfirm(const MLMEResetConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEResetConfirm::~MLMEResetConfirm()
{
}

MLMEResetConfirm& MLMEResetConfirm::operator=(const MLMEResetConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEResetConfirm::copy(const MLMEResetConfirm& other)
{
    this->status = other.status;
}

void MLMEResetConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void MLMEResetConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

macStatus_t MLMEResetConfirm::getStatus() const
{
    return this->status;
}

void MLMEResetConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

class MLMEResetConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    MLMEResetConfirmDescriptor();
    virtual ~MLMEResetConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEResetConfirmDescriptor)

MLMEResetConfirmDescriptor::MLMEResetConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEResetConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEResetConfirmDescriptor::~MLMEResetConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEResetConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEResetConfirm *>(obj)!=nullptr;
}

const char **MLMEResetConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEResetConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEResetConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int MLMEResetConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MLMEResetConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MLMEResetConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEResetConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEResetConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEResetConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEResetConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEResetConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEResetConfirm'", field);
    }
}

const char *MLMEResetConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEResetConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        default: return "";
    }
}

void MLMEResetConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEResetConfirm'", field);
    }
}

omnetpp::cValue MLMEResetConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEResetConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEResetConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEResetConfirm'", field);
    }
}

const char *MLMEResetConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEResetConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEResetConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEResetConfirm *pp = omnetpp::fromAnyPtr<MLMEResetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEResetConfirm'", field);
    }
}

Register_Class(MLMERxEnableRequest)

MLMERxEnableRequest::MLMERxEnableRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMERxEnableRequest::MLMERxEnableRequest(const MLMERxEnableRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMERxEnableRequest::~MLMERxEnableRequest()
{
}

MLMERxEnableRequest& MLMERxEnableRequest::operator=(const MLMERxEnableRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMERxEnableRequest::copy(const MLMERxEnableRequest& other)
{
    this->deferPermit = other.deferPermit;
    this->rxOnTime = other.rxOnTime;
    this->rxOnDuration = other.rxOnDuration;
}

void MLMERxEnableRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->deferPermit);
    doParsimPacking(b,this->rxOnTime);
    doParsimPacking(b,this->rxOnDuration);
}

void MLMERxEnableRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->deferPermit);
    doParsimUnpacking(b,this->rxOnTime);
    doParsimUnpacking(b,this->rxOnDuration);
}

bool MLMERxEnableRequest::getDeferPermit() const
{
    return this->deferPermit;
}

void MLMERxEnableRequest::setDeferPermit(bool deferPermit)
{
    this->deferPermit = deferPermit;
}

uint32_t MLMERxEnableRequest::getRxOnTime() const
{
    return this->rxOnTime;
}

void MLMERxEnableRequest::setRxOnTime(uint32_t rxOnTime)
{
    this->rxOnTime = rxOnTime;
}

uint32_t MLMERxEnableRequest::getRxOnDuration() const
{
    return this->rxOnDuration;
}

void MLMERxEnableRequest::setRxOnDuration(uint32_t rxOnDuration)
{
    this->rxOnDuration = rxOnDuration;
}

class MLMERxEnableRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_deferPermit,
        FIELD_rxOnTime,
        FIELD_rxOnDuration,
    };
  public:
    MLMERxEnableRequestDescriptor();
    virtual ~MLMERxEnableRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMERxEnableRequestDescriptor)

MLMERxEnableRequestDescriptor::MLMERxEnableRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMERxEnableRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMERxEnableRequestDescriptor::~MLMERxEnableRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMERxEnableRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMERxEnableRequest *>(obj)!=nullptr;
}

const char **MLMERxEnableRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMERxEnableRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMERxEnableRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MLMERxEnableRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_deferPermit
        FD_ISEDITABLE,    // FIELD_rxOnTime
        FD_ISEDITABLE,    // FIELD_rxOnDuration
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MLMERxEnableRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "deferPermit",
        "rxOnTime",
        "rxOnDuration",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MLMERxEnableRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "deferPermit") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "rxOnTime") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "rxOnDuration") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMERxEnableRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_deferPermit
        "uint32_t",    // FIELD_rxOnTime
        "uint32_t",    // FIELD_rxOnDuration
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMERxEnableRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMERxEnableRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMERxEnableRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMERxEnableRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMERxEnableRequest'", field);
    }
}

const char *MLMERxEnableRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMERxEnableRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deferPermit: return bool2string(pp->getDeferPermit());
        case FIELD_rxOnTime: return ulong2string(pp->getRxOnTime());
        case FIELD_rxOnDuration: return ulong2string(pp->getRxOnDuration());
        default: return "";
    }
}

void MLMERxEnableRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deferPermit: pp->setDeferPermit(string2bool(value)); break;
        case FIELD_rxOnTime: pp->setRxOnTime(string2ulong(value)); break;
        case FIELD_rxOnDuration: pp->setRxOnDuration(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMERxEnableRequest'", field);
    }
}

omnetpp::cValue MLMERxEnableRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deferPermit: return pp->getDeferPermit();
        case FIELD_rxOnTime: return (omnetpp::intval_t)(pp->getRxOnTime());
        case FIELD_rxOnDuration: return (omnetpp::intval_t)(pp->getRxOnDuration());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMERxEnableRequest' as cValue -- field index out of range?", field);
    }
}

void MLMERxEnableRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        case FIELD_deferPermit: pp->setDeferPermit(value.boolValue()); break;
        case FIELD_rxOnTime: pp->setRxOnTime(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_rxOnDuration: pp->setRxOnDuration(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMERxEnableRequest'", field);
    }
}

const char *MLMERxEnableRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMERxEnableRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMERxEnableRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableRequest *pp = omnetpp::fromAnyPtr<MLMERxEnableRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMERxEnableRequest'", field);
    }
}

Register_Class(MLMERxEnableConfirm)

MLMERxEnableConfirm::MLMERxEnableConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMERxEnableConfirm::MLMERxEnableConfirm(const MLMERxEnableConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMERxEnableConfirm::~MLMERxEnableConfirm()
{
}

MLMERxEnableConfirm& MLMERxEnableConfirm::operator=(const MLMERxEnableConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMERxEnableConfirm::copy(const MLMERxEnableConfirm& other)
{
    this->status = other.status;
}

void MLMERxEnableConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void MLMERxEnableConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

macStatus_t MLMERxEnableConfirm::getStatus() const
{
    return this->status;
}

void MLMERxEnableConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

class MLMERxEnableConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    MLMERxEnableConfirmDescriptor();
    virtual ~MLMERxEnableConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMERxEnableConfirmDescriptor)

MLMERxEnableConfirmDescriptor::MLMERxEnableConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMERxEnableConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMERxEnableConfirmDescriptor::~MLMERxEnableConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMERxEnableConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMERxEnableConfirm *>(obj)!=nullptr;
}

const char **MLMERxEnableConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMERxEnableConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMERxEnableConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int MLMERxEnableConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MLMERxEnableConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MLMERxEnableConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMERxEnableConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMERxEnableConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMERxEnableConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMERxEnableConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMERxEnableConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMERxEnableConfirm'", field);
    }
}

const char *MLMERxEnableConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMERxEnableConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        default: return "";
    }
}

void MLMERxEnableConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMERxEnableConfirm'", field);
    }
}

omnetpp::cValue MLMERxEnableConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMERxEnableConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMERxEnableConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMERxEnableConfirm'", field);
    }
}

const char *MLMERxEnableConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMERxEnableConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMERxEnableConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMERxEnableConfirm *pp = omnetpp::fromAnyPtr<MLMERxEnableConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMERxEnableConfirm'", field);
    }
}

Register_Class(MLMEScanRequest)

MLMEScanRequest::MLMEScanRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEScanRequest::MLMEScanRequest(const MLMEScanRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEScanRequest::~MLMEScanRequest()
{
}

MLMEScanRequest& MLMEScanRequest::operator=(const MLMEScanRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEScanRequest::copy(const MLMEScanRequest& other)
{
    this->scanType = other.scanType;
    this->scanChannels = other.scanChannels;
    this->scanDuration = other.scanDuration;
    this->securityLevel = other.securityLevel;
    this->colorScan = other.colorScan;
}

void MLMEScanRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->scanType);
    doParsimPacking(b,this->scanChannels);
    doParsimPacking(b,this->scanDuration);
    doParsimPacking(b,this->securityLevel);
    doParsimPacking(b,this->colorScan);
}

void MLMEScanRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->scanType);
    doParsimUnpacking(b,this->scanChannels);
    doParsimUnpacking(b,this->scanDuration);
    doParsimUnpacking(b,this->securityLevel);
    doParsimUnpacking(b,this->colorScan);
}

scanType_t MLMEScanRequest::getScanType() const
{
    return this->scanType;
}

void MLMEScanRequest::setScanType(scanType_t scanType)
{
    this->scanType = scanType;
}

uint8_t MLMEScanRequest::getScanChannels() const
{
    return this->scanChannels;
}

void MLMEScanRequest::setScanChannels(uint8_t scanChannels)
{
    this->scanChannels = scanChannels;
}

uint8_t MLMEScanRequest::getScanDuration() const
{
    return this->scanDuration;
}

void MLMEScanRequest::setScanDuration(uint8_t scanDuration)
{
    this->scanDuration = scanDuration;
}

uint8_t MLMEScanRequest::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMEScanRequest::setSecurityLevel(uint8_t securityLevel)
{
    this->securityLevel = securityLevel;
}

bool MLMEScanRequest::getColorScan() const
{
    return this->colorScan;
}

void MLMEScanRequest::setColorScan(bool colorScan)
{
    this->colorScan = colorScan;
}

class MLMEScanRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_scanType,
        FIELD_scanChannels,
        FIELD_scanDuration,
        FIELD_securityLevel,
        FIELD_colorScan,
    };
  public:
    MLMEScanRequestDescriptor();
    virtual ~MLMEScanRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEScanRequestDescriptor)

MLMEScanRequestDescriptor::MLMEScanRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEScanRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEScanRequestDescriptor::~MLMEScanRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEScanRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEScanRequest *>(obj)!=nullptr;
}

const char **MLMEScanRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEScanRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEScanRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int MLMEScanRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_scanType
        FD_ISEDITABLE,    // FIELD_scanChannels
        FD_ISEDITABLE,    // FIELD_scanDuration
        FD_ISEDITABLE,    // FIELD_securityLevel
        FD_ISEDITABLE,    // FIELD_colorScan
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *MLMEScanRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "scanType",
        "scanChannels",
        "scanDuration",
        "securityLevel",
        "colorScan",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int MLMEScanRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "scanType") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "scanChannels") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "scanDuration") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "colorScan") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEScanRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "scanType_t",    // FIELD_scanType
        "uint8_t",    // FIELD_scanChannels
        "uint8_t",    // FIELD_scanDuration
        "uint8_t",    // FIELD_securityLevel
        "bool",    // FIELD_colorScan
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEScanRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_scanType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEScanRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_scanType:
            if (!strcmp(propertyName, "enum")) return "scanType_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEScanRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEScanRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEScanRequest'", field);
    }
}

const char *MLMEScanRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEScanRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        case FIELD_scanType: return enum2string(pp->getScanType(), "scanType_t");
        case FIELD_scanChannels: return ulong2string(pp->getScanChannels());
        case FIELD_scanDuration: return ulong2string(pp->getScanDuration());
        case FIELD_securityLevel: return ulong2string(pp->getSecurityLevel());
        case FIELD_colorScan: return bool2string(pp->getColorScan());
        default: return "";
    }
}

void MLMEScanRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        case FIELD_scanType: pp->setScanType((scanType_t)string2enum(value, "scanType_t")); break;
        case FIELD_scanChannels: pp->setScanChannels(string2ulong(value)); break;
        case FIELD_scanDuration: pp->setScanDuration(string2ulong(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2ulong(value)); break;
        case FIELD_colorScan: pp->setColorScan(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEScanRequest'", field);
    }
}

omnetpp::cValue MLMEScanRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        case FIELD_scanType: return static_cast<int>(pp->getScanType());
        case FIELD_scanChannels: return (omnetpp::intval_t)(pp->getScanChannels());
        case FIELD_scanDuration: return (omnetpp::intval_t)(pp->getScanDuration());
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->getSecurityLevel());
        case FIELD_colorScan: return pp->getColorScan();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEScanRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEScanRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        case FIELD_scanType: pp->setScanType(static_cast<scanType_t>(value.intValue())); break;
        case FIELD_scanChannels: pp->setScanChannels(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_scanDuration: pp->setScanDuration(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_colorScan: pp->setColorScan(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEScanRequest'", field);
    }
}

const char *MLMEScanRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEScanRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEScanRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanRequest *pp = omnetpp::fromAnyPtr<MLMEScanRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEScanRequest'", field);
    }
}

Register_Class(MLMEScanConfirm)

MLMEScanConfirm::MLMEScanConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEScanConfirm::MLMEScanConfirm(const MLMEScanConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEScanConfirm::~MLMEScanConfirm()
{
    delete [] this->OWPANDescriptorList;
}

MLMEScanConfirm& MLMEScanConfirm::operator=(const MLMEScanConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEScanConfirm::copy(const MLMEScanConfirm& other)
{
    this->status = other.status;
    this->scanType = other.scanType;
    this->unscannedChannels = other.unscannedChannels;
    this->resultListSize = other.resultListSize;
    delete [] this->OWPANDescriptorList;
    this->OWPANDescriptorList = (other.OWPANDescriptorList_arraysize==0) ? nullptr : new uint8_t[other.OWPANDescriptorList_arraysize];
    OWPANDescriptorList_arraysize = other.OWPANDescriptorList_arraysize;
    for (size_t i = 0; i < OWPANDescriptorList_arraysize; i++) {
        this->OWPANDescriptorList[i] = other.OWPANDescriptorList[i];
    }
}

void MLMEScanConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->scanType);
    doParsimPacking(b,this->unscannedChannels);
    doParsimPacking(b,this->resultListSize);
    b->pack(OWPANDescriptorList_arraysize);
    doParsimArrayPacking(b,this->OWPANDescriptorList,OWPANDescriptorList_arraysize);
}

void MLMEScanConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->scanType);
    doParsimUnpacking(b,this->unscannedChannels);
    doParsimUnpacking(b,this->resultListSize);
    delete [] this->OWPANDescriptorList;
    b->unpack(OWPANDescriptorList_arraysize);
    if (OWPANDescriptorList_arraysize == 0) {
        this->OWPANDescriptorList = nullptr;
    } else {
        this->OWPANDescriptorList = new uint8_t[OWPANDescriptorList_arraysize];
        doParsimArrayUnpacking(b,this->OWPANDescriptorList,OWPANDescriptorList_arraysize);
    }
}

macStatus_t MLMEScanConfirm::getStatus() const
{
    return this->status;
}

void MLMEScanConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

int MLMEScanConfirm::getScanType() const
{
    return this->scanType;
}

void MLMEScanConfirm::setScanType(int scanType)
{
    this->scanType = scanType;
}

uint8_t MLMEScanConfirm::getUnscannedChannels() const
{
    return this->unscannedChannels;
}

void MLMEScanConfirm::setUnscannedChannels(uint8_t unscannedChannels)
{
    this->unscannedChannels = unscannedChannels;
}

uint16_t MLMEScanConfirm::getResultListSize() const
{
    return this->resultListSize;
}

void MLMEScanConfirm::setResultListSize(uint16_t resultListSize)
{
    this->resultListSize = resultListSize;
}

size_t MLMEScanConfirm::getOWPANDescriptorListArraySize() const
{
    return OWPANDescriptorList_arraysize;
}

uint8_t MLMEScanConfirm::getOWPANDescriptorList(size_t k) const
{
    if (k >= OWPANDescriptorList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)OWPANDescriptorList_arraysize, (unsigned long)k);
    return this->OWPANDescriptorList[k];
}

void MLMEScanConfirm::setOWPANDescriptorListArraySize(size_t newSize)
{
    uint8_t *OWPANDescriptorList2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = OWPANDescriptorList_arraysize < newSize ? OWPANDescriptorList_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        OWPANDescriptorList2[i] = this->OWPANDescriptorList[i];
    for (size_t i = minSize; i < newSize; i++)
        OWPANDescriptorList2[i] = 0;
    delete [] this->OWPANDescriptorList;
    this->OWPANDescriptorList = OWPANDescriptorList2;
    OWPANDescriptorList_arraysize = newSize;
}

void MLMEScanConfirm::setOWPANDescriptorList(size_t k, uint8_t OWPANDescriptorList)
{
    if (k >= OWPANDescriptorList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)OWPANDescriptorList_arraysize, (unsigned long)k);
    this->OWPANDescriptorList[k] = OWPANDescriptorList;
}

void MLMEScanConfirm::insertOWPANDescriptorList(size_t k, uint8_t OWPANDescriptorList)
{
    if (k > OWPANDescriptorList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)OWPANDescriptorList_arraysize, (unsigned long)k);
    size_t newSize = OWPANDescriptorList_arraysize + 1;
    uint8_t *OWPANDescriptorList2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        OWPANDescriptorList2[i] = this->OWPANDescriptorList[i];
    OWPANDescriptorList2[k] = OWPANDescriptorList;
    for (i = k + 1; i < newSize; i++)
        OWPANDescriptorList2[i] = this->OWPANDescriptorList[i-1];
    delete [] this->OWPANDescriptorList;
    this->OWPANDescriptorList = OWPANDescriptorList2;
    OWPANDescriptorList_arraysize = newSize;
}

void MLMEScanConfirm::appendOWPANDescriptorList(uint8_t OWPANDescriptorList)
{
    insertOWPANDescriptorList(OWPANDescriptorList_arraysize, OWPANDescriptorList);
}

void MLMEScanConfirm::eraseOWPANDescriptorList(size_t k)
{
    if (k >= OWPANDescriptorList_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)OWPANDescriptorList_arraysize, (unsigned long)k);
    size_t newSize = OWPANDescriptorList_arraysize - 1;
    uint8_t *OWPANDescriptorList2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        OWPANDescriptorList2[i] = this->OWPANDescriptorList[i];
    for (i = k; i < newSize; i++)
        OWPANDescriptorList2[i] = this->OWPANDescriptorList[i+1];
    delete [] this->OWPANDescriptorList;
    this->OWPANDescriptorList = OWPANDescriptorList2;
    OWPANDescriptorList_arraysize = newSize;
}

class MLMEScanConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
        FIELD_scanType,
        FIELD_unscannedChannels,
        FIELD_resultListSize,
        FIELD_OWPANDescriptorList,
    };
  public:
    MLMEScanConfirmDescriptor();
    virtual ~MLMEScanConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEScanConfirmDescriptor)

MLMEScanConfirmDescriptor::MLMEScanConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEScanConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEScanConfirmDescriptor::~MLMEScanConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEScanConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEScanConfirm *>(obj)!=nullptr;
}

const char **MLMEScanConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEScanConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEScanConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int MLMEScanConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_scanType
        FD_ISEDITABLE,    // FIELD_unscannedChannels
        FD_ISEDITABLE,    // FIELD_resultListSize
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_OWPANDescriptorList
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *MLMEScanConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "scanType",
        "unscannedChannels",
        "resultListSize",
        "OWPANDescriptorList",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int MLMEScanConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "scanType") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "unscannedChannels") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "resultListSize") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "OWPANDescriptorList") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEScanConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
        "int",    // FIELD_scanType
        "uint8_t",    // FIELD_unscannedChannels
        "uint16_t",    // FIELD_resultListSize
        "uint8_t",    // FIELD_OWPANDescriptorList
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEScanConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEScanConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEScanConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANDescriptorList: return pp->getOWPANDescriptorListArraySize();
        default: return 0;
    }
}

void MLMEScanConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANDescriptorList: pp->setOWPANDescriptorListArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEScanConfirm'", field);
    }
}

const char *MLMEScanConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEScanConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        case FIELD_scanType: return long2string(pp->getScanType());
        case FIELD_unscannedChannels: return ulong2string(pp->getUnscannedChannels());
        case FIELD_resultListSize: return ulong2string(pp->getResultListSize());
        case FIELD_OWPANDescriptorList: return ulong2string(pp->getOWPANDescriptorList(i));
        default: return "";
    }
}

void MLMEScanConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        case FIELD_scanType: pp->setScanType(string2long(value)); break;
        case FIELD_unscannedChannels: pp->setUnscannedChannels(string2ulong(value)); break;
        case FIELD_resultListSize: pp->setResultListSize(string2ulong(value)); break;
        case FIELD_OWPANDescriptorList: pp->setOWPANDescriptorList(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEScanConfirm'", field);
    }
}

omnetpp::cValue MLMEScanConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_scanType: return pp->getScanType();
        case FIELD_unscannedChannels: return (omnetpp::intval_t)(pp->getUnscannedChannels());
        case FIELD_resultListSize: return (omnetpp::intval_t)(pp->getResultListSize());
        case FIELD_OWPANDescriptorList: return (omnetpp::intval_t)(pp->getOWPANDescriptorList(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEScanConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEScanConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        case FIELD_scanType: pp->setScanType(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_unscannedChannels: pp->setUnscannedChannels(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_resultListSize: pp->setResultListSize(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_OWPANDescriptorList: pp->setOWPANDescriptorList(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEScanConfirm'", field);
    }
}

const char *MLMEScanConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEScanConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEScanConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEScanConfirm *pp = omnetpp::fromAnyPtr<MLMEScanConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEScanConfirm'", field);
    }
}

Register_Class(MLMESetRequest)

MLMESetRequest::MLMESetRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMESetRequest::MLMESetRequest(const MLMESetRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMESetRequest::~MLMESetRequest()
{
}

MLMESetRequest& MLMESetRequest::operator=(const MLMESetRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMESetRequest::copy(const MLMESetRequest& other)
{
    this->PIBAttribute = other.PIBAttribute;
    this->PIBAttributeIndex = other.PIBAttributeIndex;
    this->PIBAttributeValue = other.PIBAttributeValue;
}

void MLMESetRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->PIBAttribute);
    doParsimPacking(b,this->PIBAttributeIndex);
    doParsimPacking(b,this->PIBAttributeValue);
}

void MLMESetRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->PIBAttribute);
    doParsimUnpacking(b,this->PIBAttributeIndex);
    doParsimUnpacking(b,this->PIBAttributeValue);
}

PIBAttribute_t MLMESetRequest::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void MLMESetRequest::setPIBAttribute(PIBAttribute_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

uint8_t MLMESetRequest::getPIBAttributeIndex() const
{
    return this->PIBAttributeIndex;
}

void MLMESetRequest::setPIBAttributeIndex(uint8_t PIBAttributeIndex)
{
    this->PIBAttributeIndex = PIBAttributeIndex;
}

uint64_t MLMESetRequest::getPIBAttributeValue() const
{
    return this->PIBAttributeValue;
}

void MLMESetRequest::setPIBAttributeValue(uint64_t PIBAttributeValue)
{
    this->PIBAttributeValue = PIBAttributeValue;
}

class MLMESetRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_PIBAttribute,
        FIELD_PIBAttributeIndex,
        FIELD_PIBAttributeValue,
    };
  public:
    MLMESetRequestDescriptor();
    virtual ~MLMESetRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMESetRequestDescriptor)

MLMESetRequestDescriptor::MLMESetRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMESetRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMESetRequestDescriptor::~MLMESetRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMESetRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMESetRequest *>(obj)!=nullptr;
}

const char **MLMESetRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMESetRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMESetRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MLMESetRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_PIBAttribute
        FD_ISEDITABLE,    // FIELD_PIBAttributeIndex
        FD_ISEDITABLE,    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MLMESetRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "PIBAttribute",
        "PIBAttributeIndex",
        "PIBAttributeValue",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MLMESetRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "PIBAttributeIndex") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "PIBAttributeValue") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMESetRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "PIBAttribute_t",    // FIELD_PIBAttribute
        "uint8_t",    // FIELD_PIBAttributeIndex
        "uint64_t",    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMESetRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_PIBAttribute: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMESetRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_PIBAttribute:
            if (!strcmp(propertyName, "enum")) return "PIBAttribute_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMESetRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMESetRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMESetRequest'", field);
    }
}

const char *MLMESetRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMESetRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return enum2string(pp->getPIBAttribute(), "PIBAttribute_t");
        case FIELD_PIBAttributeIndex: return ulong2string(pp->getPIBAttributeIndex());
        case FIELD_PIBAttributeValue: return uint642string(pp->getPIBAttributeValue());
        default: return "";
    }
}

void MLMESetRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute((PIBAttribute_t)string2enum(value, "PIBAttribute_t")); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(string2ulong(value)); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(string2uint64(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESetRequest'", field);
    }
}

omnetpp::cValue MLMESetRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return static_cast<int>(pp->getPIBAttribute());
        case FIELD_PIBAttributeIndex: return (omnetpp::intval_t)(pp->getPIBAttributeIndex());
        case FIELD_PIBAttributeValue: return (omnetpp::intval_t)(pp->getPIBAttributeValue());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMESetRequest' as cValue -- field index out of range?", field);
    }
}

void MLMESetRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute(static_cast<PIBAttribute_t>(value.intValue())); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESetRequest'", field);
    }
}

const char *MLMESetRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMESetRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMESetRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetRequest *pp = omnetpp::fromAnyPtr<MLMESetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESetRequest'", field);
    }
}

Register_Class(MLMESetConfirm)

MLMESetConfirm::MLMESetConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMESetConfirm::MLMESetConfirm(const MLMESetConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMESetConfirm::~MLMESetConfirm()
{
}

MLMESetConfirm& MLMESetConfirm::operator=(const MLMESetConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMESetConfirm::copy(const MLMESetConfirm& other)
{
    this->status = other.status;
    this->PIBAttribute = other.PIBAttribute;
    this->PIBAttributeIndex = other.PIBAttributeIndex;
}

void MLMESetConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->PIBAttribute);
    doParsimPacking(b,this->PIBAttributeIndex);
}

void MLMESetConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->PIBAttribute);
    doParsimUnpacking(b,this->PIBAttributeIndex);
}

macStatus_t MLMESetConfirm::getStatus() const
{
    return this->status;
}

void MLMESetConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

PIBAttribute_t MLMESetConfirm::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void MLMESetConfirm::setPIBAttribute(PIBAttribute_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

uint8_t MLMESetConfirm::getPIBAttributeIndex() const
{
    return this->PIBAttributeIndex;
}

void MLMESetConfirm::setPIBAttributeIndex(uint8_t PIBAttributeIndex)
{
    this->PIBAttributeIndex = PIBAttributeIndex;
}

class MLMESetConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
        FIELD_PIBAttribute,
        FIELD_PIBAttributeIndex,
    };
  public:
    MLMESetConfirmDescriptor();
    virtual ~MLMESetConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMESetConfirmDescriptor)

MLMESetConfirmDescriptor::MLMESetConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMESetConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMESetConfirmDescriptor::~MLMESetConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMESetConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMESetConfirm *>(obj)!=nullptr;
}

const char **MLMESetConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMESetConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMESetConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MLMESetConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
        FD_ISEDITABLE,    // FIELD_PIBAttribute
        FD_ISEDITABLE,    // FIELD_PIBAttributeIndex
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MLMESetConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "PIBAttribute",
        "PIBAttributeIndex",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MLMESetConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "PIBAttributeIndex") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMESetConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
        "PIBAttribute_t",    // FIELD_PIBAttribute
        "uint8_t",    // FIELD_PIBAttributeIndex
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMESetConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_PIBAttribute: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMESetConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        case FIELD_PIBAttribute:
            if (!strcmp(propertyName, "enum")) return "PIBAttribute_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMESetConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMESetConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMESetConfirm'", field);
    }
}

const char *MLMESetConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMESetConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        case FIELD_PIBAttribute: return enum2string(pp->getPIBAttribute(), "PIBAttribute_t");
        case FIELD_PIBAttributeIndex: return ulong2string(pp->getPIBAttributeIndex());
        default: return "";
    }
}

void MLMESetConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute((PIBAttribute_t)string2enum(value, "PIBAttribute_t")); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESetConfirm'", field);
    }
}

omnetpp::cValue MLMESetConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_PIBAttribute: return static_cast<int>(pp->getPIBAttribute());
        case FIELD_PIBAttributeIndex: return (omnetpp::intval_t)(pp->getPIBAttributeIndex());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMESetConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMESetConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute(static_cast<PIBAttribute_t>(value.intValue())); break;
        case FIELD_PIBAttributeIndex: pp->setPIBAttributeIndex(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESetConfirm'", field);
    }
}

const char *MLMESetConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMESetConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMESetConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESetConfirm *pp = omnetpp::fromAnyPtr<MLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESetConfirm'", field);
    }
}

Register_Class(MLMEStartRequest)

MLMEStartRequest::MLMEStartRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEStartRequest::MLMEStartRequest(const MLMEStartRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEStartRequest::~MLMEStartRequest()
{
}

MLMEStartRequest& MLMEStartRequest::operator=(const MLMEStartRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEStartRequest::copy(const MLMEStartRequest& other)
{
    this->OWPANId = other.OWPANId;
    this->logicalChannel = other.logicalChannel;
    this->startTime = other.startTime;
    this->beaconOrder = other.beaconOrder;
    this->superframeOrder = other.superframeOrder;
    this->OWPANCoordinator = other.OWPANCoordinator;
    this->coordRealignment = other.coordRealignment;
    this->coordRealingmentSecurityLevel = other.coordRealingmentSecurityLevel;
    this->coordBeaconSecurityLevel = other.coordBeaconSecurityLevel;
}

void MLMEStartRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->OWPANId);
    doParsimPacking(b,this->logicalChannel);
    doParsimPacking(b,this->startTime);
    doParsimPacking(b,this->beaconOrder);
    doParsimPacking(b,this->superframeOrder);
    doParsimPacking(b,this->OWPANCoordinator);
    doParsimPacking(b,this->coordRealignment);
    doParsimPacking(b,this->coordRealingmentSecurityLevel);
    doParsimPacking(b,this->coordBeaconSecurityLevel);
}

void MLMEStartRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->OWPANId);
    doParsimUnpacking(b,this->logicalChannel);
    doParsimUnpacking(b,this->startTime);
    doParsimUnpacking(b,this->beaconOrder);
    doParsimUnpacking(b,this->superframeOrder);
    doParsimUnpacking(b,this->OWPANCoordinator);
    doParsimUnpacking(b,this->coordRealignment);
    doParsimUnpacking(b,this->coordRealingmentSecurityLevel);
    doParsimUnpacking(b,this->coordBeaconSecurityLevel);
}

uint16_t MLMEStartRequest::getOWPANId() const
{
    return this->OWPANId;
}

void MLMEStartRequest::setOWPANId(uint16_t OWPANId)
{
    this->OWPANId = OWPANId;
}

opticalChannel_t MLMEStartRequest::getLogicalChannel() const
{
    return this->logicalChannel;
}

void MLMEStartRequest::setLogicalChannel(opticalChannel_t logicalChannel)
{
    this->logicalChannel = logicalChannel;
}

uint32_t MLMEStartRequest::getStartTime() const
{
    return this->startTime;
}

void MLMEStartRequest::setStartTime(uint32_t startTime)
{
    this->startTime = startTime;
}

uint8_t MLMEStartRequest::getBeaconOrder() const
{
    return this->beaconOrder;
}

void MLMEStartRequest::setBeaconOrder(uint8_t beaconOrder)
{
    this->beaconOrder = beaconOrder;
}

uint8_t MLMEStartRequest::getSuperframeOrder() const
{
    return this->superframeOrder;
}

void MLMEStartRequest::setSuperframeOrder(uint8_t superframeOrder)
{
    this->superframeOrder = superframeOrder;
}

bool MLMEStartRequest::getOWPANCoordinator() const
{
    return this->OWPANCoordinator;
}

void MLMEStartRequest::setOWPANCoordinator(bool OWPANCoordinator)
{
    this->OWPANCoordinator = OWPANCoordinator;
}

bool MLMEStartRequest::getCoordRealignment() const
{
    return this->coordRealignment;
}

void MLMEStartRequest::setCoordRealignment(bool coordRealignment)
{
    this->coordRealignment = coordRealignment;
}

uint8_t MLMEStartRequest::getCoordRealingmentSecurityLevel() const
{
    return this->coordRealingmentSecurityLevel;
}

void MLMEStartRequest::setCoordRealingmentSecurityLevel(uint8_t coordRealingmentSecurityLevel)
{
    this->coordRealingmentSecurityLevel = coordRealingmentSecurityLevel;
}

uint8_t MLMEStartRequest::getCoordBeaconSecurityLevel() const
{
    return this->coordBeaconSecurityLevel;
}

void MLMEStartRequest::setCoordBeaconSecurityLevel(uint8_t coordBeaconSecurityLevel)
{
    this->coordBeaconSecurityLevel = coordBeaconSecurityLevel;
}

class MLMEStartRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_OWPANId,
        FIELD_logicalChannel,
        FIELD_startTime,
        FIELD_beaconOrder,
        FIELD_superframeOrder,
        FIELD_OWPANCoordinator,
        FIELD_coordRealignment,
        FIELD_coordRealingmentSecurityLevel,
        FIELD_coordBeaconSecurityLevel,
    };
  public:
    MLMEStartRequestDescriptor();
    virtual ~MLMEStartRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEStartRequestDescriptor)

MLMEStartRequestDescriptor::MLMEStartRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEStartRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEStartRequestDescriptor::~MLMEStartRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMEStartRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEStartRequest *>(obj)!=nullptr;
}

const char **MLMEStartRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEStartRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEStartRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 9+base->getFieldCount() : 9;
}

unsigned int MLMEStartRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_OWPANId
        FD_ISEDITABLE,    // FIELD_logicalChannel
        FD_ISEDITABLE,    // FIELD_startTime
        FD_ISEDITABLE,    // FIELD_beaconOrder
        FD_ISEDITABLE,    // FIELD_superframeOrder
        FD_ISEDITABLE,    // FIELD_OWPANCoordinator
        FD_ISEDITABLE,    // FIELD_coordRealignment
        FD_ISEDITABLE,    // FIELD_coordRealingmentSecurityLevel
        FD_ISEDITABLE,    // FIELD_coordBeaconSecurityLevel
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *MLMEStartRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "OWPANId",
        "logicalChannel",
        "startTime",
        "beaconOrder",
        "superframeOrder",
        "OWPANCoordinator",
        "coordRealignment",
        "coordRealingmentSecurityLevel",
        "coordBeaconSecurityLevel",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int MLMEStartRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "OWPANId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "logicalChannel") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "startTime") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "beaconOrder") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "superframeOrder") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "OWPANCoordinator") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "coordRealignment") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "coordRealingmentSecurityLevel") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "coordBeaconSecurityLevel") == 0) return baseIndex + 8;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEStartRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",    // FIELD_OWPANId
        "opticalChannel_t",    // FIELD_logicalChannel
        "uint32_t",    // FIELD_startTime
        "uint8_t",    // FIELD_beaconOrder
        "uint8_t",    // FIELD_superframeOrder
        "bool",    // FIELD_OWPANCoordinator
        "bool",    // FIELD_coordRealignment
        "uint8_t",    // FIELD_coordRealingmentSecurityLevel
        "uint8_t",    // FIELD_coordBeaconSecurityLevel
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEStartRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_logicalChannel: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEStartRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_logicalChannel:
            if (!strcmp(propertyName, "enum")) return "opticalChannel_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEStartRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEStartRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEStartRequest'", field);
    }
}

const char *MLMEStartRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEStartRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: return ulong2string(pp->getOWPANId());
        case FIELD_logicalChannel: return enum2string(pp->getLogicalChannel(), "opticalChannel_t");
        case FIELD_startTime: return ulong2string(pp->getStartTime());
        case FIELD_beaconOrder: return ulong2string(pp->getBeaconOrder());
        case FIELD_superframeOrder: return ulong2string(pp->getSuperframeOrder());
        case FIELD_OWPANCoordinator: return bool2string(pp->getOWPANCoordinator());
        case FIELD_coordRealignment: return bool2string(pp->getCoordRealignment());
        case FIELD_coordRealingmentSecurityLevel: return ulong2string(pp->getCoordRealingmentSecurityLevel());
        case FIELD_coordBeaconSecurityLevel: return ulong2string(pp->getCoordBeaconSecurityLevel());
        default: return "";
    }
}

void MLMEStartRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: pp->setOWPANId(string2ulong(value)); break;
        case FIELD_logicalChannel: pp->setLogicalChannel((opticalChannel_t)string2enum(value, "opticalChannel_t")); break;
        case FIELD_startTime: pp->setStartTime(string2ulong(value)); break;
        case FIELD_beaconOrder: pp->setBeaconOrder(string2ulong(value)); break;
        case FIELD_superframeOrder: pp->setSuperframeOrder(string2ulong(value)); break;
        case FIELD_OWPANCoordinator: pp->setOWPANCoordinator(string2bool(value)); break;
        case FIELD_coordRealignment: pp->setCoordRealignment(string2bool(value)); break;
        case FIELD_coordRealingmentSecurityLevel: pp->setCoordRealingmentSecurityLevel(string2ulong(value)); break;
        case FIELD_coordBeaconSecurityLevel: pp->setCoordBeaconSecurityLevel(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEStartRequest'", field);
    }
}

omnetpp::cValue MLMEStartRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: return (omnetpp::intval_t)(pp->getOWPANId());
        case FIELD_logicalChannel: return static_cast<int>(pp->getLogicalChannel());
        case FIELD_startTime: return (omnetpp::intval_t)(pp->getStartTime());
        case FIELD_beaconOrder: return (omnetpp::intval_t)(pp->getBeaconOrder());
        case FIELD_superframeOrder: return (omnetpp::intval_t)(pp->getSuperframeOrder());
        case FIELD_OWPANCoordinator: return pp->getOWPANCoordinator();
        case FIELD_coordRealignment: return pp->getCoordRealignment();
        case FIELD_coordRealingmentSecurityLevel: return (omnetpp::intval_t)(pp->getCoordRealingmentSecurityLevel());
        case FIELD_coordBeaconSecurityLevel: return (omnetpp::intval_t)(pp->getCoordBeaconSecurityLevel());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEStartRequest' as cValue -- field index out of range?", field);
    }
}

void MLMEStartRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        case FIELD_OWPANId: pp->setOWPANId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_logicalChannel: pp->setLogicalChannel(static_cast<opticalChannel_t>(value.intValue())); break;
        case FIELD_startTime: pp->setStartTime(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_beaconOrder: pp->setBeaconOrder(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_superframeOrder: pp->setSuperframeOrder(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_OWPANCoordinator: pp->setOWPANCoordinator(value.boolValue()); break;
        case FIELD_coordRealignment: pp->setCoordRealignment(value.boolValue()); break;
        case FIELD_coordRealingmentSecurityLevel: pp->setCoordRealingmentSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_coordBeaconSecurityLevel: pp->setCoordBeaconSecurityLevel(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEStartRequest'", field);
    }
}

const char *MLMEStartRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEStartRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEStartRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartRequest *pp = omnetpp::fromAnyPtr<MLMEStartRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEStartRequest'", field);
    }
}

Register_Class(MLMEStartConfirm)

MLMEStartConfirm::MLMEStartConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMEStartConfirm::MLMEStartConfirm(const MLMEStartConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMEStartConfirm::~MLMEStartConfirm()
{
}

MLMEStartConfirm& MLMEStartConfirm::operator=(const MLMEStartConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMEStartConfirm::copy(const MLMEStartConfirm& other)
{
    this->status = other.status;
}

void MLMEStartConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void MLMEStartConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

macStatus_t MLMEStartConfirm::getStatus() const
{
    return this->status;
}

void MLMEStartConfirm::setStatus(macStatus_t status)
{
    this->status = status;
}

class MLMEStartConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    MLMEStartConfirmDescriptor();
    virtual ~MLMEStartConfirmDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMEStartConfirmDescriptor)

MLMEStartConfirmDescriptor::MLMEStartConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMEStartConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMEStartConfirmDescriptor::~MLMEStartConfirmDescriptor()
{
    delete[] propertyNames;
}

bool MLMEStartConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMEStartConfirm *>(obj)!=nullptr;
}

const char **MLMEStartConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMEStartConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMEStartConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int MLMEStartConfirmDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MLMEStartConfirmDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MLMEStartConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMEStartConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "macStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMEStartConfirmDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMEStartConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "macStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMEStartConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMEStartConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMEStartConfirm'", field);
    }
}

const char *MLMEStartConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMEStartConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "macStatus_t");
        default: return "";
    }
}

void MLMEStartConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((macStatus_t)string2enum(value, "macStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEStartConfirm'", field);
    }
}

omnetpp::cValue MLMEStartConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMEStartConfirm' as cValue -- field index out of range?", field);
    }
}

void MLMEStartConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<macStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEStartConfirm'", field);
    }
}

const char *MLMEStartConfirmDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMEStartConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMEStartConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMEStartConfirm *pp = omnetpp::fromAnyPtr<MLMEStartConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMEStartConfirm'", field);
    }
}

Register_Class(MLMESyncRequest)

MLMESyncRequest::MLMESyncRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMESyncRequest::MLMESyncRequest(const MLMESyncRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMESyncRequest::~MLMESyncRequest()
{
}

MLMESyncRequest& MLMESyncRequest::operator=(const MLMESyncRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMESyncRequest::copy(const MLMESyncRequest& other)
{
    this->logicalChannel = other.logicalChannel;
    this->trackBeacon = other.trackBeacon;
}

void MLMESyncRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->logicalChannel);
    doParsimPacking(b,this->trackBeacon);
}

void MLMESyncRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->logicalChannel);
    doParsimUnpacking(b,this->trackBeacon);
}

opticalChannel_t MLMESyncRequest::getLogicalChannel() const
{
    return this->logicalChannel;
}

void MLMESyncRequest::setLogicalChannel(opticalChannel_t logicalChannel)
{
    this->logicalChannel = logicalChannel;
}

bool MLMESyncRequest::getTrackBeacon() const
{
    return this->trackBeacon;
}

void MLMESyncRequest::setTrackBeacon(bool trackBeacon)
{
    this->trackBeacon = trackBeacon;
}

class MLMESyncRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_logicalChannel,
        FIELD_trackBeacon,
    };
  public:
    MLMESyncRequestDescriptor();
    virtual ~MLMESyncRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMESyncRequestDescriptor)

MLMESyncRequestDescriptor::MLMESyncRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMESyncRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMESyncRequestDescriptor::~MLMESyncRequestDescriptor()
{
    delete[] propertyNames;
}

bool MLMESyncRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMESyncRequest *>(obj)!=nullptr;
}

const char **MLMESyncRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMESyncRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMESyncRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int MLMESyncRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_logicalChannel
        FD_ISEDITABLE,    // FIELD_trackBeacon
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *MLMESyncRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "logicalChannel",
        "trackBeacon",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int MLMESyncRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "logicalChannel") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "trackBeacon") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMESyncRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "opticalChannel_t",    // FIELD_logicalChannel
        "bool",    // FIELD_trackBeacon
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMESyncRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_logicalChannel: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *MLMESyncRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_logicalChannel:
            if (!strcmp(propertyName, "enum")) return "opticalChannel_t";
            return nullptr;
        default: return nullptr;
    }
}

int MLMESyncRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMESyncRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMESyncRequest'", field);
    }
}

const char *MLMESyncRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMESyncRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: return enum2string(pp->getLogicalChannel(), "opticalChannel_t");
        case FIELD_trackBeacon: return bool2string(pp->getTrackBeacon());
        default: return "";
    }
}

void MLMESyncRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: pp->setLogicalChannel((opticalChannel_t)string2enum(value, "opticalChannel_t")); break;
        case FIELD_trackBeacon: pp->setTrackBeacon(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESyncRequest'", field);
    }
}

omnetpp::cValue MLMESyncRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: return static_cast<int>(pp->getLogicalChannel());
        case FIELD_trackBeacon: return pp->getTrackBeacon();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMESyncRequest' as cValue -- field index out of range?", field);
    }
}

void MLMESyncRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        case FIELD_logicalChannel: pp->setLogicalChannel(static_cast<opticalChannel_t>(value.intValue())); break;
        case FIELD_trackBeacon: pp->setTrackBeacon(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESyncRequest'", field);
    }
}

const char *MLMESyncRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMESyncRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMESyncRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncRequest *pp = omnetpp::fromAnyPtr<MLMESyncRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESyncRequest'", field);
    }
}

Register_Class(MLMESyncLossIndication)

MLMESyncLossIndication::MLMESyncLossIndication(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MLMESyncLossIndication::MLMESyncLossIndication(const MLMESyncLossIndication& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MLMESyncLossIndication::~MLMESyncLossIndication()
{
}

MLMESyncLossIndication& MLMESyncLossIndication::operator=(const MLMESyncLossIndication& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MLMESyncLossIndication::copy(const MLMESyncLossIndication& other)
{
    this->lossReason = other.lossReason;
    this->OWPANId = other.OWPANId;
    this->logicalChannel = other.logicalChannel;
    this->securityLevel = other.securityLevel;
}

void MLMESyncLossIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->lossReason);
    doParsimPacking(b,this->OWPANId);
    doParsimPacking(b,this->logicalChannel);
    doParsimPacking(b,this->securityLevel);
}

void MLMESyncLossIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->lossReason);
    doParsimUnpacking(b,this->OWPANId);
    doParsimUnpacking(b,this->logicalChannel);
    doParsimUnpacking(b,this->securityLevel);
}

uint8_t MLMESyncLossIndication::getLossReason() const
{
    return this->lossReason;
}

void MLMESyncLossIndication::setLossReason(uint8_t lossReason)
{
    this->lossReason = lossReason;
}

int MLMESyncLossIndication::getOWPANId() const
{
    return this->OWPANId;
}

void MLMESyncLossIndication::setOWPANId(int OWPANId)
{
    this->OWPANId = OWPANId;
}

int MLMESyncLossIndication::getLogicalChannel() const
{
    return this->logicalChannel;
}

void MLMESyncLossIndication::setLogicalChannel(int logicalChannel)
{
    this->logicalChannel = logicalChannel;
}

int MLMESyncLossIndication::getSecurityLevel() const
{
    return this->securityLevel;
}

void MLMESyncLossIndication::setSecurityLevel(int securityLevel)
{
    this->securityLevel = securityLevel;
}

class MLMESyncLossIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_lossReason,
        FIELD_OWPANId,
        FIELD_logicalChannel,
        FIELD_securityLevel,
    };
  public:
    MLMESyncLossIndicationDescriptor();
    virtual ~MLMESyncLossIndicationDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MLMESyncLossIndicationDescriptor)

MLMESyncLossIndicationDescriptor::MLMESyncLossIndicationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MLMESyncLossIndication)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MLMESyncLossIndicationDescriptor::~MLMESyncLossIndicationDescriptor()
{
    delete[] propertyNames;
}

bool MLMESyncLossIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MLMESyncLossIndication *>(obj)!=nullptr;
}

const char **MLMESyncLossIndicationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MLMESyncLossIndicationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MLMESyncLossIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int MLMESyncLossIndicationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_lossReason
        FD_ISEDITABLE,    // FIELD_OWPANId
        FD_ISEDITABLE,    // FIELD_logicalChannel
        FD_ISEDITABLE,    // FIELD_securityLevel
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MLMESyncLossIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lossReason",
        "OWPANId",
        "logicalChannel",
        "securityLevel",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MLMESyncLossIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "lossReason") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "OWPANId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "logicalChannel") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *MLMESyncLossIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_lossReason
        "int",    // FIELD_OWPANId
        "int",    // FIELD_logicalChannel
        "int",    // FIELD_securityLevel
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MLMESyncLossIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MLMESyncLossIndicationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MLMESyncLossIndicationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MLMESyncLossIndicationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MLMESyncLossIndication'", field);
    }
}

const char *MLMESyncLossIndicationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MLMESyncLossIndicationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        case FIELD_lossReason: return ulong2string(pp->getLossReason());
        case FIELD_OWPANId: return long2string(pp->getOWPANId());
        case FIELD_logicalChannel: return long2string(pp->getLogicalChannel());
        case FIELD_securityLevel: return long2string(pp->getSecurityLevel());
        default: return "";
    }
}

void MLMESyncLossIndicationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        case FIELD_lossReason: pp->setLossReason(string2ulong(value)); break;
        case FIELD_OWPANId: pp->setOWPANId(string2long(value)); break;
        case FIELD_logicalChannel: pp->setLogicalChannel(string2long(value)); break;
        case FIELD_securityLevel: pp->setSecurityLevel(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESyncLossIndication'", field);
    }
}

omnetpp::cValue MLMESyncLossIndicationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        case FIELD_lossReason: return (omnetpp::intval_t)(pp->getLossReason());
        case FIELD_OWPANId: return pp->getOWPANId();
        case FIELD_logicalChannel: return pp->getLogicalChannel();
        case FIELD_securityLevel: return pp->getSecurityLevel();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MLMESyncLossIndication' as cValue -- field index out of range?", field);
    }
}

void MLMESyncLossIndicationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        case FIELD_lossReason: pp->setLossReason(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_OWPANId: pp->setOWPANId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_logicalChannel: pp->setLogicalChannel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_securityLevel: pp->setSecurityLevel(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESyncLossIndication'", field);
    }
}

const char *MLMESyncLossIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MLMESyncLossIndicationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MLMESyncLossIndicationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MLMESyncLossIndication *pp = omnetpp::fromAnyPtr<MLMESyncLossIndication>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MLMESyncLossIndication'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

