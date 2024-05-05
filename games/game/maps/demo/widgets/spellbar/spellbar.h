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
I32 bbWidgetNew_Spellbar2(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){
	//construct widget
	bbWidget* widget;
	bbPool* pool = widgets->m_Pool;
	//there will be one key-value pair for each widget
	bbDictionary* dict = widgets->m_AddressDict;
	I32 map = widgets->m_Pool->m_Map;
	I32 flag = bbWidget_empty_new(&widget, widgets, sc, parent);

	bbWidgetFunctions* functions = widgets->m_Functions;

	// widget->v_OnMouse = "click widget"

	widget->m_String = "Spell Bar";
	widget->m_AnimationInt[0] = 24; // SPELLBAR
	widget->m_Frame[0] = 1;         // SHOWHIDE
	widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "frame");


	bbScreenCoordsF SCF;
	bbScreenCoordsI SCI;

	float widgetScale = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.WidgetScale;
	SCF.x = 80 * widgetScale;
	SCF.y = 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_Dimensions = SCI;
	//call constructors for spell buttons

	SCF = bbScreenCoordsI_getF(sc, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	SCF.x += 80 * widgetScale;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);



	bbWidget* spell;
	I32 type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spell");
	bbWidget_new(&spell, widgets, type, widget->p_Node.p_Pool.Self, SCI);
	//initialise widget

	bbCommandEmpty cmd;
	cmd.type = c_SetIdle;
	bbWidget_onCommand(&cmd, widget);
}

//typedef I32 bbWidget_Mouse(void* void_mouseEvent, void* void_widget);
I32 bbWidgetClick_Spellbar(void* void_mouseEvent, void* void_widget){
	// Show/hide spell buttons (may wish to display cooldown bars)
}

//typedef I32 bbWidget_OnCommand (bbWidget* widget, void* data);
I32 bbWidgetCommand_Spellbar(bbWidget* widget, void* command){

	bbCommandEmpty* commandEmpty = command;

	switch (commandEmpty->type) {
		case c_SetIdle:
		{
			widget->s_State = s_Idle;

			//send command to spell and prompt?
			return f_Success;
		}
		case c_RequestCode:
		{
			widget->s_State = s_WaitingForCode;
			//pass request to prompt
			return f_Success;
		}
		case c_ReturnCode:
		{
			//deactivate current spell
			//request activate spell given by code
				//if the above line returns "on cooldown", request code from
				// prompt

			return f_Success;
		}
		case c_ActivateSpell:
		{
			//activate which spell?
			return f_Success;
		}
		case c_DeactivateSpell:
		{
			//pass command to active spell
			return f_Success;
		}
		case c_RequestClick:
		{
			//pass request to viewport
			return f_Success;
		}
		case c_ReturnClick:
		{
			//pass click to active spell
			return f_Success;
		}
		case c_RequestAnswer:
		{
			//pass request to prompt
			return f_Success;
		}
		case c_ReturnAnswer:
		{
			//pass answer to active spell
			return f_Success;
		}
		/* //used to pass command from spell to viewport
		case c_CastSpell:
		{

			return f_Success;
		} */
		default:
			bbDebug("command not found\n");
			return f_None;

	}
}

