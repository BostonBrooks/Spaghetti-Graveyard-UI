/**
 * @brief Most or all objects will exist in some kind of pool
 * This particular implementation allows the pool to expand when needed,
 * to hold a very large number of objects, since it is not known how large
 * the pool will need to be at runtime.
 *
 * It might be useful to provide a data structure bbPool* pools[maps][types]
 * to aid in locating objects given an object handle?
*/

#include "engine/logic/bbIntTypes.h"
#include "engine/logic/bbTerminal.h"

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
#define f_PoolCollisionDetected        -11
///@}

#define bbHandle                       U64;

typedef struct {
    I32 address;
    I32 collision;
} bbHandle_unpacked;

/// any object in a pool must begin with bbPool_data
typedef struct {
    I32 Self;
    I32 Prev;
    I32 Next;
    I32 Collision;
    /// an object knows what pool it belongs to
    void* Pool;
    bool InUse;
} bbPool_data;

/// a bin is a linked list containing objects
typedef struct {
    I32 Head;
    I32 Tail;
} bbPool_bin;

typedef struct {
    /// what map does the pool belong to?
    U8 m_Map;
    /// what class of object is contained in the pool
    U8 m_Class;
    /// how big is the object stored in the pool?
    U16 m_SizeOf;
    /// list of available spaces for object
    bbPool_bin m_Available;
    /// list of in use objects
    bbPool_bin m_InUse;
    /// number of chunks
    I32 m_Level1;
    ///size of chunks
    I32 m_Level2;
    /// array of chunks
    void** m_Objects;
} bbPool;

///Create an new pool with object's size = Sizeof, type is like an enum
I32 bbPool_NewPool(bbPool** RBR, I32 map, I32 type, I32 SizeOf, I32 level1, I32
level2);

///Delete entire pool
I32 bbPool_DeletePool(bbPool* pool);

///Delete contents of pool, but keep empty pool
I32 bbPool_ClearPool(bbPool* pool);

///Create object in pool
I32 bbPool_New(void** RBR, bbPool* pool);

///Remove object from pool
I32 bbPool_Delete(bbPool* pool, bbHandle handle);

///Remove object from pool, given its memory address
I32 bbPool_DeleteAddress(bbPool_data* address);

///Lookup object at Address, error if m_Pool_InUse == f_PoolInUse
I32 bbPool_Lookup(void** RBR, bbPool* pool, bbHandle handle);