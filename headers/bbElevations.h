/**
 * @file
* @brief bbElevations contains all of the data for hill shading and curved ground surfaces
 *
*/
#ifndef BBELEVATIONS_H
#define BBELEVATIONS_H

#include "headers/bbMapConstants.h"

typedef struct {

    int32_t** m_HeightValues;

    sfTexture** m_ShadingTextures;
} bbElevations;

bbElevations_new(char* file_path, bbMapConstants constants);

#endif BBELEVATIONS_H