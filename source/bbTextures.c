#include "headers/bbSystemIncludes.h"
#include "headers/bbTextures.h"
#include "headers/bbDictionary.h"

int32_t _bbTextures_new(bbTextures** self, int32_t numTextures){
	bbTextures* textures = calloc(1, sizeof(bbTextures));
	bbAssert(textures != NULL, "calloc failed\n");
	textures->m_NumTextures = numTextures;
	textures->m_Textures = calloc(numTextures, sizeof(sfTexture*));
	int32_t flag = bbDictionary_new(&textures->m_Dictionary, numTextures);
	bbAssert(flag == f_Success, "bbDictionary_new failed\n");
	*self = textures;
	return f_Success;

}

int32_t texture_load(bbTextures* textures, char* key, int32_t address, char* filename,sfBool smooth){

	//bbDebug("key is %s, address is %d, filename is %s, smooth is %c\n", key, address, filename, smooth == sfTrue ? 'T' : 'F');
	sfTexture* texture = sfTexture_createFromFile(filename, NULL);
	bbAssert(texture != NULL, "sfTexture failed to load\n");
	sfTexture_setSmooth(texture, smooth);
	textures->m_Textures[address] = texture;
	bbDictionary_add(textures->m_Dictionary, key, address);
	return f_Success;
}

int32_t bbTextures_new(bbTextures** self, char* folderPath, int32_t numTextures){

	bbDebug("path to map folder is %s\n", folderPath);
	bbTextures* textures;
	_bbTextures_new(&textures, numTextures);

	char string[256];

	sprintf(string, "%s/textures.csv", folderPath);
	bbDebug("file path is %s\n", string);

	FILE* file = fopen(string, "r");
	bbAssert(file != NULL, "fopen failed\n");

	fscanf(file, "%[^\n]\n", string);
	bbAssert(strcmp(string,
			"Label:,Virtual Address:,File:,Smooth:,Comment:") == 0,
			"bad textures.csv file\n");

	char key[KEY_LENGTH];
	int address;
	char fileName[256];
	char filePath[256];
	char smooth;
	int flag;

	while (fscanf(file, "%[^,],%d,%[^,],%c%*[^\n]\n", key, &address, fileName, &smooth) == 4){
		sprintf(filePath, "%s/%s", folderPath, fileName);
		//printf("%s\n", filePath);
		texture_load(textures, key, address, filePath, smooth == 'T' ? sfTrue : sfFalse);
	}

	fclose(file);

	*self = textures;
	return f_Success;
}

//if key is int, return texture at that address
//otherwise, look up key in dictionary and return the texture pointed to.
int32_t bbTextures_lookup (sfTexture** self, bbTextures* textures, char* key){

	bbDictionary* dict = textures->m_Dictionary;

	int32_t len = strlen(key);
	char digits[] = "0123456789";
	int int_len = strspn(key, digits);
	int address;
	if (len == int_len){
		address = atoi(key);
	} else {
		address = bbDictionary_lookup(dict, key);
		bbAssert(address >= 0, "bad data from dictionary\n");
	}

	sfTexture* texture = textures->m_Textures[address];

	*self = texture;

	return f_Success;
}