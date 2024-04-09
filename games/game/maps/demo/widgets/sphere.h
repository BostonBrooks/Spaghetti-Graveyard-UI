/**
 * @file
 * @brief The functions in this file define the behavior of an object with class bbWidget and type Sphere
 * The sphere does nothing, gets spawned on a click to decal
 * Used to show that clicks are landing in the right position
 *
 */


#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"

//typedef int32_t bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);


int32_t bbWidget_sphere_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent) {
///	Spawn a null widget on selected map at coordinates mc


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);

    widget->m_String = "Menu / Pause Button";
    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->m_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickText");

    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;

    //negative size means cant be clicked
    float widgetScale = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.WidgetScale;
    SCF.x = -1 * widgetScale;
    SCF.y = -1 * widgetScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;



    widget->p_Node.p_Tree.Visible = true;
    widget->p_Node.p_Tree.SubwidgetsVisible = true;



    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 29; // SPHERE
    widget->m_Frame[0] = 0;         // NOT USED
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "sprite");




    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;

}
//typedef int32_t bbWidget_Mouse(void* void_mouseEvent, void* void_widget);

/// if you click the widget, it will printf some text
int32_t bbWidget_MouseClickSphere(void* void_mouseEvent, void* void_widget){
    bbMouseEvent* event = void_mouseEvent;
    bbWidget* widget = void_widget;
    bbScreenCoordsI sc = event->m_ScreenCoords;

    if (event->m_type == f_MouseLeft) {
        if (bbWidget_containsPoint(widget, event->m_ScreenCoords)) {
            int32_t map = widget->p_Node.p_Pool.Self;
            bbWidgetFunctions *functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

            int32_t type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "sphere");

            bbWidget *newWidget;
            bbWidget_new(&newWidget, g_Game->m_Maps[map]->m_Widgets, type, widget->p_Node.p_Pool.Self, sc);
            return f_Break;
        }
    }
    return f_Continue;

}