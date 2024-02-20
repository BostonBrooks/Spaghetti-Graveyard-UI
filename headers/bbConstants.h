/**
 * @file
 * @brief Compile time constants. Run-time loading of constants on a per-map basis is preferred. Should be able to increase these values without breaking code.
 */


#ifndef CONSTANTS_H
#define CONSTANTS_H

///The number of maps that can be loaded at one time.
#define N_MAPS                  16
///May want to change this to be set at runtime? Variables set at runtime are preferred
#define DRAWABLES_PER_AI        16
#define ANIMATIONS_PER_DRAWABLE 16

#endif // CONSTANTS_H