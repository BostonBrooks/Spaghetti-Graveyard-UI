///This file is a test to see how a class can implement both bbPool and bbTree

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/bbIntTypes.h"

typedef struct {
    I32 Self;
    I32 Prev;
    I32 Next;
    I32 InUse;
    I32 Map;
} bbPool_data;

typedef struct {
    // Integer address (location in pool) of parent node
    I32 Parent;
    // Start of list of daughter nodes
    I32 Head;
    // End of list of daughter nodes
    I32 Tail;
    // Previous in list of daughter nodes
    I32 Prev;
    // Next in list of daughter nodes
    I32 Next;

} bbTree;


typedef struct {
    bbPool_data p_Pool;
    bbTree p_Tree;
} bbEmptyNode;

typedef struct {
    bbPool_data p_Pool;
    bbTree p_Tree;
    char intA;
    I32 intB;
} bbTestNode;

int main (void){

    bbEmptyNode* emptyNode = malloc(sizeof (bbEmptyNode));
    bbTestNode* testNode = malloc(sizeof(bbTestNode));

    uint64_t E  = emptyNode;
    uint64_t E0 = &emptyNode->p_Pool;
    uint64_t E1 = &emptyNode->p_Tree;
    uint64_t T  = testNode;
    uint64_t T0 = &testNode->p_Pool;
    uint64_t T1 = &testNode->p_Tree;

    printf("E = %" PRIu64", E0 = %" PRIu64", E1 = %" PRIu64"\n", E, E0, E1);
    printf("T = %" PRIu64", T0 = %" PRIu64", T1 = %" PRIu64"\n", T, T0, T1);

    int64_t E0mE = E0-E;
    int64_t E1mE = E1-E;
    int64_t T0mT = T0-T;
    int64_t T1mT = T1-T;

    printf("E0-E = %" PRIi64", E1-E = %" PRIi64"\n", E0mE, E1mE);
    printf("T0-T = %" PRIi64", T1-T = %" PRIi64"\n", T0mT, T1mT);


    exit(0);
}

/* Output is:
 * E = 2740883079136, E0 = 2740883079136, E1 = 2740883079156
 * T = 2740883052048, T0 = 2740883052048, T1 = 2740883052068
 * E0-E = 0, E1-E = 20
 * T0-T = 0, T1-T = 20
 * I don't see any problem here
 */