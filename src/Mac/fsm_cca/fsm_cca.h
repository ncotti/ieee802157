#ifndef FSM_CCA_H_
#define FSM_CCA_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_cca_state_t {
    ST_CCA_IDLE,
    ST_CCA_WAIT_CONFIRM,
} fsm_cca_state_t;

#define FSM_CCA_STATE_QTY 2                   /// Total amount of states
#define FSM_CCA_INITIAL_STATE ST_CCA_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_cca_state_t (*fsm_cca_fn_t)(Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_cca_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
fsm_cca_state_t fsm_cca(Mac* mac);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_cca_transition_t fsm_cca_transition_table[FSM_CCA_STATE_QTY][FSM_CCA_STATE_QTY];

#endif // FSM_CCA_H_
