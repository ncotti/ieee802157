#include "fsm_superframe.h"

/******************************************************************************
 * Transition Functions
******************************************************************************/
void from_beacon_to_CAP(Mac* mac) {

}

void from_CAP_to_CFP(Mac* mac) {
}

void from_CFP_to_inactive(Mac* mac) {
}

void from_inactive_to_beacon(Mac* mac) {
    mac->varBeaconInterval = aBaseSuperframeDuration * pow(2, mac->macBeaconOrder);

    if (mac->macSuperframeOrder != 15) {
        mac->varSuperframeDuration = aBaseSuperframeDuration * pow(2, mac->macSuperframeOrder);
        mac->varSlotDuration = aBaseSlotDuration * pow(2, mac->macSuperframeOrder);

        mac->varSlotCount = 0;
        mac->scheduleAfter(mac->varSlotDuration * mac->varOpticalClockDuration, mac->timerSlot);
    }

    mac->scheduleAfter(mac->varBeaconInterval * mac->varOpticalClockDuration, mac->timerBeaconInterval);

    // TODO transmit beacon frame without random access
}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_superframe_transition_t fsm_superframe_transition_table[FSM_SUPERFRAME_STATE_QTY][FSM_SUPERFRAME_STATE_QTY] = {
                    /*ST_BEACON*/   /*ST_CAP*/      /*ST_CFP*/      /*ST_INACTIVE*/
    /*ST_BEACON*/   {NULL,          NULL,           NULL,           NULL,       },
    /*ST_CAP*/      {NULL,          NULL,           NULL,           NULL,       },
    /*ST_CFP*/      {NULL,          NULL,           NULL,           NULL,       },
    /*ST_INACTIVE*/ {NULL,          NULL,           NULL,           NULL,       },
};
