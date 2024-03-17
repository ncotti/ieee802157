#ifndef FSM_SCAN_H_
#define FSM_SCAN_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_scan_state_t {
    ST_SCAN_IDLE,
    ST_SCAN_WAIT_FOR_BEACON_INACTIVE,
    ST_SCAN_CHANGING_CHANNEL,
    ST_SCAN_TX_ON,
    ST_SCAN_SENDING_DATA,
    ST_SCAN_RX_ON,
    ST_SCAN_RECEIVING_DATA,
    ST_SCAN_TRX_OFF,

} fsm_scan_state_t;

#define FSM_SCAN_STATE_QTY 8                   /// Total amount of states
#define FSM_SCAN_INITIAL_STATE ST_SCAN_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_scan_state_t (*fsm_scan_fn_t)(Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_scan_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
void fsm_scan(Mac* mac);

fsm_scan_state_t fsm_scan_get_state(void);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_scan_transition_t fsm_scan_transition_table[FSM_SCAN_STATE_QTY][FSM_SCAN_STATE_QTY];

#endif // FSM_SCAN_H_
