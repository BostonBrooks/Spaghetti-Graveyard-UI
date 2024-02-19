/** 
* @brief
 *
 *
 *
*/

#ifndef BBANIMATION_H
#define BBANIMATION_H

#include "../headers/system_includes.h"
/** @name bbAnimation contains an array of references to sfSprites
 * to be played in succession to give the appearance of movement
 **/
///@{
typedef struct { //bbAnimation

	char m_Key[33];
	///Default DrawFunction if not specified by bbDrawable
	int32_t m_DrawFunction;
	int32_t m_Angles;
	int32_t m_Frames;
	int32_t m_Framerate;
	int32_t m_Sprites[];

} bbAnimation;
///@}

/** @name bbAnimations is a container for all of the animations used in a single bbMap
 **/
///@{
typedef struct { //bbAnimations

	bbAnimation** m_Animations;
	bbDictionary* m_Dictionary;

} bbAnimations;

#endif //BBANIMATION_H