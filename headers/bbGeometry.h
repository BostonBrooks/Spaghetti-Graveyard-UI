/**
 * @file
 * @brief This file describes data types and methods for dealing with 3d map coordinates and 2d screen coordinates
 * int32_t map is included as an argument to many of these functions because important constants are defined in the bbMap object.
*/

#ifndef BBGEOMETRY_H
#define BBGEOMETRY_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbFloorDiv.h"


///Floating point, 2d coordinates used by CSFML
typedef struct {
	///x axis is the number of pixels to the right of top left
	float x;
	///y axis is down number of pixels down from top left
	float y;
} bbScreenCoordsF;

///Fixed point, 2d coordinates, precision given by bbMap::m_ScreenPPP
typedef struct {
	///x axis is the number of pixels to the right of top left
	int32_t x;
	///y axis is down number of pixels down from top left
	int32_t y;
} bbScreenCoordsI;

///Floating point, 2d coordinates used by CSFML
typedef struct {
	///x axis is the number of pixels to the right of top left
	float x;
	///y axis is down number of pixels down from top left
	float y;
} bbViewportCoordsF;

///Fixed point, 2d coordinates, precision given by bbMap::m_ScreenPPP
typedef struct {
	///x axis is the number of pixels to the right of top left
	int32_t x;
	///y axis is down number of pixels down from top left
	int32_t y;
} bbViewportCoordsI;

///Fixed point, 3d coordinates
typedef struct {
	///i axis points down and to the right
	int32_t i;
	///j axis points up and to the right
	int32_t j;
	///k axis points up, in units of points
	int32_t k;
} bbMapCoords;


///Fixed point, 3d coordinates
typedef struct {
	///i axis points down and to the right
	int32_t i;
	///j axis points up and to the right
	int32_t j;
	///k axis points up, not sure if this coordinate is useful
	int32_t k;
} bbTileCoords;

///Fixed point, 3d coordinates
typedef struct {
	///i axis points down and to the right
	int32_t i;
	///j axis points up and to the right
	int32_t j;
	///k axis points up, not sure if this coordinate is useful
	int32_t k;
} bbSquareCoords;

///Floating point, 3d coordinates. Let's not use these.
typedef struct {
	///i axis points down and to the right, in whatever units
	float i;
	///j axis points up and to the right, in whatever units
	float j;
	///k axis points up, whatever units
	float k;
} bbFloat3D;

///Used for hitboxes & clickboxes
typedef struct {
	int32_t top;
	int32_t left;
	int32_t height;
	int32_t width;
} bbIntRect;

/// Return a vector parallel to foo, but with absolute value = 1
bbFloat3D bbFloat3D_normalise (bbFloat3D foo);

/// Look up the elevation of a point on the map given by tile coordinates
int32_t bbTileCoords_getElevation(int32_t map, int32_t i, int32_t j);

/// Find the coordinates of the tile containing the point given in map coordinates
bbTileCoords bbMapCoords_getTileCoords (int32_t map, bbMapCoords mc);

/// Find the coordinates of the square containing the point given in map coordinates
bbSquareCoords bbMapCoords_getSquareCoords (int32_t map, bbMapCoords mc);

/// Find the screen coordinates of a point if (0,0,0) is in the top left corner of the screen
bbScreenCoordsI bbMapCoords_getScreenCoords_topleft (int32_t map, bbMapCoords mc);

/// Find the screen coordinates of a point if viewpoint is in the centre of the screen
bbScreenCoordsI bbMapCoords_getScreenCoords_centre (int32_t map, bbMapCoords mc);

/// A vector from A to B on screen. Used for hitboxes. Should return the same value independent on viewport scale.
bbScreenCoordsI bbMapCoords_getScreenCoords_vector (int32_t map, bbMapCoords A, bbMapCoords B);

/// Find the screen coordinates of a point if viewpoint is in the centre of the screen
bbScreenCoordsI bbTileCoords_getScreenCoords_centre (int32_t map, bbMapCoords mc);

///et cetera

#endif // BBGEOMETRY_H