#define BBDEBUG

#include "headers/bbGame.h"
#include "headers/bbConstants.h"
#include "headers/bbPrintf.h"
#include "headers/bbGraphicsSettings.h"

int32_t bbGame_new(char* game_name) {

	//Read gamedata.txt

	bbGame* game = calloc(1, sizeof(bbGame));

	char* game_path[256];
	sprintf(game_path, "../games/%s/gamedata.txt", game_name);
	FILE* gamedatafile = fopen(game_path,"r");
	bbAssert(gamedatafile != NULL, "fopen failed\n");

	char string[256];
	int32_t height;
	int32_t width;

	fscanf(gamedatafile, "%[^\n]\n", string);


	bbAssert(strcmp(string, "GraphicsSettings:") == 0, "bad gamedata file\n");

	fscanf(gamedatafile, "Title: \"%[^\"]\"\n", string);

	fscanf(gamedatafile, "Height: %d\n", &height);
	fscanf(gamedatafile, "Width: %d\n", &width);

	game->m_GraphicsSettings = bbGraphicsSettings_new(string, height, width);

	for (int i = 0; i < N_MAPS; i++){
		strcpy(game->m_MapNames[i], "NONE");
	}

    fscanf(gamedatafile, "\n\n%[^\n]\n", string);
	bbAssert(strcmp(string, "Maps:") == 0, "bad gamedata file\n");

	int32_t mapnumber;
	while(fscanf(gamedatafile, "%d, %[^\n]\n", &mapnumber, string) == 2){
		strcpy(game->m_MapNames[mapnumber], string);

	}
	for (int i = 0; i < N_MAPS; i++){
		bbDebug("%d, %s\n", i, game->m_MapNames[i]);
	}

	g_Game = game;
    //Load map 0;

	bbMap_new(int32_t mapnum)



    sleep(5);

}
