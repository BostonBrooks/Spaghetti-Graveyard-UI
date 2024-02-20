/**
 * @file
 * @brief bbMap stores all the game data pertaining to one map in the game.
 * There should be enough data provided to update the map,
 * but not display the graphics of the game.
*/

#ifndef BBMAP_H
#define BBMAP_H

#include "../headers/bbSystemIncludes.h"

typedef struct { //bbMap

/** @name Constants
 * Many of the constants in constants.h in the previous iteration will be offloaded here
 **/
///@{
    ///How large things like monsters appear on screen
    float m_3DScale;
	///How large things like spell buttons appear on screen
	float m_2DScale;

	int32_t m_ElevationScale;
	int32_t m_MaxPixelValue;

	int32_t m_PointsPerPixel;
	int32_t m_PixelsPerTile;
	int32_t m_TilesPerSquare;
	int32_t m_SquaresPerMapI;
	int32_t m_SquaresPerMapJ;

	int32_t m_FramerateLimit;



///@}
/** @name Derived Constants **/
///@{
	int32_t m_PointsPerTile;
	int32_t m_PointsPerSquare;
	int32_t m_PixelsPerSquare;

///@}
	/// Increased with every update of the map
	int32_t m_MapTime;


	bbTerain* m_Terrain;
	bbDrawables* m_Drawables;
	bbAI_FSMs* m_AI_FSMs;




	bbMedia* m_Media;
	bbWidgets* m_widgets;



} bbMap;

#endif //BBMAP_H