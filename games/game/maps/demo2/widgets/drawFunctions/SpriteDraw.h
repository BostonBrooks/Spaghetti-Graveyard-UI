#include <inttypes.h>
#include "headers/bbWidget.h"
#include "headers/bbAnimation.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"

#include "headers/bbIntTypes.h"


I32 bbWidgetDraw_Sprite (bbWidget* widget, I32 i){

	I32 map = widget->p_Node.p_Pool.Map;
	bbSprites* sprites = g_Game->m_Maps[map]->m_Sprites;
	I32 spriteNum = widget->m_AnimationInt[i];
	sfSprite* sprite = sprites->m_Sprites[spriteNum];
    bbScreenCoordsI SCI = widget->m_ScreenCoords;
	sfVector2f position = bbScreenCoordsI_getV2f(SCI, &g_Game->m_Maps[map]->p_Constants);
	sfSprite_setPosition(sprite, position);
	sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);

	return f_Success;
}
