/**
 * @file
* @brief bbGame is the root of all data stored by the game.
 *
*/

#ifndef BBGAME_H
#define BBGAME_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbGraphicsSettings.h"
#include "headers/bbMap.h"
#include "headers/bbConstants.h"

typedef struct { //bbGame

    bbGraphicsSettings* m_GraphicsSettings;

	int32_t m_CurrentMap;

	bbMap* m_Maps[N_MAPS];


	///Increased with every iteration of game loop
	int32_t m_GlobalTime;

} bbGame;

#endif //BBGAME_H