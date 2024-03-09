/**
 * @file
 * @brief The functions in this folder define the behavior of an object with class bbActor and type NULL
 */
#include "headers/bbGeometry.h"
#include "headers/bbSystemIncludes.h"
#include "headers/bbFlags.h"
#include "headers/bbActor.h"

///	Spawn a null actor on selected map at coordinates mc
int32_t bbActor_NULL_new(bbActor** actor, int32_t map, bbMapCoords mc){}

/// Update actor
int32_t bbActor_NULL_update(bbActor* actor){}

/// Send a command to the actor
int32_t bbActor_NULL_onCommand(bbActor* actor, int32_t command, void* data){}

/// Delete actor, (being careful not to leave any dangling pointers)
int32_t bbActor_NULL_delete(bbActor* actor){}
