/**
 * @brief Compile time constants. Run-time loading of constants on a per-map basis is preferred
 */


#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "../headers/system_includes.h"

///The number of maps that can be loaded at one time.
#define N_MAPS                  16
///May want to change this to be set at runtime? Variables set at runtime are preferred
#define DRAWABLES_PER_AI        16
#define ANIMATIONS_PER_DRAWABLE 16

#endif // CONSTANTS_H