//
// Generated file, do not edit! Created by opp_msgtool 6.0 from msgs//types.msg.
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
#include "types_m.h"

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

Register_Enum(opticalChannel_t, (opticalChannel_t::C_190_380, opticalChannel_t::C_380_529, opticalChannel_t::C_529_598, opticalChannel_t::C_598_649, opticalChannel_t::C_649_694, opticalChannel_t::C_694_737, opticalChannel_t::C_737_780, opticalChannel_t::C_780_10k));

Register_Enum(batteryInformation_t, (batteryInformation_t::BAT_UNKNOWN, batteryInformation_t::BAT_LESS_50, batteryInformation_t::BAT_MORE_50, batteryInformation_t::BAT_CONNECTED));

Register_Enum(deviceType_t, (deviceType_t::DEV_INFRASTRUCTURE, deviceType_t::DEV_MOBILE, deviceType_t::DEV_VEHICLE, deviceType_t::DEV_UNKNOWN));

Register_Enum(colorStabilizationScheme_t, (colorStabilizationScheme_t::NO_COLOR, colorStabilizationScheme_t::FROM_DEVICE_TO_COORD, colorStabilizationScheme_t::FROM_COORD_TO_DEVICE, colorStabilizationScheme_t::BOTH_WAYS));

Register_Enum(maxSupportedOpticalClock_t, (maxSupportedOpticalClock_t::MAX_200K, maxSupportedOpticalClock_t::MAX_400K, maxSupportedOpticalClock_t::MAX_3_75M, maxSupportedOpticalClock_t::MAX_7_5M, maxSupportedOpticalClock_t::MAX_15M, maxSupportedOpticalClock_t::MAX_30M, maxSupportedOpticalClock_t::MAX_60M, maxSupportedOpticalClock_t::MAX_120M));

capabilityInformation_t::capabilityInformation_t()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const capabilityInformation_t& a)
{
    doParsimPacking(b,a.powerSource);
    doParsimPacking(b,a.batteryInformation);
    doParsimPacking(b,a.securityCapability);
    doParsimPacking(b,a.coordinatorCapability);
    doParsimPacking(b,a.traficSupport);
    doParsimPacking(b,a.broadcastSupport);
    doParsimPacking(b,a.peerToPeerSupport);
    doParsimPacking(b,a.starSupport);
    doParsimPacking(b,a.deviceType);
    doParsimPacking(b,a.beaconSupport);
    doParsimPacking(b,a.dimmingSupport);
    doParsimPacking(b,a.continuousVisibilityTransmission);
    doParsimPacking(b,a.cvdSupport);
    doParsimPacking(b,a.phyISupport);
    doParsimPacking(b,a.phyIISupport);
    doParsimPacking(b,a.phyIIISupport);
    doParsimPacking(b,a.colorStabilizationCapability);
    doParsimPacking(b,a.maxTxClock);
    doParsimPacking(b,a.maxRxClock);
    doParsimPacking(b,a.explicitClockNotificationRequest);
    doParsimPacking(b,a.ccaSupport);
    doParsimPacking(b,a.phyIVSupport);
    doParsimPacking(b,a.phyVSupport);
    doParsimPacking(b,a.phyVISupport);
    doParsimPacking(b,a.numberOfOpticalSources);
    doParsimPacking(b,a.multipleDirectionSupport);
    doParsimPacking(b,a.numberOfCellsSupported);
    doParsimPacking(b,a.bandsUsedForPhy3);
}

void __doUnpacking(omnetpp::cCommBuffer *b, capabilityInformation_t& a)
{
    doParsimUnpacking(b,a.powerSource);
    doParsimUnpacking(b,a.batteryInformation);
    doParsimUnpacking(b,a.securityCapability);
    doParsimUnpacking(b,a.coordinatorCapability);
    doParsimUnpacking(b,a.traficSupport);
    doParsimUnpacking(b,a.broadcastSupport);
    doParsimUnpacking(b,a.peerToPeerSupport);
    doParsimUnpacking(b,a.starSupport);
    doParsimUnpacking(b,a.deviceType);
    doParsimUnpacking(b,a.beaconSupport);
    doParsimUnpacking(b,a.dimmingSupport);
    doParsimUnpacking(b,a.continuousVisibilityTransmission);
    doParsimUnpacking(b,a.cvdSupport);
    doParsimUnpacking(b,a.phyISupport);
    doParsimUnpacking(b,a.phyIISupport);
    doParsimUnpacking(b,a.phyIIISupport);
    doParsimUnpacking(b,a.colorStabilizationCapability);
    doParsimUnpacking(b,a.maxTxClock);
    doParsimUnpacking(b,a.maxRxClock);
    doParsimUnpacking(b,a.explicitClockNotificationRequest);
    doParsimUnpacking(b,a.ccaSupport);
    doParsimUnpacking(b,a.phyIVSupport);
    doParsimUnpacking(b,a.phyVSupport);
    doParsimUnpacking(b,a.phyVISupport);
    doParsimUnpacking(b,a.numberOfOpticalSources);
    doParsimUnpacking(b,a.multipleDirectionSupport);
    doParsimUnpacking(b,a.numberOfCellsSupported);
    doParsimUnpacking(b,a.bandsUsedForPhy3);
}

class capabilityInformation_tDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_powerSource,
        FIELD_batteryInformation,
        FIELD_securityCapability,
        FIELD_coordinatorCapability,
        FIELD_traficSupport,
        FIELD_broadcastSupport,
        FIELD_peerToPeerSupport,
        FIELD_starSupport,
        FIELD_deviceType,
        FIELD_beaconSupport,
        FIELD_dimmingSupport,
        FIELD_continuousVisibilityTransmission,
        FIELD_cvdSupport,
        FIELD_phyISupport,
        FIELD_phyIISupport,
        FIELD_phyIIISupport,
        FIELD_colorStabilizationCapability,
        FIELD_maxTxClock,
        FIELD_maxRxClock,
        FIELD_explicitClockNotificationRequest,
        FIELD_ccaSupport,
        FIELD_phyIVSupport,
        FIELD_phyVSupport,
        FIELD_phyVISupport,
        FIELD_numberOfOpticalSources,
        FIELD_multipleDirectionSupport,
        FIELD_numberOfCellsSupported,
        FIELD_bandsUsedForPhy3,
    };
  public:
    capabilityInformation_tDescriptor();
    virtual ~capabilityInformation_tDescriptor();

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

