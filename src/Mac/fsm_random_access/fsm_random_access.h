#ifndef FSM_RANDOM_ACCESS_H_
#define FSM_RANDOM_ACCESS_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_random_access_state_t {
    ST_IDLE,
    ST_WAIT_FOR_BACKOFF_BOUNDARY,
    ST_DELAY,
    ST_CCA,
    ST_TRANSMIT,
    ST_WAIT_FOR_ACK,
    ST_RETRY,
} fsm_random_access_state_t;

#define FSM_RANDOM_ACCESS_STATE_QTY 7               /// Total amount of states
#define FSM_RANDOM_ACCESS_INITIAL_STATE ST_IDLE     /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_random_access_state_t (*fsm_random_access_fn_t)(const cMessage*, Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_random_access_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
fsm_random_access_state_t fsm_random_access(const cMessage* msg, Mac* mac);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_random_access_transition_t fsm_random_access_transition_table[FSM_RANDOM_ACCESS_STATE_QTY][FSM_RANDOM_ACCESS_STATE_QTY];

#endif // FSM_RANDOM_ACCESS_H_
