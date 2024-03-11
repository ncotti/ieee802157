/*
 * states.h
 *
 *  Created on: Mar 11, 2024
 *      Author: cotti
 */

#ifndef STATES_H_
#define STATES_H_

#include <omnetpp.h>
#include "../mac.h"

using namespace omnetpp;

/******************************************************************************
 * Type definitions and defines
******************************************************************************/
/// Total amount of states
#define STATE_SUPERFRAME_QTY 4

/// @brief All possible states
typedef enum stateSuperframeEnum_t {
    ST_BEACON,
    ST_CAP,
    ST_CFP,
    ST_INACTIVE,
} stateSuperframeEnum_t;

/// @brief Represents a state, composed of the state's value and function.
typedef struct stateSuperframe_t {
    stateSuperframeEnum_t st;
    struct stateSuperframe_t (*stFn)(const cMessage*, Mac*);
} stateSuperframe_t;

/******************************************************************************
 * Extern state variables
******************************************************************************/
extern const stateSuperframe_t stBeacon;
extern const stateSuperframe_t stCAP;
extern const stateSuperframe_t stCFP;
extern const stateSuperframe_t stInactive;

/******************************************************************************
 * Prototypes
******************************************************************************/
stateSuperframe_t stateBeaconFn(const cMessage* msg, Mac* mac);
stateSuperframe_t stateCAPFn(const cMessage* msg, Mac* mac);
stateSuperframe_t stateCFPFn(const cMessage* msg, Mac* mac);
stateSuperframe_t stateInactiveFn(const cMessage* msg, Mac* mac);

#endif /* STATES_H_ */
