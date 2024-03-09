#include <stdio.h>
#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbMapConstants.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"
#include "headers/bbAnimation.h"
#include "headers/bbElevations.h"
#include "headers/bbSystemIncludes.h"
#include "headers/bbPrintf.h"

bbGame* g_Game;

int main (void) {
	//Select game:
	char game_name[] = GAME_NAME;
	int32_t flag;

	//create bbGame from gamedata.txt
	char file_path[256];
	sprintf(file_path, "../games/%s/gamedata.txt", game_name);
	flag = bbGame_new(file_path, &g_Game);

	printf("map name 0 is: %s\n", g_Game->m_MapNames[0]);

	bbAssert(flag >= 0, "bad flag\n");

	int32_t CurrentMap = g_Game->m_CurrentMap;
	char* map_name = g_Game->m_MapNames[CurrentMap];


	bbMap* Current_Map = g_Game->m_Maps[CurrentMap];
	bbMapConstants* constants = &Current_Map->m_Constants;

    sprintf(file_path, "../games/%s/maps/%s/mapdata.txt", game_name, map_name);
    flag = bbMap_new(file_path, &Current_Map);
	bbAssert(flag >= 0, "bad flag\n");

	bbMap_printConstants(Current_Map);

	sfRenderWindow* window = g_Game->m_GraphicsSettings->m_Window;

	//constants->FramerateLimit not defined
	//sfRenderWindow_setFramerateLimit(window, constants->FramerateLimit);
	sprintf(file_path, "%s: %s", game_name, Current_Map->m_Name);
	sfRenderWindow_setTitle(window, file_path);
	sfRenderWindow_display(window);

	printf("did we make it this far?\n");

    sprintf(file_path, "../games/%s/maps/%s/textures.csv", game_name, map_name);
    flag = bbTextures_new(file_path, constants->Textures, &Current_Map->m_Textures);
	bbAssert(flag >= 0, "bad flag\n");


    sprintf(file_path, "../games/%s/maps/%s/sprites.csv", game_name, map_name);
    flag = bbSprites_new(file_path, &Current_Map->m_Textures, constants->Sprites, &Current_Map->m_Sprites);
	bbAssert(flag >= 0, "bad flag\n");

    sprintf(file_path, "../games/%s/maps/%s/animations.csv", game_name, map_name);
    flag = bbAnimations_new(file_path, &Current_Map->m_Sprites, constants->Animations, &Current_Map->m_Animations);
	bbAssert(flag >= 0, "bad flag\n");


    sprintf(file_path, "../games/%s/maps/%s/skins.csv", game_name, map_name);
    flag = bbSkins_new(file_path, &Current_Map->m_Animations, constants->Skins, &Current_Map->m_Skins);
	bbAssert(flag >= 0, "bad flag\n");

    // draw one frame of an animation of a skin to window

    sprintf(file_path, "../games/%s/maps/%s/elevations.bmp", game_name, map_name);
    flag = bbElevations_new(file_path, constants, &Current_Map->m_Elevations);
	bbAssert(flag >= 0, "bad flag\n");



	sleep(5);
}
