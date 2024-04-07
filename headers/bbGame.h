/**
 * @file bbGame
* @brief bbGame is the root of all data stored by the game.
 *
*/
#ifndef BBGAME_H
#define BBGAME_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbEngineConstants.h"
#include "headers/bbGameConstants.h"
#include "headers/bbMap.h"



typedef struct {
	bbGameConstants m_Constants;
	sfRenderWindow* m_Window;
	//bbViewport* m_Viewport;
	int32_t m_CurrentMap;
	char m_MapNames[N_MAPS][256];
	int32_t m_GlobalTime;
	///data for the game can be stored in any location in the file system
	char* m_FolderPath;
	char* m_GameName;

	bbMap* m_Maps[N_MAPS];

} bbGame;

extern bbGame* g_Game;


int32_t bbGame_new(bbGame** self, char* folder_path);

#endif //BBGAME_H