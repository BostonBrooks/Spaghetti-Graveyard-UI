/** The spellbar acts an an interface between the current spell,
 * user interface and game
*/

#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbIntTypes.h"
#include "headers/bbCommands.h"

//typedef I32 bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);
I32 bbWidgetNew_Spellbar(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){
	//construct widget
	bbWidget* widget;
	bbPool* pool = widgets->m_Pool;
	//there will be one key-value pair for each widget
	bbDictionary* dict = widgets->m_AddressDict;
	I32 map = widgets->m_Pool->m_Map;
	I32 flag = bbWidget_empty_new(&widget, widgets, sc, parent);

	bbWidgetFunctions* functions = widgets->m_Functions;

	widget->v_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "spellbar");

	widget->m_String = "Spell Bar";
	widget->m_AnimationInt[0] = 24; // SPELLBAR
	widget->m_Frame[0] = 1;         // SHOWHIDE
	widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "frame");
    widget->v_OnCommand = bbWidgetFunctions_getInt(functions, f_WidgetOnCommand, "spellbar");

	bbScreenCoordsF SCF;
	bbScreenCoordsI SCI;

	float widgetScale = g_Game->m_GraphicsSettings->m_WidgetScale;
	SCF.x = 80 * widgetScale;
	SCF.y = 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_Dimensions = SCI;
	//call constructors for spell buttons
	bbWidget* spell;
	I32 type;
	bbCommandEmpty cmd;
	cmd.type = c_SetIdle;
	SCF = bbScreenCoordsI_getF(sc, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);

	SCF.x += 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spell1");
	bbWidget_new(&spell, widgets, type, widget->p_Node.p_Pool.Self, SCI);
	bbWidget_onCommand(&cmd, spell);

	SCF.x += 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spell2");
	bbWidget_new(&spell, widgets, type, widget->p_Node.p_Pool.Self, SCI);

	SCF.x += 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spell3");
	bbWidget_new(&spell, widgets, type, widget->p_Node.p_Pool.Self, SCI);

	SCF.x += 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spell4");
	bbWidget_new(&spell, widgets, type, widget->p_Node.p_Pool.Self, SCI);
	bbWidget_onCommand(&cmd, spell);

	widget->m_CurrentSpell = spell;

	bbWidget_onCommand(&cmd, widget);

    *reference = widget;

	return f_Success;
}

//typedef I32 bbWidget_Mouse(void* void_mouseEvent, void* void_widget);
I32 bbWidgetClick_Spellbar(void* void_mouseEvent, void* void_widget){

	return f_Continue;
}

//typedef I32 bbWidget_OnCommand (bbWidget* widget, void* data);
I32 bbWidgetCommand_Spellbar(bbWidget* widget, void* command){

	bbCommandEmpty* commandEmpty = command;

	switch (commandEmpty->type) {
        case c_ReturnCode: {
			bbCommandStr* cmdStr = command;

			//bbDialog("\nspellbar\n-> return code\n-> %s", cmdStr->m_str);

			I32 flag = strcmp(cmdStr->m_str, "");
			if (flag == 0){
				//bbDialog("\n->string empty");
				//What was the last spell?
				//if valid:
				//    spell -> c_ActivateSpell
			} else {
				I32 map = widget->p_Node.p_Pool.Map;
				bbDictionary* dict = g_Game->m_Maps[map]->m_Widgets->m_CodeDict;
				I32 spellInt = bbDictionary_lookup(dict, cmdStr->m_str);
				if(spellInt < 0){
					bbDialog("\nspell not found");
					bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
					bbCommandEmpty cmdEmpty;
					cmdEmpty.type = c_RequestCode;
					bbWidget_onCommand(&cmdEmpty, prompt);
					return f_None;
				}
				bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
				bbWidget* spell;
				bbPool_Lookup(&spell, pool, spellInt);
				bbCommandEmpty cmdEmpty;
				cmdEmpty.type = c_ActivateSpell;

				bbWidget_onCommand(&cmdEmpty, spell);

			}
            //lookup spell, send wakeup message to spell
            return f_None;
        }
		case c_SetCurrentSpell: {
			bbCommandPtr* cmdPtr = command;
			widget->m_CurrentSpell = cmdPtr->m_ptr;
			//spell informs spellbar that it is the current spell
			return f_None;
		}

        case c_ReturnAnswer: {
			if (widget->m_CurrentSpell == NULL){
				I32 map = widget->p_Node.p_Pool.Map;
				bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
				bbCommandEmpty cmdEmpty;
				cmdEmpty.type = c_RequestCode;
				bbWidget_onCommand(&cmdEmpty, prompt);
				return f_None;

			}
			//pass answer to current spell
			bbCommandStr* cmdStr = command;
			bbCommandStr newCmdStr;
			newCmdStr.type = c_ReturnAnswer;
			newCmdStr.m_str = cmdStr->m_str;
			bbWidget_onCommand(&newCmdStr, widget->m_CurrentSpell);

            return f_None;
        }
        case c_ReturnClick: {
			if (widget->m_CurrentSpell == NULL){
				//bbDialog("\nno spell selected");
				I32 map = widget->p_Node.p_Pool.Map;
				bbWidget* prompt = g_Game->m_Maps[map]->m_Widgets->m_Prompt;
				bbCommandEmpty cmdEmpty;
				cmdEmpty.type = c_RequestCode;
				bbWidget_onCommand(&cmdEmpty, prompt);
				return f_None;

			}
			//bbDialog("\nrelay click to spell");
			//pass answer to current spell
			bbWidget_onCommand(command, widget->m_CurrentSpell);

			return f_None;
		}
		default:
			bbDebug("Spellbar: Command %d not found\n", commandEmpty->type);
			return f_None;

	}
}

