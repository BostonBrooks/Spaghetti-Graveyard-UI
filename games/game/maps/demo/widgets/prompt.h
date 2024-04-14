/**
 * @file
 * @brief The functions in this file define the behavior of an object with class bbWidget and type prompt
 * Prompt is the parent of three text boxes, the dialogue, 'prompt' and input
 */

#include <inttypes.h>

#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbCommands.h"
#include "headers/bbString.h"
#include "headers/bbFlags.h"

//typedef int32_t bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);
int32_t bbWidget_prompt_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent) {


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;
    int32_t map = widgets->m_Pool->m_Map;
    bbWidget *widget;
    int32_t flag;
    sfVector2f positionV2f = bbScreenCoordsI_getV2f(sc, &g_Game->m_Maps[map]->p_Constants);
    flag = bbWidget_empty_new(&widget, widgets, sc, parent);

        //TODO value should not be hard coded
    widget->m_String = calloc(1028, sizeof(char));
    bbStr_setStr(widget->m_String, "prompt");
    widget->m_Text = sfText_create();
    sfText_setPosition(widget->m_Text, positionV2f);
    sfText_setString(widget->m_Text, widget->m_String);


    sfText_setFont(widget->m_Text, g_Game->m_Maps[map]->m_Fonts->m_Fonts[0]);
    sfText_setColor(widget->m_Text, sfBlack);



    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->v_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickText");
    widget->v_OnCommand = bbWidgetFunctions_getInt(functions, f_WidgetOnCommand, "prompt");


    widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "text");




    int32_t type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "textbox");

    bbWidget* subWidget;

    bbCommandSetDim cmd;
    cmd.type = f_CommandSetDim;
    bbScreenCoordsI SCI;

    //Dialogue
    cmd.m_rows = 17;
    cmd.m_columns = 23;

    SCI.x = 881 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    SCI.y = 24 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    flag = bbWidget_new(&subWidget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self, SCI);
    bbAssert(flag == f_Success, "bad flag from bbWidget_new()\n");
    widget->m_SubwidgetArray[0] = subWidget->p_Node.p_Pool.Self;
    bbWidget_onCommand(&cmd, subWidget);

    cmd.m_rows = 3;
    cmd.m_columns = 23;

    //Query
    SCI.x = 881 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    SCI.y = 494 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    flag = bbWidget_new(&subWidget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self, SCI);
    bbAssert(flag == f_Success, "bad flag from bbWidget_new()\n");
    widget->m_SubwidgetArray[1] = subWidget->p_Node.p_Pool.Self;
    bbWidget_onCommand(&cmd, subWidget);

    cmd.m_rows = 3;
    cmd.m_columns = 23;

    //input
    SCI.x = 881 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    SCI.y = 606 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    flag = bbWidget_new(&subWidget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self, SCI);
    bbAssert(flag == f_Success, "bad flag from bbWidget_new()\n");
    widget->m_SubwidgetArray[2] = subWidget->p_Node.p_Pool.Self;
    bbWidget_onCommand(&cmd, subWidget);


    g_Game->m_Maps[map]->misc.m_ActiveTextbox = widget->p_Node.p_Pool.Self;
    *reference = widget;
    return f_Success;
}
//typedef int32_t bbWidget_OnCommand (bbWidget* widget, void* data);
int32_t bbWidget_Command_prompt(bbWidget* widget, void* data){
    bbCommandEmpty* commandEmpty = data;

    switch (commandEmpty->type) {
        case f_CommandPutChar: {
            bbCommandPutChar *commandPutChar = data;
            bbStr_putChar(widget->m_String, commandPutChar->m_char);
            sfText_setString(widget->m_Text, widget->m_String);


            int32_t map = widget->p_Node.p_Pool.Map;
            int32_t widget_int;
            bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
            bbWidget* subWidget;
            bbCommandPutChar cmd;
            cmd.type = f_CommandPutChar;
            cmd.m_char = commandPutChar->m_char;

            //Dialogue
            widget_int = widget->m_SubwidgetArray[0];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            //Query
            widget_int = widget->m_SubwidgetArray[1];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            //input
            widget_int = widget->m_SubwidgetArray[2];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            break;
        }
        case f_CommandPutStr: {
            bbCommandPutStr *commandPutStr = data;
            bbStr_putStr(widget->m_String, commandPutStr->m_str);
            sfText_setString(widget->m_Text, widget->m_String);
            break;
        }
        default:
        bbDebug("Command not found\n");
    }

}
