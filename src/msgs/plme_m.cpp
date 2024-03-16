//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs/plme.msg.
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
#include "plme_m.h"

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

Register_Class(PLMECCARequest)

PLMECCARequest::PLMECCARequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMECCARequest::PLMECCARequest(const PLMECCARequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMECCARequest::~PLMECCARequest()
{
}

PLMECCARequest& PLMECCARequest::operator=(const PLMECCARequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMECCARequest::copy(const PLMECCARequest& other)
{
}

void PLMECCARequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
}

void PLMECCARequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
}

class PLMECCARequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    PLMECCARequestDescriptor();
    virtual ~PLMECCARequestDescriptor();

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

Register_ClassDescriptor(PLMECCARequestDescriptor)

PLMECCARequestDescriptor::PLMECCARequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMECCARequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMECCARequestDescriptor::~PLMECCARequestDescriptor()
{
    delete[] propertyNames;
}

bool PLMECCARequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMECCARequest *>(obj)!=nullptr;
}

const char **PLMECCARequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMECCARequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMECCARequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int PLMECCARequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *PLMECCARequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int PLMECCARequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *PLMECCARequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **PLMECCARequestDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMECCARequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PLMECCARequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMECCARequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMECCARequest'", field);
    }
}

const char *PLMECCARequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMECCARequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void PLMECCARequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMECCARequest'", field);
    }
}

omnetpp::cValue PLMECCARequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMECCARequest' as cValue -- field index out of range?", field);
    }
}

void PLMECCARequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMECCARequest'", field);
    }
}

const char *PLMECCARequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr PLMECCARequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMECCARequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCARequest *pp = omnetpp::fromAnyPtr<PLMECCARequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMECCARequest'", field);
    }
}

Register_Class(PLMECCAConfirm)

PLMECCAConfirm::PLMECCAConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMECCAConfirm::PLMECCAConfirm(const PLMECCAConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMECCAConfirm::~PLMECCAConfirm()
{
}

PLMECCAConfirm& PLMECCAConfirm::operator=(const PLMECCAConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMECCAConfirm::copy(const PLMECCAConfirm& other)
{
    this->status = other.status;
}

void PLMECCAConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void PLMECCAConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

phyStatus_t PLMECCAConfirm::getStatus() const
{
    return this->status;
}

void PLMECCAConfirm::setStatus(phyStatus_t status)
{
    this->status = status;
}

class PLMECCAConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    PLMECCAConfirmDescriptor();
    virtual ~PLMECCAConfirmDescriptor();

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

Register_ClassDescriptor(PLMECCAConfirmDescriptor)

PLMECCAConfirmDescriptor::PLMECCAConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMECCAConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMECCAConfirmDescriptor::~PLMECCAConfirmDescriptor()
{
    delete[] propertyNames;
}

bool PLMECCAConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMECCAConfirm *>(obj)!=nullptr;
}

const char **PLMECCAConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMECCAConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMECCAConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PLMECCAConfirmDescriptor::getFieldTypeFlags(int field) const
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

const char *PLMECCAConfirmDescriptor::getFieldName(int field) const
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

int PLMECCAConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMECCAConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "phyStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMECCAConfirmDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMECCAConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "phyStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int PLMECCAConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMECCAConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMECCAConfirm'", field);
    }
}

const char *PLMECCAConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMECCAConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "phyStatus_t");
        default: return "";
    }
}

void PLMECCAConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((phyStatus_t)string2enum(value, "phyStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMECCAConfirm'", field);
    }
}

omnetpp::cValue PLMECCAConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMECCAConfirm' as cValue -- field index out of range?", field);
    }
}

void PLMECCAConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<phyStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMECCAConfirm'", field);
    }
}

const char *PLMECCAConfirmDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMECCAConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMECCAConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMECCAConfirm *pp = omnetpp::fromAnyPtr<PLMECCAConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMECCAConfirm'", field);
    }
}

Register_Class(PLMEGetRequest)

