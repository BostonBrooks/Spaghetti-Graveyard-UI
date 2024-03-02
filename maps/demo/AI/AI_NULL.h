/**
 * @file
 * @brief The functions in this folder define the behavior of an object with class bbAI_FSM and type NULL
 */
#include "headers/bbGeometry.h"
#include "headers/bbSystemIncludes.h"
#include "headers/bbFlags.h"
#include "headers/bbAI_FSM.h"

///	Spawn a null AI Finite State Machine on selected map at coordinates mc
int32_t AI_NULL_new(int32_t map, bbMapCoords mc){}

/// Update Finite State Machine
int32_t AI_NULL_update(bbAI_FSM* ai){}

/// Send a command to the Finite State Machine
int32_t AI_NULL_onCommand(bbAI_FSM* ai, int32_t command, void* data){}

/// Delete Finite State Machine
int32_t AI_NULL_delete(bbAI_FSM* ai){}