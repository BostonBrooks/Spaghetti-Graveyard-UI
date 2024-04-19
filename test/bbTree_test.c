#include "headers/bbPool.h"
#include "headers/bbTree.h"
#include "headers/bbFlags.h"
#include <inttypes.h>
#include <stdio.h>
#include "headers/bbIntTypes.h"

typedef struct {
    bbNode p_Node;
    char intA;
    I32 intB;
} bbTestNode2;

I32 bbTreeTestFunction (void* reference, void* node){

    bbTestNode2* testNode = node;
    printf("%c = %d\n", testNode->intA, testNode->intB);
    return f_Continue;
}

int main(void){
    printf("in main()\n");
    bbPool* pool;
    I32 flag = 1;
    flag = bbPool_NewPool(&pool, 0, sizeof(bbTestNode2), 100, 100);
    bbAssert(flag >= 0, "bad flag");
    bbTestNode2* root;
    flag = bbPool_New(&root, pool, f_PoolNextAvailable);
    bbAssert(flag >= 0, "bad flag");
    bbTreeFunction* testfunc = bbTreeTestFunction;

    root->intA = 'r';
    root->intB = 0;

    testfunc(NULL, root);
    bbNode_setParent(root, NULL, pool);

    for (I32 i = 0; i < 3; i++){
        printf("i = %d\n", i);
        bbTestNode2* nodeI;

        flag = bbPool_New(&nodeI, pool, f_PoolNextAvailable);
        bbAssert(flag >= 0, "bad flag\n");
        nodeI->intA = 'i';
        nodeI->intB = i;


        bbNode_setParent(nodeI, root, pool);


        for (I32 j = 0; j<4; j++){
            printf(" j = %d\n", j);

            bbTestNode2* nodeJ;
            flag = bbPool_New(&nodeJ, pool, f_PoolNextAvailable);

            bbAssert(flag >= 0, "bad flag\n");
            nodeJ->intA = 'j';
            nodeJ->intB = j;

            bbNode_setParent(nodeJ, nodeI, pool);

            for (I32 k = 0; k < 5; k++){
                printf("  k = %d\n", k);
                bbTestNode2* nodeK;

                flag = bbPool_New(&nodeK, pool, f_PoolNextAvailable);
                bbAssert(flag >= 0, "bad flag\n");
                nodeK->intA = 'k';
                nodeK->intB = k;
                bbNode_setParent(nodeK, nodeJ, pool);

            }
        }
    }
    descending_search(NULL, root, bbTreeTestFunction, pool);
    //ascending_search(NULL, root, bbTreeTestFunction, pool);
}