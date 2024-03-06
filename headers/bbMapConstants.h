/**
 * @file
 * @brief bbMapConstants stores all the constants that have been removed from global scope and given per-map scope
 */
#ifndef BBMAPCONSTANTS_H
#define BBMAPCONSTANTS_H

#include <inttypes.h>

typedef struct {

/** @name Constants
 * Many of the constants in constants.h in the previous iteration will be offloaded here
 */
///@{
    ///How large things like monsters appear on screen
    float m_ViewportScale;
	///How large things like spell buttons appear on screen
	float m_WidgetScale;

	int32_t m_ElevationScale;
	int32_t m_MaxPixelValue;
	int32_t** m_Elevations;

	int32_t m_PointsPerPixel;
	int32_t m_PixelsPerTile;
	int32_t m_TilesPerSquare;
	int32_t m_SquaresPerMapI;
	int32_t m_SquaresPerMapJ;

	int32_t m_ScreenPPP;

	int32_t m_FramerateLimit;

    int32_t m_Textures;
    int32_t m_Sprites;
    int32_t m_Animations;
    int32_t m_Skins;

///@}
/** @name Derived Constants **/
///@{
	int32_t m_PointsPerTile;
	int32_t m_PointsPerSquare;
	int32_t m_PixelsPerSquare;

///@} **/

} bbMapConstants;

#endif //BBMAPCONSTANTS_H