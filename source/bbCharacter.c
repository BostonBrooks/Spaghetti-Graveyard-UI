#include "headers/bbCharacter.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbCommands.h"

int32_t Event_inputChar(char character, int32_t map){
    if (character == '/') {
        bbHere();
        bbCommandEmpty cmd1;
        cmd1.type = f_CommandSetInactive;
        int32_t widget_int = g_Game->m_Maps[map]->misc.m_ActiveSpell;
        bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
        bbWidget* widget;
        bbPool_Lookup(&widget, pool, widget_int);
        bbWidget_onCommand(&cmd1, widget);
        cmd1.type = f_CommandSetActive;
        widget_int = g_Game->m_Maps[map]->misc.m_SpellSelector;
        bbPool_Lookup(&widget, pool, widget_int);
        bbWidget_onCommand(&cmd1, widget);

    }

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