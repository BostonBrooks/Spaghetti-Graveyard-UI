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




/**
 * This function initialises sprites from data found in the given file.
 */
extern bbSprites* bbSprites_CreateFromFile(char File[]);\

extern sfSprite* sfSpriteLocate (int map_int, int animation_int, int angle_int, int frame_int);
extern sfSprite* sfSpriteLocateWKey (int map_int, char* animation_key, int angle_int, int frame_int);
#endif //BBSPRITES_H