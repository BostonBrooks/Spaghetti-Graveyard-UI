/// stuff for fonts and drawing sfText here

#include <inttypes.h>
#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"
#include "headers/bbFonts.h"


int32_t bbFonts_new(bbFonts** self, char* folderPath, int32_t numTextures){

    if (folderPath == NULL) {
        bbFonts *fonts = calloc(1, sizeof(bbFonts));
        fonts->m_Fonts = calloc(1, sizeof(sfFont *));
        fonts->m_Fonts[0] = sfFont_createFromFile("../games/game/graphics/Bowman.ttf");
        bbAssert(fonts->m_Fonts[0] != NULL, "Bowman font failed to load");
        *self = fonts;
    }
    return f_Success;
}


