#include "headers/bbGraphicsSettings.h"
#include "headers/bbPrintf.h"
#include "headers/bbConstants.h"

bbGraphicsSettings* bbGraphicsSettings_new(char* string, int32_t height, int32_t width){

	sfVideoMode mode;
	mode.width = width;
	mode.height = height;
	mode.bitsPerPixel = 32;

	sfRenderWindow* window = sfRenderWindow_create(mode, string, sfResize | sfClose,NULL);

	sfColor beige = COLOUR_BEIGE;
	sfRenderWindow_clear(window, beige);
	sfRenderWindow_display(window);

	bbGraphicsSettings* graphics = calloc(1, sizeof (bbGraphicsSettings));

	graphics->m_Height = height;
	graphics->m_Width = width;
	strcpy(graphics->m_Title, string);
    graphics->m_Window = window;

	return graphics;

}