//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License; or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful;
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not; see http://www.gnu.org/licenses/.
// 

/// @brief Logical channels are separated according to the optical wavelength.
///     C_XX_YY indicates an optical channel between wavelengths XX and YY.
enum opticalChannel_t {
    C_190_380 = 0;
    C_380_529 = 1;
    C_529_598 = 2;
    C_598_649 = 3;
    C_649_694 = 4;
    C_694_737 = 5;
    C_737_780 = 6;
    C_780_10k = 7;
};

enum batteryInformation_t {
    BAT_UNKNOWN     = 0;
    BAT_LESS_50     = 1;
    BAT_MORE_50     = 2;
    BAT_CONNECTED   = 3;
};

enum deviceType_t {
    DEV_INFRASTRUCTURE  = 0;
    DEV_MOBILE          = 1;
    DEV_VEHICLE         = 2;
    DEV_UNKNOWN         = 3;
};

enum colorStabilizationScheme_t {
    NO_COLOR                = 0;
    FROM_DEVICE_TO_COORD    = 1;
    FROM_COORD_TO_DEVICE    = 2;
    BOTH_WAYS               = 3;
};

enum maxSupportedOpticalClock_t {
    MAX_200K    = 0;
    MAX_400K    = 1;
    MAX_3_75M   = 2;
    MAX_7_5M    = 3;
    MAX_15M     = 4;
    MAX_30M     = 5;
    MAX_60M     = 6;
    MAX_120M    = 7;
};

struct capabilityInformation_t {
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
    //uint8_t aggregationBitmap[];     // For each "numberOfCellsSupported"; indicate the sum of the channels opticalChannel_t is transmitting (each bit is a channel)
    //uint8_t guardBitmap[];           // For each "numberOfCellsSupported"; indicate the channels that "leak" and should be filtered.
};

struct security_t {
    uint8_t securityLevel;
    uint8_t keyIdMode;
    uint64_t keySource;
    uint8_t keyIndex;
};

enum commandFrameIdentifier_t {
    ASSOCIATION_REQUEST                     = 0x01;
    ASSOCIATION_RESPONSE                    = 0x02;
    DISASSOCIATION_NOTIFICATION             = 0x03;
    DATA_REQUEST                            = 0x04;
    OWPAN_ID_CONFLICT_NOTIFICATION          = 0x05;
    BEACON_REQUEST                          = 0x06;
    COORDINATOR_REALIGNMENT                 = 0x07;
    GTS_REQUEST                             = 0x08;
    BLINKING_NOTIFICATION                   = 0x09;
    DIMMING_NOTIFICATION                    = 0x0a;
    FAST_LINK_RECOVERY                      = 0x0b;
    MOBILITY_NOTIFICATION                   = 0x0c;
    GTS_RESPONSE                            = 0x0d;
    CLOCK_RATE_CHANGE_NOTIFICATION          = 0x0e;
    MULTIPLE_CHANNEL_ASSIGNMENT             = 0x0f;
    BAND_HOPING                             = 0x10;
    COLOR_STABILIZATION_TIMER_NOTIFICATION  = 0x11;
    COLOR_STABILIZATION_INFORMATION         = 0x12;
    CVD_DISABLE                             = 0x13;
    INFORMATION_ELEMENT                     = 0x14;
};

enum macStatus_t {
    ASSOCIATION_SUCCESSFUL = 0x00;
    OWPAN_AT_CAPACITY = 0x01;
    OWPAN_ACCESS_DENIED = 0x02;
    SUCCESS = 0x80;
    TRANSACTION_OVERFLOW = 0x81;
    TRANSACTION_EXPIRED = 0x82;
    CHANNEL_ACCESS_FAILURE = 0x83;
    INVALID_ADDRESS = 0x84;
    INVALID_GTS = 0x85;
    NO_ACK = 0x86;
    COUNTER_ERROR = 0x87;
    FRAME_TOO_LONG = 0x88;
    UNAVAILABLE_KEY = 0x89;
    UNSUPPORTED_SECURITY = 0x8a;
    INVALID_PARAMETER = 0x8b;
    INVALID_INDEX = 0x8c;
    UNSUPPORTED_ATTRIBUTE_MAC = 0x8d;
    READ_ONLY = 0x8e;
    SCAN_IN_PROGRESS = 0x8f;
};

enum frameType_t {
   beacon  = 0;
   data    = 1;
   ack     = 2;
   command = 3;
   cvd     = 4;
};

enum addressingMode_t {
   noAddress   = 0;
   broadcast   = 1;
   bit16       = 2;
   bit64       = 3;
};

enum dataType_t {
   single = 0;
   packed = 1;
   burst = 2;
};

enum PIBAttribute_t {
    PHY_CURRENT_CHANNEL                 = 0x00;
    PHY_CCA_MODE                        = 0x01;
    PHY_DIM                             = 0x02;
    PHY_USE_EXTENDED_MODE               = 0x03;
    PHY_COLOR_FUNCTION                  = 0x04;
    PHY_BLINKING_NOTIFICATION_FREQUENCY = 0x05;
    PHY_OCC_ENABLE                      = 0x06;
    PHY_OCC_MCS_ID                      = 0x07;
    PHY_PSDU_LENGTH                     = 0x08;

