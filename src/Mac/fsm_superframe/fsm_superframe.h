/*
 * fsm_beacon.h
 *
 *  Created on: Mar 11, 2024
 *      Author: cotti
 */

#ifndef FSM_SUPERFRAME_H_
#define FSM_SUPERFRAME_H_

#include <omnetpp.h>
#include "states.h"
#include "transitions.h"

stateSuperframe_t fsmSuperframe(stateSuperframe_t currentState, const cMessage* msg, Mac* mac);

#endif /* FSM_SUPERFRAME_H_ */
