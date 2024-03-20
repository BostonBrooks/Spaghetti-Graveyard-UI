#include "headers/bbSystemIncludes.h"
#include "headers/bbGame.h"
#include "headers/bbPrintf.h"


int32_t bbGame_new(bbGame** self, char* folderPath){

	bbGame* game = calloc(1, sizeof(bbGame));
	bbAssert(game != NULL, "calloc failed\n");

	strcpy(&game->m_FolderPath, folderPath);
	char string[256];
	int32_t integer;
	float floatingPoint;

	sprintf(string, "%s/gamedata.txt", folderPath);
	bbDebug("file path is %s\n", string);

	FILE* file = fopen(string, "r");
	bbAssert(file != NULL, "fopen failed\n")

	fscanf(file, "%[^\n]\n", string);
	bbAssert(strcmp(string, "GraphicsSettings:") == 0, "bad gamedata.txt file\n");
	fscanf(file, "Title: \"%[^\"]\"\n", string);
	strcpy(&game->m_GameName, string);
	fscanf(file, "Height: %d\n", &integer);
	game->m_Constants.Height = integer;
	fscanf(file, "Width: %d\n", &integer);
	game->m_Constants.Width = integer;
	fscanf(file, "%[^\n]\n", string);
	bbAssert(strcmp(string, "Maps:") == 0, "bad gamedata.txt file\n");

	for(int i = 0; i < N_MAPS; i++){
		strcpy(game->m_MapNames[i], "NULL");
	}

	while(fscanf(file, "%d, %[^\n]\n", &integer, string) == 2){
		strcpy(&game->m_MapNames[integer], string);
	}

	fclose(file);

	sfVideoMode mode;
	mode.height = game->m_Constants.Height;
	mode.width = game->m_Constants.Width;
	mode.bitsPerPixel = 32;

	sfRenderWindow* window = sfRenderWindow_create(mode, &game->m_GameName, sfResize | sfClose, NULL);

	sfColor beige = COLOUR_BEIGE;
	sfRenderWindow_clear(window, beige);
	sfRenderWindow_display(window);

	game->m_Window = window;
	*self = game;

	return f_Success;
}