    MAC_ACK_WAIT_DURATION = 0x40;
    MAC_ASSOCIATED_OWPAN_COORD = 0x41;
    MAC_ASSOCIATED_PERMIT = 0x42;
    MAC_AUTO_REQUEST = 0x43;
    MAC_BEACON_PAYLOAD = 0x44;
    MAC_BEACON_PAYLOAD_LENGTH = 0x45;
    MAC_BEACON_ORDER = 0x46;
    MAC_BEACON_TX_TIME = 0x47;
    MAC_BSN = 0x48;
    MAC_COORD_EXTENDED_ADDRESS = 0x49;
    MAC_COORD_SHORT_ADDRESS = 0x4a;
    MAC_DSN = 0x4b;
    MAC_GTS_PERMIT = 0x4c;
    MAC_MAX_BE = 0x4d;
    MAC_MAX_CSMA_BACKOFFS = 0x4e;
    MAC_MAX_FRAME_TOTAL_WAIT_TIME = 0x4f;
    MAC_MAX_FRAME_RETRIES = 0x50;
    MAC_MIN_BE = 0x51;
    MAC_MIN_LIFS_PERIOD = 0x52;
    MAC_MIN_SIFS_PERIOD = 0x53;
    MAC_OWPAN_ID = 0x54;
    MAC_RESPONSE_WAIT_TIME = 0x55;
    MAC_RX_ON_WHEN_IDLE = 0x56;
    MAC_SECURITY_ENABLED = 0x57;
    MAC_SHORT_ADDRESS = 0x58;
    MAC_SUPERFRAME_ORDER = 0x59;
    MAC_TIMESTAMP_SUPPORTED = 0x5a;
    MAC_TRANSACTION_PERSISTENCE_TIME = 0x5b;
    MAC_DIM = 0x5c;
    MAC_NUM_ACKS = 0x5d;
    MAC_LINK_TIME_OUT = 0x5e;
    MAC_DIM_OVERRIDE_REQUEST = 0x5f;
    MAC_DIM_PWM_OVERRIDE_REQUEST = 0x60;
    MAC_DIM_DATA_FAILURE_INDICATION = 0x61;
    MAC_DURING_ASSOC_COLOR = 0x62;
    MAC_DURING_DISASSOC_COLOR = 0x63;
    MAC_DURING_SCAN_COLOR = 0x64;
    MAC_COLOR_RECEIVED = 0x65;
    MAC_COLOR_NOT_RECEIVED = 0x66;
    MAC_CQI_COLOR_LFER = 0x67;
    MAC_CQI_COLOR_MFER = 0x68;
    MAC_CQI_COLOR_HFER = 0x69;
    MAC_CF_APP_COLOR = 0x6a;
    MAC_COLOR_STABILIZATION = 0x6b;
    MAC_COLOR_STABILIZATION_TIMER = 0x6c;
    MAC_USE_DIMMED_OOK_MODE = 0x6d;
    MAC_TIME_STAMP_OFFSET = 0x6e;
    MAC_USE_BLINKING_NOTIFICATION = 0x6f;
    MAC_BLINKING_NOTIFICATION_FREQUENCY = 0x70;
    MAC_LED_ID_AMBIGUITY_RESOLUTION = 0x71;
    MAC_FRAME_CONTROL = 0x72;
    MAC_SEQUENCE_NUMBER = 0x73;
    MAC_DESTINATION_OWPAN_IDENTIFIER = 0x74;
    MAC_DESTINATION_ADDRESS = 0x75;
    MAC_SOURCE_OWPAN_IDENTIFIER = 0x76;
    MAC_SOURCE_ADDRESS = 0x77;
    MAC_ACKNOWLEDGE_FIELD = 0x78;
    MAC_FRAME_PAYLOAD = 0x79;
    MAC_FCS = 0x7a;
    MAC_MSDU_LENGTH = 0x7b;
    MAC_OFFSET_VPWM_DATA_USAGE = 0x7c;
    MAC_2DCODE_TX_DATA_TYPE = 0x7d;
};

struct OWPANDescritpor_t {
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
};

enum scanType_t {
    ACTIVE_SCAN = 0x00;
    PASSIVE_SCAN = 0x01;
    SCAN_OVER_BACKHAUL = 0x10;
};


enum MCS_t {
    PHYI_11_67K     = 0x00;
    PHYI_24_44K     = 0x01;
    PHYI_48_89K     = 0x02;
    PHYI_73_3K      = 0x03;
    PHYI_100K       = 0x04;
    PHYI_35_56K     = 0x05;
    PHYI_71_11K     = 0x06;
    PHYI_124_4K     = 0x07;
    PHYI_266_6K     = 0x08;

    PHYII_1_25M     = 0x10;
    PHYII_2M        = 0x11;
    PHYII_2_5M      = 0x12;
    PHYII_4M        = 0x13;
    PHYII_5M        = 0x14;
    PHYII_6M        = 0x15;
    PHYII_9_6M      = 0x16;
    PHYII_12M       = 0x17;
    PHYII_19_2M     = 0x18;
    PHYII_24M       = 0x19;
    PHYII_38_4M     = 0x1a;
    PHYII_48M       = 0x1b;
    PHYII_76_8M     = 0x1c;
    PHYII_96M       = 0x1d;
};


enum phyStatus_t {
    BUSY                    = 0x00;
    BUSY_RX                 = 0x01;
    BUSY_TX                 = 0x02;
    FORCE_TRX_OFF           = 0x03;
    IDLE                    = 0x04;
    INVALID_PARAMETER_PHY   = 0x05;
    RX_ON                   = 0x06;
    SUCCESS_PHY             = 0x07;
    TRX_OFF                 = 0x08;
    TX_ON                   = 0x09;
    UNSUPPORTED_ATTRIBUTE   = 0x0a;
};

enum topology_t {
    TOPOLOGY_INDEPENDENT = 0x00;
    TOPOLOGY_PEER_TO_PEER = 0x01;
    TOPOLOGY_STAR = 0x02;
    TOPOLOGY_BROADCAST = 0x03;
}
