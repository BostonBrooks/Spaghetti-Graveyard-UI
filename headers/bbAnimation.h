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
#include "headers/bbIntTypes.h"

typedef struct {
	char m_Key[KEY_LENGTH];

	I32 v_DrawFunction; // default draw function for the given animation
	I32 m_Angles;
	I32 m_Frames;
	//What does this do?
	I32 m_Framerate;
	//the animation itself knows where to find its sprites container
	bbSprites* m_Sprites;
	//list of length m_Angles * m_Sprites
	I32 i_Sprites[];

} bbAnimation;

typedef struct { //bbAnimations
	I32 m_NumAnimations;
	bbSprites* m_Sprites;
	bbAnimation** m_Animations;
	bbDictionary* m_Dictionary;

} bbAnimations;

I32 bbAnimations_new(bbAnimations** self, bbSprites* Sprites, char* folderPath,
		I32 numAnimations);


#endif //BBANIMATIONS_H