PLMEGetRequest::PLMEGetRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMEGetRequest::PLMEGetRequest(const PLMEGetRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMEGetRequest::~PLMEGetRequest()
{
}

PLMEGetRequest& PLMEGetRequest::operator=(const PLMEGetRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMEGetRequest::copy(const PLMEGetRequest& other)
{
    this->PIBAttribute = other.PIBAttribute;
}

void PLMEGetRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->PIBAttribute);
}

void PLMEGetRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->PIBAttribute);
}

PIBAttribute_t PLMEGetRequest::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void PLMEGetRequest::setPIBAttribute(PIBAttribute_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

class PLMEGetRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_PIBAttribute,
    };
  public:
    PLMEGetRequestDescriptor();
    virtual ~PLMEGetRequestDescriptor();

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

Register_ClassDescriptor(PLMEGetRequestDescriptor)

PLMEGetRequestDescriptor::PLMEGetRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMEGetRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMEGetRequestDescriptor::~PLMEGetRequestDescriptor()
{
    delete[] propertyNames;
}

bool PLMEGetRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMEGetRequest *>(obj)!=nullptr;
}

const char **PLMEGetRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMEGetRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMEGetRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PLMEGetRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_PIBAttribute
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PLMEGetRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "PIBAttribute",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PLMEGetRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMEGetRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "PIBAttribute_t",    // FIELD_PIBAttribute
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMEGetRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMEGetRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PLMEGetRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMEGetRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMEGetRequest'", field);
    }
}

const char *PLMEGetRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMEGetRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return enum2string(pp->getPIBAttribute(), "PIBAttribute_t");
        default: return "";
    }
}

void PLMEGetRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute((PIBAttribute_t)string2enum(value, "PIBAttribute_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMEGetRequest'", field);
    }
}

omnetpp::cValue PLMEGetRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return static_cast<int>(pp->getPIBAttribute());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMEGetRequest' as cValue -- field index out of range?", field);
    }
}

void PLMEGetRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute(static_cast<PIBAttribute_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMEGetRequest'", field);
    }
}

const char *PLMEGetRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMEGetRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMEGetRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetRequest *pp = omnetpp::fromAnyPtr<PLMEGetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMEGetRequest'", field);
    }
}

Register_Class(PLMEGetConfirm)

PLMEGetConfirm::PLMEGetConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMEGetConfirm::PLMEGetConfirm(const PLMEGetConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMEGetConfirm::~PLMEGetConfirm()
{
}

PLMEGetConfirm& PLMEGetConfirm::operator=(const PLMEGetConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMEGetConfirm::copy(const PLMEGetConfirm& other)
{
    this->status = other.status;
    this->PIBAttribute = other.PIBAttribute;
    this->PIBAttributeValue = other.PIBAttributeValue;
}

void PLMEGetConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->PIBAttribute);
    doParsimPacking(b,this->PIBAttributeValue);
}

void PLMEGetConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->PIBAttribute);
    doParsimUnpacking(b,this->PIBAttributeValue);
}

phyStatus_t PLMEGetConfirm::getStatus() const
{
    return this->status;
}

void PLMEGetConfirm::setStatus(phyStatus_t status)
{
    this->status = status;
}

uint8_t PLMEGetConfirm::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void PLMEGetConfirm::setPIBAttribute(uint8_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

uint64_t PLMEGetConfirm::getPIBAttributeValue() const
{
    return this->PIBAttributeValue;
}

void PLMEGetConfirm::setPIBAttributeValue(uint64_t PIBAttributeValue)
{
    this->PIBAttributeValue = PIBAttributeValue;
}

class PLMEGetConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
        FIELD_PIBAttribute,
        FIELD_PIBAttributeValue,
    };
  public:
    PLMEGetConfirmDescriptor();
    virtual ~PLMEGetConfirmDescriptor();

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

Register_ClassDescriptor(PLMEGetConfirmDescriptor)

PLMEGetConfirmDescriptor::PLMEGetConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMEGetConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMEGetConfirmDescriptor::~PLMEGetConfirmDescriptor()
{
    delete[] propertyNames;
}

