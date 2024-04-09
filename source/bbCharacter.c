#include "headers/bbCharacter.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbCommands.h"

int32_t Event_inputChar(char character, int32_t map){

    int32_t widget_int = g_Game->m_Maps[map]->misc.m_ActiveTextbox;

    bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;

    bbWidget* widget;

    bbPool_Lookup(&widget, pool, widget_int);

    bbCommandPutChar cmd;

    cmd.type = f_CommandPutChar;
    cmd.m_char= character;

    bbWidget_onCommand(&cmd, widget);

    return f_Success;

}