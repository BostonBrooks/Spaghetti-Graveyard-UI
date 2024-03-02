/**
 * @file
 * @brief sfTexture is define in SFML as raw pixel data
 * bbTextures is a container for sfTextures
*/

#ifndef BBTEXTURES_H
#define BBTEXTURES_H

#include "headers/bbSystemIncludes.h"

typedef struct { //bbTextures

	sfTexture** m_VTable;
	bbDictionary* m_Dictionary;

} bbTextures;


#endif //BBTEXTURES_H