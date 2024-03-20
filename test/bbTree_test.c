#include "headers/bbPool.h"
#include "headers/bbTree.h"
#include "headers/bbFlags.h"
#include <inttypes.h>
#include <stdio.h>

typedef struct {
    bbPool_data p_Pool;
    bbTree p_Tree;
    char intA;
    int32_t intB;
} bbTestNode;

int32_t bbTreeTestFunction (void* reference, void* node){

    bbTestNode* testNode = node;
    printf("%c = %d\n", testNode->intA, testNode->intB);
    return f_Continue;
}

int main(void){
    printf("in main()\n");
    bbPool* pool;
    int32_t flag = 1;
    flag = bbPool_NewPool(&pool, 0, sizeof(bbTestNode), 100, 100);
    bbAssert(flag >= 0, "bad flag");
    bbTestNode* root;
    flag = bbPool_New(&root, pool, f_PoolNextAvailable);
    bbDebug("p_Pool.Self = %d\n", root->p_Pool.Self);
    bbAssert(flag >= 0, "bad flag");
    bbTreeFunction* testfunc = bbTreeTestFunction;

    root->intA = 'r';
    root->intB = 0;

    testfunc(NULL, root);

    bbNode_setParent(&root, NULL, pool);


    for (int32_t i = 0; i < 3; i++){
        printf("i = %d\n", i);
        bbTestNode* nodeI;

        flag = bbPool_New(&nodeI, pool, f_PoolNextAvailable);
        bbAssert(flag >= 0, "bad flag\n");
        bbDebug("p_Pool.Self = %d\n", nodeI->p_Pool.Self);
        nodeI->intA = 'i';
        nodeI->intB = i;
        bbNode_setParent(&nodeI, &root, pool);


        /*for (int32_t j = 0; j<4; j++){
            printf(" j = %d\n", j);
            bbDebug("did we make it here?(0)\n");

            bbTestNode* nodeJ;
            flag = bbPool_New(&nodeJ, pool, f_PoolNextAvailable);

            bbDebug("did we make it here?(Y)\n");
            bbAssert(flag >= 0, "bad flag\n");
            bbDebug("p_Pool.Self = %d\n", nodeJ->p_Pool.Self);
            nodeJ->intA = 'j';
            nodeJ->intB = j;

            bbDebug("did we make it here?\n");
            bbNode_setParent(&nodeJ, &nodeI, pool);

            bbDebug("did we make it here?(2)\n");
            for (int32_t k = 0; k < 5; k++){
                printf("  k = %d\n", k);
                bbTestNode* nodeK;

                flag = bbPool_New(&nodeK, pool, f_PoolNextAvailable);
                bbAssert(flag >= 0, "bad flag\n");
                bbDebug("p_Pool.Self = %d\n", nodeK->p_Pool.Self);
                nodeK->intA = 'k';
                nodeK->intB = k;
                bbNode_setParent(&nodeK, &nodeJ, pool);

            }
        }*/
    }
    printf("did we get here???");
    descending_search(NULL, root, bbTreeTestFunction, pool);
    //ascending_search(NULL, root, bbTreeTestFunction, pool);
}