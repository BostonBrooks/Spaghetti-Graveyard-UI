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
#include "headers/bbDictionary.h"

typedef struct { //bbGame

    bbGraphicsSettings* m_GraphicsSettings;

	int32_t m_CurrentMap;

	bbMap* m_Maps[N_MAPS];

	char m_MapNames[N_MAPS][256];

	///Increased with every iteration of game loop
	int32_t m_GlobalTime;

} bbGame;

extern bbGame* g_Game;

/// Start the game and load map names;
int32_t bbGame_new(bbGame** gGame, char* file_path);
/// Free all memory and exit
int32_t bbGame_delete();

#endif //BBGAME_H