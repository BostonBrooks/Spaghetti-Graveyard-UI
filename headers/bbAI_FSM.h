/**
 * @file
 * @brief A bbAI_FSM (Finite State Machine) contains the code to control behaviours of things in-game
*/

#ifndef BBAI_FSM_H
#define BBAI_FSM_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbPool.h"
#include "headers/bbGeometry.h"
#include "headers/bbConstants.h"

///bbAI_FSM is a Finite State Machine that controls things like monsters and characters in-game
typedef struct { //bbAI_FSM


	bbPool_data p_Pool;

/** @name State Stuff
 * Stuff for determining the state of the FSM
 **/
///@{
	bbSquareCoords m_SquareCoords;
	bbMapCoords    m_MapCoords;
	int32_t        m_Drawables[DRAWABLES_PER_AI];

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
} bbAI_FSM;


/* Functions:
 *  Update by memory address
 *  Update integer address in pool
 *  Update everything in pool
 */

/// bbAI_FSMs is a container for objects of type bbAI_FSM
typedef struct { //bbAI_FSMs

	bbPool* m_Pool;

} bbAI_FSMs;

/** Update individual AI given its location in memory */
int32_t bbAI_FSM_update(bbAI_FSM* fsm);

/** Update individual AI given its location in pool */
int32_t bbAI_FSM_update_int(int32_t bbMap_int, int32_t fsm_int);

/** Update all AIs in bbAI_FSMs container (given map number) */
int32_t bbAI_FSMs_update(int32_t bbMap_int);






#endif // BBAI_FSM_H