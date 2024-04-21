/**
 * @file
 * @brief The functions in this folder define the behavior of an object with class bbWidget and type NULL
 */
#define BBDEBUG

#include "headers/bbPrintf.h"

#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbWidgetTimer.h"

///	Spawn a null widget on selected map at coordinates mc
I32 bbWidgetNew_Decal(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){



    bbWidget* widget;
    bbWidget_empty_new(&widget, widgets, sc, NULL);
    I32 flag;
    widget->m_String = "Decal / Root Widget";

    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->v_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickSphere");


    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;

    SCF.x = 0;
    SCF.y = 0;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_ScreenCoords = SCI;

    SCF.x = 1280;
    SCF.y = 720;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;


    widget->m_AnimationInt[0] = 162; //DECAL_1280
    widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "sprite");


    *reference = widget;
    return f_Success;
}

/// Update widget
I32 bbWidget_Decal_update(bbWidget* widget){}

/// Send a command to the widget / update widget, etc
I32 bbWidget_Decal_onCommand(bbWidget* widget, void* command){}

/// Delete widget
I32 bbWidget_Decal_delete(bbWidget* widget){}

/// Draw widget to screen
I32 bbWidget_Decal_draw(bbWidget* widget){}


