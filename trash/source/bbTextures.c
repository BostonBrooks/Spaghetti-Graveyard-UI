
#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"
#include "headers/bbTextures.h"
#include "headers/bbPrintf.h"
#include "headers/bbFlags.h"
#include "headers/bbMap.h"
#include "headers/bbGame.h"

int32_t bbTextures_new(char* file_path, int32_t num_textures, bbTextures** Textures){
	bbTextures* textures = calloc(1, sizeof (bbTextures));
	*Textures = textures;
	return 1;
}

/*
int texture_load(int32_t map, char* key, int address, char* file_name, sfBool smooth){

	bbTextures* textures = g_Game->m_Maps[map]->m_Media->m_Textures;

	sfTexture* new_texture = sfTexture_createFromFile(file_name, NULL);
	sfTexture_setSmooth(new_texture, smooth);

	textures->m_VTable[address] = new_texture;
	bbDictionary_add(textures->m_Dictionary, key, address);

	return f_Success;

}

int32_t bbTextures_new(char* file_name, int32_t num_textures){

	bbTextures* textures = calloc(1, sizeof(bbTextures));

	textures->m_VTable = calloc(num_textures, sizeof(sfTexture*));
	bbAssert(textures->m_VTable != NULL, "calloc failed");


	textures->m_Dictionary = bbDictionary_new(547);


	FILE* textures_file = fopen (file_name, "r");
	bbAssert(textures_file != NULL, "fopen failed");

	char string[512];

    int flag = fscanf(textures_file, "%[^\n]\n", string);

	flag = strcmp(string, "Label:,Virtual Address:,File:,Smooth:,Comment:");

    bbAssert(flag == 0, "Bad textures.csv file\n");

	char key[KEY_LENGTH];
	int address;
	char file[256];
	char smooth;

	while (flag = fscanf(
			textures_file,
			"%[^,],%d,%[^,],%c,%*[\n]\n",
			key, &address, file, &smooth)){
		texture_load(key, address, file, smooth == 'T' ? sfTrue : sfFalse);
	}

	fclose (textures_file);
	return f_Success;
}

int32_t bbTextures_locate (int32_t map, char* key){
	bbTextures* textures = g_Game->m_Maps[map]->m_Media.m_Textures;

	return bbDictionary_lookup(textures->m_Dictionary, key);
}
 */