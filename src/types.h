/*
 * types.h
 *
 *  Created on: Mar 3, 2024
 *      Author: cotti
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <omnetpp.h>

/*******************************************************************************
 * MAC Types
*******************************************************************************/

typedef enum {
    BAT_UNKNOWN     = 0b00,
    BAT_LESS_50     = 0b01,
    BAT_MORE_50     = 0b10,
    BAT_CONNECTED   = 0b11,
} batteryInformation_t;

typedef enum {
    DEV_INFRASTRUCTURE  = 0b00,
    DEV_MOBILE          = 0b01,
    DEV_VEHICLE         = 0b10,
    DEV_UNKNOWN         = 0b11,
} deviceType_t;

typedef enum {
    NO_COLOR                = 0b00,
    FROM_DEVICE_TO_COORD    = 0b01,
    FROM_COORD_TO_DEVICE    = 0b10,
    BOTH_WAYS               = 0b11,
} colorStabilizationScheme_t;

typedef enum {
    MAX_200K    = 0b000,
    MAX_400K    = 0b001,
    MAX_3_75M   = 0b010,
    MAX_7_5M    = 0b011,
    MAX_15M     = 0b100,
    MAX_30M     = 0b101,
    MAX_60M     = 0b110,
    MAX_120M    = 0b111,
} maxSupportedOpticalClock_t;

typedef struct {
    bool powerSource;                           // "1" if connected to AC power mains
    batteryInformation_t batteryInformation;
    bool securityCapability;                    // Cryptographically protected MAC
    bool coordinatorCapability;
    bool traficSupport;                         // "0" if only capable of broadcasting
    bool broadcastSupport;
    bool peerToPeerSupport;
    bool starSupport;
    deviceType_t deviceType;
    bool beaconSupport;                         // "1" if capable of sending beacons
    bool dimmingSupport;
    bool continuousVisibilityTransmission;
    bool cvdSupport;
    bool phyISupport;
    bool phyIISupport;
    bool phyIIISupport;
    colorStabilizationScheme_t colorStabilizationCapability;
    maxSupportedOpticalClock_t maxTxClock;
    maxSupportedOpticalClock_t maxRxClock;
    bool explicitClockNotificationRequest;
    bool ccaSupport;
    bool phyIVSupport;
    bool phyVSupport;
    bool phyVISupport;
    uint8_t numberOfOpticalSources;
    uint8_t multipleDirectionSupport;
    uint16_t numberOfCellsSupported;
    uint8_t bandsUsedForPhy3;
    uint8_t* aggregationBitmap;     // For each "numberOfCellsSupported", indicate the sum of the channels opticalChannel_t is transmitting (each bit is a channel)
    uint8_t* guardBitmap;           // For each "numberOfCellsSupported", indicate the channels that "leak" and should be filtered.
} capabilityInformation_t;

typedef struct {
    uint8_t securityLevel;
    uint8_t keyIdMode;
    uint64_t keySource;
    uint8_t keyIndex;
} security_t ;

typedef enum {
    ASSOCIATION_REQUEST                     = 0x01,
    ASSOCIATION_RESPONSE                    = 0x02,
    DISASSOCIATION_NOTIFICATION             = 0x03,
    DATA_REQUEST                            = 0x04,
    OWPAN_ID_CONFLICT_NOTIFICATION          = 0x05,
    BEACON_REQUEST                          = 0x06,
    COORDINATOR_REALIGNMENT                 = 0x07,
    GTS_REQUEST                             = 0x08,
    BLINKING_NOTIFICATION                   = 0x09,
    DIMMING_NOTIFICATION                    = 0x0a,
    FAST_LINK_RECOVERY                      = 0x0b,
    MOBILITY_NOTIFICATION                   = 0x0c,
    GTS_RESPONSE                            = 0x0d,
    CLOCK_RATE_CHANGE_NOTIFICATION          = 0x0e,
    MULTIPLE_CHANNEL_ASSIGNMENT             = 0x0f,
    BAND_HOPING                             = 0x10,
    COLOR_STABILIZATION_TIMER_NOTIFICATION  = 0x11,
    COLOR_STABILIZATION_INFORMATION         = 0x12,
    CVD_DISABLE                             = 0x13,
    INFORMATION_ELEMENT                     = 0x14,
} commandFrameIdentifier_t;

typedef enum {
    ASSOCIATION_SUCCESSFUL = 0x00,
    OWPAN_AT_CAPACITY = 0x01,
    OWPAN_ACCESS_DENIED = 0x02,
    SUCCESS = 0x80,
    TRANSACTION_OVERFLOW,
    TRANSACTION_EXPIRED,
    CHANNEL_ACCESS_FAILURE,
    INVALID_ADDRESS,
    INVALID_GTS,
    NO_ACK,
    COUNTER_ERROR,
    FRAME_TOO_LONG,
    UNAVAILABLE_KEY,
    UNSUPPORTED_SECURITY,
    INVALID_PARAMETER,
} macStatus_t ;

