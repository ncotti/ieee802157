//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/phy_msgs/phy_msg.msg.
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
#include "phy_msg_m.h"

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

Register_Class(PhyMsg)

PhyMsg::PhyMsg(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

PhyMsg::PhyMsg(const PhyMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

PhyMsg::~PhyMsg()
{
    delete [] this->payload;
}

PhyMsg& PhyMsg::operator=(const PhyMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PhyMsg::copy(const PhyMsg& other)
{
    delete [] this->payload;
    this->payload = (other.payload_arraysize==0) ? nullptr : new uint8_t[other.payload_arraysize];
    payload_arraysize = other.payload_arraysize;
    for (size_t i = 0; i < payload_arraysize; i++) {
        this->payload[i] = other.payload[i];
    }
}

void PhyMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    b->pack(payload_arraysize);
    doParsimArrayPacking(b,this->payload,payload_arraysize);
}

void PhyMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    delete [] this->payload;
    b->unpack(payload_arraysize);
    if (payload_arraysize == 0) {
        this->payload = nullptr;
    } else {
        this->payload = new uint8_t[payload_arraysize];
        doParsimArrayUnpacking(b,this->payload,payload_arraysize);
    }
}

size_t PhyMsg::getPayloadArraySize() const
{
    return payload_arraysize;
}

uint8_t PhyMsg::getPayload(size_t k) const
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    return this->payload[k];
}

void PhyMsg::setPayloadArraySize(size_t newSize)
{
    uint8_t *payload2 = (newSize==0) ? nullptr : new uint8_t[newSize];
    size_t minSize = payload_arraysize < newSize ? payload_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        payload2[i] = this->payload[i];
    for (size_t i = minSize; i < newSize; i++)
        payload2[i] = 0;
    delete [] this->payload;
    this->payload = payload2;
    payload_arraysize = newSize;
}

void PhyMsg::setPayload(size_t k, uint8_t payload)
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    this->payload[k] = payload;
}

void PhyMsg::insertPayload(size_t k, uint8_t payload)
{
    if (k > payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    size_t newSize = payload_arraysize + 1;
    uint8_t *payload2 = new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        payload2[i] = this->payload[i];
    payload2[k] = payload;
    for (i = k + 1; i < newSize; i++)
        payload2[i] = this->payload[i-1];
    delete [] this->payload;
    this->payload = payload2;
    payload_arraysize = newSize;
}

void PhyMsg::appendPayload(uint8_t payload)
{
    insertPayload(payload_arraysize, payload);
}

void PhyMsg::erasePayload(size_t k)
{
    if (k >= payload_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)payload_arraysize, (unsigned long)k);
    size_t newSize = payload_arraysize - 1;
    uint8_t *payload2 = (newSize == 0) ? nullptr : new uint8_t[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        payload2[i] = this->payload[i];
    for (i = k; i < newSize; i++)
        payload2[i] = this->payload[i+1];
    delete [] this->payload;
    this->payload = payload2;
    payload_arraysize = newSize;
}

class PhyMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_payload,
    };
  public:
    PhyMsgDescriptor();
    virtual ~PhyMsgDescriptor();

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

Register_ClassDescriptor(PhyMsgDescriptor)

PhyMsgDescriptor::PhyMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PhyMsg)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

PhyMsgDescriptor::~PhyMsgDescriptor()
{
    delete[] propertyNames;
}

bool PhyMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PhyMsg *>(obj)!=nullptr;
}

const char **PhyMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PhyMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PhyMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PhyMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_payload
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PhyMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payload",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PhyMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PhyMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_payload
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PhyMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *PhyMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PhyMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_payload: return pp->getPayloadArraySize();
        default: return 0;
    }
}

void PhyMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_payload: pp->setPayloadArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PhyMsg'", field);
    }
}

const char *PhyMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PhyMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_payload: return ulong2string(pp->getPayload(i));
        default: return "";
    }
}

void PhyMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_payload: pp->setPayload(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PhyMsg'", field);
    }
}

omnetpp::cValue PhyMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_payload: return (omnetpp::intval_t)(pp->getPayload(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PhyMsg' as cValue -- field index out of range?", field);
    }
}

void PhyMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        case FIELD_payload: pp->setPayload(i,omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PhyMsg'", field);
    }
}

const char *PhyMsgDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PhyMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PhyMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PhyMsg *pp = omnetpp::fromAnyPtr<PhyMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PhyMsg'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

