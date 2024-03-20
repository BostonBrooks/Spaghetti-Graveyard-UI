#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"
#include <inttypes.h>
///include files containing widget functions, later these will be stored in a Dynamic Linked Library
//#include "maps/demo/widgets/Widget_NULL.h"
#include "games/game/maps/demo/widgets/decal.h"
#include "games/game/maps/demo/widgets/AnimationDraw0.h"
#include "games/game/maps/demo/widgets/fireworks.h"
#include "games/game/maps/demo/widgets/prompt.h"



int32_t bbWidgetFunctions_populate(int32_t map){


    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

	bbWidgetFunctions_add(functions, wf_Constructor, bbWidget_Decal_new, "decal");
	bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_Decal_draw, "decal");
	bbWidgetFunctions_add(functions, wf_Constructor, bbWidget_Fireworks_new, "fireworks");
	bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_Fireworks_draw, "fireworks");
	bbWidgetFunctions_add(functions, wf_AnimationDraw, bbWidget_AnimationDraw0, "animation");


	bbWidgetFunctions_add(functions, wf_Constructor, bbWidget_Prompt_new, "prompt");
	bbWidgetFunctions_add(functions, wf_OnCommand, bbWidget_Prompt_onCommand, "prompt");
	bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_Prompt_draw, "prompt");


	return f_Success;
}