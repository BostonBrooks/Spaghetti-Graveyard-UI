#include "headers/bbPrintf.h"
#include "headers/bbWidget.h"
#include "headers/bbMap.h"
#include "headers/bbGame.h"


bbWidget* bbWidget_Locate(int32_t map, int32_t self){
	bbMap* Map = g_Game->m_Maps[map];
	bbPool* pool = Map->m_widgets->m_Pool;
	bbWidget* widget;
	int32_t flag = bbPool_Lookup(&widget, pool, self);
	bbAssert(flag >= 0, "");
	return widget;
}

int32_t bbWidget_OnCommand(int32_t map, int32_t self, int32_t command, void* data){
	bbWidget* widget = bbWidget_Locate(map, self);
	int cmdint = widget->m_OnCommand;

	//int32_t (*m_Command[N_WIDGET_TYPES])(int32_t map, int32_t self, int32_t command, void* data);
	int32_t (*fun_ptr)(int, int, int, void*);

	fun_ptr = g_Game->m_Maps[map]->m_widgets->m_OnCommand[cmdint];

	return fun_ptr(map, self, command, data);
}

int32_t bbWidget_OnUpdate(int32_t map, int32_t self){
	bbWidget* widget = bbWidget_Locate(map, self);
	int updateint = widget->m_OnUpdate;

	//int32_t (*m_OnUpdate[N_WIDGET_TYPES])(int32_t map, int32_t self);
	int32_t (*fun_ptr)(int, int);

	fun_ptr = g_Game->m_Maps[map]->m_widgets->m_OnDraw[updateint];

	return fun_ptr(map, self);
}

int32_t bbWidget_OnDraw(int32_t map, int32_t self){
	bbWidget* widget = bbWidget_Locate(map, self);
	int drawfnint = widget->m_OnDraw;

    //int32_t (*m_OnDraw[N_WIDGET_TYPES])(int32_t map, int32_t self);
	int32_t (*fun_ptr)(int, int);

	fun_ptr = g_Game->m_Maps[map]->m_widgets->m_OnDraw[drawfnint];

	return fun_ptr(map, self);
}

/// be careful of deleting an object while it is included in a list...
int32_t bbWidget_OnDelete(int32_t map, int32_t self){
	bbWidget* widget = bbWidget_Locate(map, self);
	int deleteint = widget->m_OnDelete;

	//int32_t (*m_OnDelete[N_WIDGET_TYPES])(int32_t map, int32_t self);
	int32_t (*fun_ptr)(int, int);

	fun_ptr = g_Game->m_Maps[map]->m_widgets->m_OnDelete[deleteint];

	return fun_ptr(map, self);
}


int32_t bbWidget_OnMouse(int32_t map, int32_t self, void* data){
	bbWidget* widget = bbWidget_Locate(map, self);
	int mouseint = widget->m_OnDelete;

	//int32_t (*m_OnMouse[N_WIDGET_TYPES])(int32_t map, int32_t self, void* data);
	int32_t (*fun_ptr)(int, int, void*);

	fun_ptr = g_Game->m_Maps[map]->m_widgets->m_OnMouse[mouseint];

	return fun_ptr(map, self, data);
}