bool PLMEGetConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMEGetConfirm *>(obj)!=nullptr;
}

const char **PLMEGetConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMEGetConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMEGetConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int PLMEGetConfirmDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *PLMEGetConfirmDescriptor::getFieldName(int field) const
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
        "PIBAttributeValue",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int PLMEGetConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "PIBAttributeValue") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMEGetConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "phyStatus_t",    // FIELD_status
        "uint8_t",    // FIELD_PIBAttribute
        "uint64_t",    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMEGetConfirmDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMEGetConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "phyStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int PLMEGetConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMEGetConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMEGetConfirm'", field);
    }
}

const char *PLMEGetConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMEGetConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "phyStatus_t");
        case FIELD_PIBAttribute: return ulong2string(pp->getPIBAttribute());
        case FIELD_PIBAttributeValue: return uint642string(pp->getPIBAttributeValue());
        default: return "";
    }
}

void PLMEGetConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((phyStatus_t)string2enum(value, "phyStatus_t")); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute(string2ulong(value)); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(string2uint64(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMEGetConfirm'", field);
    }
}

omnetpp::cValue PLMEGetConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_PIBAttribute: return (omnetpp::intval_t)(pp->getPIBAttribute());
        case FIELD_PIBAttributeValue: return (omnetpp::intval_t)(pp->getPIBAttributeValue());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMEGetConfirm' as cValue -- field index out of range?", field);
    }
}

void PLMEGetConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<phyStatus_t>(value.intValue())); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMEGetConfirm'", field);
    }
}

const char *PLMEGetConfirmDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMEGetConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMEGetConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMEGetConfirm *pp = omnetpp::fromAnyPtr<PLMEGetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMEGetConfirm'", field);
    }
}

Register_Class(PLMESetRequest)

PLMESetRequest::PLMESetRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMESetRequest::PLMESetRequest(const PLMESetRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMESetRequest::~PLMESetRequest()
{
}

PLMESetRequest& PLMESetRequest::operator=(const PLMESetRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMESetRequest::copy(const PLMESetRequest& other)
{
    this->PIBAttribute = other.PIBAttribute;
    this->PIBAttributeValue = other.PIBAttributeValue;
}

void PLMESetRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->PIBAttribute);
    doParsimPacking(b,this->PIBAttributeValue);
}

void PLMESetRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->PIBAttribute);
    doParsimUnpacking(b,this->PIBAttributeValue);
}

PIBAttribute_t PLMESetRequest::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void PLMESetRequest::setPIBAttribute(PIBAttribute_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

uint64_t PLMESetRequest::getPIBAttributeValue() const
{
    return this->PIBAttributeValue;
}

void PLMESetRequest::setPIBAttributeValue(uint64_t PIBAttributeValue)
{
    this->PIBAttributeValue = PIBAttributeValue;
}

class PLMESetRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_PIBAttribute,
        FIELD_PIBAttributeValue,
    };
  public:
    PLMESetRequestDescriptor();
    virtual ~PLMESetRequestDescriptor();

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

Register_ClassDescriptor(PLMESetRequestDescriptor)

PLMESetRequestDescriptor::PLMESetRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMESetRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMESetRequestDescriptor::~PLMESetRequestDescriptor()
{
    delete[] propertyNames;
}

bool PLMESetRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMESetRequest *>(obj)!=nullptr;
}

const char **PLMESetRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMESetRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMESetRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int PLMESetRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_PIBAttribute
        FD_ISEDITABLE,    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *PLMESetRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "PIBAttribute",
        "PIBAttributeValue",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int PLMESetRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "PIBAttributeValue") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMESetRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "PIBAttribute_t",    // FIELD_PIBAttribute
        "uint64_t",    // FIELD_PIBAttributeValue
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMESetRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMESetRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PLMESetRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMESetRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMESetRequest'", field);
    }
}

