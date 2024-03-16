#include "fsm_get.h"

static uint8_t PIBAttributeCounter = 0;

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_idle_to_wait(Mac* mac) {
    mac->notificationGetRequest = false;
    mac->plme_get_request(mac->getPIBAttribute);
}

static void from_wait_to_idle (Mac* mac) {
    mac->notificationConfirmReceived = false;

    macStatus_t status;

    if (mac->confirmPhyStatus == phyStatus_t::UNSUPPORTED_ATTRIBUTE) {
        status = macStatus_t::UNSUPPORTED_ATTRIBUTE_MAC;
    } else {
        status = macStatus_t::SUCCESS;
    }
    mac->mlme_get_confirm(status, mac->getPIBAttribute, 0, mac->getPHYPIBAttributeValue);
}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_get_transition_t fsm_get_transition_table[FSM_GET_STATE_QTY][FSM_GET_STATE_QTY] = {
                /*ST_IDLE*/                 /*ST_WAIT*/
    /*ST_IDLE*/ {NULL,                  from_idle_to_wait,      },
    /*ST_WAIT*/ {from_wait_to_idle,     NULL,                   },
};
