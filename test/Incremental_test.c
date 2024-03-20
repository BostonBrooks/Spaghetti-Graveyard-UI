#include "headers/bbSystemIncludes.h"
#include "headers/bbEngineConstants.h"
#include "headers/bbGame.h"
#include "headers/bbPrintf.h"
#include "headers/bbMap.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"
#include "headers/bbAnimation.h"

bbGame* g_Game;

int main (void){
	int flag;
	flag = bbGame_new(&g_Game, GAME_PATH);

	g_Game->m_CurrentMap = 0;

	sfRenderWindow_setFramerateLimit(g_Game->m_Window, 60);
	//bbVerbose("(Empty) game object created\n");

	char mapPath[512];

	sprintf(mapPath, "%s/maps/%s", GAME_PATH, &g_Game->m_MapNames[g_Game->m_CurrentMap]);

	//bbDebug("mapPath is %s\n", mapPath);

	flag = bbMap_new(&g_Game->m_Maps[g_Game->m_CurrentMap], mapPath);

	bbMap* testmap = g_Game->m_Maps[g_Game->m_CurrentMap];

	//bbDebug("name of test map is %s\n", testmap->m_Name);

    flag = bbTextures_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures,
			mapPath, g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Textures);

	sfTexture* texture;
	bbTextures_lookup(&texture, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Textures, "PINE_TREE");
	bbAssert(texture != NULL, "bad texture\n");

	sfSprite* sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);

	sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);
	sfRenderWindow_display(g_Game->m_Window);


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


	//bbDebug("p_Constants.Animations = %d\n", g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Animations);

	flag = bbAnimations_new(&g_Game->m_Maps[g_Game->m_CurrentMap]->m_Animations,
							g_Game->m_Maps[g_Game->m_CurrentMap]->m_Sprites,
							mapPath,
							g_Game->m_Maps[g_Game->m_CurrentMap]->p_Constants.Animations);

	//bbDebug("bbAnimations_new flag = %d\n", flag);
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

    bbWidgets_new(g_Game->m_CurrentMap);
	bbWidgetFunctions_new(g_Game->m_CurrentMap);

	bbWidgetFunctions_populate(g_Game->m_CurrentMap);

	bbWidgetFunctions* functions = g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Functions;
	bbWidget* widget;
	int32_t type = bbWidgetFunctions_getInt(functions, wf_Constructor, "decal");
	bbWidget_new(&widget, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, f_None);

	bbWidget* fireworks;
	type = bbWidgetFunctions_getInt(functions, wf_Constructor, "fireworks");
	bbWidget_new(&fireworks, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Pool.Self);

	bbWidget* prompt;
	type = bbWidgetFunctions_getInt(functions, wf_Constructor, "prompt");
	bbDebug("prompt type = %d\n", type);
	bbWidget_new(&prompt, g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets, type, widget->p_Pool.Self);


	bbDebug("in main: map = %d, ondraw = %d\n", widget->p_Pool.Map, widget->m_OnDraw);

	g_Game->m_Maps[g_Game->m_CurrentMap]->m_Widgets->m_Decal = widget;

	for (int32_t i = 0; i < 100; i++){
		bbWidget_draw(widget);
		sfRenderWindow_display(g_Game->m_Window);
		printf("==========================\n");
	}

}
