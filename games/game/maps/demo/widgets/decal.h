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

///	Spawn a null widget on selected map at coordinates mc
int32_t bbWidget_Decal_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){

    bbPool* pool = widgets->m_Pool;
    bbDictionary* dict = widgets->m_AddressDict;

    bbWidget* widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


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

    bbWidgetFunctions* functions = widgets->m_Functions;



    for(int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 162; //DECAL_1280
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "sprite");


    bbNode_setParent(widget, NULL, g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_Pool);


    *reference = widget;
    return f_Success;
}

/// Update widget
int32_t bbWidget_Decal_update(bbWidget* widget){}

/// Send a command to the widget / update widget, etc
int32_t bbWidget_Decal_onCommand(bbWidget* widget, int32_t command, void* data){}

/// Delete widget
int32_t bbWidget_Decal_delete(bbWidget* widget){}

/// Draw widget to screen
int32_t bbWidget_Decal_draw(bbWidget* widget){}
