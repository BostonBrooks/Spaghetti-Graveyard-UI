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
int32_t bbWidget_Widget2pt0_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){


	bbPool* pool = widgets->m_Pool;
	bbDictionary* dict = widgets->m_AddressDict;

	bbWidget* widget;
	int32_t flag;

	flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


	bbScreenCoordsF SCF;
	bbScreenCoordsI SCI;

	SCF.x = 200;
	SCF.y = 420;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_ScreenCoords = SCI;


	bbWidgetFunctions* functions = widgets->m_Functions;



	for(int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
		widget->m_AnimationInt[i] = f_None;
		widget->m_Angle[i] = 0;
		widget->m_Frame[i] = 0;
		widget->m_AnimationDraw[i] = f_None;
	}


	widget->m_AnimationInt[0] = 23;
	widget->m_AnimationDraw[0] = bbWidgetFunctions_getInt(functions, wf_AnimationDraw, "animation");

	*reference = widget;
	return f_Success;
}

/// Update widget
int32_t bbWidget_Widget2pt0_update(bbWidget* widget){
	return f_Success;
}

/// Send a command to the widget / update widget, etc
int32_t bbWidget_Widget2pt0_onCommand(bbWidget* widget, int32_t command, void* data){
	return f_Success;
}

/// Delete widget
int32_t bbWidget_Widget2pt0_delete(bbWidget* widget){
	return f_Success;
}

/// Draw widget to screen
int32_t bbWidget_Widget2pt0_draw(bbWidget* widget){
	return f_Success;
}
