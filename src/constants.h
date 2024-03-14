/*
 * mac_constants.h
 *
 *  Created on: Mar 10, 2024
 *      Author: cotti
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "phy_constants.h"



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
