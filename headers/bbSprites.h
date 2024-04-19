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
#include "headers/bbIntTypes.h"

typedef struct { //bbSprites
	I32 m_NumSprites;
	sfSprite** m_Sprites;
	bbDictionary* m_Dictionary;

} bbSprites;

I32 bbSprites_new(bbSprites** self, bbTextures* textures, char* folderPath, bbMapConstants* constants);

I32 bbSprites_lookupInt(bbSprites* sprites, char* key);

#endif //BBSPRITES_H
