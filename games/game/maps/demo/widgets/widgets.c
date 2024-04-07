#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"
#include <inttypes.h>
///include files containing widget functions, later these will be stored in a Dynamic Linked Library
#include "games/game/maps/demo/widgets/AnimationDraw.h"
#include "games/game/maps/demo/widgets/FrameDraw.h"
#include "games/game/maps/demo/widgets/SpriteDraw.h"
#include "games/game/maps/demo/widgets/RedRectDraw.h"
#include "games/game/maps/demo/widgets/fireworks.h"
#include "games/game/maps/demo/widgets/decal.h"
#include "games/game/maps/demo/widgets/spellbar.h"



int32_t bbWidgetFunctions_populate(int32_t map){


    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

    bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_AnimationDraw, "animation");
    bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_FrameDraw, "frame");
    bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_SpriteDraw, "sprite");
    bbWidgetFunctions_add(functions, wf_DrawFunction, bbWidget_RedRectDraw, "redrect");

	bbWidgetFunctions_add(functions, wf_Constructor, bbWidget_fireworks_new, "fireworks");

    bbWidgetFunctions_add(functions, wf_Constructor, bbWidget_Decal_new, "decal");
    bbWidgetFunctions_add(functions, wf_Constructor, bbWidget_spellBar_new, "spellBar");



	return f_Success;
}
