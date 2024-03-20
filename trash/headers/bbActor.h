/**
 * @file
 * @brief A bbActor (Finite State Machine) contains the code to control behaviours of things in-game
*/

#ifndef BBACTOR_H
#define BBACTOR_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbPool.h"
#include "headers/bbGeometry.h"
#include "headers/bbConstants.h"

///bbActor is a Finite State Machine that controls things like monsters and characters in-game
typedef struct { //bbActor


	bbPool_data p_Pool;

/** @name State Stuff
 * Stuff for determining the state of the Actor
 **/
///@{
	bbSquareCoords m_SquareCoords;
	bbMapCoords    m_MapCoords;
	int32_t        m_Drawables[DRAWABLES_PER_ACTOR];

	/** What AI state function to call */
	int32_t m_ExternalState;
	/** Parameter of state function */
	int32_t m_InternalState;
	/**Set to true if the state has just been altered, otherwise false */
	bool m_StateTransition;
	/** Counts the number of loop iterations since last reset */
	int32_t m_Clock;

	/**Specifies a point in future given by the number of loops processed since loading the map.*/
	int32_t m_Clock2;
	/** The AI is attacking this position and if when the attack lands,
	 * the enemy is close enough to this point, it will be hit.
	 */
	bbMapCoords attack_centre;
///@}
} bbActor;


/* Functions:
 *  Update by memory address
 *  Update integer address in pool
 *  Update everything in pool
 */

/// bbActors is a container for objects of type bbActor
typedef struct { //bbActors

	bbPool* m_Pool;

} bbActors;

int32_t bbActor_new(bbActor** self, int32_t type, bbMapCoords location);

/** Update individual AI given its location in memory */
//int32_t bbActor_update(bbActor* actor);

/** Update individual AI given its location in pool */
//int32_t bbActor_updateI(int32_t bbMap_int, int32_t actor_int);

/** Update all AIs in bbActors pool) */
int32_t bbActors_updateI(bbPool* pool);






#endif // BBACTOR_H