Register_ClassDescriptor(capabilityInformation_tDescriptor)

capabilityInformation_tDescriptor::capabilityInformation_tDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(capabilityInformation_t)), "")
{
    propertyNames = nullptr;
}

capabilityInformation_tDescriptor::~capabilityInformation_tDescriptor()
{
    delete[] propertyNames;
}

bool capabilityInformation_tDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<capabilityInformation_t *>(obj)!=nullptr;
}

const char **capabilityInformation_tDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *capabilityInformation_tDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int capabilityInformation_tDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 28+base->getFieldCount() : 28;
}

unsigned int capabilityInformation_tDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_powerSource
        0,    // FIELD_batteryInformation
        FD_ISEDITABLE,    // FIELD_securityCapability
        FD_ISEDITABLE,    // FIELD_coordinatorCapability
        FD_ISEDITABLE,    // FIELD_traficSupport
        FD_ISEDITABLE,    // FIELD_broadcastSupport
        FD_ISEDITABLE,    // FIELD_peerToPeerSupport
        FD_ISEDITABLE,    // FIELD_starSupport
        0,    // FIELD_deviceType
        FD_ISEDITABLE,    // FIELD_beaconSupport
        FD_ISEDITABLE,    // FIELD_dimmingSupport
        FD_ISEDITABLE,    // FIELD_continuousVisibilityTransmission
        FD_ISEDITABLE,    // FIELD_cvdSupport
        FD_ISEDITABLE,    // FIELD_phyISupport
        FD_ISEDITABLE,    // FIELD_phyIISupport
        FD_ISEDITABLE,    // FIELD_phyIIISupport
        0,    // FIELD_colorStabilizationCapability
        0,    // FIELD_maxTxClock
        0,    // FIELD_maxRxClock
        FD_ISEDITABLE,    // FIELD_explicitClockNotificationRequest
        FD_ISEDITABLE,    // FIELD_ccaSupport
        FD_ISEDITABLE,    // FIELD_phyIVSupport
        FD_ISEDITABLE,    // FIELD_phyVSupport
        FD_ISEDITABLE,    // FIELD_phyVISupport
        FD_ISEDITABLE,    // FIELD_numberOfOpticalSources
        FD_ISEDITABLE,    // FIELD_multipleDirectionSupport
        FD_ISEDITABLE,    // FIELD_numberOfCellsSupported
        FD_ISEDITABLE,    // FIELD_bandsUsedForPhy3
    };
    return (field >= 0 && field < 28) ? fieldTypeFlags[field] : 0;
}

const char *capabilityInformation_tDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "powerSource",
        "batteryInformation",
        "securityCapability",
        "coordinatorCapability",
        "traficSupport",
        "broadcastSupport",
        "peerToPeerSupport",
        "starSupport",
        "deviceType",
        "beaconSupport",
        "dimmingSupport",
        "continuousVisibilityTransmission",
        "cvdSupport",
        "phyISupport",
        "phyIISupport",
        "phyIIISupport",
        "colorStabilizationCapability",
        "maxTxClock",
        "maxRxClock",
        "explicitClockNotificationRequest",
        "ccaSupport",
        "phyIVSupport",
        "phyVSupport",
        "phyVISupport",
        "numberOfOpticalSources",
        "multipleDirectionSupport",
        "numberOfCellsSupported",
        "bandsUsedForPhy3",
    };
    return (field >= 0 && field < 28) ? fieldNames[field] : nullptr;
}

int capabilityInformation_tDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "powerSource") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "batteryInformation") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "securityCapability") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "coordinatorCapability") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "traficSupport") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "broadcastSupport") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "peerToPeerSupport") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "starSupport") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "deviceType") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "beaconSupport") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "dimmingSupport") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "continuousVisibilityTransmission") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "cvdSupport") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "phyISupport") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "phyIISupport") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "phyIIISupport") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "colorStabilizationCapability") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "maxTxClock") == 0) return baseIndex + 17;
    if (strcmp(fieldName, "maxRxClock") == 0) return baseIndex + 18;
    if (strcmp(fieldName, "explicitClockNotificationRequest") == 0) return baseIndex + 19;
    if (strcmp(fieldName, "ccaSupport") == 0) return baseIndex + 20;
    if (strcmp(fieldName, "phyIVSupport") == 0) return baseIndex + 21;
    if (strcmp(fieldName, "phyVSupport") == 0) return baseIndex + 22;
    if (strcmp(fieldName, "phyVISupport") == 0) return baseIndex + 23;
    if (strcmp(fieldName, "numberOfOpticalSources") == 0) return baseIndex + 24;
    if (strcmp(fieldName, "multipleDirectionSupport") == 0) return baseIndex + 25;
    if (strcmp(fieldName, "numberOfCellsSupported") == 0) return baseIndex + 26;
    if (strcmp(fieldName, "bandsUsedForPhy3") == 0) return baseIndex + 27;
    return base ? base->findField(fieldName) : -1;
}

