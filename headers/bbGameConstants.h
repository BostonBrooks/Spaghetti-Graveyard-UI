#include "headers/bbSystemIncludes.h"
/// contains data about the game?
#ifndef BBGAMECONSTANTS_H
#define BBGAMECONSTANTS_H

#include "headers/bbGeometry.h"

typedef struct{
	//bbGame has no concept of bbScreenCoordsI or bbScreenCoordsF
	int32_t Height;
	int32_t Width;
}bbGameConstants;


#endif // BBGAMECONSTANTS_H