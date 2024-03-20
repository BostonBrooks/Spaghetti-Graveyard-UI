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
	int32_t m_NumTextures;
	sfTexture** m_Textures;
	bbDictionary* m_Dictionary;

} bbTextures;

int32_t bbTextures_new(bbTextures** self, char* folderPath, int32_t numTextures);

//if key is int, return texture at that address
//otherwise, look up key in dictionary and return the texture pointed to.
int32_t bbTextures_lookup (sfTexture** self, bbTextures* textures, char* key);

#endif //BBTEXTURES_H