const char *capabilityInformation_tDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_powerSource
        "batteryInformation_t",    // FIELD_batteryInformation
        "bool",    // FIELD_securityCapability
        "bool",    // FIELD_coordinatorCapability
        "bool",    // FIELD_traficSupport
        "bool",    // FIELD_broadcastSupport
        "bool",    // FIELD_peerToPeerSupport
        "bool",    // FIELD_starSupport
        "deviceType_t",    // FIELD_deviceType
        "bool",    // FIELD_beaconSupport
        "bool",    // FIELD_dimmingSupport
        "bool",    // FIELD_continuousVisibilityTransmission
        "bool",    // FIELD_cvdSupport
        "bool",    // FIELD_phyISupport
        "bool",    // FIELD_phyIISupport
        "bool",    // FIELD_phyIIISupport
        "colorStabilizationScheme_t",    // FIELD_colorStabilizationCapability
        "maxSupportedOpticalClock_t",    // FIELD_maxTxClock
        "maxSupportedOpticalClock_t",    // FIELD_maxRxClock
        "bool",    // FIELD_explicitClockNotificationRequest
        "bool",    // FIELD_ccaSupport
        "bool",    // FIELD_phyIVSupport
        "bool",    // FIELD_phyVSupport
        "bool",    // FIELD_phyVISupport
        "uint8_t",    // FIELD_numberOfOpticalSources
        "uint8_t",    // FIELD_multipleDirectionSupport
        "uint16_t",    // FIELD_numberOfCellsSupported
        "uint8_t",    // FIELD_bandsUsedForPhy3
    };
    return (field >= 0 && field < 28) ? fieldTypeStrings[field] : nullptr;
}

const char **capabilityInformation_tDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_batteryInformation: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_deviceType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_colorStabilizationCapability: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_maxTxClock: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_maxRxClock: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *capabilityInformation_tDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_batteryInformation:
            if (!strcmp(propertyName, "enum")) return "batteryInformation_t";
            return nullptr;
        case FIELD_deviceType:
            if (!strcmp(propertyName, "enum")) return "deviceType_t";
            return nullptr;
        case FIELD_colorStabilizationCapability:
            if (!strcmp(propertyName, "enum")) return "colorStabilizationScheme_t";
            return nullptr;
        case FIELD_maxTxClock:
            if (!strcmp(propertyName, "enum")) return "maxSupportedOpticalClock_t";
            return nullptr;
        case FIELD_maxRxClock:
            if (!strcmp(propertyName, "enum")) return "maxSupportedOpticalClock_t";
            return nullptr;
        default: return nullptr;
    }
}

int capabilityInformation_tDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void capabilityInformation_tDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'capabilityInformation_t'", field);
    }
}

const char *capabilityInformation_tDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string capabilityInformation_tDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        case FIELD_powerSource: return bool2string(pp->powerSource);
        case FIELD_batteryInformation: return enum2string(pp->batteryInformation, "batteryInformation_t");
        case FIELD_securityCapability: return bool2string(pp->securityCapability);
        case FIELD_coordinatorCapability: return bool2string(pp->coordinatorCapability);
        case FIELD_traficSupport: return bool2string(pp->traficSupport);
        case FIELD_broadcastSupport: return bool2string(pp->broadcastSupport);
        case FIELD_peerToPeerSupport: return bool2string(pp->peerToPeerSupport);
        case FIELD_starSupport: return bool2string(pp->starSupport);
        case FIELD_deviceType: return enum2string(pp->deviceType, "deviceType_t");
        case FIELD_beaconSupport: return bool2string(pp->beaconSupport);
        case FIELD_dimmingSupport: return bool2string(pp->dimmingSupport);
        case FIELD_continuousVisibilityTransmission: return bool2string(pp->continuousVisibilityTransmission);
        case FIELD_cvdSupport: return bool2string(pp->cvdSupport);
        case FIELD_phyISupport: return bool2string(pp->phyISupport);
        case FIELD_phyIISupport: return bool2string(pp->phyIISupport);
        case FIELD_phyIIISupport: return bool2string(pp->phyIIISupport);
        case FIELD_colorStabilizationCapability: return enum2string(pp->colorStabilizationCapability, "colorStabilizationScheme_t");
        case FIELD_maxTxClock: return enum2string(pp->maxTxClock, "maxSupportedOpticalClock_t");
        case FIELD_maxRxClock: return enum2string(pp->maxRxClock, "maxSupportedOpticalClock_t");
        case FIELD_explicitClockNotificationRequest: return bool2string(pp->explicitClockNotificationRequest);
        case FIELD_ccaSupport: return bool2string(pp->ccaSupport);
        case FIELD_phyIVSupport: return bool2string(pp->phyIVSupport);
        case FIELD_phyVSupport: return bool2string(pp->phyVSupport);
        case FIELD_phyVISupport: return bool2string(pp->phyVISupport);
        case FIELD_numberOfOpticalSources: return ulong2string(pp->numberOfOpticalSources);
        case FIELD_multipleDirectionSupport: return ulong2string(pp->multipleDirectionSupport);
        case FIELD_numberOfCellsSupported: return ulong2string(pp->numberOfCellsSupported);
        case FIELD_bandsUsedForPhy3: return ulong2string(pp->bandsUsedForPhy3);
        default: return "";
    }
}

void capabilityInformation_tDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        case FIELD_powerSource: pp->powerSource = string2bool(value); break;
        case FIELD_securityCapability: pp->securityCapability = string2bool(value); break;
        case FIELD_coordinatorCapability: pp->coordinatorCapability = string2bool(value); break;
        case FIELD_traficSupport: pp->traficSupport = string2bool(value); break;
        case FIELD_broadcastSupport: pp->broadcastSupport = string2bool(value); break;
        case FIELD_peerToPeerSupport: pp->peerToPeerSupport = string2bool(value); break;
        case FIELD_starSupport: pp->starSupport = string2bool(value); break;
        case FIELD_beaconSupport: pp->beaconSupport = string2bool(value); break;
        case FIELD_dimmingSupport: pp->dimmingSupport = string2bool(value); break;
        case FIELD_continuousVisibilityTransmission: pp->continuousVisibilityTransmission = string2bool(value); break;
        case FIELD_cvdSupport: pp->cvdSupport = string2bool(value); break;
        case FIELD_phyISupport: pp->phyISupport = string2bool(value); break;
        case FIELD_phyIISupport: pp->phyIISupport = string2bool(value); break;
        case FIELD_phyIIISupport: pp->phyIIISupport = string2bool(value); break;
        case FIELD_explicitClockNotificationRequest: pp->explicitClockNotificationRequest = string2bool(value); break;
        case FIELD_ccaSupport: pp->ccaSupport = string2bool(value); break;
        case FIELD_phyIVSupport: pp->phyIVSupport = string2bool(value); break;
        case FIELD_phyVSupport: pp->phyVSupport = string2bool(value); break;
        case FIELD_phyVISupport: pp->phyVISupport = string2bool(value); break;
        case FIELD_numberOfOpticalSources: pp->numberOfOpticalSources = string2ulong(value); break;
        case FIELD_multipleDirectionSupport: pp->multipleDirectionSupport = string2ulong(value); break;
        case FIELD_numberOfCellsSupported: pp->numberOfCellsSupported = string2ulong(value); break;
        case FIELD_bandsUsedForPhy3: pp->bandsUsedForPhy3 = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'capabilityInformation_t'", field);
    }
}

