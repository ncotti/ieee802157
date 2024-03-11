/*
 * fsm_beacon.c
 *
 *  Created on: Mar 11, 2024
 *      Author: cotti
 */

#include "fsm_superframe.h"

using namespace omnetpp;

/// @brief Finite State Machine. Execute current state, change to a new state
///     if corresponds, and apply transition from one state to other.
/// @param currentState Current state of the machine.
/// @param data Pointer to the data from the events that could trigger a
///     state transition.
/// @return Next state.
stateSuperframe_t fsmSuperframe(stateSuperframe_t currentState, const cMessage* msg, Mac* mac) {
    stateSuperframe_t newState = currentState.stFn(msg, mac);
    transitionSuperframeFn_t transition = transitionTableSuperframe[currentState.st][newState.st];
    if (transition) {
        transition(mac);
    }
    return newState;
}




