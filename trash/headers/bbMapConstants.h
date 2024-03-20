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
	float ViewportScale;
	///How large things like spell buttons appear on screen
	float WidgetScale;

	int32_t ElevationScale;
	int32_t MaxPixelValue;

	int32_t PointsPerPixel;
	int32_t PixelsPerTile;
	int32_t TilesPerSquare;
	int32_t SquaresPerMapI;
	int32_t SquaresPerMapJ;

	int32_t ScreenPPP;

	int32_t FramerateLimit;

	int32_t Textures;
	int32_t Sprites;
	int32_t Animations;
	int32_t Skins;

///@}
/** @name Derived Constants **/
///@{
	int32_t PointsPerTile;
	int32_t PointsPerSquare;
	int32_t PixelsPerSquare;

	//#define ELEVATION_MAX       (ELEVATION_SCALE * PIXEL_VALUE_MAX)

///@} **/

} bbMapConstants;

#endif //BBMAPCONSTANTS_H
