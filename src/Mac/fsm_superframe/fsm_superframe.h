#ifndef FSM_SUPERFRAME_H_
#define FSM_SUPERFRAME_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_superframe_state_t {
    ST_BEACON,
    ST_CAP,
    ST_CFP,
    ST_INACTIVE,
} fsm_superframe_state_t;

#define FSM_SUPERFRAME_STATE_QTY 4                  /// Total amount of states
#define FSM_SUPERFRAME_INITIAL_STATE ST_INACTIVE    /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_superframe_state_t (*fsm_superframe_fn_t)(const cMessage*, Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_superframe_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
void fsm_superframe(const cMessage* msg, Mac* mac);

fsm_superframe_state_t fsm_superframe_get_state(void);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_superframe_transition_t fsm_superframe_transition_table[FSM_SUPERFRAME_STATE_QTY][FSM_SUPERFRAME_STATE_QTY];

#endif // FSM_SUPERFRAME_H_
