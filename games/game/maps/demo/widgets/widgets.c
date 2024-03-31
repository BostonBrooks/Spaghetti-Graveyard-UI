#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"
#include <inttypes.h>
///include files containing widget functions, later these will be stored in a Dynamic Linked Library
#include "games/game/maps/demo/widgets/AnimationDraw.h"
#include "games/game/maps/demo/widgets/SpriteDraw.h"
#include "games/game/maps/demo/widgets/fireworks.h"



int32_t bbWidgetFunctions_populate(int32_t map){


    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

	bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_AnimationDraw0, "animation");
	bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_SpriteDraw, "sprite");

	bbWidgetFunctions_add(functions, wf_Constructor, bbWidget_fireworks_new, "fireworks");




	return f_Success;
}
