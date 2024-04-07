#include <inttypes.h>
#include "headers/bbWidget.h"
#include "headers/bbAnimation.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"



int32_t bbWidget_CoolDownDraw (bbWidget* widget, int32_t i){


    sfRectangleShape* rect = widget->m_RedRect;
	sfRenderWindow_drawRectangleShape(g_Game->m_Window, rect, NULL);



	return f_Success;
}
