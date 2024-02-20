/**
 * @file
* @brief bbGraphicsSettings contains data pertaining to the window the game is being displayed in
*/

#ifndef BBGRAPHICSSETTINGS_H
#define BBGRAPHICSSETTINGS_H

#include "../headers/bbSystemIncludes.h"

typedef struct { //bbGraphicsSettings

    sfRenderWindow* m_Window;
	int32_t m_Height;
	int32_t m_Width;
	char m_Title[128];

} bbGraphicsSettings;


#endif //BBGRAPHICSSETTINGS_H
