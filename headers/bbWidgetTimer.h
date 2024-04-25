/** Used for example, to notify a widget of when it's cooldown ends.
 * If a spell widget is on a cooldown, and the user clicks to activate the spell,
 * the spell will be activated as soon as the cooldown ends
 * Each bbWidgetTimerNode belongs to one widget,
 * Keeping track of what node is deleted by who will be interesting
 */
#ifndef BBWIDGETTIMER_H
#define BBWIDGETTIMER_H

#include "headers/bbIntTypes.h"
#include "headers/bbDeque.h"


///bbWidgetTimer is a wrapper for bbPriorityQueue
typedef bbPriorityQueue bbWidgetTimer;

typedef struct{
    bbPool_data p_Node;
    I32 i_widget;
    I32 f_message;
} bbWidgetTimerNode;


///create a new timer
//I32 bbPriorityQueue_new(void** RBR, I32 map, I32 SizeOf, I32 level1, I32 Level2);
I32 bbWidgetTimer_new (void** RBR, I32 map); //SIZEOF = sizeof(bbWidgetTimerNode)

///create a new message
//I32 bbPQNode_new(void** RBR, bbPriorityQueue* Queue, I32 address);
I32 bbWidgetTimerNode_new(void** RBR, bbWidgetTimer* Timer);
///add message to queue
//bbPQNode_insertAfter(bbPriorityQueue* Queue, bbPQNode* node);
I32 bbWidgetTimer_add(bbWidgetTimer* Timer, bbWidgetTimerNode* node);
///remove message from queue
//I32 bbPQNode_remove(bbPriorityQueue* Queue, I32 address);
I32 bbWidgetTimer_remove(bbWidgetTimer* Timer, I32 address);

///delete message
//I32 bbPQNode_delete(bbPriorityQueue* Queue, I32 address);
I32 bbWidgetTimer_delete(bbWidgetTimer* Timer, I32 address);

I32 bbWidgetTimer_update(bbWidgetTimer* Timer, I32 time);


/* bbQueueFunction_timer(void* time_ptr, void* node)
 * is the basis for a function that calls bbWidget.v_onTimer
 */







#endif // BBWIDGETTIMER_H