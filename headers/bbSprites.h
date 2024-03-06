/**
 * @file
 * @brief sfSprite is the basic object drawn to the viewport
 **/

#ifndef BBSPRITES_H
#define BBSPRITES_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"


/// bbSprites is a container for sfSprites used in a single bbMap
typedef struct { //bbSprites

	sfSprite** m_Sprites;
	bbDictionary* m_Dictionary;

} bbSprites;

int32_t bbSprites_new(char* file, bbTextures* textures);
int32_t bbSprites_clear(int32_t map);
int32_t bbSprites_locate(int32_t map, char* key);

#endif //BBSPRITES_H