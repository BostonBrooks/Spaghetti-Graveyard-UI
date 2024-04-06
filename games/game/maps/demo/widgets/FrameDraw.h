///Draw one frame of animation without incrementing the frame number

#include <inttypes.h>
#include "headers/bbWidget.h"
#include "headers/bbAnimation.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"



int32_t bbWidget_FrameDraw (bbWidget* widget, int32_t i){
	int32_t animationInt = widget->m_AnimationInt[i];
	int32_t angle = widget->m_Angle[i];
	int32_t frame = widget->m_Frame[i];



	int32_t map = widget->p_Node.p_Pool.Map;

	bbScreenCoordsI SCI = widget->m_ScreenCoords;
	bbScreenCoordsF SCF = bbScreenCoordsI_getF(SCI, &g_Game->m_Maps[map]->p_Constants);

	bbAnimation* animation = g_Game->m_Maps[map]->m_Animations->m_Animations[animationInt];

	int32_t angles = animation->m_Angles;
	int32_t frames = animation->m_Frames;


	bbSprites* sprites = animation->m_Sprites;

	int32_t spriteInt = frames*angle+frame;

	int32_t spriteNum = animation->i_Sprites[spriteInt];

	sfSprite* sprite = sprites->m_Sprites[spriteNum];

	sfVector2f position;
	position.x = SCF.x;
	position.y = SCF.y;

	sfSprite_setPosition(sprite, position);

	sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);



	return f_Success;
}
