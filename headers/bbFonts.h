/// stuff for fonts and drawing sfText here

#ifndef BBFONTS_H
#define BBFONTS_H


#include "headers/bbSystemIncludes.h"
#include "headers/bbDictionary.h"
#include "headers/bbIntTypes.h"

typedef struct {

    I32 n_NumFonts;
    sfFont** m_Fonts;
    bbDictionary* m_Dictionary;

} bbFonts;

I32 bbFonts_new(bbFonts** self, char* folderPath, I32 numTextures);


#endif //BBFONTS_H