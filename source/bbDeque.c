#include "headers/bbPool.h"
#include "headers/bbIntTypes.h"
#include "headers/bbDeque.h"
#include "headers/bbFlags.h"
#include "headers/bbPrintf.h"




///wrapper to bbPool_NewPool
I32 bbPriorityQueue_new(void** RBR, I32 map, I32 SizeOf, I32 Level1, I32 Level2){
    bbPriorityQueue* queue = malloc(sizeof(bbPriorityQueue));
    queue->m_Highest = f_None;
    queue->m_Lowest = f_None;
    bbPool_NewPool(&queue->p_Pool, map, SizeOf, Level1, Level2);
    *RBR = queue;
    return f_Success;
}

I32 bbPriorityQueue_existingPool(void** RBR, bbPool* pool){
    bbPriorityQueue* queue = malloc(sizeof(bbPriorityQueue));
    queue->m_Highest = f_None;
    queue->m_Lowest = f_None;
    queue->p_Pool = pool;
	*RBR = queue;
    return f_Success;
}

I32 bbPQNode_new(void** RBR, bbPriorityQueue* Queue, I32 address){
    bbPool* pool = Queue->p_Pool;
    bbPool_data* node;
    I32 flag = bbPool_New(&node, pool, address);
    node->Next = -1;
    node->Prev = -1;
    *RBR = node;
    return flag;
}


I32 bbPQNode_delete(bbPriorityQueue* Queue, I32 address){
    bbPool* pool = Queue->p_Pool;
    bbPool_data* node;
    bbPool_Lookup(&node, pool, address);

    I32 i_Higher = node->Next;
    I32 i_Lower = node->Prev;

    bbPool_data* Higher;
    bbPool_data* Lower;

    if (i_Higher != f_None && i_Lower != f_None){

        bbPool_Lookup(&Higher, pool, i_Higher);
        bbPool_Lookup(&Lower, pool, i_Lower);

        Lower->Next = i_Higher;
        Higher->Prev = i_Lower;

        //its nice to clean these up as they are returned to the pool
        node->Prev = f_None;
        node->Next = f_None;
        bbPool_Delete(pool, address);
        return f_Success;
    }

    if(i_Lower != f_None){ //i_Higher == f_None

        bbPool_Lookup(&Lower, pool, i_Lower);
        Lower->Next = f_None;
        Queue->m_Highest = i_Lower;

        //its nice to clean these up as they are returned to the pool
        node->Next = f_None;
        node->Prev = f_None;
        bbPool_Delete(pool, address);

        return f_Success;
    }
    if(i_Higher != f_None){ //i_lower == f_None

        bbPool_Lookup(&Higher, pool, i_Higher);
        Higher->Prev = f_None;
        Queue->m_Lowest = i_Higher;

        //its nice to clean these up as they are returned to the pool
        node->Next = f_None;
        node->Prev = f_None;
        bbPool_Delete(pool, address);

        return f_Success;
    }
    //(i_Higher == f_None && i_Lower == f_None)

    Queue->m_Lowest = f_None;
    Queue->m_Highest = f_None;

    node->Prev = f_None;
    node->Next = f_None;

    bbPool_Delete(pool, address);

    return f_Success;
}
I32 bbPQNode_insertAfter(bbPriorityQueue* Queue, I32 i_node) {

    bbPool* pool = Queue->p_Pool;
    bbPool_data* newNode;
    I32 flag = bbPool_Lookup(&newNode, pool, i_node);




    if (Queue->m_Highest == f_None) {

        bbAssert(Queue->m_Lowest == f_None, "head/tail mismatch");
        Queue->m_Highest = newNode->Self;
        Queue->m_Lowest = newNode->Self;
        newNode->Next = -1;
        newNode->Prev = -1;

        return f_Success;
    }

    bbPool_data* Highest;
    bbPool_Lookup(&Highest, pool, Queue->m_Highest);

    if (Highest->Priority <= newNode->Priority){
        //insert newNode as next highest;
        newNode->Next = -1;
        newNode->Prev = Highest->Self;
        Highest->Next = newNode->Self;
        Queue->m_Highest = newNode->Self;

        return f_Success;
    }
    bbPool_data* node;

    bbPool_Lookup(&node, pool, Highest->Prev);

    while(1) {
        if (node->Priority <= newNode->Priority) {

            //insert newNode after Next
            bbPool_data* node2;
            bbPool_Lookup(&node2, pool, node->Next);

            //node < newNode < node2

            node->Next = newNode->Self;
            newNode->Prev = node->Self;
            newNode->Next = node2->Self;
            node2->Prev = newNode->Self;



            return f_Success;
        }
        if (node->Prev == f_None) {
            node->Prev = newNode->Self;
            newNode->Next = node->Self;
            newNode->Prev = f_None;
            Queue->m_Lowest = newNode->Self;
            return f_Success;
        }
        bbPool_Lookup(&node, pool, node->Prev);
    }

}

I32 bbPriorityQueue_ascendingSearch(void* RBR, bbPriorityQueue* queue, bbQueueFunction* myFunc){
    bbPool* pool = queue->p_Pool;
    I32 nodeInt = queue->m_Lowest;
    bbTestPQNode* node;
    I32 flag;
    while(nodeInt >= 0){

        flag = bbPool_Lookup(&node, pool, nodeInt);
        flag = myFunc(RBR, node);
        nodeInt = node->p_Node.Next;
        if (flag == f_Delete) bbPQNode_delete(queue, node->p_Node.Self);
        if (flag == f_Break) break;
    }
    return f_Success;
}


I32 bbQueueFunction_print(void* UNUSED, void* node){

    bbTestPQNode* testNode = node;
    printf("NODE: Self = %d, Priority = %d\n", testNode->p_Node.Self, testNode->p_Node.Priority);
    return f_Success;
}


I32 bbQueueFunction_timer(void* time_ptr, void* node){
    bbTestPQNode* testNode = node;
    timePtr* ptr = time_ptr;
    I32 time = ptr->time;
    if (testNode->p_Node.Priority <= time){
        printf("NODE: Self = %d, Time = %d\n", testNode->p_Node.Self, testNode->p_Node.Priority);
        return f_Delete;
    }
    return f_Break;
}
