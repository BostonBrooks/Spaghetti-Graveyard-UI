#include <stdio.h>
#include "../headers/bbGame.h"
#include "../headers/bbMap.h"
bbGame* g_Game;

int main (void){
	//Select game:
	char game_name[] = "game";

	//create bbGame from gamedata.txt
	char gamedata_path[256];
	sprintf(gamedata_path, "../games/%s/gamedata.txt", game_name);
	bbGame* game = bbGame_new(gamedata_path);
	g_Game = game;

	char* map_name = g_Game->m_MapNames[0];
	char file_path[256];

    sprintf(file_path, "../games/%s/maps/%s/mapdata.txt", game, map_name);
    bbMap* map0 = bbMap_new(file_path);
    g_Game->m_Maps[0] = map0;

    sprintf(file_path, "../games/%s/maps/%s/textures.csv", game, map_name);
    bbTextures* textures = bbTextures_new(file_path, map0->m_Constants.m_Textures);
    g_Game->m_Maps[0]->m_Textures = textures;

    sprintf(file_path, "../games/%s/maps/%s/sprites.csv", game, map_name);
    bbSprites* sprites = bbSprites_new(file_path, textures, map0->m_Constants.m_Sprites);
    g_Game->m_Maps[0]->m_Sprites = sprites;

    sprintf(file_path, "../games/%s/maps/%s/animations.csv", game, map_name);
    bbAnimations* animations = bbAnimations_new(file_path, sprites, map0->m_Constants.m_Animations);
    g_Game->m_Maps[0]->m_Animations = animations;

    sprintf(file_path, "../games/%s/maps/%s/skins.csv", game, map_name);
    bbSkins* skins = bbSkins_new(file_path, animations, map0->m_Constants.m_Skins);
    g_Game->m_Maps[0]->m_Skins = skins;

    // draw one frame of an animation to the window