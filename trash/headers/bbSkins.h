/**
 * @file
 * @brief Skins store a collection of animations, pertaining to one bbDrawable type
 *
 *
 */

#ifndef BBSKINS
#define BBSKINS

#include <inttypes.h>
#include "headers/bbDictionary.h"
#include "headers/bbAnimation.h"


typedef struct {
	int32_t** animations_int;
	int32_t** drawfunctions_int;
} bbSkin;

typedef struct { //bbTextures

	bbSkin* m_VTable;
	bbDictionary* m_Dictionary;

} bbSkins;

int32_t bbSkins_new(bbSkins** skins, bbAnimations* animations /* or NULL */, int32_t num_skins, char* file_path);
#endif //BBSKINS
