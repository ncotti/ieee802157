#ifndef FSM_START_NET_H_
#define FSM_START_NET_H_

#include <omnetpp.h>
#include "../Net.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_start_net_state_t {
    ST_START_NET_IDLE,
    ST_START_NET_RESET,
    ST_START_NET_SET_OWPAN_ID,
    ST_START_NET_SCAN,
    ST_START_NET_SET_VARIABLES,
    ST_START_NET_START,
} fsm_start_net_state_t;

#define FSM_START_NET_STATE_QTY 8                       /// Total amount of states
#define FSM_START_NET_INITIAL_STATE ST_START_NET_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_start_net_state_t (*fsm_start_net_fn_t)(Net*);

/// @brief Function pointer for transitions.
typedef void (*fsm_start_net_transition_t)(Net*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Nethine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
void fsm_start_net(Net* net);

fsm_start_net_state_t fsm_start_net_get_state(void);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_start_net_transition_t fsm_start_net_transition_table[FSM_START_NET_STATE_QTY][FSM_START_NET_STATE_QTY];

#endif // FSM_START_NET_H_
