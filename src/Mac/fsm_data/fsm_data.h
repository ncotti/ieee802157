#ifndef FSM_DATA_H_
#define FSM_DATA_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Types and definitions
******************************************************************************/
/// @brief All possible states
typedef enum fsm_data_state_t {
    ST_DATA_IDLE,
    ST_DATA_RX_ON,
    ST_DATA_CCA,
    ST_DATA_TX_ON,
    ST_DATA_TRANSMIT,
    ST_DATA_WAIT_FOR_ACK,
    ST_DATA_TRX_OFF,


} fsm_data_state_t;

#define FSM_DATA_STATE_QTY 8                   /// Total amount of states
#define FSM_DATA_INITIAL_STATE ST_DATA_IDLE   /// Initial state

/// @brief Function pointer for state functions.
typedef fsm_data_state_t (*fsm_data_fn_t)(Mac*);

/// @brief Function pointer for transitions.
typedef void (*fsm_data_transition_t)(Mac*);

/******************************************************************************
 * Prototypes and external variables
******************************************************************************/
/// @brief Finite State Machine. Executes current state, changes to a new state
///     if corresponds, and applies transition from one state to other.
/// @param data Pointer to the data from events that could trigger a
///     state transition, or could be modified during the transition.
/// @return Current state, after executing the transition.
void fsm_data(Mac* mac);

fsm_data_state_t fsm_data_get_state(void);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern const fsm_data_transition_t fsm_data_transition_table[FSM_DATA_STATE_QTY][FSM_DATA_STATE_QTY];

#endif // FSM_DATA_H_