const char *PLMESetRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMESetRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return enum2string(pp->getPIBAttribute(), "PIBAttribute_t");
        case FIELD_PIBAttributeValue: return uint642string(pp->getPIBAttributeValue());
        default: return "";
    }
}

void PLMESetRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute((PIBAttribute_t)string2enum(value, "PIBAttribute_t")); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(string2uint64(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetRequest'", field);
    }
}

omnetpp::cValue PLMESetRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: return static_cast<int>(pp->getPIBAttribute());
        case FIELD_PIBAttributeValue: return (omnetpp::intval_t)(pp->getPIBAttributeValue());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMESetRequest' as cValue -- field index out of range?", field);
    }
}

void PLMESetRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_PIBAttribute: pp->setPIBAttribute(static_cast<PIBAttribute_t>(value.intValue())); break;
        case FIELD_PIBAttributeValue: pp->setPIBAttributeValue(omnetpp::checked_int_cast<uint64_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetRequest'", field);
    }
}

const char *PLMESetRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMESetRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMESetRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetRequest *pp = omnetpp::fromAnyPtr<PLMESetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetRequest'", field);
    }
}

Register_Class(PLMESetConfirm)

PLMESetConfirm::PLMESetConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMESetConfirm::PLMESetConfirm(const PLMESetConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMESetConfirm::~PLMESetConfirm()
{
}

PLMESetConfirm& PLMESetConfirm::operator=(const PLMESetConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMESetConfirm::copy(const PLMESetConfirm& other)
{
    this->status = other.status;
    this->PIBAttribute = other.PIBAttribute;
}

void PLMESetConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->PIBAttribute);
}

void PLMESetConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->PIBAttribute);
}

phyStatus_t PLMESetConfirm::getStatus() const
{
    return this->status;
}

void PLMESetConfirm::setStatus(phyStatus_t status)
{
    this->status = status;
}

PIBAttribute_t PLMESetConfirm::getPIBAttribute() const
{
    return this->PIBAttribute;
}

void PLMESetConfirm::setPIBAttribute(PIBAttribute_t PIBAttribute)
{
    this->PIBAttribute = PIBAttribute;
}

class PLMESetConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
        FIELD_PIBAttribute,
    };
  public:
    PLMESetConfirmDescriptor();
    virtual ~PLMESetConfirmDescriptor();

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

Register_ClassDescriptor(PLMESetConfirmDescriptor)

PLMESetConfirmDescriptor::PLMESetConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMESetConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMESetConfirmDescriptor::~PLMESetConfirmDescriptor()
{
    delete[] propertyNames;
}

bool PLMESetConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMESetConfirm *>(obj)!=nullptr;
}

const char **PLMESetConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMESetConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMESetConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int PLMESetConfirmDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *PLMESetConfirmDescriptor::getFieldName(int field) const
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
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int PLMESetConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "PIBAttribute") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMESetConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "phyStatus_t",    // FIELD_status
        "PIBAttribute_t",    // FIELD_PIBAttribute
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMESetConfirmDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMESetConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "phyStatus_t";
            return nullptr;
        case FIELD_PIBAttribute:
            if (!strcmp(propertyName, "enum")) return "PIBAttribute_t";
            return nullptr;
        default: return nullptr;
    }
}

int PLMESetConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMESetConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMESetConfirm'", field);
    }
}

const char *PLMESetConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMESetConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "phyStatus_t");
        case FIELD_PIBAttribute: return enum2string(pp->getPIBAttribute(), "PIBAttribute_t");
        default: return "";
    }
}

void PLMESetConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((phyStatus_t)string2enum(value, "phyStatus_t")); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute((PIBAttribute_t)string2enum(value, "PIBAttribute_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetConfirm'", field);
    }
}

omnetpp::cValue PLMESetConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        case FIELD_PIBAttribute: return static_cast<int>(pp->getPIBAttribute());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMESetConfirm' as cValue -- field index out of range?", field);
    }
}

void PLMESetConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<phyStatus_t>(value.intValue())); break;
        case FIELD_PIBAttribute: pp->setPIBAttribute(static_cast<PIBAttribute_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetConfirm'", field);
    }
}

