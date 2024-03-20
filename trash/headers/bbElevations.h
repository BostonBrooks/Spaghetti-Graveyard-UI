/**
 * @file
* @brief bbElevations contains all of the data for hill shading and curved ground surfaces
 *
*/
#ifndef BBELEVATIONS_H
#define BBELEVATIONS_H

#include "headers/bbMapConstants.h"
#include "headers/bbSystemIncludes.h"

typedef struct {

    int32_t** m_HeightValues;
    sfTexture** m_ShadingTextures;

} bbElevations;

int32_t bbElevations_new(bbElevations** Elevations, char* file_path, bbMapConstants* constants);

#endif BBELEVATIONS_H
