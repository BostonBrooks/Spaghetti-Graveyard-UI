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

bbGame* g_Game;



int main (void){

// ---------- Launch Game ---------- //
	int flag;
	flag = bbGame_new(&g_Game, GAME_PATH);

	g_Game->m_CurrentMap = 0;

	sfRenderWindow_setFramerateLimit(g_Game->m_Window, 60);
	//bbVerbose("(Empty) game object created\n");

	char mapPath[512];

	sprintf(mapPath, "%s/maps/%s", GAME_PATH, &g_Game->m_MapNames[g_Game->m_CurrentMap]);


	flag = bbMap_new(&g_Game->m_Maps[g_Game->m_CurrentMap], mapPath);

	bbMap* testmap = g_Game->m_Maps[g_Game->m_CurrentMap];


// ---------- Textures ---------- //

	flag = bbTextures_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures,
			mapPath, g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Textures);

	sfTexture* texture;
	bbTextures_lookup(&texture, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures, "PINE_TREE");
	bbAssert(texture != NULL, "bad texture\n");

	sfSprite* sprite = sfSprite_create();
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

	bbMap* map = g_Game->m_Maps[g_Game->m_CurrentMap];
	bbAnimations* anims = map->m_Animations;
	bbAssert(anims != NULL, "bad bbAnimations*\n");
	bbAnimation* anim = anims->m_Animations[8];
	int32_t spriteInt = anim->i_Sprites[0];

	sprite = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites->m_Sprites[spriteInt];

	position.x = 600;
	position.y = 320;

	sfSprite_setPosition(sprite, position);
	sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);
	sfRenderWindow_display(g_Game->m_Window);

// ---------- Widgets  ---------- //

	bbWidgets_new(g_Game->m_CurrentMap);
	bbWidgetFunctions_new(g_Game->m_CurrentMap);

	bbWidgetFunctions_populate(g_Game->m_CurrentMap);
  // ---------- deprecated widget stuff ---------- //
  /*
	bbWidgetFunctions* functions = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Functions;
	bbWidget* widget;
	int32_t type = bbWidgetFunctions_getInt(functions, wf_Constructor, "decal");
	bbWidget_new(&widget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, f_None);

	bbWidget* fireworks;
	type = bbWidgetFunctions_getInt(functions, wf_Constructor, "fireworks");
	bbWidget_new(&fireworks, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self);

	bbWidget* prompt;
	type = bbWidgetFunctions_getInt(functions, wf_Constructor, "prompt");
	bbDebug("prompt type = %d\n", type);
	bbWidget_new(&prompt, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Node.p_Pool.Self);


	//bbDebug("in main: map = %d, ondraw = %d\n", widget->p_Node.p_Pool.Map, widget->m_OnDraw);

	g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Decal = widget;

	for (int32_t i = 0; i < 16; i++){
		bbWidget_draw(widget);
		sfRenderWindow_display(g_Game->m_Window);
		printf("==========================\n");
	}
*/

// ---------- bbTree inherits bbPool  ---------- //
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

// ---------- New widget stuff  ---------- //

	bbWidgetFunctions* functions = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Functions;
	int32_t type = bbWidgetFunctions_getInt(functions, wf_Constructor, "2pt0");
	bbWidget* Widget2pt0;

	bbWidget_new(&Widget2pt0, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, f_None);


	for (int i = 0; i < 64; i++){
		bbWidget_draw_new(NULL, Widget2pt0);
		sfRenderWindow_display(g_Game->m_Window);
	}
	exit(0);
}