const char *PLMESetConfirmDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMESetConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMESetConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetConfirm *pp = omnetpp::fromAnyPtr<PLMESetConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetConfirm'", field);
    }
}

Register_Class(PLMESetTrxStateRequest)

PLMESetTrxStateRequest::PLMESetTrxStateRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMESetTrxStateRequest::PLMESetTrxStateRequest(const PLMESetTrxStateRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMESetTrxStateRequest::~PLMESetTrxStateRequest()
{
}

PLMESetTrxStateRequest& PLMESetTrxStateRequest::operator=(const PLMESetTrxStateRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMESetTrxStateRequest::copy(const PLMESetTrxStateRequest& other)
{
    this->state = other.state;
}

void PLMESetTrxStateRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->state);
}

void PLMESetTrxStateRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->state);
}

phyStatus_t PLMESetTrxStateRequest::getState() const
{
    return this->state;
}

void PLMESetTrxStateRequest::setState(phyStatus_t state)
{
    this->state = state;
}

class PLMESetTrxStateRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_state,
    };
  public:
    PLMESetTrxStateRequestDescriptor();
    virtual ~PLMESetTrxStateRequestDescriptor();

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

Register_ClassDescriptor(PLMESetTrxStateRequestDescriptor)

PLMESetTrxStateRequestDescriptor::PLMESetTrxStateRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMESetTrxStateRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMESetTrxStateRequestDescriptor::~PLMESetTrxStateRequestDescriptor()
{
    delete[] propertyNames;
}

bool PLMESetTrxStateRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMESetTrxStateRequest *>(obj)!=nullptr;
}

const char **PLMESetTrxStateRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMESetTrxStateRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMESetTrxStateRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PLMESetTrxStateRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_state
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *PLMESetTrxStateRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "state",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int PLMESetTrxStateRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "state") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMESetTrxStateRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "phyStatus_t",    // FIELD_state
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMESetTrxStateRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_state: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *PLMESetTrxStateRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_state:
            if (!strcmp(propertyName, "enum")) return "phyStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int PLMESetTrxStateRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMESetTrxStateRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMESetTrxStateRequest'", field);
    }
}

const char *PLMESetTrxStateRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMESetTrxStateRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_state: return enum2string(pp->getState(), "phyStatus_t");
        default: return "";
    }
}

void PLMESetTrxStateRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_state: pp->setState((phyStatus_t)string2enum(value, "phyStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetTrxStateRequest'", field);
    }
}

omnetpp::cValue PLMESetTrxStateRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_state: return static_cast<int>(pp->getState());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMESetTrxStateRequest' as cValue -- field index out of range?", field);
    }
}

void PLMESetTrxStateRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_state: pp->setState(static_cast<phyStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetTrxStateRequest'", field);
    }
}

const char *PLMESetTrxStateRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMESetTrxStateRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMESetTrxStateRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateRequest *pp = omnetpp::fromAnyPtr<PLMESetTrxStateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetTrxStateRequest'", field);
    }
}

Register_Class(PLMESetTrxStateConfirm)

