/*
 * transitions.h
 *
 *  Created on: Mar 11, 2024
 *      Author: cotti
 */

#ifndef TRANSITIONS_H_
#define TRANSITIONS_H_

#include "states.h"

/******************************************************************************
 * Type definitions and external variables
******************************************************************************/
/// @brief Function pointer for transitions.
typedef void (*transitionSuperframeFn_t)(Mac* mac);

/// @brief Transition table, contains all actions to be done when passing
///     from one state to another.
extern transitionSuperframeFn_t transitionTableSuperframe[STATE_SUPERFRAME_QTY][STATE_SUPERFRAME_QTY];

/******************************************************************************
 * Prototypes
******************************************************************************/
/// @brief Actions executed while transitioning from state "A" to state "A"
void fromBeaconToCAP(Mac* mac);

/// @brief Actions executed while transitioning from state "A" to state "B"
void fromCAPToCFP(Mac* mac);

/// @brief Actions executed while transitioning from state "B" to state "C"
void fromCFPToInactive(Mac* mac);

/// @brief Actions executed while transitioning from state "C" to state "A"
void fromInactiveToBeacon(Mac* mac);

#endif /* TRANSITIONS_H_ */
