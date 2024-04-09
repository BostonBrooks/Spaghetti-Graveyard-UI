#include <inttypes.h>
#include "headers/bbWidget.h"
#include "headers/bbAnimation.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"



int32_t bbWidget_TextDraw (bbWidget* widget, int32_t i){

    int32_t map = widget->p_Node.p_Pool.Map;

    bbScreenCoordsI SCI = widget->m_ScreenCoords;
    sfVector2f positionV2f = bbScreenCoordsI_getV2f(SCI, &g_Game->m_Maps[map]->p_Constants);

    sfText_setPosition(widget->m_Text, positionV2f);

    sfRenderWindow_drawText(g_Game->m_Window, widget->m_Text, NULL);

    return f_Success;
}
