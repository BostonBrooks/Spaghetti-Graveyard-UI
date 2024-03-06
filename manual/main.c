#include <stdio.h>
#include "../headers/bbGame.h"
#include "../headers/bbMap.h"
bbGame* g_Game;

int main (void){
	//Select game:
	char game_name[] = "game";

	//create bbGame from gamedata.txt
	char path_to_gamedata[256];
	sprintf(path_to_gamedata, "../games/%s/gamedata.txt", game_name);
	bbGame* game = bbGame_new(path_to_gamedata);
	g_Game = game;

	char map_name = g_Game->m_MapNames[0];
	char path_to_mapdata[256];
	sprintf(path_to_gamedata, "../games/%s/maps/%s/mapdata.txt", game, map_name);
	bbMap* map0 = bbMap_new(path_to_mapdata);
	g_Game->m_Maps[0] = map0;

	char textures_file






}