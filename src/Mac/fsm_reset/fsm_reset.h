#ifndef FSM_RESET_H_
#define FSM_RESET_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_reset_state_t {
    ST_RESET_IDLE,
    ST_RESET_WAIT_TRX_CONFIRM,
} fsm_reset_state_t;

#define FSM_RESET_STATE_QTY 2                   /// Total amount of states
#define FSM_RESET_INITIAL_STATE ST_RESET_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_reset_state_t (*fsm_reset_fn_t)(Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_reset_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
fsm_reset_state_t fsm_reset(Mac* mac);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_reset_transition_t fsm_reset_transition_table[FSM_RESET_STATE_QTY][FSM_RESET_STATE_QTY];

#endif // FSM_RESET_H_
