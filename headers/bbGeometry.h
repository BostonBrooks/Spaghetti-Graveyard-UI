#include <inttypes.h>

#ifndef BBGEOMETRY_H
#define BBGEOMETRY_H

#include "headers/bbMapConstants.h"

///Fixed point, 2d coordinates, precision given by bbMap::m_ScreenPPP
typedef struct {
	///x axis is  right of top left
	int32_t x;
	///y axis is down from top left
	int32_t y;
} bbScreenCoordsI;

typedef struct {
	///x axis is  right of top left
	float x;
	///y axis is down from top left
	float y;
} bbScreenCoordsF;

bbScreenCoordsF bbScreenCoordsI_getF(bbScreenCoordsI SCI, bbMapConstants* constants);
bbScreenCoordsI bbScreenCoordsF_getI(bbScreenCoordsF SCF, bbMapConstants* constants);
sfVector2f bbScreenCoordsI_getV2f(bbScreenCoordsI SCI, bbMapConstants* constants);

#endif //BBGEOMETRY_H