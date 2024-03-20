/**
 * @file
 * @brief bbGame is the root of all data stored by the game.
 *
 */

#ifndef BBTERRAIN_H
#define BBTERRAIN_H

#include "headers/bbSystemIncludes.h"

/// bbTerrainSquare holds textures from one square of the maps' ground surface
typedef struct { //bbTerrainSquare

} bbTerrainSquare;

/// bbTerrainSquares holds textures from all square of the maps' ground surface
typedef struct { //bbTerrainSquare
	///m_SquaresPerMapI by m_SquaresPerMapJ array of pointers of type bbTerrainSquare
	bbTerrainSquare*** m_Squares;
} bbTerrainSquares;

#endif //BBTERRAIN_H