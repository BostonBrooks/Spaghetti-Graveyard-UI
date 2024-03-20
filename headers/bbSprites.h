/**
 * @file
 * @brief sfTexture is define in SFML as raw pixel data
 * bbTextures is a container for sfTextures
*/

#ifndef BBSPRITES_H
#define BBSPRITES_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"
#include "headers/bbTextures.h"
#include "headers/bbMapConstants.h"

typedef struct { //bbSprites
	int32_t m_NumSprites;
	sfSprite** m_Sprites;
	bbDictionary* m_Dictionary;

} bbSprites;

int32_t bbSprites_new(bbSprites** self, bbTextures* textures, char* folderPath, bbMapConstants* constants);

int32_t bbSprites_lookupInt(bbSprites* sprites, char* key);

#endif //BBSPRITES_H
