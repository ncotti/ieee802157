/*
 * transitions.cpp
 *
 *  Created on: Mar 11, 2024
 *      Author: cotti
 */

#include "transitions.h"

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transitionTable[X][Y]
transitionSuperframeFn_t transitionTableSuperframe[STATE_SUPERFRAME_QTY][STATE_SUPERFRAME_QTY] = {
    {NULL,      NULL,    NULL,     NULL, },
    {NULL,          NULL,        NULL, NULL,  },
    {NULL,      NULL,        NULL, NULL       },
};

/******************************************************************************
 * Transition Functions
******************************************************************************/
void fromBeaconToCAP(Mac* mac) {

}

void fromCAPToCFP(Mac* mac) {
}

void fromCFPToInactive(Mac* mac) {
}

void fromInactiveToBeacon(Mac* mac) {
    mac->varBeaconInterval = aBaseSuperframeDuration * pow(2, mac->macBeaconOrder);

    if (mac->macSuperframeOrder != 15) {
        mac->varSuperframeDuration = aBaseSuperframeDuration * pow(2, mac->macSuperframeOrder);
        mac->varSlotDuration = aBaseSlotDuration * pow(2, mac->macSuperframeOrder);

        mac->varSlotCount = 0;
        mac->scheduleAfter(mac->varSlotDuration * mac->varOpticalClockDuration, mac->timerSlot);
    }

    mac->scheduleAfter(mac->varBeaconInterval * mac->varOpticalClockDuration, mac->timerBeaconInterval);

    // TODO transmit beacon frame
}

