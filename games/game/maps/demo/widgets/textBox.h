/**
 * @file
 * @brief The functions in this file define the behavior of an object with class bbWidget and type textBox
 * and its member widgets
 *
 * The bbTree representing the spellBar is structured as such
 *
 *    prompt
 *      - textBox
 *      - queryBox
 *      - inputBox
 */


#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbCommands.h"
#include "headers/bbString.h"

//typedef int32_t bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);
int32_t bbWidget_textBox_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent) {

    bbHere();
    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;
    int32_t map = widgets->m_Pool->m_Map;
    bbWidget *widget;
    int32_t flag;
    sfVector2f positionV2f = bbScreenCoordsI_getV2f(sc, &g_Game->m_Maps[map]->p_Constants);
    bbHere();
    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);

    widget->m_String = calloc(1028, sizeof(char));
    strcpy(widget->m_String, "New Text Box");
    widget->m_Text = sfText_create();
    sfText_setPosition(widget->m_Text, positionV2f);
    sfText_setString(widget->m_Text, widget->m_String);

    bbHere();
    sfText_setFont(widget->m_Text, g_Game->m_Maps[map]->m_Fonts->m_Fonts[0]);

    bbHere();
/*  text = sfText_create();
 sfText_setString(text, "Hello SFML");
 sfText_setFont(text, font);
 sfText_setCharacterSize(text, 50);
 */

    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->m_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickText");

    widget->m_ScreenCoords = sc;

    bbScreenCoordsI SCI;
    SCI.x = 350 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;
    SCI.y = 350 * g_Game->m_Maps[map]->p_Constants.ScreenPPP;

    widget->m_Dimensions = SCI;

    widget->p_Node.p_Tree.Visible = true;
    widget->p_Node.p_Tree.SubwidgetsVisible = true;

    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "text");

    bbHere();
    bbNode_setParent(widget, parent, pool);

    g_Game->m_Maps[map]->misc.m_ActiveTextbox = widget->p_Node.p_Pool.Self;
    *reference = widget;
    return f_Success;
}

//typedef int32_t bbWidget_OnCommand (bbWidget* widget, void* data);
int32_t bbWidget_Command_textBox(bbWidget* widget, void* data){
    bbCommandEmpty* commandEmpty = data;

    switch (commandEmpty->type) {
        case f_CommandPutChar: {
            bbCommandPutChar *commandPutChar = data;
            bbStr_putChar(widget->m_String, commandPutChar->m_char);
            bbStr_setBounds(widget->m_String, 12, 10);
            //may or may not be necessary
            sfText_setString(widget->m_Text, widget->m_String);
            break;
        }
        default:
        bbDebug("Command not found\n");
    }

}
