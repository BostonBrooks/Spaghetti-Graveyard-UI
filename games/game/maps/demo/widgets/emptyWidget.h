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

/// set the default values and add to tree data structure
int32_t bbWidget_empty_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){
    bbPool* pool =  widgets->m_Pool;
    bbDictionary* dict = widgets->m_AddressDict;
    bbWidget* widget;
    int32_t flag;
    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);

    for(int32_t i = 0; i < subwidgetarraysize; i++){
        widget->m_SubwidgetArray[i] = f_None;
    }
    widget->p_Node.p_Tree.Visible = true;
    widget->p_Node.p_Tree.SubwidgetsVisible = true;

    widget->m_ScreenCoords = sc;
    widget->m_Dimensions.x = f_None;
    widget->m_Dimensions.y = f_None;

    widget->m_String = "Initialised empty widget";

    widget->m_Text = NULL;
    widget->m_Font = NULL;
    widget->m_TextRows = f_None;
    widget->m_TextRows = f_None;
    widget->m_Code = "007";

    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
        widget->m_AnimationStart[i] = f_None;
    }

    widget->m_State = f_None;
    widget->m_OnCommand = f_None;
    widget->m_OnUpdate = f_None;
    widget->m_OnDraw = f_None;
    widget->m_OnDelete = f_None;
    widget->m_OnMouse = f_None;

    widget->m_CoolDownStart = f_None;
    widget->m_CoolDownEnd = f_None;
    widget->m_RedRect = NULL;
    widget->m_GreenRect = NULL;

    widget->m_ExtraData = NULL;

    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}