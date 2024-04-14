/**
 * @file
 * @brief sfTexture is define in SFML as raw pixel data
 * bbTextures is a container for sfTextures
*/

#ifndef BBANIMATIONS_H
#define BBANIMATIONS_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"

typedef struct {
	char m_Key[KEY_LENGTH];

	int32_t v_DrawFunction; // default draw function for the given animation
	int32_t m_Angles;
	int32_t m_Frames;
	//What does this do?
	int32_t m_Framerate;
	//the animation itself knows where to find its sprites container
	bbSprites* m_Sprites;
	//list of length m_Angles * m_Sprites
	int32_t i_Sprites[];

} bbAnimation;

typedef struct { //bbAnimations
	int32_t m_NumAnimations;
	bbSprites* m_Sprites;
	bbAnimation** m_Animations;
	bbDictionary* m_Dictionary;

} bbAnimations;

int32_t bbAnimations_new(bbAnimations** self, bbSprites* Sprites, char* folderPath,
		int32_t numAnimations);


#endif //BBANIMATIONS_H
