#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"
#include <inttypes.h>
///include files containing widget functions, later these will be stored in a Dynamic Linked Library
#include "games/game/maps/demo/widgets/AnimationDraw.h"
#include "games/game/maps/demo/widgets/FrameDraw.h"
#include "games/game/maps/demo/widgets/SpriteDraw.h"
#include "games/game/maps/demo/widgets/CoolDownDraw.h"
#include "games/game/maps/demo/widgets/fireworks.h"
#include "games/game/maps/demo/widgets/decal.h"
#include "games/game/maps/demo/widgets/spellbar.h"
#include "games/game/maps/demo/widgets/MouseClickText.h"
#include "games/game/maps/demo/widgets/TextDraw.h"
#include "games/game/maps/demo/widgets/sphere.h"
#include "games/game/maps/demo/widgets/textBox.h"




int32_t bbWidgetFunctions_populate(int32_t map){


    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidget_AnimationDraw, "animation");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidget_FrameDraw, "frame");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidget_SpriteDraw, "sprite");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidget_CoolDownDraw, "cooldown");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidget_TextDraw, "text");

    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidget_fireworks_new, "fireworks");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidget_textBox_new, "textbox");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidget_Decal_new, "decal");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidget_sphere_new, "sphere");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidget_spellBar_new, "spellBar");

    bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidget_MouseClickText, "clickText");
    bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidget_MouseClickSphere, "clickSphere");


    bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidget_Command_textBox, "textbox");




	return f_Success;
}

