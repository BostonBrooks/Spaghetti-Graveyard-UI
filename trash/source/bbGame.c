#define BBDEBUG

#include "headers/bbGame.h"
#include "headers/bbConstants.h"
#include "headers/bbPrintf.h"
#include "headers/bbGraphicsSettings.h"

int32_t bbGame_new(char* file_path, bbGame** gGame) {

	//Read gamedata.txt

	bbGame* game = calloc(1, sizeof(bbGame));


	FILE* gamedatafile = fopen(file_path,"r");
	bbAssert(gamedatafile != NULL, "fopen failed\n");

	char string[256];
	int32_t height;
	int32_t width;

	fscanf(gamedatafile, "%[^\n]\n", string);


	bbAssert(strcmp(string, "GraphicsSettings:") == 0, "bad gamedata file\n");

	fscanf(gamedatafile, "Title: \"%[^\"]\"\n", string);

	fscanf(gamedatafile, "Height: %d\n", &height);
	fscanf(gamedatafile, "Width: %d\n", &width);

	// Create new window
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

	game->m_CurrentMap = 0;

	*gGame = game;
	return 1;

}
