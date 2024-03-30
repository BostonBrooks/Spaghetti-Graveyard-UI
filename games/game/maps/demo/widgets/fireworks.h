/**
 * @file
 * @brief The functions in this file define the behavior of an object with class bbWidget and type fireworks
 */


#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"

///	Spawn a null widget on selected map at coordinates mc
int32_t bbWidget_Fireworks_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

	bbPool* pool = widgets->m_Pool;
	bbDictionary* dict = widgets->m_AddressDict;

	bbWidget* widget;
	int32_t flag;

	flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


	bbScreenCoordsF SCF;
	bbScreenCoordsI SCI;

	SCF.x = 200;
	SCF.y = 420;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_ScreenCoords = SCI;

	SCF.x = 466;
	SCF.y = 262;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_Dimensions = SCI;

	widget->m_Visible = true;
	widget->m_SubwidgetsVisible = true;


	widget->m_SpriteInt = -1;

	bbWidgetFunctions* functions = widgets->m_Functions;

	widget->m_OnDraw = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "fireworks");
	widget->p_Node.p_Tree.Parent = parent;
	widget->p_Node.p_Tree.Head = f_None;
	widget->p_Node.p_Tree.Tail = f_None;
	widget->p_Node.p_Tree.Prev = f_None;
	widget->p_Node.p_Tree.Next = f_None;

	for(int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
		widget->m_AnimationInt[i] = f_None;
		widget->m_Angle[i] = 0;
		widget->m_Frame[i] = 0;
		widget->m_AnimationDraw[i] = f_None;
	}


	widget->m_AnimationInt[0] = 23;
	widget->m_AnimationDraw[0] = bbWidgetFunctions_getInt(functions, wf_AnimationDraw, "animation");


	printf("parent = %d\n", parent);
	bbWidget* parentWidget;
	flag = bbPool_Lookup(&parentWidget, pool, parent);

	//add widget to parentWidget's subwidgets

	if (parentWidget->p_Node.p_Tree.Head == f_None){
		bbAssert(parentWidget->p_Node.p_Tree.Tail == f_None, "head/tail mismatch");
		parentWidget->p_Node.p_Tree.Head = widget->p_Node.p_Pool.Self;
		parentWidget->p_Node.p_Tree.Tail = widget->p_Node.p_Pool.Self;

		widget->p_Node.p_Tree.Next = f_None;
		widget->p_Node.p_Tree.Prev = f_None;

	} else {
		bbWidget* prevWidget;
		printf("checking 2\n");
		bbPool_Lookup(&prevWidget, pool, parentWidget->p_Node.p_Tree.Tail);
		printf("checking 3\n");
		prevWidget->p_Node.p_Tree.Next = widget->p_Node.p_Pool.Self;
		widget->p_Node.p_Tree.Prev = prevWidget->p_Node.p_Pool.Self;
		widget->p_Node.p_Tree.Next = f_None;
		parentWidget->p_Node.p_Tree.Tail = widget->p_Node.p_Pool.Self;
	}

	*reference = widget;

	return f_Success;
}

/// Update widget
int32_t bbWidget_Fireworks_update(bbWidget* widget){}

/// Send a command to the widget / update widget, etc
int32_t bbWidget_Fireworks_onCommand(bbWidget* widget, int32_t command, void* data){}

/// Delete widget
int32_t bbWidget_Fireworks_delete(bbWidget* widget){}

/// Draw widget to screen
int32_t bbWidget_Fireworks_draw(bbWidget* widget){

	//draw self

	for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
		if (widget->m_AnimationDraw[i] < 0) continue;

		bbWidget_AnimationDraw* function = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_Functions->AnimationDraw[widget->m_AnimationDraw[i]];
		int32_t flag = function(widget, i);
	}


	//draw subwidgets
	int32_t subwidgetInt = widget->p_Node.p_Tree.Head;
	bbWidget* subwidget;
	int32_t flag;
	bbPool* pool = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_Pool;

	while (subwidgetInt >= 0){
		flag = bbPool_Lookup(&subwidget, pool, subwidgetInt);
		bbWidget_draw(subwidget);
		subwidgetInt = subwidget->p_Node.p_Tree.Next;
	}

	return f_Success;
}