PLMESetTrxStateConfirm::PLMESetTrxStateConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMESetTrxStateConfirm::PLMESetTrxStateConfirm(const PLMESetTrxStateConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMESetTrxStateConfirm::~PLMESetTrxStateConfirm()
{
}

PLMESetTrxStateConfirm& PLMESetTrxStateConfirm::operator=(const PLMESetTrxStateConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMESetTrxStateConfirm::copy(const PLMESetTrxStateConfirm& other)
{
    this->status = other.status;
}

void PLMESetTrxStateConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void PLMESetTrxStateConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

phyStatus_t PLMESetTrxStateConfirm::getStatus() const
{
    return this->status;
}

void PLMESetTrxStateConfirm::setStatus(phyStatus_t status)
{
    this->status = status;
}

class PLMESetTrxStateConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    PLMESetTrxStateConfirmDescriptor();
    virtual ~PLMESetTrxStateConfirmDescriptor();

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

Register_ClassDescriptor(PLMESetTrxStateConfirmDescriptor)

PLMESetTrxStateConfirmDescriptor::PLMESetTrxStateConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMESetTrxStateConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMESetTrxStateConfirmDescriptor::~PLMESetTrxStateConfirmDescriptor()
{
    delete[] propertyNames;
}

bool PLMESetTrxStateConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMESetTrxStateConfirm *>(obj)!=nullptr;
}

const char **PLMESetTrxStateConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMESetTrxStateConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMESetTrxStateConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PLMESetTrxStateConfirmDescriptor::getFieldTypeFlags(int field) const
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

const char *PLMESetTrxStateConfirmDescriptor::getFieldName(int field) const
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

int PLMESetTrxStateConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMESetTrxStateConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "phyStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMESetTrxStateConfirmDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMESetTrxStateConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "phyStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int PLMESetTrxStateConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMESetTrxStateConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMESetTrxStateConfirm'", field);
    }
}

const char *PLMESetTrxStateConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMESetTrxStateConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "phyStatus_t");
        default: return "";
    }
}

void PLMESetTrxStateConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((phyStatus_t)string2enum(value, "phyStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetTrxStateConfirm'", field);
    }
}

omnetpp::cValue PLMESetTrxStateConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMESetTrxStateConfirm' as cValue -- field index out of range?", field);
    }
}

void PLMESetTrxStateConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<phyStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetTrxStateConfirm'", field);
    }
}

const char *PLMESetTrxStateConfirmDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMESetTrxStateConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMESetTrxStateConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESetTrxStateConfirm *pp = omnetpp::fromAnyPtr<PLMESetTrxStateConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESetTrxStateConfirm'", field);
    }
}

Register_Class(PLMESwitchRequest)

PLMESwitchRequest::PLMESwitchRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMESwitchRequest::PLMESwitchRequest(const PLMESwitchRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMESwitchRequest::~PLMESwitchRequest()
{
}

PLMESwitchRequest& PLMESwitchRequest::operator=(const PLMESwitchRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMESwitchRequest::copy(const PLMESwitchRequest& other)
{
    this->SWBitMap = other.SWBitMap;
    this->dir = other.dir;
}

void PLMESwitchRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->SWBitMap);
    doParsimPacking(b,this->dir);
}

void PLMESwitchRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->SWBitMap);
    doParsimUnpacking(b,this->dir);
}

bool PLMESwitchRequest::getSWBitMap() const
{
    return this->SWBitMap;
}

void PLMESwitchRequest::setSWBitMap(bool SWBitMap)
{
    this->SWBitMap = SWBitMap;
}

bool PLMESwitchRequest::getDir() const
{
    return this->dir;
}

void PLMESwitchRequest::setDir(bool dir)
{
    this->dir = dir;
}

class PLMESwitchRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_SWBitMap,
        FIELD_dir,
    };
  public:
    PLMESwitchRequestDescriptor();
    virtual ~PLMESwitchRequestDescriptor();

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

Register_ClassDescriptor(PLMESwitchRequestDescriptor)

PLMESwitchRequestDescriptor::PLMESwitchRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMESwitchRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMESwitchRequestDescriptor::~PLMESwitchRequestDescriptor()
{
    delete[] propertyNames;
}

bool PLMESwitchRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMESwitchRequest *>(obj)!=nullptr;
}

const char **PLMESwitchRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMESwitchRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMESwitchRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int PLMESwitchRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_SWBitMap
        FD_ISEDITABLE,    // FIELD_dir
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *PLMESwitchRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SWBitMap",
        "dir",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int PLMESwitchRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "SWBitMap") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "dir") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMESwitchRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_SWBitMap
        "bool",    // FIELD_dir
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMESwitchRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMESwitchRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PLMESwitchRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMESwitchRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMESwitchRequest'", field);
    }
}

