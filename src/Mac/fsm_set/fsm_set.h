#ifndef FSM_SET_H_
#define FSM_SET_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_set_state_t {
    ST_SET_IDLE,
    ST_SET_WAIT_CONFIRM,
} fsm_set_state_t;

#define FSM_SET_STATE_QTY 2                   /// Total amount of states
#define FSM_SET_INITIAL_STATE ST_SET_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_set_state_t (*fsm_set_fn_t)(Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_set_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
fsm_set_state_t fsm_set(Mac* mac);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_set_transition_t fsm_set_transition_table[FSM_SET_STATE_QTY][FSM_SET_STATE_QTY];

#endif // FSM_SET_H_
