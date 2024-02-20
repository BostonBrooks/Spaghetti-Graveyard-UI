/**
 * @brief A bbAI_FSM (Finite State Machine) contains the code to control behaviours of things in-game
*/

#ifndef BBAI_FSM_H
#define BBAI_FSM_H

#include "../headers/system_includes.h"

typedef struct { //bbAI_FSM

/** @name Pool Stuff
 * Stuff for including object in pool
 **/
///@{
	int32_t m_Pool_Self;
	int32_t m_Pool_Prev;
	int32_t m_Pool_Next;
	int32_t m_Pool_In_Use;
	int32_t m_Map;  ///What map was being loaded when this object was constructed?
///@}

/** @name State Stuff
 * Stuff for determining the state of the FSM
 **/
///@{
	bbSquareCoords m_SquareCoords;
	bbMapCoords    m_MapCoords;
	int32_t        m_Drawables[DRAWBLES_PER_AI];

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

	bbAI_FSM_Pool* m_Pool;

} bbAI_FSMs;

int32_t bbAIControl_update(bbAI_FSM* fsm);

/** Update individual AI given its location in pool */
int32_t bbAIControl_update_int(int32_t bbMap_int, int32_t fsm_int);

/** Update all AIs in pool */
int32_t bbAIControl_updatePool(int32_t bbMap_int);






#endif // BBAI_FSM_H