typedef enum {
   beacon  = 0b000,
   data    = 0b001,
   ack     = 0b010,
   command = 0b011,
   cvd     = 0b100,
} frameType_t;

typedef enum {
   noAddress   = 0b00,
   broadcast   = 0b01,
   bit16       = 0b10,
   bit64       = 0b11,
} addressingMode_t;

typedef enum {
   single = 0b00,
   packed = 0b01,
   burst = 0b10,
} dataType_t;

// Logical channels are separated according to the optical wavelength.
// C_XX_YY indicates an optical channel between wavelengths XX and YY
typedef enum {
    C_190_380 = 0b000,
    C_380_529 = 0b001,
    C_529_598 = 0b010,
    C_598_649 = 0b011,
    C_649_694 = 0b100,
    C_694_737 = 0b101,
    C_737_780 = 0b110,
    C_780_10k = 0b111,
} opticalChannel_t;


typedef enum {
    MAC_ACK_WAIT_DURATION = 0x40,
    MAC_ASSOCIATED_OWPAN_COORD = 0x41,
    MAC_ASSOCIATED_PERMIT = 0x42,
    MAC_AUTO_REQUEST = 0x43,
    MAC_BEACON_PAYLOAD = 0x44,
    MAC_BEACON_PAYLOAD_LENGTH = 0x45,
    MAC_BEACON_ORDER = 0x46,
    MAC_BEACON_TX_TIME,
} macPibIdentifier_t ;

typedef struct {
    addressingMode_t coordAddrMode;
    uint16_t coordOWPANId;
    uint64_t coordAddress;
    opticalChannel_t logicalChannel;
    uint16_t superframeSpec;
    bool GTSPermit;
    uint8_t linkQuality;
    uint32_t timeStamp;
    uint8_t securityFailure;
    uint8_t securityLevel;
    uint8_t keyIdMode;
    uint64_t keySource;
    uint8_t keyIndex;
} OWPANDescritpor_t;

typedef enum {
    ACTIVE_SCAN = 0x00,
    PASSIVE_SCAN = 0x01,
    SCAN_OVER_BACKHAUL = 0x10,
} scanType_t;

/*******************************************************************************
 * PHY Types
*******************************************************************************/
typedef enum {
    PHYI_11_67K     = 0b000000,
    PHYI_24_44K     = 0b000001,
    PHYI_48_89K     = 0b000010,
    PHYI_73_3K      = 0b000011,
    PHYI_100K       = 0b000100,
    PHYI_35_56K     = 0b000101,
    PHYI_71_11K     = 0b000110,
    PHYI_124_4K     = 0b000111,
    PHYI_266_6K     = 0b001000,

    PHYII_1_25M     = 0b010000,
    PHYII_2M        = 0b010001,
    PHYII_2_5M      = 0b010010,
    PHYII_4M        = 0b010011,
    PHYII_5M        = 0b010100,
    PHYII_6M        = 0b010101,
    PHYII_9_6M      = 0b010110,
    PHYII_12M       = 0b010111,
    PHYII_19_2M     = 0b011000,
    PHYII_24M       = 0b011001,
    PHYII_38_4M     = 0b011010,
    PHYII_48M       = 0b011011,
    PHYII_76_8M     = 0b011100,
    PHYII_96M       = 0b011101,
} dataRate_t ;

typedef enum {
    PHY_CURRENT_CHANNEL                 = 0x00,
    PHY_CCA_MODE                        = 0x01,
    PHY_DIM                             = 0x02,
    PHY_USE_EXTENDED_MODE               = 0x03,
    PHY_COLOR_FUNCTION                  = 0x04,
    PHY_BLINKING_NOTIFICATION_FREQUENCY = 0x05,
    PHY_OCC_ENABLE                      = 0x06,
    PHY_OCC_MCS_ID                      = 0x07,
    PHY_PSDU_LENGTH                     = 0x08,
} phyPIBAtrribute_t;

typedef enum {
    BUSY                    = 0x00,
    BUSY_RX                 = 0x01,
    BUSY_TX                 = 0x02,
    FORCE_TRX_OFF           = 0x03,
    IDLE                    = 0x04,
    INVALID_PARAMETER_PHY   = 0x05,
    RX_ON                   = 0x06,
    SUCCESS_PHY             = 0x07,
    TRX_OFF                 = 0x08,
    TX_ON                   = 0x09,
    UNSUPPORTED_ATTRIBUTE   = 0x0a,
} phyStatus_t ;












#endif /* TYPES_H_ */