const char *PLMESwitchRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMESwitchRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        case FIELD_SWBitMap: return bool2string(pp->getSWBitMap());
        case FIELD_dir: return bool2string(pp->getDir());
        default: return "";
    }
}

void PLMESwitchRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        case FIELD_SWBitMap: pp->setSWBitMap(string2bool(value)); break;
        case FIELD_dir: pp->setDir(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESwitchRequest'", field);
    }
}

omnetpp::cValue PLMESwitchRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        case FIELD_SWBitMap: return pp->getSWBitMap();
        case FIELD_dir: return pp->getDir();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMESwitchRequest' as cValue -- field index out of range?", field);
    }
}

void PLMESwitchRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        case FIELD_SWBitMap: pp->setSWBitMap(value.boolValue()); break;
        case FIELD_dir: pp->setDir(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESwitchRequest'", field);
    }
}

const char *PLMESwitchRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMESwitchRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMESwitchRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchRequest *pp = omnetpp::fromAnyPtr<PLMESwitchRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESwitchRequest'", field);
    }
}

Register_Class(PLMESwitchConfirm)

PLMESwitchConfirm::PLMESwitchConfirm(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PLMESwitchConfirm::PLMESwitchConfirm(const PLMESwitchConfirm& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PLMESwitchConfirm::~PLMESwitchConfirm()
{
}

PLMESwitchConfirm& PLMESwitchConfirm::operator=(const PLMESwitchConfirm& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PLMESwitchConfirm::copy(const PLMESwitchConfirm& other)
{
    this->status = other.status;
}

void PLMESwitchConfirm::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->status);
}

void PLMESwitchConfirm::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
}

phyStatus_t PLMESwitchConfirm::getStatus() const
{
    return this->status;
}

void PLMESwitchConfirm::setStatus(phyStatus_t status)
{
    this->status = status;
}

class PLMESwitchConfirmDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_status,
    };
  public:
    PLMESwitchConfirmDescriptor();
    virtual ~PLMESwitchConfirmDescriptor();

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

Register_ClassDescriptor(PLMESwitchConfirmDescriptor)

PLMESwitchConfirmDescriptor::PLMESwitchConfirmDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PLMESwitchConfirm)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PLMESwitchConfirmDescriptor::~PLMESwitchConfirmDescriptor()
{
    delete[] propertyNames;
}

bool PLMESwitchConfirmDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PLMESwitchConfirm *>(obj)!=nullptr;
}

const char **PLMESwitchConfirmDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PLMESwitchConfirmDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PLMESwitchConfirmDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int PLMESwitchConfirmDescriptor::getFieldTypeFlags(int field) const
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

const char *PLMESwitchConfirmDescriptor::getFieldName(int field) const
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

int PLMESwitchConfirmDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *PLMESwitchConfirmDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "phyStatus_t",    // FIELD_status
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **PLMESwitchConfirmDescriptor::getFieldPropertyNames(int field) const
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

const char *PLMESwitchConfirmDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_status:
            if (!strcmp(propertyName, "enum")) return "phyStatus_t";
            return nullptr;
        default: return nullptr;
    }
}

int PLMESwitchConfirmDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PLMESwitchConfirmDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PLMESwitchConfirm'", field);
    }
}

const char *PLMESwitchConfirmDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PLMESwitchConfirmDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return enum2string(pp->getStatus(), "phyStatus_t");
        default: return "";
    }
}

void PLMESwitchConfirmDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus((phyStatus_t)string2enum(value, "phyStatus_t")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESwitchConfirm'", field);
    }
}

omnetpp::cValue PLMESwitchConfirmDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: return static_cast<int>(pp->getStatus());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PLMESwitchConfirm' as cValue -- field index out of range?", field);
    }
}

void PLMESwitchConfirmDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        case FIELD_status: pp->setStatus(static_cast<phyStatus_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESwitchConfirm'", field);
    }
}

const char *PLMESwitchConfirmDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PLMESwitchConfirmDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PLMESwitchConfirmDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PLMESwitchConfirm *pp = omnetpp::fromAnyPtr<PLMESwitchConfirm>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PLMESwitchConfirm'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

