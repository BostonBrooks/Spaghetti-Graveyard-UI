/**
 * @file
 * @brief The functions in this folder define the behavior of an object with class bbWidget and type fireworks
 */

#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"

///	Spawn a null widget on selected map at coordinates mc
int32_t bbWidget_fireworks_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


	bbPool* pool = widgets->m_Pool;
	bbDictionary* dict = widgets->m_AddressDict;

	bbWidget* widget;
	int32_t flag;

	flag = bbPool_New(&widget, pool, f_PoolNextAvailable);

    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->m_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickText");
    widget->m_String = "Fireworks XD";
	bbScreenCoordsF SCF;
	bbScreenCoordsI SCI;

	SCF.x = 20;
	SCF.y = 315;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_ScreenCoords = SCI;

    widget->p_Node.p_Tree.Visible = true;
    widget->p_Node.p_Tree.SubwidgetsVisible = true;




	for(int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
		widget->m_AnimationInt[i] = f_None;
		widget->m_Angle[i] = 0;
		widget->m_Frame[i] = 0;
		widget->m_DrawFunction[i] = f_None;
	}


	widget->m_AnimationInt[0] = 23; //Fireworks
	widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "animation");
    bbDebug("drawfunction = %d\n", widget->m_DrawFunction[0]);
    widget->m_AnimationStart[0] = 0;

    bbNode_setParent(widget, parent, pool);

	*reference = widget;


	return f_Success;
}

/// Update widget
int32_t bbWidget_fireworks_update(bbWidget* widget){
	return f_Success;
}

/// Send a command to the widget / update widget, etc
int32_t bbWidget_fireworks_onCommand(bbWidget* widget, void* command){
	return f_Success;
}

/// Delete widget
int32_t bbWidget_fireworks_delete(bbWidget* widget){
	return f_Success;
}

/// Draw widget to screen
int32_t bbWidget_fireworks_draw(bbWidget* widget){
	return f_Success;
}
