#include "fsm_reset.h"

static uint8_t PIBAttributeCounter = 0;

/******************************************************************************
 * Transition Functions
******************************************************************************/
static void from_idle_to_wait_trx(Mac* mac) {
    mac->notificationResetRequest = false;
    mac->plme_set_trx_state_request(phyStatus_t::FORCE_TRX_OFF);
}

static void from_wait_trx_to_idle (Mac* mac) {
    mac->notificationConfirmReceived = false;

    if (mac->setDefaultPIB) {
        mac->setDefaultPIB = false;
        mac->resetPIB();
    }

    mac->mlme_reset_confirm(macStatus_t::SUCCESS);
}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_reset_transition_t fsm_reset_transition_table[FSM_RESET_STATE_QTY][FSM_RESET_STATE_QTY] = {
                    /*ST_IDLE*/                 /*ST_WAIT_TRX*/
    /*ST_IDLE*/     {NULL,                      from_idle_to_wait_trx,  },
    /*ST_WAIT_TRX*/ {from_wait_trx_to_idle,     NULL,                   },
};
