#ifndef FSM_GET_H_
#define FSM_GET_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_get_state_t {
    ST_GET_IDLE,
    ST_GET_WAIT_CONFIRM,
} fsm_get_state_t;

#define FSM_GET_STATE_QTY 2                   /// Total amount of states
#define FSM_GET_INITIAL_STATE ST_GET_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_get_state_t (*fsm_get_fn_t)(Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_get_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
fsm_get_state_t fsm_get(Mac* mac);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_get_transition_t fsm_get_transition_table[FSM_GET_STATE_QTY][FSM_GET_STATE_QTY];

#endif // FSM_GET_H_
