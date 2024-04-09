#include <inttypes.h>
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbAnimation.h"
#include "headers/bbGame.h"

//typedef int32_t bbWidget_Mouse(void* void_mouseEvent, void* void_widget);

/// if you click the widget, it will printf some text
int32_t bbWidget_MouseClickText(void* void_mouseEvent, void* void_widget){
    bbMouseEvent* event = void_mouseEvent;
    bbWidget* widget = void_widget;

    if (event->m_type == f_MouseLeft) {
        if (bbWidget_containsPoint(widget, event->m_ScreenCoords)) {
            bbPrintf("You clicked %s\n", widget->m_String);
            return f_Break;
        }
    }
    return f_Continue;

}