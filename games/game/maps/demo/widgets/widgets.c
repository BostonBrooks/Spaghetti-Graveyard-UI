#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"
#include "headers/bbIntTypes.h"

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
#include "games/game/maps/demo/widgets/prompt.h"




I32 bbWidgetFunctions_populate(I32 map){


    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Animation, "animation");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Frame, "frame");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Sprite, "sprite");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Cooldown, "cooldown");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Text, "text");

    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Fireworks, "fireworks");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Textbox, "textbox");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Decal, "decal");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Sphere, "sphere");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Spellbar, "spellBar");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Prompt, "prompt");

    bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Text, "clickText");
    bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Sphere, "clickSphere");


    bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Textbox, "textbox");
    bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Prompt, "prompt");
bbHere();

    bbWidgetFunctions_add(functions, f_WidgetOnTimer, bbWidget_Sphere_onTimer, "sphere");

bbHere();


	return f_Success;
}

