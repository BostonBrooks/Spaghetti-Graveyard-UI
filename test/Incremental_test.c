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

bbGame* g_Game;



int main (void) {

// ---------- Launch Game ---------- //
    int flag;
    flag = bbGame_new(&g_Game, GAME_PATH);

    g_Game->m_CurrentMap = 0;

    sfRenderWindow_setFramerateLimit(g_Game->m_Window, 60);
    //bbVerbose("(Empty) game object created\n");
    sfVector2i screenPosition;
    screenPosition.x = 0;
    screenPosition.y = -25;
    sfRenderWindow_setPosition(g_Game->m_Window, screenPosition);

    char mapPath[512];

    sprintf(mapPath, "%s/maps/%s", GAME_PATH, &g_Game->m_MapNames[g_Game->m_CurrentMap]);


    flag = bbMap_new(&g_Game->m_Maps[g_Game->m_CurrentMap], mapPath);

    bbMap *testmap = g_Game->m_Maps[g_Game->m_CurrentMap];


// ---------- Textures ---------- //

    flag = bbTextures_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures,
                          mapPath, g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Textures);

    sfTexture *texture;
    bbTextures_lookup(&texture, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures, "PINE_TREE");
    bbAssert(texture != NULL, "bad texture\n");

    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);
    sfRenderWindow_display(g_Game->m_Window);

// ---------- Sprites  ---------- //
    flag = bbSprites_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites,
                         g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures,
                         mapPath,
                         &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);


    sprite = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites->m_Sprites[44];

    sfVector2f position;
    position.x = 400;
    position.y = 320;

    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);
    sfRenderWindow_display(g_Game->m_Window);

// ---------- Animations  ---------- //

    flag = bbAnimations_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Animations,
                            g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites,
                            mapPath,
                            g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Animations);

    bbMap *map = g_Game->m_Maps[g_Game->m_CurrentMap];
    bbAnimations *anims = map->m_Animations;
    bbAssert(anims != NULL, "bad bbAnimations*\n");
    bbAnimation *anim = anims->m_Animations[8];
    int32_t spriteInt = anim->i_Sprites[0];

    sprite = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites->m_Sprites[spriteInt];

    position.x = 600;
    position.y = 320;

    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);
    sfRenderWindow_display(g_Game->m_Window);
// ---------- Fonts  ---------- //

    bbFonts_new(&map->m_Fonts, NULL, 1);

// ---------- Widgets  ---------- //

    bbWidgets_new(g_Game->m_CurrentMap);
    bbWidgetFunctions_new(g_Game->m_CurrentMap);

    bbWidgetFunctions_populate(g_Game->m_CurrentMap);
    // ---------- deprecated widget stuff ---------- //
    /*
      bbScreenCoordsI SCZero;
      SCZero.x = 0;
      SCZero.y = 0;
      bbWidgetFunctions* functions = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Functions;
      bbWidget* widget;
      int32_t type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "decal");
      bbWidget_new(&widget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, f_None, SCZero);

      bbWidget* fireworks;
      type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "fireworks");
      bbWidget_new(&fireworks, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self, SCZero);

      bbWidget* prompt;
      type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "prompt");
      bbDebug("prompt type = %d\n", type);
      bbWidget_new(&prompt, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self, SCZero);


      //bbDebug("in main: map = %d, ondraw = %d\n", widget->p_Node.p_Pool.Map, widget->m_OnDraw);

      g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Decal = widget;

      for (int32_t i = 0; i < 16; i++){
          bbWidget_draw(widget);
          sfRenderWindow_display(g_Game->m_Window);
          printf("==========================\n");
      }
  */

