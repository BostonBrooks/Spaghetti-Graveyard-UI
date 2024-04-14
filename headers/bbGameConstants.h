#include "headers/bbSystemIncludes.h"
/// contains data about the game?
#ifndef BBGAMECONSTANTS_H
#define BBGAMECONSTANTS_H

#include "headers/bbGeometry.h"

typedef struct{
	//bbGame has no concept of bbScreenCoordsI or bbScreenCoordsF
    //window height pixels
	int32_t Height;
    //window width pixels
	int32_t Width;
}bbGameConstants;


#endif // BBGAMECONSTANTS_H