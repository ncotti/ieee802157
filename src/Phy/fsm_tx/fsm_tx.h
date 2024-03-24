#ifndef FSM_TX_H_
#define FSM_TX_H_

#include <omnetpp.h>
#include "../phy.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_tx_state_t {
    ST_TX_IDLE,
    ST_TX_WAIT_CONFIRM,
} fsm_tx_state_t;

#define FSM_TX_STATE_QTY 2                   /// Total amount of states
#define FSM_TX_INITIAL_STATE ST_TX_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_tx_state_t (*fsm_tx_fn_t)(Phy*);

/// @brief Function pointer for transitions.
typedef void (*fsm_tx_transition_t)(Phy*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
fsm_tx_state_t fsm_tx(Phy* mac);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_tx_transition_t fsm_tx_transition_table[FSM_TX_STATE_QTY][FSM_TX_STATE_QTY];

#endif // FSM_TX_H_
