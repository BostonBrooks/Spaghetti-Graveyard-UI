#include "headers/bbWidgetTimer.h"
#include "headers/bbGame.h"
#include "headers/bbWidget.h"

I32 bbWidgetTimer_new (void** RBR, I32 map){
    I32 flag;


    flag = bbPriorityQueue_new(RBR, map, sizeof(bbWidgetTimerNode), 100, 100);


}

//I32 bbPQNode_new(void** RBR, bbPriorityQueue* Queue, I32 address);
I32 bbWidgetTimerNode_new(void** RBR, bbWidgetTimer* Timer){
    I32 flag = bbPQNode_new(RBR, Timer, f_PoolNextAvailable);
    return flag;
}



I32 bbWidgetTimer_add(bbWidgetTimer* Timer, bbWidgetTimerNode* node){
    I32 flag = bbPQNode_insertAfter(Timer, node->p_PQNode.p_Pool.Self);
}

/* not yet implemented / could cause bugs
I32 bbWidgetTimer_remove(bbWidgetTimer* Timer, I32 address){
    I32 flag = bbPQNode_remove(Timer, address);
    return flag;
}
*/

//I32 ;
I32 bbWidgetTimer_delete(bbWidgetTimer* Timer, I32 address){
    I32 flag = bbPQNode_delete(Timer, address);
}

I32 WidgetTimerFunc(void* time_ptr, void* node){
    bbWidgetTimerNode* timerNode = node;
    bbWidget* widget;
    I32 i_widget;
    i_widget = timerNode->i_widget;
    I32 map = timerNode->p_PQNode.p_Pool.Map;
    bbPool* pool = g_Game->m_Maps[map]->m_Widgets->m_Pool;
    bbPool_Lookup(&widget, pool, i_widget);
    timePtr* ptr = time_ptr;
    I32 time = ptr->time;

    if (timerNode->p_PQNode.p_Queue.Priority <= time){
        bbWidget_onTimer(timerNode, widget);
        return f_Delete;
    }
    return f_Break;
}

I32 bbWidgetTimer_update(bbWidgetTimer* Timer, I32 time){

    timePtr timeptr;
    timeptr.time = time;

    bbPriorityQueue_ascendingSearch(&time, Timer, WidgetTimerFunc);

    return f_Success;
}