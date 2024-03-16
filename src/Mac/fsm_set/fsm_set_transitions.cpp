#include "fsm_set.h"

static uint8_t PIBAttributeCounter = 0;

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_idle_to_wait(Mac* mac) {
    mac->notificationSetRequest = false;
    mac->plme_set_request(mac->setPIBAttribute, mac->setPIBAttributeValue);
}

static void from_wait_to_idle (Mac* mac) {
    mac->notificationConfirmReceived = false;

    macStatus_t status;

    if (mac->confirmPhyStatus == phyStatus_t::UNSUPPORTED_ATTRIBUTE) {
        status = macStatus_t::UNSUPPORTED_ATTRIBUTE_MAC;
    } else if (mac->confirmPhyStatus == phyStatus_t::INVALID_PARAMETER_PHY) {
        status = macStatus_t::INVALID_PARAMETER;
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
const fsm_set_transition_t fsm_set_transition_table[FSM_SET_STATE_QTY][FSM_SET_STATE_QTY] = {
                /*ST_IDLE*/                 /*ST_WAIT*/
    /*ST_IDLE*/ {NULL,                  from_idle_to_wait,      },
    /*ST_WAIT*/ {from_wait_to_idle,     NULL,                   },
};