omnetpp::cValue capabilityInformation_tDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        case FIELD_powerSource: return pp->powerSource;
        case FIELD_batteryInformation: return static_cast<int>(pp->batteryInformation);
        case FIELD_securityCapability: return pp->securityCapability;
        case FIELD_coordinatorCapability: return pp->coordinatorCapability;
        case FIELD_traficSupport: return pp->traficSupport;
        case FIELD_broadcastSupport: return pp->broadcastSupport;
        case FIELD_peerToPeerSupport: return pp->peerToPeerSupport;
        case FIELD_starSupport: return pp->starSupport;
        case FIELD_deviceType: return static_cast<int>(pp->deviceType);
        case FIELD_beaconSupport: return pp->beaconSupport;
        case FIELD_dimmingSupport: return pp->dimmingSupport;
        case FIELD_continuousVisibilityTransmission: return pp->continuousVisibilityTransmission;
        case FIELD_cvdSupport: return pp->cvdSupport;
        case FIELD_phyISupport: return pp->phyISupport;
        case FIELD_phyIISupport: return pp->phyIISupport;
        case FIELD_phyIIISupport: return pp->phyIIISupport;
        case FIELD_colorStabilizationCapability: return static_cast<int>(pp->colorStabilizationCapability);
        case FIELD_maxTxClock: return static_cast<int>(pp->maxTxClock);
        case FIELD_maxRxClock: return static_cast<int>(pp->maxRxClock);
        case FIELD_explicitClockNotificationRequest: return pp->explicitClockNotificationRequest;
        case FIELD_ccaSupport: return pp->ccaSupport;
        case FIELD_phyIVSupport: return pp->phyIVSupport;
        case FIELD_phyVSupport: return pp->phyVSupport;
        case FIELD_phyVISupport: return pp->phyVISupport;
        case FIELD_numberOfOpticalSources: return (omnetpp::intval_t)(pp->numberOfOpticalSources);
        case FIELD_multipleDirectionSupport: return (omnetpp::intval_t)(pp->multipleDirectionSupport);
        case FIELD_numberOfCellsSupported: return (omnetpp::intval_t)(pp->numberOfCellsSupported);
        case FIELD_bandsUsedForPhy3: return (omnetpp::intval_t)(pp->bandsUsedForPhy3);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'capabilityInformation_t' as cValue -- field index out of range?", field);
    }
}

void capabilityInformation_tDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        case FIELD_powerSource: pp->powerSource = value.boolValue(); break;
        case FIELD_securityCapability: pp->securityCapability = value.boolValue(); break;
        case FIELD_coordinatorCapability: pp->coordinatorCapability = value.boolValue(); break;
        case FIELD_traficSupport: pp->traficSupport = value.boolValue(); break;
        case FIELD_broadcastSupport: pp->broadcastSupport = value.boolValue(); break;
        case FIELD_peerToPeerSupport: pp->peerToPeerSupport = value.boolValue(); break;
        case FIELD_starSupport: pp->starSupport = value.boolValue(); break;
        case FIELD_beaconSupport: pp->beaconSupport = value.boolValue(); break;
        case FIELD_dimmingSupport: pp->dimmingSupport = value.boolValue(); break;
        case FIELD_continuousVisibilityTransmission: pp->continuousVisibilityTransmission = value.boolValue(); break;
        case FIELD_cvdSupport: pp->cvdSupport = value.boolValue(); break;
        case FIELD_phyISupport: pp->phyISupport = value.boolValue(); break;
        case FIELD_phyIISupport: pp->phyIISupport = value.boolValue(); break;
        case FIELD_phyIIISupport: pp->phyIIISupport = value.boolValue(); break;
        case FIELD_explicitClockNotificationRequest: pp->explicitClockNotificationRequest = value.boolValue(); break;
        case FIELD_ccaSupport: pp->ccaSupport = value.boolValue(); break;
        case FIELD_phyIVSupport: pp->phyIVSupport = value.boolValue(); break;
        case FIELD_phyVSupport: pp->phyVSupport = value.boolValue(); break;
        case FIELD_phyVISupport: pp->phyVISupport = value.boolValue(); break;
        case FIELD_numberOfOpticalSources: pp->numberOfOpticalSources = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_multipleDirectionSupport: pp->multipleDirectionSupport = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_numberOfCellsSupported: pp->numberOfCellsSupported = omnetpp::checked_int_cast<uint16_t>(value.intValue()); break;
        case FIELD_bandsUsedForPhy3: pp->bandsUsedForPhy3 = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'capabilityInformation_t'", field);
    }
}

const char *capabilityInformation_tDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr capabilityInformation_tDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void capabilityInformation_tDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    capabilityInformation_t *pp = omnetpp::fromAnyPtr<capabilityInformation_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'capabilityInformation_t'", field);
    }
}

security_t::security_t()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const security_t& a)
{
    doParsimPacking(b,a.securityLevel);
    doParsimPacking(b,a.keyIdMode);
    doParsimPacking(b,a.keySource);
    doParsimPacking(b,a.keyIndex);
}

