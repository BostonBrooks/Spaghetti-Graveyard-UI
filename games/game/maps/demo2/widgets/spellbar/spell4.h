/** This spell is a prototype for widgets that control the casting of spells
*
 *
*/

#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbIntTypes.h"
#include "headers/bbCommands.h"
#include <stdlib.h>

//typedef I32 bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);
I32 bbWidgetNew_Spell4(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){
	//construct widget
	bbWidget* widget;
	bbPool* pool = widgets->m_Pool;
	//there will be one key-value pair for each widget
	bbDictionary* dict = widgets->m_AddressDict;
	I32 map = widgets->m_Pool->m_Map;
	I32 flag = bbWidget_empty_new(&widget, widgets, sc, parent);

	bbWidgetFunctions* functions = widgets->m_Functions;

	widget->v_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "spell4");
	widget->v_OnCommand = bbWidgetFunctions_getInt(functions, f_WidgetOnCommand, "spell4");
	widget->m_String = "Spell4";
	widget->m_String2 = calloc(128, sizeof(char));
	widget->m_AnimationInt[0] = 24; // SPELLBAR
	widget->m_Frame[0] = 5;         // PLUS
	widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "frame");

	widget->m_CoolDownStart = 0;
	widget->m_CoolDownEnd = 60;

	widget->m_RedRect = sfRectangleShape_create();
	sfColor RedHalfAlpha;
	RedHalfAlpha.r = 255;
	RedHalfAlpha.g = 0;
	RedHalfAlpha.b = 0;
	RedHalfAlpha.a = 127;
	sfRectangleShape_setFillColor(widget->m_RedRect, RedHalfAlpha);

	sfVector2f vector2f;
	vector2f = bbScreenCoordsI_getV2f(sc, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	sfRectangleShape_setPosition(widget->m_RedRect, vector2f);
	vector2f = bbScreenCoordsI_getV2f(sc, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	sfRectangleShape_setSize(widget->m_RedRect, vector2f);
	widget->v_DrawFunction[1] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "cooldown");

	bbScreenCoordsF SCF;
	bbScreenCoordsI SCI;

	float widgetScale = g_Game->m_GraphicsSettings->m_WidgetScale;
	SCF.x = 80 * widgetScale;
	SCF.y = 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_Dimensions = SCI;

	//initialise widget

	bbCommandEmpty cmd;
	cmd.type = c_SetIdle;
	bbWidget_onCommand(&cmd, widget);

    bbDictionary* codeDict = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_CodeDict;
    widget->m_Code = "4";
    bbDictionary_add(codeDict, widget->m_Code, widget->p_Node.p_Pool.Self);

	*reference = widget;
    return f_Success;
}

//typedef I32 bbWidget_Mouse(void* void_mouseEvent, void* void_widget);
I32 bbWidgetClick_Spell4(void* void_mouseEvent, void* void_widget){

	bbMouseEvent* event = void_mouseEvent;
	bbWidget* widget = void_widget;
	bbScreenCoordsI sc = event->m_ScreenCoords;

	if (! bbWidget_containsPoint(widget, event->m_ScreenCoords)) return f_Continue;
	if (event->m_type != f_MouseLeft) return f_Continue;

	bbCommandEmpty cmd;
	cmd.type = c_ActivateSpell;
	bbWidget_onCommand(&cmd, widget);

	return f_Break;
}

//typedef I32 bbWidget_OnCommand (bbWidget* widget, void* data);
I32 bbWidgetCommand_Spell4(bbWidget* widget, void* command){

	bbCommandEmpty* commandEmpty = command;

	switch (commandEmpty->type) {

        case c_ActivateSpell: {
			//bbDialog("\nActivate Spell");
			I32 map = widget->p_Node.p_Pool.Map;
            //if the spell is available, message spellbar to set current spell
			if (widget->m_CoolDownEnd > g_Game->m_Maps[map]->misc.m_MapTime){

				//bbDialog("\nSpell on cooldown");
				I32 map = widget->p_Node.p_Pool.Map;
				bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
				bbCommandEmpty cmdEmpty;
				cmdEmpty.type = c_RequestCode;
				bbWidget_onCommand(&cmdEmpty, prompt);
				return f_None;

			}

			widget->s_State = s_WaitingForAnswer;

			bbCommandPtr cmdPtr;
			cmdPtr.type = c_SetCurrentSpell;
			cmdPtr.m_ptr = widget;
			bbWidget* spellbar = g_Game->m_Maps[map]->m_Widgets->m_SpellBar;
			bbWidget_onCommand(&cmdPtr, spellbar);



			I32 x = 1 + rand()%11;
			I32 y = rand()%12;
			sprintf(widget->m_String2, "%d", y);
			char question[512];
			sprintf(question, "what is %d / %d", x*y, x);

			bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
			bbCommandStr cmdStr;
			cmdStr.type = c_RequestAnswer;
			cmdStr.m_str = question;
			bbWidget_onCommand(&cmdStr, prompt);

            //request answer from prompt
            return f_None;
        }
        case c_ReturnAnswer: {
			bbCommandStr* cmdStr = command;
			I32 flag = strcmp(widget->m_String2, cmdStr->m_str);
			if (flag != 0){
				bbDialog("\nyou entered %s\nanswer is %s", cmdStr->m_str, widget->m_String2);
				I32 map = widget->p_Node.p_Pool.Map;
				bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
				bbCommandEmpty cmdEmpty;
				cmdEmpty.type = c_RequestCode;
				bbWidget_onCommand(&cmdEmpty, prompt);
				return f_None;

			}
			widget->s_State = s_WaitingForClick;

			I32 map = widget->p_Node.p_Pool.Map;
			bbCommandEmpty cmdEmpty;
			cmdEmpty.type = c_RequestClick;
			bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
			bbWidget_onCommand(&cmdEmpty, prompt);
			bbWidget* viewport = g_Game->m_Maps[map]->m_Widgets->m_Viewport;
			bbWidget_onCommand(&cmdEmpty, viewport);
			return f_None;
        }
        case c_ReturnClick: {
            if (widget->s_State != s_WaitingForClick){
				//bbDialog("\nspell click unexpected");
				I32 map = widget->p_Node.p_Pool.Map;
				bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
				bbCommandEmpty cmdEmpty;
				cmdEmpty.type = c_RequestCode;
				bbWidget_onCommand(&cmdEmpty, prompt);
				return f_None;

			}
			//bbDialog("\nsend spell to viewport");

			I32 map = widget->p_Node.p_Pool.Map;

			widget->m_CoolDownStart = g_Game->m_Maps[map]->misc.m_MapTime;
			widget->m_CoolDownEnd = g_Game->m_Maps[map]->misc.m_MapTime + 180;

			bbCommand2I* cmd2i = command;
			widget->s_State = s_Idle;
			bbCommand3I cmd3i;
			cmd3i.type = c_CastSpell;
			//pass screen coordinates
			cmd3i.m_intx = cmd2i->m_intx;
			cmd3i.m_inty = cmd2i->m_inty;
			//pass effect type;
			cmd3i.m_intz = 4;
			bbWidget* viewport = g_Game->m_Maps[map]->m_Widgets->m_Viewport;
			bbWidget_onCommand(&cmd3i, viewport);

			bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
			bbCommandEmpty cmdEmpty;
			cmdEmpty.type = c_RequestCode;
			bbWidget_onCommand(&cmdEmpty, prompt);
			return f_None;

        }
		default:
			bbDebug("spell: Command %d not found\n", commandEmpty->type);
			return f_None;

	}
}

