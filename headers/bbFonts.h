/// stuff for fonts and drawing sfText here

#ifndef BBFONTS_H
#define BBFONTS_H

#include <inttypes.h>
#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"

typedef struct {

    int32_t n_NumFonts;
    sfFont** m_Fonts;
    bbDictionary* m_Dictionary;

} bbFonts;

int32_t bbFonts_new(bbFonts** self, char* folderPath, int32_t numTextures);


#endif //BBFONTS_H