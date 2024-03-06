/**
 * @file
* @brief
*/

#ifndef BBANIMATION_H
#define BBANIMATION_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"

/// bbAnimation contains an array of references to sfSprites to be drawn in succession to give the appearance of movement.
typedef struct { //bbAnimation

	char m_Key[33];
	///Default DrawFunction if not specified by bbDrawable
	int32_t m_DrawFunction;
	int32_t m_Angles;
	int32_t m_Frames;
	int32_t m_Framerate;
	int32_t m_Sprites[];

} bbAnimation;


/// bbAnimations is a container for all of the animations used in a single bbMap
typedef struct { //bbAnimations

	bbAnimation** m_Animations;
	bbDictionary* m_Dictionary;

} bbAnimations;


int32_t bbAnimation_new(char* file_path, bbSprites* sprites);
int32_t bbAnimations_clear(int32_t map);
int32_t bbAnimations_locate(int32_t map, char* key);
extern int32_t bbAnimation_getSprite(bbAnimation* animation, int32_t angle_int, int32_t frame_int);


#endif //BBANIMATION_H