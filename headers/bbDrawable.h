/**
 * @file
* @brief bbGame is the root of all data stored by the game.
 *
 * ************************************
 *
*/

#ifndef BBDRAWABLE_H
#define BBDRAWABLE_H

#include "headers/bbSystemIncludes.h"
/** @name Avoidance types
 * Defines the footprint of a bbDrawable (m_AvoidanceShape) so other objects cannot walk through it.
 **/
///@{
#define AVOIDANCE_NULL             -1
#define AVOIDANCE_CIRCULAR          0
#define AVOIDANCE_SQUARE            1
#define AVOIDANCE_LINE              2
#define AVOIDANCE_RECTANGLE         3
#define AVOIDANCE_POLYGON           4
///@}


/** bbDrawable holds all the data about one object to be drawn to the viewport
 * and to interact with with AI_FSM objects.
 */

typedef struct { //bbDrawable
/** @name Pool Stuff
 * Stuff for including object in pool
 **/
///@{
	int32_t m_Pool_Self;
	int32_t m_Pool_Prev;
	int32_t m_Pool_Next;
	int32_t m_Pool_In_Use;
	///What map was m_CurrentMap when this object was constructed?
	int32_t m_Map;
///@}
/** @name Square Stuff
 * Linked list of drawables belonging to one bbDrawableSquare
 * Sorted by distance from the screen
 **/
///@{
    int32_t m_SquareNext;
	int32_t m_SquarePrev;
///@}
/** @name Costmetic Data
 * Stuff for drawing the drawable to the viewport
 **/
///@{
	int32_t m_Health;
	int32_t m_MaxHealth;
	int32_t m_DisplayHealthUntil;
	int32_t m_HealthBarHeight;
	int32_t m_HealthBarWidth;
	int32_t m_HealthBarLength;
	int32_t m_CosmeticRadius;

///@}
/** @name Animation Data
 * Stuff for drawing the drawable's animations to the viewport
 * These could all be rolled into the one sub-structure
 **/
///@{
	int32_t m_StartTime; //m_Frame[i] = ((current time - start time)/framerate)%frames
	int32_t m_Animation[ANIMATIONS_PER_DRAWABLE];
	int32_t m_Angle[ANIMATIONS_PER_DRAWABLE];
	int32_t m_Frame[ANIMATIONS_PER_DRAWABLE];
	int32_t m_DrawFunction[ANIMATIONS_PER_DRAWABLE];
///@}

/** @name Skin Data
 * Animation Data can be offloaded to a predefined set of values stored in a skin object
 **/
///@{

	int32_t m_Skin;
	int32_t m_State;
///@}
/** @name AI_FSM Data
 * Determines the behaviour of bbAI_FSM objects interacting with the drawable
 **/
///@{
bool m_Static;
	int32_t m_AvoidanceRadius;
	int32_t m_AvoidanceShape;
	bbMapCoords m_PreferredNextLocation;
	bbMapCoords m_TargetLocation;
	int32_t m_TargetDrawable;
///@}


} bbDrawable;

/// bbDrawableSquare contains drawables from one square of the maps' ground surface
typedef struct { //bbDrawableSquare

	int32_t m_Head;
	int32_t m_Tail;
} bbDrawableSquare;

/// bbDrawables contains drawables from all squares of the maps' ground surface
typedef struct { //bbTerrainSquare

	bbDrawable_Pool* m_Pool;
	///m_SquaresPerMapI by m_SquaresPerMapJ array of  bbDrawableSquare
	bbDrawableSquare** m_Squares;
	bbDrawableSquare m_Lost;

} bbDrawables;

#endif //BBDRAWABLE_H