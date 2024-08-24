#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbGeometry.h"
#include "headers/bbIntTypes.h"

///include files containing widget functions, later these will be stored in a Dynamic Linked Library
#include "games/game/maps/demo2/widgets/drawFunctions/AnimationDraw.h"
#include "games/game/maps/demo2/widgets/drawFunctions/FrameDraw.h"
#include "games/game/maps/demo2/widgets/drawFunctions/SpriteDraw.h"
#include "games/game/maps/demo2/widgets/drawFunctions/CoolDownDraw.h"
#include "games/game/maps/demo2/widgets/drawFunctions/RenderTextureDraw.h"
#include "games/game/maps/demo2/widgets/fireworks.h"
#include "games/game/maps/demo2/widgets/layout.h"
#include "games/game/maps/demo2/widgets/viewport.h"
#include "games/game/maps/demo2/widgets/MouseClickText.h"
#include "games/game/maps/demo2/widgets/drawFunctions/TextDraw.h"
#include "games/game/maps/demo2/widgets/sphere.h"
#include "games/game/maps/demo2/widgets/textBox.h"
#include "games/game/maps/demo2/widgets/prompt.h"
#include "games/game/maps/demo2/widgets/spellbar/spellbar.h"
#include "games/game/maps/demo2/widgets/spellbar/spell1.h"
#include "games/game/maps/demo2/widgets/spellbar/spell2.h"
#include "games/game/maps/demo2/widgets/spellbar/spell3.h"
#include "games/game/maps/demo2/widgets/spellbar/spell4.h"



I32 bbWidgetFunctions_populate(I32 map){


    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

	//typedef I32 bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);
	bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Animation, "animation");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Frame, "frame");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Sprite, "sprite");
    bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Cooldown, "cooldown");
	bbWidgetFunctions_add(functions, f_WidgetDrawFunction, bbWidgetDraw_Text, "text");
	bbWidgetFunctions_add(functions, f_WidgetDrawFunction,
						  bbWidgetDraw_RenderTexture, "rendertexture");

//typedef I32 bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Fireworks, "fireworks");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Textbox, "textbox");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Layout, "layout");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Viewport, "viewport");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Sphere, "sphere");
  //  bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Spellbar, "spellBar");
    bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Prompt, "prompt");
	bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Spellbar, "spellbar");
	bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Spell1, "spell1");
	bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Spell2, "spell2");
	bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Spell3, "spell3");
	bbWidgetFunctions_add(functions, f_WidgetConstructor, bbWidgetNew_Spell4, "spell4");

	//typedef I32 bbWidget_Mouse(void* void_mouseEvent, void* void_widget);
    bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Text, "clickText");
    bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Sphere, "clickSphere");
	bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Layout, "layout");
	bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Spell1, "spell1");
	bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Spell2, "spell2");
	bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Spell3, "spell3");
	bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Spell4, "spell4");
	bbWidgetFunctions_add(functions, f_WidgetMouseHandler, bbWidgetClick_Spellbar, "spellbar");
	bbWidgetFunctions_add(functions, f_WidgetMouseHandler,
						  bbWidgetClick_Viewport, "viewport");

	//typedef I32 bbWidget_OnCommand (bbWidget* widget, void* data);
    bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Textbox, "textbox");
    bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Prompt, "prompt");
	bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Spellbar, "spellbar");
	bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Spell1, "spell1");
	bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Spell2, "spell2");
	bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Spell3, "spell3");
	bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Spell4, "spell4");
	bbWidgetFunctions_add(functions, f_WidgetOnCommand, bbWidgetCommand_Viewport, "viewport");

	//typedef I32 bbWidget_OnTimer (bbWidget* widget, void* void_timerNode);
    bbWidgetFunctions_add(functions, f_WidgetOnTimer, bbWidget_Sphere_onTimer, "sphere");

	return f_Success;
}