void __doUnpacking(omnetpp::cCommBuffer *b, security_t& a)
{
    doParsimUnpacking(b,a.securityLevel);
    doParsimUnpacking(b,a.keyIdMode);
    doParsimUnpacking(b,a.keySource);
    doParsimUnpacking(b,a.keyIndex);
}

class security_tDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_securityLevel,
        FIELD_keyIdMode,
        FIELD_keySource,
        FIELD_keyIndex,
    };
  public:
    security_tDescriptor();
    virtual ~security_tDescriptor();

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

Register_ClassDescriptor(security_tDescriptor)

security_tDescriptor::security_tDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(security_t)), "")
{
    propertyNames = nullptr;
}

security_tDescriptor::~security_tDescriptor()
{
    delete[] propertyNames;
}

bool security_tDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<security_t *>(obj)!=nullptr;
}

const char **security_tDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *security_tDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int security_tDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int security_tDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_securityLevel
        FD_ISEDITABLE,    // FIELD_keyIdMode
        FD_ISEDITABLE,    // FIELD_keySource
        FD_ISEDITABLE,    // FIELD_keyIndex
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *security_tDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "securityLevel",
        "keyIdMode",
        "keySource",
        "keyIndex",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int security_tDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "keyIdMode") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "keySource") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "keyIndex") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *security_tDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",    // FIELD_securityLevel
        "uint8_t",    // FIELD_keyIdMode
        "uint64_t",    // FIELD_keySource
        "uint8_t",    // FIELD_keyIndex
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **security_tDescriptor::getFieldPropertyNames(int field) const
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

const char *security_tDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int security_tDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void security_tDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'security_t'", field);
    }
}

const char *security_tDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string security_tDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        case FIELD_securityLevel: return ulong2string(pp->securityLevel);
        case FIELD_keyIdMode: return ulong2string(pp->keyIdMode);
        case FIELD_keySource: return uint642string(pp->keySource);
        case FIELD_keyIndex: return ulong2string(pp->keyIndex);
        default: return "";
    }
}

void security_tDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        case FIELD_securityLevel: pp->securityLevel = string2ulong(value); break;
        case FIELD_keyIdMode: pp->keyIdMode = string2ulong(value); break;
        case FIELD_keySource: pp->keySource = string2uint64(value); break;
        case FIELD_keyIndex: pp->keyIndex = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'security_t'", field);
    }
}

omnetpp::cValue security_tDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->securityLevel);
        case FIELD_keyIdMode: return (omnetpp::intval_t)(pp->keyIdMode);
        case FIELD_keySource: return (omnetpp::intval_t)(pp->keySource);
        case FIELD_keyIndex: return (omnetpp::intval_t)(pp->keyIndex);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'security_t' as cValue -- field index out of range?", field);
    }
}

void security_tDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        case FIELD_securityLevel: pp->securityLevel = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_keyIdMode: pp->keyIdMode = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_keySource: pp->keySource = omnetpp::checked_int_cast<uint64_t>(value.intValue()); break;
        case FIELD_keyIndex: pp->keyIndex = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'security_t'", field);
    }
}

const char *security_tDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr security_tDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void security_tDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    security_t *pp = omnetpp::fromAnyPtr<security_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'security_t'", field);
    }
}

Register_Enum(commandFrameIdentifier_t, (commandFrameIdentifier_t::ASSOCIATION_REQUEST, commandFrameIdentifier_t::ASSOCIATION_RESPONSE, commandFrameIdentifier_t::DISASSOCIATION_NOTIFICATION, commandFrameIdentifier_t::DATA_REQUEST, commandFrameIdentifier_t::OWPAN_ID_CONFLICT_NOTIFICATION, commandFrameIdentifier_t::BEACON_REQUEST, commandFrameIdentifier_t::COORDINATOR_REALIGNMENT, commandFrameIdentifier_t::GTS_REQUEST, commandFrameIdentifier_t::BLINKING_NOTIFICATION, commandFrameIdentifier_t::DIMMING_NOTIFICATION, commandFrameIdentifier_t::FAST_LINK_RECOVERY, commandFrameIdentifier_t::MOBILITY_NOTIFICATION, commandFrameIdentifier_t::GTS_RESPONSE, commandFrameIdentifier_t::CLOCK_RATE_CHANGE_NOTIFICATION, commandFrameIdentifier_t::MULTIPLE_CHANNEL_ASSIGNMENT, commandFrameIdentifier_t::BAND_HOPING, commandFrameIdentifier_t::COLOR_STABILIZATION_TIMER_NOTIFICATION, commandFrameIdentifier_t::COLOR_STABILIZATION_INFORMATION, commandFrameIdentifier_t::CVD_DISABLE, commandFrameIdentifier_t::INFORMATION_ELEMENT));

Register_Enum(macStatus_t, (macStatus_t::ASSOCIATION_SUCCESSFUL, macStatus_t::OWPAN_AT_CAPACITY, macStatus_t::OWPAN_ACCESS_DENIED, macStatus_t::SUCCESS, macStatus_t::TRANSACTION_OVERFLOW, macStatus_t::TRANSACTION_EXPIRED, macStatus_t::CHANNEL_ACCESS_FAILURE, macStatus_t::INVALID_ADDRESS, macStatus_t::INVALID_GTS, macStatus_t::NO_ACK, macStatus_t::COUNTER_ERROR, macStatus_t::FRAME_TOO_LONG, macStatus_t::UNAVAILABLE_KEY, macStatus_t::UNSUPPORTED_SECURITY, macStatus_t::INVALID_PARAMETER, macStatus_t::INVALID_INDEX, macStatus_t::UNSUPPORTED_ATTRIBUTE_MAC, macStatus_t::READ_ONLY, macStatus_t::SCAN_IN_PROGRESS));

Register_Enum(frameType_t, (frameType_t::beacon, frameType_t::data, frameType_t::ack, frameType_t::command, frameType_t::cvd));

