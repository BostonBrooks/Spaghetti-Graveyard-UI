/**
 * @file
* @brief bbMedia stores all of the graphics, etc needed to display everything
 * drawn to the screen, pertaining to one of the game's maps
 * media is reloaded every time a new map is loaded or made current.
 * we can loosen our restriction on floating point numbers out of a sense of necessity
 * a bbMap should be update-able without having it's bbMedia loaded;
*/

#ifndef BBMEDIA_H
#define BBMEDIA_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"
#include "headers/bbAnimation.h"

typedef struct { //bbMedia

	///bbTextures stores all of the textures used in an individual map.
	bbTextures* m_Textures;
	///bbSprites stores all of the sprites used in an individual map.
	bbSprites* m_Sprites;
	///bbAnimations stores all of the sprites used in an individual map.
	bbAnimations* m_Animations;


} bbMedia;

#endif //BBMEDIA_H
