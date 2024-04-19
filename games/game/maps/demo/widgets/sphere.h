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
#include "headers/bbIntTypes.h"

//typedef I32 bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);


I32 bbWidgetNew_Sphere(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent) {
///	Spawn a null widget on selected map at coordinates mc


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    I32 flag =bbWidget_empty_new(&widget, widgets, sc, parent);


    widget->m_String = "Menu / Pause Button";
    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->v_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickText");

    widget->m_AnimationInt[0] = 29; // SPHERE
    widget->m_Frame[0] = 0;         // NOT USED
    widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "sprite");

    *reference = widget;
    return f_Success;

}
//typedef I32 bbWidget_Mouse(void* void_mouseEvent, void* void_widget);

/// if you click the widget, it will spawn a sphere
I32 bbWidgetClick_Sphere(void* void_mouseEvent, void* void_widget){
    bbMouseEvent* event = void_mouseEvent;
    bbWidget* widget = void_widget;
    bbScreenCoordsI sc = event->m_ScreenCoords;

    if (event->m_type == f_MouseLeft) {
        if (bbWidget_containsPoint(widget, event->m_ScreenCoords)) {
            I32 map = widget->p_Node.p_Pool.Self;
            bbWidgetFunctions *functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

            I32 type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "sphere");

            bbWidget *newWidget;
            bbWidget_new(&newWidget, g_Game->m_Maps[map]->m_Widgets, type, widget->p_Node.p_Pool.Self, sc);
            return f_Break;
        }
    }
    return f_Continue;

}