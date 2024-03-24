#include "fsm_cca.h"

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_idle_to_wait(Mac* mac) {
    mac->notificationSetRequest = false;
    mac->plme_set_request(mac->setPIBAttribute, mac->setPIBAttributeValue);
}

static void from_wait_to_idle (Mac* mac) {
    macStatus_t status;

    mac->notificationConfirmReceived = false;

    if (mac->confirmPhyStatus == phyStatus_t::UNSUPPORTED_ATTRIBUTE) {
        status = macStatus_t::UNSUPPORTED_ATTRIBUTE_MAC;
    } else if (mac->confirmPhyStatus == phyStatus_t::INVALID_PARAMETER_PHY) {
        status = macStatus_t::INVALID_PARAMETER;
    } else {
        status = macStatus_t::SUCCESS;
    }
    mac->mlme_set_confirm(status, mac->setPIBAttribute, 0);
}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_cca_transition_t fsm_cca_transition_table[FSM_CCA_STATE_QTY][FSM_CCA_STATE_QTY] = {
                /*ST_IDLE*/                 /*ST_WAIT*/
    /*ST_IDLE*/ {NULL,                  from_idle_to_wait,      },
    /*ST_WAIT*/ {from_wait_to_idle,     NULL,                   },
};
