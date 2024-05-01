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
#include "headers/bbIntTypes.h"

#define i_spellbar   0
#define i_dialogue   1
#define i_query      2
#define i_answer     3

//typedef I32 bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);
I32 bbWidgetNew_Prompt(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent) {


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;
    I32 map = widgets->m_Pool->m_Map;
    bbWidget *widget;
    I32 flag;
    sfVector2f positionV2f = bbScreenCoordsI_getV2f(sc, &g_Game->m_Maps[map]->p_Constants);
    flag = bbWidget_empty_new(&widget, widgets, sc, parent);

    widget->m_SubwidgetArray[i_spellbar] = g_Game->m_Maps[map]->misc.m_SpellBar_deprecated;

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




    I32 type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "textbox");

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
    widget->m_SubwidgetArray[i_dialogue] = subWidget->p_Node.p_Pool.Self;
    bbWidget_onCommand(&cmd, subWidget);

    cmd.m_rows = 3;
    cmd.m_columns = 23;

    //Query
    SCI.x = 881 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    SCI.y = 494 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    flag = bbWidget_new(&subWidget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self, SCI);
    bbAssert(flag == f_Success, "bad flag from bbWidget_new()\n");
    widget->m_SubwidgetArray[i_query] = subWidget->p_Node.p_Pool.Self;
    bbWidget_onCommand(&cmd, subWidget);

    cmd.m_rows = 3;
    cmd.m_columns = 23;

    //input
    SCI.x = 881 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    SCI.y = 606 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    flag = bbWidget_new(&subWidget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self, SCI);
    bbAssert(flag == f_Success, "bad flag from bbWidget_new()\n");
    widget->m_SubwidgetArray[i_answer] = subWidget->p_Node.p_Pool.Self;
    bbWidget_onCommand(&cmd, subWidget);


    g_Game->m_Maps[map]->misc.m_ActiveTextbox_deprecated = widget->p_Node.p_Pool.Self;
    *reference = widget;
    return f_Success;
}
//typedef I32 bbWidget_OnCommand (bbWidget* widget, void* data);
I32 bbWidgetCommand_Prompt(bbWidget* widget, void* data){
    bbCommandEmpty* commandEmpty = data;

    switch (commandEmpty->type) {
/*        case f_CommandPutChar: {
            bbCommandPutChar *commandPutChar = data;
            bbStr_putChar(widget->m_String, commandPutChar->m_char);
            sfText_setString(widget->m_Text, widget->m_String);


            I32 map = widget->p_Pool.p_Pool.Map;
            I32 widget_int;
            bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
            bbWidget* subWidget;
            bbCommandPutChar cmd;
            cmd.type = f_CommandPutChar;
            cmd.m_char = commandPutChar->m_char;

            //Dialogue
            widget_int = widget->m_SubwidgetArray[i_dialogue];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            //Query
            widget_int = widget->m_SubwidgetArray[i_query];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            //input
            widget_int = widget->m_SubwidgetArray[i_answer];
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
        */
        case f_PromptSetQuery: {
            bbCommandSetStr *commandSetString = data;
            bbStr_setStr(widget->m_String, "");
            sfText_setString(widget->m_Text, widget->m_String);


            I32 map = widget->p_Node.p_Pool.Map;
            I32 widget_int;
            bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
            bbWidget* subWidget;
            bbCommandSetStr cmd;

            //Query
            cmd.type = f_CommandSetStr;
            cmd.m_str = commandSetString->m_str;
            widget_int = widget->m_SubwidgetArray[i_query];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            //input
            cmd.m_str = "?:";
            widget_int = widget->m_SubwidgetArray[i_answer];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            break;
        }
        case f_PromptAddChar:  {
            bbCommandPutChar *commandPutChar = data;
            bbStr_putChar(widget->m_String, commandPutChar->m_char);
            sfText_setString(widget->m_Text, widget->m_String);


            I32 map = widget->p_Node.p_Pool.Map;
            I32 widget_int;
            bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
            bbWidget* subWidget;
            bbCommandPutChar cmd;
            cmd.type = f_CommandPutChar;
            cmd.m_char = commandPutChar->m_char;

            //input
            widget_int = widget->m_SubwidgetArray[i_answer];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);

            break;
        }
        case f_PromptReturnAnswer: {     //bbCharacter.h requests current answer, sends to spellbar
            bbCommandSetStr* cmd = data;

            //return answer to caller
            cmd->type = f_PromptReturnAnswer;

            //cmd->str must point to a char buffer
            strcpy(cmd->m_str, widget->m_String);

            //gather data
            I32 map = widget->p_Node.p_Pool.Map;
            I32 widget_int;
            bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
            bbWidget* subWidget;
            bbCommandSetStr cmd2;

            //reset answer widget
            cmd2.type = f_CommandSetStr;
            cmd2.m_str = "/:";

            widget_int = widget->m_SubwidgetArray[i_answer];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd2, subWidget);

            //reset answer stored in prompt
            bbStr_setStr(widget->m_String, "");
            sfText_setString(widget->m_Text, widget->m_String);
            break;
        }
        case f_PromptAddDialogue: {
            bbCommandPutStr *commandPutStr = data;

            bbCommandPutStr cmd;
            cmd.type = f_CommandPutStr;
            cmd.m_str = commandPutStr->m_str;

            //gather data
            I32 map = widget->p_Node.p_Pool.Map;
            I32 widget_int;
            bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
            bbWidget* subWidget;
            widget_int = widget->m_SubwidgetArray[i_dialogue];
            bbPool_Lookup(&subWidget, pool, widget_int);
            bbWidget_onCommand(&cmd, subWidget);



            break;
        }
        default:
        bbDebug("Command not found\n");
    }

}
