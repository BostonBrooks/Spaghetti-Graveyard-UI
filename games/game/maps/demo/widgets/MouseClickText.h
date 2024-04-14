#include <inttypes.h>
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbAnimation.h"
#include "headers/bbGame.h"
#include "headers/bbCommands.h"

//typedef int32_t bbWidget_Mouse(void* void_mouseEvent, void* void_widget);

/// if you click the widget, it will printf some text
int32_t bbWidget_MouseClickText(void* void_mouseEvent, void* void_widget){
    bbMouseEvent* event = void_mouseEvent;
    bbWidget* widget = void_widget;

    if (event->m_type == f_MouseLeft) {
        if (bbWidget_containsPoint(widget, event->m_ScreenCoords)) {
            char string[512];
            int32_t promptInt = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->misc.m_ActiveTextbox;
            bbPool* pool = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_Pool;
            bbWidget* promptWidget;
            bbPool_Lookup(&promptWidget, pool, promptInt);
            int32_t dialogueInt = promptWidget->m_SubwidgetArray[0];
            bbWidget* dialogueWidget;
            bbPool_Lookup(&dialogueWidget, pool, dialogueInt);
            sprintf(string,"\nYou clicked %s", widget->m_String);

            bbCommandPutStr cmd;
            cmd.type = f_CommandPutStr;
            cmd.m_str = string;
            bbWidget_onCommand(&cmd, dialogueWidget);

            return f_Break;
        }
    }
    return f_Continue;

}