Register_Enum(addressingMode_t, (addressingMode_t::noAddress, addressingMode_t::broadcast, addressingMode_t::bit16, addressingMode_t::bit64));

Register_Enum(dataType_t, (dataType_t::single, dataType_t::packed, dataType_t::burst));

Register_Enum(PIBAttribute_t, (PIBAttribute_t::PHY_CURRENT_CHANNEL, PIBAttribute_t::PHY_CCA_MODE, PIBAttribute_t::PHY_DIM, PIBAttribute_t::PHY_USE_EXTENDED_MODE, PIBAttribute_t::PHY_COLOR_FUNCTION, PIBAttribute_t::PHY_BLINKING_NOTIFICATION_FREQUENCY, PIBAttribute_t::PHY_OCC_ENABLE, PIBAttribute_t::PHY_OCC_MCS_ID, PIBAttribute_t::PHY_PSDU_LENGTH, PIBAttribute_t::MAC_ACK_WAIT_DURATION, PIBAttribute_t::MAC_ASSOCIATED_OWPAN_COORD, PIBAttribute_t::MAC_ASSOCIATED_PERMIT, PIBAttribute_t::MAC_AUTO_REQUEST, PIBAttribute_t::MAC_BEACON_PAYLOAD, PIBAttribute_t::MAC_BEACON_PAYLOAD_LENGTH, PIBAttribute_t::MAC_BEACON_ORDER, PIBAttribute_t::MAC_BEACON_TX_TIME, PIBAttribute_t::MAC_BSN, PIBAttribute_t::MAC_COORD_EXTENDED_ADDRESS, PIBAttribute_t::MAC_COORD_SHORT_ADDRESS, PIBAttribute_t::MAC_DSN, PIBAttribute_t::MAC_GTS_PERMIT, PIBAttribute_t::MAC_MAX_BE, PIBAttribute_t::MAC_MAX_CSMA_BACKOFFS, PIBAttribute_t::MAC_MAX_FRAME_TOTAL_WAIT_TIME, PIBAttribute_t::MAC_MAX_FRAME_RETRIES, PIBAttribute_t::MAC_MIN_BE, PIBAttribute_t::MAC_MIN_LIFS_PERIOD, PIBAttribute_t::MAC_MIN_SIFS_PERIOD, PIBAttribute_t::MAC_OWPAN_ID, PIBAttribute_t::MAC_RESPONSE_WAIT_TIME, PIBAttribute_t::MAC_RX_ON_WHEN_IDLE, PIBAttribute_t::MAC_SECURITY_ENABLED, PIBAttribute_t::MAC_SHORT_ADDRESS, PIBAttribute_t::MAC_SUPERFRAME_ORDER, PIBAttribute_t::MAC_TIMESTAMP_SUPPORTED, PIBAttribute_t::MAC_TRANSACTION_PERSISTENCE_TIME, PIBAttribute_t::MAC_DIM, PIBAttribute_t::MAC_NUM_ACKS, PIBAttribute_t::MAC_LINK_TIME_OUT, PIBAttribute_t::MAC_DIM_OVERRIDE_REQUEST, PIBAttribute_t::MAC_DIM_PWM_OVERRIDE_REQUEST, PIBAttribute_t::MAC_DIM_DATA_FAILURE_INDICATION, PIBAttribute_t::MAC_DURING_ASSOC_COLOR, PIBAttribute_t::MAC_DURING_DISASSOC_COLOR, PIBAttribute_t::MAC_DURING_SCAN_COLOR, PIBAttribute_t::MAC_COLOR_RECEIVED, PIBAttribute_t::MAC_COLOR_NOT_RECEIVED, PIBAttribute_t::MAC_CQI_COLOR_LFER, PIBAttribute_t::MAC_CQI_COLOR_MFER, PIBAttribute_t::MAC_CQI_COLOR_HFER, PIBAttribute_t::MAC_CF_APP_COLOR, PIBAttribute_t::MAC_COLOR_STABILIZATION, PIBAttribute_t::MAC_COLOR_STABILIZATION_TIMER, PIBAttribute_t::MAC_USE_DIMMED_OOK_MODE, PIBAttribute_t::MAC_TIME_STAMP_OFFSET, PIBAttribute_t::MAC_USE_BLINKING_NOTIFICATION, PIBAttribute_t::MAC_BLINKING_NOTIFICATION_FREQUENCY, PIBAttribute_t::MAC_LED_ID_AMBIGUITY_RESOLUTION, PIBAttribute_t::MAC_FRAME_CONTROL, PIBAttribute_t::MAC_SEQUENCE_NUMBER, PIBAttribute_t::MAC_DESTINATION_OWPAN_IDENTIFIER, PIBAttribute_t::MAC_DESTINATION_ADDRESS, PIBAttribute_t::MAC_SOURCE_OWPAN_IDENTIFIER, PIBAttribute_t::MAC_SOURCE_ADDRESS, PIBAttribute_t::MAC_ACKNOWLEDGE_FIELD, PIBAttribute_t::MAC_FRAME_PAYLOAD, PIBAttribute_t::MAC_FCS, PIBAttribute_t::MAC_MSDU_LENGTH, PIBAttribute_t::MAC_OFFSET_VPWM_DATA_USAGE, PIBAttribute_t::MAC_2DCODE_TX_DATA_TYPE));

OWPANDescritpor_t::OWPANDescritpor_t()
{
}

