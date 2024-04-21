#include "headers/bbPool.h"
#include "headers/bbIntTypes.h"
#include "headers/bbPriorityQueue.h"
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

I32 bbPriorityQueue_existingPool(bbPool* pool){
    bbPriorityQueue* queue = malloc(sizeof(bbPriorityQueue));
    queue->m_Highest = f_None;
    queue->m_Lowest = f_None;
    queue->p_Pool = pool;
    return f_Success;
}

I32 bbPQNode_new(void** RBR, bbPriorityQueue* Queue, I32 address){
    bbPool* pool = Queue->p_Pool;
    bbPQNode* node;
    I32 flag = bbPool_New(&node, pool, address);
    node->p_Queue.Higher = -1;
    node->p_Queue.Lower = -1;
    *RBR = node;
    return flag;
}


I32 bbPQNode_delete(bbPriorityQueue* Queue, I32 address){
    bbPool* pool = Queue->p_Pool;
    bbPQNode* node;
    bbPool_Lookup(&node, pool, address);

    I32 i_Higher = node->p_Queue.Higher;
    I32 i_Lower = node->p_Queue.Lower;

    bbPQNode* Higher;
    bbPQNode* Lower;

    if (i_Higher != f_None && i_Lower != f_None){

        bbPool_Lookup(&Higher, pool, i_Higher);
        bbPool_Lookup(&Lower, pool, i_Lower);

        Lower->p_Queue.Higher = i_Higher;
        Higher->p_Queue.Lower = i_Lower;

        //its nice to clean these up as they are returned to the pool
        node->p_Queue.Lower = f_None;
        node->p_Queue.Higher = f_None;
        //bbPool_Delete(pool, address); TODO implement this function
        return f_Success;
    }

    if(i_Lower != f_None){ //i_Higher == f_None

        bbPool_Lookup(&Lower, pool, i_Lower);
        Lower->p_Queue.Higher = f_None;
        Queue->m_Highest = i_Lower;

        //its nice to clean these up as they are returned to the pool
        node->p_Queue.Higher = f_None;
        node->p_Queue.Lower = f_None;
        //bbPool_Delete(pool, address);TODO implement this function

        return f_Success;
    }
    if(i_Higher != f_None){ //i_lower == f_None

        bbPool_Lookup(&Higher, pool, i_Higher);
        Higher->p_Queue.Lower = f_None;
        Queue->m_Lowest = i_Higher;

        //its nice to clean these up as they are returned to the pool
        node->p_Queue.Higher = f_None;
        node->p_Queue.Lower = f_None;
        //bbPool_Delete(pool, address);TODO implement this function

        return f_Success;
    }
    //(i_Higher == f_None && i_Lower == f_None)

    Queue->m_Lowest = f_None;
    Queue->m_Highest = f_None;

    node->p_Queue.Lower = f_None;
    node->p_Queue.Higher = f_None;

    //bbPool_Delete(pool, address); TODO implement this function

    return f_Success;
}
I32 bbPQNode_insertAfter(bbPriorityQueue* Queue, bbPQNode* node) {

    bbPool *pool = Queue->p_Pool;
    bbPQNode *newNode = node;
    //I32 flag = bbPool_Lookup(&newNode, pool, Node);




    if (Queue->m_Highest == f_None) {

        bbAssert(Queue->m_Lowest == f_None, "head/tail mismatch");
        Queue->m_Highest = newNode->p_Pool.Self;
        Queue->m_Lowest = newNode->p_Pool.Self;
        newNode->p_Queue.Higher = -1;
        newNode->p_Queue.Lower = -1;

        return f_Success;
    }

    bbPQNode *Highest;
    bbPool_Lookup(&Highest, pool, Queue->m_Highest);

    if (Highest->p_Queue.Priority <= newNode->p_Queue.Priority){
        //insert newNode as next highest;
        newNode->p_Queue.Higher = -1;
        newNode->p_Queue.Lower = Highest->p_Pool.Self;
        Highest->p_Queue.Higher = newNode->p_Pool.Self;
        Queue->m_Highest = newNode->p_Pool.Self;

        return f_Success;
    }


    bbPool_Lookup(&node, pool, Highest->p_Queue.Lower);

    while(1) {
        if (node->p_Queue.Priority <= newNode->p_Queue.Priority) {

            //insert newNode after Next
            bbPQNode* node2;
            bbPool_Lookup(&node2, pool, node->p_Queue.Higher);

            //node < newNode < node2

            node->p_Queue.Higher = newNode->p_Pool.Self;
            newNode->p_Queue.Lower = node->p_Pool.Self;
            newNode->p_Queue.Higher = node2->p_Pool.Self;
            node2->p_Queue.Lower = newNode->p_Pool.Self;



            return f_Success;
        }
        if (node->p_Queue.Lower == f_None) {
            node->p_Queue.Lower = newNode->p_Pool.Self;
            newNode->p_Queue.Higher = node->p_Pool.Self;
            newNode->p_Queue.Lower = f_None;
            Queue->m_Lowest = newNode->p_Pool.Self;
            return f_Success;
        }
        bbPool_Lookup(&node, pool, node->p_Queue.Lower);
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
        nodeInt = node->p_PQNode.p_Queue.Higher;
        if (flag == f_Delete) bbPQNode_delete(queue, node->p_PQNode.p_Pool.Self);
        if (flag == f_Break) break;
    }
    return f_Success;
}


I32 bbQueueFunction_print(void* UNUSED, void* node){

    bbTestPQNode* testNode = node;
    printf("NODE: Self = %d, Priority = %d\n", testNode->p_PQNode.p_Pool.Self, testNode->p_PQNode.p_Queue.Priority);
    return f_Success;
}


I32 bbQueueFunction_timer(void* time_ptr, void* node){
    bbTestPQNode* testNode = node;
    timePtr* ptr = time_ptr;
    I32 time = ptr->time;
    if (testNode->p_PQNode.p_Queue.Priority <= time){
        printf("NODE: Self = %d, Time = %d\n", testNode->p_PQNode.p_Pool.Self, testNode->p_PQNode.p_Queue.Priority);
        return f_Delete;
    }
    return f_Break;
}
