#include "headers/bbList.h"
#include "headers/bbPrintf.h"

#include <stdio.h>
#include <stdlib.h>
int main(void){


    bbList* queue;
    I32 flag = bbList_new(&queue, 0, sizeof(bbTestDQNode), 7, 11);

    bbTestDQNode* node;

    for(I32 i = 0; i<60; i++) {
        flag = bbListNode_new(&node, queue, f_PoolNextAvailable);
        I32 rnd = rand();

        node->p_PQNode.p_Queue.Priority = rnd % 60;

		bbListNode_insertAfter(queue, node->p_PQNode.p_Pool.Self);

    }

    timePtr time;


    for (I32 i = 0; i < 60; i++) {
        time.time = i;
        printf("TIME = %d\n", i);


		bbList_ascendingSearch(&time, queue, bbListFunction_timer);

    }
    exit(EXIT_SUCCESS);
}