void __doPacking(omnetpp::cCommBuffer *b, const OWPANDescritpor_t& a)
{
    doParsimPacking(b,a.coordAddrMode);
    doParsimPacking(b,a.coordOWPANId);
    doParsimPacking(b,a.coordAddress);
    doParsimPacking(b,a.logicalChannel);
    doParsimPacking(b,a.superframeSpec);
    doParsimPacking(b,a.GTSPermit);
    doParsimPacking(b,a.linkQuality);
    doParsimPacking(b,a.timeStamp);
    doParsimPacking(b,a.securityFailure);
    doParsimPacking(b,a.securityLevel);
    doParsimPacking(b,a.keyIdMode);
    doParsimPacking(b,a.keySource);
    doParsimPacking(b,a.keyIndex);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OWPANDescritpor_t& a)
{
    doParsimUnpacking(b,a.coordAddrMode);
    doParsimUnpacking(b,a.coordOWPANId);
    doParsimUnpacking(b,a.coordAddress);
    doParsimUnpacking(b,a.logicalChannel);
    doParsimUnpacking(b,a.superframeSpec);
    doParsimUnpacking(b,a.GTSPermit);
    doParsimUnpacking(b,a.linkQuality);
    doParsimUnpacking(b,a.timeStamp);
    doParsimUnpacking(b,a.securityFailure);
    doParsimUnpacking(b,a.securityLevel);
    doParsimUnpacking(b,a.keyIdMode);
    doParsimUnpacking(b,a.keySource);
    doParsimUnpacking(b,a.keyIndex);
}

class OWPANDescritpor_tDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_coordAddrMode,
        FIELD_coordOWPANId,
        FIELD_coordAddress,
        FIELD_logicalChannel,
        FIELD_superframeSpec,
        FIELD_GTSPermit,
        FIELD_linkQuality,
        FIELD_timeStamp,
        FIELD_securityFailure,
        FIELD_securityLevel,
        FIELD_keyIdMode,
        FIELD_keySource,
        FIELD_keyIndex,
    };
  public:
    OWPANDescritpor_tDescriptor();
    virtual ~OWPANDescritpor_tDescriptor();

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

Register_ClassDescriptor(OWPANDescritpor_tDescriptor)

OWPANDescritpor_tDescriptor::OWPANDescritpor_tDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(OWPANDescritpor_t)), "")
{
    propertyNames = nullptr;
}

OWPANDescritpor_tDescriptor::~OWPANDescritpor_tDescriptor()
{
    delete[] propertyNames;
}

bool OWPANDescritpor_tDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OWPANDescritpor_t *>(obj)!=nullptr;
}

const char **OWPANDescritpor_tDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *OWPANDescritpor_tDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int OWPANDescritpor_tDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 13+base->getFieldCount() : 13;
}

unsigned int OWPANDescritpor_tDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_coordAddrMode
        FD_ISEDITABLE,    // FIELD_coordOWPANId
        FD_ISEDITABLE,    // FIELD_coordAddress
        0,    // FIELD_logicalChannel
        FD_ISEDITABLE,    // FIELD_superframeSpec
        FD_ISEDITABLE,    // FIELD_GTSPermit
        FD_ISEDITABLE,    // FIELD_linkQuality
        FD_ISEDITABLE,    // FIELD_timeStamp
        FD_ISEDITABLE,    // FIELD_securityFailure
        FD_ISEDITABLE,    // FIELD_securityLevel
        FD_ISEDITABLE,    // FIELD_keyIdMode
        FD_ISEDITABLE,    // FIELD_keySource
        FD_ISEDITABLE,    // FIELD_keyIndex
    };
    return (field >= 0 && field < 13) ? fieldTypeFlags[field] : 0;
}

const char *OWPANDescritpor_tDescriptor::getFieldName(int field) const
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
        "logicalChannel",
        "superframeSpec",
        "GTSPermit",
        "linkQuality",
        "timeStamp",
        "securityFailure",
        "securityLevel",
        "keyIdMode",
        "keySource",
        "keyIndex",
    };
    return (field >= 0 && field < 13) ? fieldNames[field] : nullptr;
}

int OWPANDescritpor_tDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "coordAddrMode") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "coordOWPANId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "coordAddress") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "logicalChannel") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "superframeSpec") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "GTSPermit") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "linkQuality") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "timeStamp") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "securityFailure") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "securityLevel") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "keyIdMode") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "keySource") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "keyIndex") == 0) return baseIndex + 12;
    return base ? base->findField(fieldName) : -1;
}

const char *OWPANDescritpor_tDescriptor::getFieldTypeString(int field) const
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
        "opticalChannel_t",    // FIELD_logicalChannel
        "uint16_t",    // FIELD_superframeSpec
        "bool",    // FIELD_GTSPermit
        "uint8_t",    // FIELD_linkQuality
        "uint32_t",    // FIELD_timeStamp
        "uint8_t",    // FIELD_securityFailure
        "uint8_t",    // FIELD_securityLevel
        "uint8_t",    // FIELD_keyIdMode
        "uint64_t",    // FIELD_keySource
        "uint8_t",    // FIELD_keyIndex
    };
    return (field >= 0 && field < 13) ? fieldTypeStrings[field] : nullptr;
}

const char **OWPANDescritpor_tDescriptor::getFieldPropertyNames(int field) const
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
        case FIELD_logicalChannel: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *OWPANDescritpor_tDescriptor::getFieldProperty(int field, const char *propertyName) const
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
        case FIELD_logicalChannel:
            if (!strcmp(propertyName, "enum")) return "opticalChannel_t";
            return nullptr;
        default: return nullptr;
    }
}

int OWPANDescritpor_tDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void OWPANDescritpor_tDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'OWPANDescritpor_t'", field);
    }
}

const char *OWPANDescritpor_tDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OWPANDescritpor_tDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        case FIELD_coordAddrMode: return enum2string(pp->coordAddrMode, "addressingMode_t");
        case FIELD_coordOWPANId: return ulong2string(pp->coordOWPANId);
        case FIELD_coordAddress: return uint642string(pp->coordAddress);
        case FIELD_logicalChannel: return enum2string(pp->logicalChannel, "opticalChannel_t");
        case FIELD_superframeSpec: return ulong2string(pp->superframeSpec);
        case FIELD_GTSPermit: return bool2string(pp->GTSPermit);
        case FIELD_linkQuality: return ulong2string(pp->linkQuality);
        case FIELD_timeStamp: return ulong2string(pp->timeStamp);
        case FIELD_securityFailure: return ulong2string(pp->securityFailure);
        case FIELD_securityLevel: return ulong2string(pp->securityLevel);
        case FIELD_keyIdMode: return ulong2string(pp->keyIdMode);
        case FIELD_keySource: return uint642string(pp->keySource);
        case FIELD_keyIndex: return ulong2string(pp->keyIndex);
        default: return "";
    }
}

