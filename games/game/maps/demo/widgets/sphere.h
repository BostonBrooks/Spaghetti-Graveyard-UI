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
    int32_t flag =bbWidget_empty_new(&widget, widgets, sc, parent);


    widget->m_String = "Menu / Pause Button";
    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->v_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickText");

    widget->m_AnimationInt[0] = 29; // SPHERE
    widget->m_Frame[0] = 0;         // NOT USED
    widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "sprite");

    *reference = widget;
    return f_Success;

}
//typedef int32_t bbWidget_Mouse(void* void_mouseEvent, void* void_widget);

/// if you click the widget, it will spawn a sphere
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