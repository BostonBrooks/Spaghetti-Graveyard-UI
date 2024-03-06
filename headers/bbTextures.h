/**
 * @file
 * @brief sfTexture is define in SFML as raw pixel data
 * bbTextures is a container for sfTextures
*/

#ifndef BBTEXTURES_H
#define BBTEXTURES_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"

typedef struct { //bbTextures

	sfTexture** m_VTable;
	bbDictionary* m_Dictionary;

} bbTextures;

int32_t bbTextures_new(char* file_path);
int32_t bbTextures_clear(int32_t map);
int32_t bbTextures_locate(int32_t map, char* key);

#endif //BBTEXTURES_H