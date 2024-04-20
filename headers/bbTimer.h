#include "headers/bbPool.h"
#include "headers/bbIntTypes.h"


typedef struct {
    bbPool_data p_Pool;
    I32 p_prev;
    I32 p_next;
    I32 p_time;

    I32 m_type;      //Widget, actor, drawable?
    I32 i_owner;   //location of object in pool
    I32 m_message;
} bbTimerNode;


typedef struct {

    bbPool* p_Pool;

    I32 p_head;
    I32 p_tail;


} bbTimer;



I32 bbTimer_newTimer (bbTimer** timer,  I32 map, I32 Level1, I32 Level2){
    bbTimer* newTimer = calloc(1, sizeof (bbTimer));
    bbPool_NewPool(&newTimer->p_Pool, map, sizeof(bbTimerNode), Level1, Level2);

    newTimer->p_head = -1;
    newTimer->p_tail = -1;
}

I32