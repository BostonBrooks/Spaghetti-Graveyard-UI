/**
 * @file
 * @brief Pools pre-allocate space for objects in the game to quickly allocate and de-allocate individual objects
 *
 * The first element of an object in a pool must be "bbPool_data p_PoolData;"
 */

#ifndef BBPOOL_H
#define BBPOOL_H

#include <inttypes.h>
#include <stdlib.h>
#include "headers/bbPrintf.h"


/** @name Pool Error Codes
 * Stuff for passing flags around when using pools
 **/
///@{
#define f_PoolSuccess                    0
#define f_PoolNone                      -1
#define f_PoolInUse                     -2
#define f_PoolNotInUse                  -3
#define f_PoolLvl1NotInitialised        -4
#define f_PoolLvl1AlreadyInitialised    -5
#define f_PoolLvl1OutOfBounds           -6
#define f_PoolMallocFailed              -7
#define f_PoolFull                      -8
#define f_PoolLvl1Full                  -9
#define f_PoolNextAvailable            -10
///@}


typedef struct {
	int32_t Self;
	int32_t Prev;
	int32_t Next;
	int32_t InUse;
	int32_t Map;
} bbPool_data;

typedef struct {
	int32_t Head;
	int32_t Tail;
} bbPool_bin;

typedef struct {
	int32_t m_Map;
	int32_t m_SizeOf;
	bbPool_bin m_Available;
	bbPool_bin m_InUse;
	int32_t m_Level1;
	int32_t m_Level2;
	void** m_Objects;
} bbPool;


///Look up object at location Pool[lvl1][lvl2];
int32_t bbPool_Lookup2(void** return_by_reference, bbPool* Pool, int32_t lvl1, int32_t lvl2);


///Lookup object at address, ignoring m_Pool_InUse;
int32_t bbPool_Lookup_sudo(void** return_by_reference, bbPool* Pool, int32_t Address);


///Lookup object at Address, error if m_Pool_InUse == f_PoolInUse
int32_t bbPool_Lookup(void** return_by_reference, bbPool* Pool, int32_t Address);

///Create an new pool with object's size = Sizeof
int32_t bbPool_NewPool(bbPool** return_by_reference, int32_t SizeOf, int32_t Level1, int32_t Level2);

///Delete entire pool
int32_t bbPool_DeletePool(bbPool* Pool);

///Delete contents of pool, but keep empty pool
int32_t bbPool_ClearPool(bbPool* Pool);

/// Allocate data in pool
int32_t bbPool_IncreasePool(bbPool* Pool, int32_t Level1_Address);

///Create object in pool
int32_t bbPool_New(bbPool* Pool, int32_t address);

///Remove object from pool
int32_t bbPool_Delete(bbPool* Pool, int32_t address);

#endif //BBPOOL_H
