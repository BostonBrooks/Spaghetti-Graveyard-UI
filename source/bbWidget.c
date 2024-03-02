#include "headers/bbWidget.h"
#include "headers/bbMap.h"
#include "headers/bbGame.h"


bbWidget* bbWidget_Locate(int32_t map, int32_t self){
	bbMap* Map = g_Game->m_Maps[map];
	bbPool* pool = Map->m_widgets->m_Pool;
	bbWidget* widget = bbPool_Lookup(pool, self);
	//TODO assert widget is good?
	return widget;
}


int32_t bbWidget_OnDraw(int32_t map, int32_t self){
}