/*
 * phy_constants.h
 *
 *  Created on: Mar 14, 2024
 *      Author: cotti
 */

#ifndef PHY_CONSTANTS_H_
#define PHY_CONSTANTS_H_

/// PHY sublayer constants
#define aMaxPHYIFrameSize 1023
#define aMaxPHYIIFrameSize 65535
#define aTurnaroundTime_TX_RX 0
#define aTurnaroundTime_RX_TX_PHYI 240
#define aTurnaroundTime_RX_TX_PHYII 5120
#define aPreambleFrequency 2232
#define aFrequencyLabelingRatio 1.5

// TDP (Topology dependent patters)
#define TDP_VISIBILITY_P1       (uint64_t) 0b111101011001000
#define TDP_PEER_TO_PEER_P2     (uint64_t) 0b001011101111110
#define TDP_STAR_P3             (uint64_t) 0b100110000010011
#define TDP_BROADCAST_P4        (uint64_t) 0b010000110100101



#endif /* PHY_CONSTANTS_H_ */
