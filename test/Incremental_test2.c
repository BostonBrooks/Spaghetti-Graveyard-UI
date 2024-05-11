#include <inttypes.h>
#include <stdio.h>
#include "headers/bbSystemIncludes.h"
#include "headers/bbEngineConstants.h"
#include "headers/bbGame.h"
#include "headers/bbPrintf.h"
#include "headers/bbMap.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"
#include "headers/bbAnimation.h"
#include "headers/bbPool.h"
#include "headers/bbTree.h"
#include "headers/bbDispatch.h"
#include "headers/bbWidget.h"
#include "headers/bbCharacter.h"
#include "headers/bbIntTypes.h"

bbGame* g_Game;

int main (void){
// ---------- Launch Game ---------- //

    I32 flag;
    flag = bbGame_new(&g_Game, GAME_PATH);
    bbDebug("flag0 = %d\n", flag);
    g_Game->m_CurrentMap = 0;;
    I32 mapInt = 0;
    sfRenderWindow_setFramerateLimit(g_Game->m_Window, 60);
    sfVector2i screenPosition;
    screenPosition.x = 0;
    screenPosition.y = -25;
    sfRenderWindow_setPosition(g_Game->m_Window, screenPosition);
    char mapPath[512];
    sprintf(mapPath, "%s/maps/%s", GAME_PATH, &g_Game->m_MapNames[g_Game->m_CurrentMap]);
    flag = bbMap_new(&g_Game->m_Maps[g_Game->m_CurrentMap], mapPath);
    bbMap* map = g_Game->m_Maps[mapInt];

// ---------- Textures ---------- //
    flag = bbTextures_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures,
                          mapPath, g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Textures);
    bbDebug("flag1 = %d\n", flag);
    // ---------- Sprites  ---------- //
    flag = bbSprites_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites,
                         g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures,
                         mapPath,
                         &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);
    bbDebug("flag2 = %d\n", flag);

// ---------- Animations  ---------- //

    flag = bbAnimations_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Animations,
                            g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites,
                            mapPath,
                            g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Animations);
    bbDebug("flag3 = %d\n", flag);

// ---------- Fonts  ---------- //

    bbFonts_new(&map->m_Fonts, NULL, 1);

	bbHere();
// ---------- Widgets  ---------- //

    bbWidgets_new(mapInt);

	bbHere();
    //Needed to include RBR to prevent circular reference in header files
    bbWidgetTimer_new(&g_Game->m_Maps[mapInt]->m_WidgetTimer, mapInt);
    bbWidgetFunctions_new(mapInt);
    bbWidgetFunctions_populate(mapInt);
    bbWidgetFunctions* functions = map->m_Widgets->m_Functions;

// ---------- Spawn Widgets  ---------- //
    I32 type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "layout");
    bbWidget* Layout;
    bbScreenCoordsI SC0; SC0.x = 0; SC0.y = 0;
    flag = bbWidget_new(&Layout, map->m_Widgets, type, f_None, SC0);
    bbDebug("flag4 = %d\n", flag);

    type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "viewport");
    bbWidget* Viewport;
    flag = bbWidget_new(&Viewport, map->m_Widgets, type, Layout->p_Node.p_Pool.Self, SC0);
    bbDebug("flagZ = %d\n", flag);

    type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spellBar");
    bbWidget* Spellbar;
    bbScreenCoordsF SCF;
    SCF.x =  g_Game->m_GraphicsSettings->m_SpellbarLeft;
    SCF.y = g_Game->m_GraphicsSettings->m_SpellbarBottom - 80 * g_Game->m_GraphicsSettings->m_WidgetScale;
    bbScreenCoordsI SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);
    flag = bbWidget_new(&Spellbar, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, Layout->p_Node.p_Pool.Self, SCI);
    bbDebug("flag5 = %d\n", flag);

	type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spellbar");
	SCF.x =  g_Game->m_GraphicsSettings->m_SpellbarLeft;
	SCF.y = 120;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);
	flag = bbWidget_new(&Spellbar, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, Layout->p_Node.p_Pool.Self, SCI);
	bbDebug("flag5.5 = %d\n", flag);

    bbWidget* Prompt;
    SCF.x = 30; SCF.y = 24;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);
    type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "prompt");
    flag = bbWidget_new(&Prompt, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, Layout->p_Node.p_Pool.Self, SCI);
    bbDebug("flag6 = %d\n", flag);

    g_Game->m_Maps[g_Game->m_CurrentMap]->misc.m_MapTime = 0;
    g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Layout = Layout;
    g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Prompt = Prompt;
    g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_SpellBar = Spellbar;

    sfSprite* cursor = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites->m_Sprites[229];
    sfVector2i cursorPosI; sfVector2f cursorPosF;

    sfRenderWindow_setMouseCursorVisible(g_Game->m_Window, false);

    /*
    bbWidget* fireworks;
    SCF.x = 0; SCF.y = 0;
    SCI = bbScreenCoordsF_getI(SCF, &map->p_Constants);
    type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "fireworks");
    bbWidget_new(&fireworks, map->m_Widgets, type, Layout->p_Node.p_Pool.Self, SCI);
*/
    I32 paused = 0;

    sfText* activeText = sfText_create();
    sfText_setColor(activeText, sfRed);
    sfVector2f position; position.x = 5; position.y = 5;
    sfText_setPosition(activeText, position);
    sfText_setFont(activeText, map->m_Fonts->m_Fonts[0]);
    sfText_setColor(activeText, sfRed);

    bbWidget* activeSpell;
    bbPool_Lookup(&activeSpell,
                  map->m_Widgets->m_Pool,
                  map->misc.m_ActiveSpell_deprecated);

    sfText_setString(activeText, activeSpell->m_String);

    bbPrintf("map = %d\n", g_Game->m_CurrentMap);
    while (1){

        if(!paused) bbWidgetTimer_update(g_Game->m_Maps[g_Game->m_CurrentMap]->m_WidgetTimer,
                                         g_Game->m_Maps[g_Game->m_CurrentMap]->misc.m_MapTime);
        EventDispatch(g_Game->m_CurrentMap);
        sfRenderWindow_clear(g_Game->m_Window, sfBlue);
        if(!paused) descending_searchVisible(NULL, Layout, bbWidget_onUpdate, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Pool);

        descending_searchVisible(NULL, Layout, bbWidget_draw, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Pool);


        cursorPosI = sfMouse_getPosition(g_Game->m_Window);
        cursorPosF.x = cursorPosI.x;
        cursorPosF.y = cursorPosI.y;
        sfSprite_setPosition(cursor, cursorPosF);
        sfRenderWindow_drawSprite(g_Game->m_Window, cursor, NULL);

        bbPool_Lookup(&activeSpell,
                      map->m_Widgets->m_Pool,
                      map->misc.m_ActiveSpell_deprecated);
        sfText_setString(activeText, activeSpell->m_String);
        sfRenderWindow_drawText(g_Game->m_Window, activeText, NULL);

        sfRenderWindow_display(g_Game->m_Window);

        if(!paused) g_Game->m_Maps[g_Game->m_CurrentMap]->misc.m_MapTime += 1;
    }

}
