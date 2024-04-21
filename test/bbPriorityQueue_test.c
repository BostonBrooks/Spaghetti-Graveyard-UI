#include "headers/bbPriorityQueue.h"
#include "headers/bbPrintf.h"

#include <stdio.h>
#include <stdlib.h>
int main(void){


    bbPriorityQueue* queue;
    I32 flag = bbPriorityQueue_new(&queue,0, sizeof(bbTestPQNode), 7, 11);

    bbTestPQNode* node;

    for(I32 i = 0; i<60; i++) {
        flag = bbPQNode_new(&node, queue, f_PoolNextAvailable);
        I32 rnd = rand();

        node->p_PQNode.p_Queue.Priority = rnd % 60;

        bbPQNode_insertAfter(queue, node->p_PQNode.p_Pool.Self);

    }

    timePtr time;


    for (I32 i = 0; i < 60; i++) {
        time.time = i;
        printf("TIME = %d\n", i);


        bbPriorityQueue_ascendingSearch(&time, queue, bbQueueFunction_timer);

    }
    exit(EXIT_SUCCESS);
}