// ---------- bbTree inherits bbPool  ---------- //
/* Do not modify bbTree or bbPool
	bbNode* emptyNode = malloc(sizeof (bbNode));
	bbTestNode* testNode = malloc(sizeof(bbTestNode));

	uint64_t E  = emptyNode;
	uint64_t E0 = &emptyNode->p_Pool;
	uint64_t E1 = &emptyNode->p_Tree;
	uint64_t T  = testNode;
	uint64_t T0 = &testNode->p_Node.p_Pool;
	uint64_t T1 = &testNode->p_Node.p_Tree;

	testNode->string = "Hello Poppet";

	bbDebug("E = %" PRIu64", E0 = %" PRIu64", E1 = %" PRIu64"\n", E, E0, E1);
	bbDebug("T = %" PRIu64", T0 = %" PRIu64", T1 = %" PRIu64"\n", T, T0, T1);

	int64_t E0mE = E0-E;
	int64_t E1mE = E1-E;
	int64_t T0mT = T0-T;
	int64_t T1mT = T1-T;

	bbDebug("E0-E = %" PRIi64", E1-E = %" PRIi64"\n", E0mE, E1mE);
	bbDebug("T0-T = %" PRIi64", T1-T = %" PRIi64"\n", T0mT, T1mT);

	free (emptyNode);

	emptyNode = testNode;

	emptyNode->p_Tree.Parent = 193;

	bbDebug("testNode->p_Tree.Parent = %d\n", testNode->p_Node.p_Tree.Parent);

	testNode->p_Node.p_Tree.Parent = 31415926;

	bbDebug("emptyNode->Node.p_Tree.Parent = %d\n", emptyNode->p_Tree.Parent);

	bbDebug("%s\n", testNode->string);
*/
// ---------- New widget stuff  ---------- //
    /*{
        bbWidgetFunctions *functions = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Functions;
        int32_t type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "fireworks");
        bbWidget *FireWorks;

        bbWidget_new(&FireWorks, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, f_None, SCZero);


        for (int i = 0; i < 64; i++) {
            sfRenderWindow_clear(g_Game->m_Window, sfBlue);
            bbWidget_draw(NULL, FireWorks);
            sfRenderWindow_display(g_Game->m_Window);
        }
    }*/
    /*{
        map = g_Game->m_Maps[g_Game->m_CurrentMap];
        anims = map->m_Animations;
        bbAssert(anims != NULL, "bad bbAnimations*\n");
        anim = anims->m_Animations[24];

        for (int i = 0; i < 10; i++) { ;
            spriteInt = anim->i_Sprites[i];

            sprite = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites->m_Sprites[spriteInt];

            position.x = 80 * i;
            position.y = 0;

            sfSprite_setPosition(sprite, position);
            sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);
        }
    }*/

    bbWidgetFunctions* functions = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Functions;
    int32_t type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "decal");
    bbWidget* Decal;

    bbScreenCoordsI SC0; SC0.x = 0; SC0.y = 0;

    bbWidget_new(&Decal, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, f_None, SC0);

    //int32_t descending_search(void* reference, void* root, bbTreeFunction* myFunc, bbPool* pool);


    //Decal is the root widget. create new widgets an add to the tree

    type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "spellBar");
    bbWidget* menuButton;

    bbScreenCoordsF SCF; SCF.x = 20;

    SCF.y = 720 - 20 - 80 * g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.WidgetScale;
    bbScreenCoordsI SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);
    bbWidget_new(&menuButton, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, Decal->p_Node.p_Pool.Self, SCI);

    SCF.x = 30;
    SCF.y = 24;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);

    type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "prompt");


    flag = bbWidget_new(&menuButton, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, Decal->p_Node.p_Pool.Self, SCI);
    bbDebug("flag = %d\n", flag);

    descending_search(NULL, Decal, bbWidget_draw, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Pool);

    sfRenderWindow_display(g_Game->m_Window);

    g_Game->m_Maps[g_Game->m_CurrentMap]->misc.m_MapTime = 0;
    g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Decal = Decal;

    sfSprite* cursor = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites->m_Sprites[229];
    sfVector2i cursorPosI;
    sfVector2f cursorPosF;

    sfRenderWindow_setMouseCursorVisible(g_Game->m_Window, false);


    bbWidget* fireworks;
    SCF.x = 0;
    SCF.y = 0;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants);
    type = bbWidgetFunctions_getInt(functions, f_WidgetConstructor, "fireworks");

    bbWidget_new(&fireworks, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, Decal->p_Node.p_Pool.Self, SCI);
    bbHere();

    int32_t paused = 0;

    while (1){


        EventDispatch(g_Game->m_CurrentMap);
        sfRenderWindow_clear(g_Game->m_Window, sfBlue);
        if(!paused) descending_searchVisible(NULL, Decal, bbWidget_onUpdate, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Pool);

        descending_searchVisible(NULL, Decal, bbWidget_draw, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Pool);


        cursorPosI = sfMouse_getPosition(g_Game->m_Window);
        cursorPosF.x = cursorPosI.x;
        cursorPosF.y = cursorPosI.y;
        sfSprite_setPosition(cursor, cursorPosF);
        sfRenderWindow_drawSprite(g_Game->m_Window, cursor, NULL);


        sfRenderWindow_display(g_Game->m_Window);

        if(!paused) g_Game->m_Maps[g_Game->m_CurrentMap]->misc.m_MapTime += 1;
    }
}