void OWPANDescritpor_tDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        case FIELD_coordOWPANId: pp->coordOWPANId = string2ulong(value); break;
        case FIELD_coordAddress: pp->coordAddress = string2uint64(value); break;
        case FIELD_superframeSpec: pp->superframeSpec = string2ulong(value); break;
        case FIELD_GTSPermit: pp->GTSPermit = string2bool(value); break;
        case FIELD_linkQuality: pp->linkQuality = string2ulong(value); break;
        case FIELD_timeStamp: pp->timeStamp = string2ulong(value); break;
        case FIELD_securityFailure: pp->securityFailure = string2ulong(value); break;
        case FIELD_securityLevel: pp->securityLevel = string2ulong(value); break;
        case FIELD_keyIdMode: pp->keyIdMode = string2ulong(value); break;
        case FIELD_keySource: pp->keySource = string2uint64(value); break;
        case FIELD_keyIndex: pp->keyIndex = string2ulong(value); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OWPANDescritpor_t'", field);
    }
}

omnetpp::cValue OWPANDescritpor_tDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        case FIELD_coordAddrMode: return static_cast<int>(pp->coordAddrMode);
        case FIELD_coordOWPANId: return (omnetpp::intval_t)(pp->coordOWPANId);
        case FIELD_coordAddress: return (omnetpp::intval_t)(pp->coordAddress);
        case FIELD_logicalChannel: return static_cast<int>(pp->logicalChannel);
        case FIELD_superframeSpec: return (omnetpp::intval_t)(pp->superframeSpec);
        case FIELD_GTSPermit: return pp->GTSPermit;
        case FIELD_linkQuality: return (omnetpp::intval_t)(pp->linkQuality);
        case FIELD_timeStamp: return (omnetpp::intval_t)(pp->timeStamp);
        case FIELD_securityFailure: return (omnetpp::intval_t)(pp->securityFailure);
        case FIELD_securityLevel: return (omnetpp::intval_t)(pp->securityLevel);
        case FIELD_keyIdMode: return (omnetpp::intval_t)(pp->keyIdMode);
        case FIELD_keySource: return (omnetpp::intval_t)(pp->keySource);
        case FIELD_keyIndex: return (omnetpp::intval_t)(pp->keyIndex);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'OWPANDescritpor_t' as cValue -- field index out of range?", field);
    }
}

void OWPANDescritpor_tDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        case FIELD_coordOWPANId: pp->coordOWPANId = omnetpp::checked_int_cast<uint16_t>(value.intValue()); break;
        case FIELD_coordAddress: pp->coordAddress = omnetpp::checked_int_cast<uint64_t>(value.intValue()); break;
        case FIELD_superframeSpec: pp->superframeSpec = omnetpp::checked_int_cast<uint16_t>(value.intValue()); break;
        case FIELD_GTSPermit: pp->GTSPermit = value.boolValue(); break;
        case FIELD_linkQuality: pp->linkQuality = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_timeStamp: pp->timeStamp = omnetpp::checked_int_cast<uint32_t>(value.intValue()); break;
        case FIELD_securityFailure: pp->securityFailure = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_securityLevel: pp->securityLevel = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_keyIdMode: pp->keyIdMode = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        case FIELD_keySource: pp->keySource = omnetpp::checked_int_cast<uint64_t>(value.intValue()); break;
        case FIELD_keyIndex: pp->keyIndex = omnetpp::checked_int_cast<uint8_t>(value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OWPANDescritpor_t'", field);
    }
}

const char *OWPANDescritpor_tDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr OWPANDescritpor_tDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void OWPANDescritpor_tDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    OWPANDescritpor_t *pp = omnetpp::fromAnyPtr<OWPANDescritpor_t>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'OWPANDescritpor_t'", field);
    }
}

Register_Enum(scanType_t, (scanType_t::ACTIVE_SCAN, scanType_t::PASSIVE_SCAN, scanType_t::SCAN_OVER_BACKHAUL));

Register_Enum(MCS_t, (MCS_t::PHYI_11_67K, MCS_t::PHYI_24_44K, MCS_t::PHYI_48_89K, MCS_t::PHYI_73_3K, MCS_t::PHYI_100K, MCS_t::PHYI_35_56K, MCS_t::PHYI_71_11K, MCS_t::PHYI_124_4K, MCS_t::PHYI_266_6K, MCS_t::PHYII_1_25M, MCS_t::PHYII_2M, MCS_t::PHYII_2_5M, MCS_t::PHYII_4M, MCS_t::PHYII_5M, MCS_t::PHYII_6M, MCS_t::PHYII_9_6M, MCS_t::PHYII_12M, MCS_t::PHYII_19_2M, MCS_t::PHYII_24M, MCS_t::PHYII_38_4M, MCS_t::PHYII_48M, MCS_t::PHYII_76_8M, MCS_t::PHYII_96M));

Register_Enum(phyStatus_t, (phyStatus_t::BUSY, phyStatus_t::BUSY_RX, phyStatus_t::BUSY_TX, phyStatus_t::FORCE_TRX_OFF, phyStatus_t::IDLE, phyStatus_t::INVALID_PARAMETER_PHY, phyStatus_t::RX_ON, phyStatus_t::SUCCESS_PHY, phyStatus_t::TRX_OFF, phyStatus_t::TX_ON, phyStatus_t::UNSUPPORTED_ATTRIBUTE));

Register_Enum(topology_t, (topology_t::TOPOLOGY_INDEPENDENT, topology_t::TOPOLOGY_PEER_TO_PEER, topology_t::TOPOLOGY_STAR, topology_t::TOPOLOGY_BROADCAST));

namespace omnetpp {

}  // namespace omnetpp

