#include "fsm_random_access.h"

/******************************************************************************
 * Transition Functions
******************************************************************************/
void from_idle_to_wait_for_backoff_boundary(Mac* mac) {
    mac->varNumberOfBackoffs = 0;
    mac->varBackoffExponent = mac->macMinBE;
}

void from_idle_to_delay(Mac* mac) {
    mac->varNumberOfBackoffs = 0;
    mac->varBackoffExponent = mac->macMinBE;
    mac->varRandomDelay = mac->intuniform(0, pow(2, mac->varBackoffExponent) - 1);
}

void from_wait_for_backoff_boundary_to_delay(Mac* mac) {
    mac->varRandomDelay = mac->intuniform(0, pow(2, mac->varBackoffExponent) - 1);
}

void from_delay_to_delay(Mac* mac) {
    mac->varRandomDelay--;
}

void from_CCA_to_retry(Mac* mac) {
    mac->varNumberOfBackoffs++;
    mac->varBackoffExponent = (mac->varBackoffExponent + 1 < mac->macMaxBE) ? mac->varBackoffExponent + 1 :  mac->macMaxBE;
}

void from_transmit_to_wait_for_ack(Mac* mac) {
    mac->scheduleAfter(mac->macAckWaitDuration * mac->varOpticalClockDuration, mac->notificationAckNotReceived);
}

void from_transmit_to_idle(Mac* mac) {
    mac->scheduleAfter(0, mac->notificationTxSuccess);
}

void from_wait_for_ack_to_idle(Mac* mac) {
    mac->cancelEvent(mac->notificationAckNotReceived);

    mac->scheduleAfter(0, mac->notificationTxSuccess);
}

void from_wait_for_ack_to_retry(Mac* mac) {
    mac->varNumberOfBackoffs++;
    mac->varBackoffExponent = (mac->varBackoffExponent + 1 < mac->macMaxBE) ? mac->varBackoffExponent + 1 :  mac->macMaxBE;
}

void from_retry_to_idle(Mac* mac) {
    mac->scheduleAfter(0, mac->notificationTxFailure);
}

void from_retry_to_delay(Mac* mac) {
    mac->varRandomDelay = mac->intuniform(0, pow(2, mac->varBackoffExponent) - 1);
}

/******************************************************************************
 * Transition Table
******************************************************************************/
/// @brief Transition table, holding all actions to be executed when
///     transitioning from state "X" to state "Y" as a matrix:
///         transition_table[X][Y]
const fsm_random_access_transition_t fsm_random_access_transition_table[FSM_RANDOM_ACCESS_STATE_QTY][FSM_RANDOM_ACCESS_STATE_QTY] = {
        {NULL,          from_idle_to_wait_for_backoff_boundary,           from_idle_to_delay,                        NULL,                   NULL,                       NULL,           NULL,           },
        {NULL,          NULL,                                       from_wait_for_backoff_boundary_to_delay,      NULL,                   NULL,                       NULL,           NULL,           },
        {NULL,          NULL,                                       from_delay_to_delay,                       NULL,                   NULL,                       NULL,           NULL,           },
        {NULL,          NULL,                                       NULL,                                   NULL,                   NULL,      NULL,           from_CCA_to_retry, },
        {from_transmit_to_idle,          NULL,                                       NULL,                                   NULL,                   from_transmit_to_wait_for_ack,                       NULL,           NULL,        },
        {from_wait_for_ack_to_idle,          NULL,                                       NULL,                                   NULL,                   NULL,                       NULL,           from_wait_for_ack_to_retry,      },
        {from_retry_to_idle,          NULL,                                       from_retry_to_delay,                                   NULL,                   NULL,                       NULL,           NULL,           },
};
