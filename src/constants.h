/*
 * mac_constants.h
 *
 *  Created on: Mar 10, 2024
 *      Author: cotti
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/// PHY sublayer constants
#define aMaxPHYIFrameSize 1023
#define aMaxPHYIIFrameSize 65535
#define aTurnaroundTime_TX_RX 0
#define aTurnaroundTime_RX_TX_PHYI 240
#define aTurnaroundTime_RX_TX_PHYII 5120
#define aPreambleFrequency 2232
#define aFrequencyLabelingRatio 1.5

/// MAC sublayer constants, as defined in Table 61 of the IEEE 802.15.7
#define aBaseSlotDuration           60
#define aBaseSuperframeDuration     (aBaseSlotDuration * aNumSuperframeSlots)
#define aExtendedAddress            ((uint64_t) 0x1) // Device specific
#define aGTSDDescPersistenceTime    4
#define aMaxBeaconOverhead          75
#define aMaxBeaconPayloadLength     (aMaxPHYIFrameSize - aMaxBeaconOverhead)
#define aMaxLostBeacons             4
#define aMaxMACPayloadSize          (aMaxPHYIFrameSize - aMinMPDUOverhead)
#define aMaxMPDUUnsecuredOverhead   25
#define aMaxSIFSFrameSize           18
#define aMinCAPLength               440
#define aMinMPDUOverhead            9
#define aNumSuperframeSlots         16
#define aUnitBackoffPeriod          20



#endif /* CONSTANTS_H_ */
