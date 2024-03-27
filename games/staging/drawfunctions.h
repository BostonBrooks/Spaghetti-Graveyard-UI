//We will no longer use bbWidget_DrawFunction** DrawFunctions

//instead use bbWidget_AnimationDraw** AnimationDraw

//will later rename this to  bbWidget_Draw** OnDraw

// int32_t bbWidget_draw (bbWidget* widget);
// will call bbWidget_DrawFunction** DrawFunctions

//int32_t bbWidget_draw (bbWidget* widget); will be an instance of
// typedef int32_t bbTreeFunction (void* reference, void* node);

#include <inttypes.h>
#include "headers/bbWidget.h"
#include "headers/bbGame.h"

//typedef int32_t bbTreeFunction (void* reference, void* node);
int32_t bbWidget_draw_new(void* void_unused, void* void_widget){
	bbWidget* widget = void_widget;

	int32_t map = widget->p_Node.p_Pool.Map;
	bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;
	bbWidget_AnimationDraw* drawFunctions = *functions->AnimationDraw;

	for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
		int drawfunction_int = widget->m_AnimationDraw[i];
		if (drawfunction_int >= 0) {

			//TODO skins, default drawfunction given by animation or skin
			functions->AnimationDraw[i](widget, i);

		}
	}
}

