#include "headers/bbSystemIncludes.h"
/// contains data about the map

#ifndef BBMAPCONSTANTS_H
#define BBMAPCONSTANTS_H

typedef struct{
	float DrawableScale;
	float WidgetScale;
	int32_t ElevationScale;
	int32_t MaxPixelValue;
	int32_t PointsPerPixel;
	int32_t PixelsPerTile;
	int32_t TilesPerSquare;
	int32_t SquaresPerMapI;
	int32_t SquaresPerMapJ;
	int32_t ScreenPPP;
	int32_t Textures;
	int32_t Sprites;
	int32_t Animations;
	int32_t Skins;
	int32_t Widget_Constructors;
	int32_t Widget_DrawFunctions;
	int32_t Widget_Updates;
	int32_t Widget_Destructors;
	int32_t Widget_OnCommands;
	int32_t PointsPerTile;
	int32_t PointsPerSquare;
	int32_t PixelsPerSquare;

}bbMapConstants;

#endif // BBMAPCONSTANTS_H
