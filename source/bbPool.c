/**
 * @file
 * @brief Pools pre-allocate space for objects in the game to quickly allocate and de-allocate individual objects
 *
 * Objects in pool must contain members:<br>
 * int32_t p_Pool_Self;<br>
 * int32_t p_Pool_Prev;<br>
 * int32_t p_Pool_Next;<br>
 * int32_t p_Pool_InUse;<br>
 * int32_t p_Pool_Allocated<br>
 * int32_t p_Map;<br>
 */



#include <inttypes.h>
#include <stdlib.h>
#include "headers/bbPrintf.h"
#include "headers/bbPool.h"



///This object contains all the data required to be placed in a pool, but no data of it's own
typedef struct {
	bbPool_data p_Pool;
} bbPool_null;



///Look up object at location Pool[lvl1][lvl2];
void* bbPool_Lookup2(bbPool* Pool, int32_t lvl1, int32_t lvl2){

	int8_t* array = Pool->m_Objects[lvl1];

	int32_t index = lvl2 * Pool->m_SizeOf;

	return &array[index];
}


///Lookup object at address, ignoring m_Pool_InUse;
void* bbPool_Lookup_sudo(bbPool* Pool, int32_t Address){
	// Address in lvl1 of Pool
	int lvl1_Address = Address / Pool->m_Level2;
	// Address in lvl2 of Pool
	int lvl2_Address = Address % Pool->m_Level2;

	return bbPool_Lookup2(Pool, lvl1_Address, lvl2_Address);
}


///Lookup object at Address, error if m_Pool_InUse == f_Pool_InUse
void* bbPool_Lookup(bbPool* Pool, int32_t Address){
	bbPool_null* Object = bbPool_Lookup_sudo(Pool, Address);
	bbAssert(Object->p_Pool.InUse == f_Pool_InUse,
			 "Trying to lookup non-existant member of pool\n");
	return Object;
}

bbPool* bbPool_NewPool(int32_t map, int32_t SizeOf, int32_t Level1, int32_t Level2){
	bbPool* Pool = malloc(sizeof(bbPool));
	bbAssert(Pool != NULL, "malloc returned null pointer?\n");
	Pool->m_Map = map;
	Pool->m_SizeOf = SizeOf;
	Pool->m_Level1 = Level1;
	Pool->m_Level2 = Level2;
	Pool->m_Available.Head = f_Pool_None;
	Pool->m_Available.Tail = f_Pool_None;
	Pool->m_InUse.Head = f_Pool_None;
	Pool->m_InUse.Tail = f_Pool_None;
	Pool->m_Objects = calloc(Level1, sizeof(void*));
	for (int i; i < Level1; i++){
		Pool->m_Objects[i] = NULL;
	}
	return Pool;
}

int32_t bbPool_DeletePool(bbPool* Pool){
	for (int i; i < Pool->m_Level1; i++){
		//It's ok to free a NULL pointer
		free(Pool->m_Objects[i]);
	}
	free(Pool);

}
int32_t bbPool_ClearPool(bbPool* Pool){

	for (int i; i < Pool->m_Level1; i++){
		//It's ok to free a NULL pointer
		free(Pool->m_Objects[i]);
		Pool->m_Objects[i] = NULL;
	}

	Pool->m_Available.Head = f_Pool_None;
	Pool->m_Available.Tail = f_Pool_None;
	Pool->m_InUse.Head = f_Pool_None;
	Pool->m_InUse.Tail = f_Pool_None;
}

int32_t bbPool_IncreasePool(bbPool* Pool, int32_t Level1_Address){


	bbAssert(Level1_Address == f_Pool_NextAvailable, "Feature not implemented\n");
	int32_t i = 0;
	//Find next available / NULL entry in level1 of the pool
	if(Level1_Address == f_Pool_NextAvailable){
		while (i < Pool->m_Level1 && Pool->m_Objects[i] != NULL){
			i++;
		}
		if(i == Pool->m_Level1){
			bbWarning(1==0, "level1 pool full\n");
			return f_Pool_Lvl1Full;
		}
	} else {
		i = Level1_Address;
		if (Pool->m_Objects[i] != NULL){
			bbWarning(1==0, "lvl 1 already initialised?\n");
			return f_Pool_Lvl1AlreadyInitialised;
		}
	}
	void* lvl2pool = calloc(Pool->m_Level2, Pool->m_SizeOf);
	bbWarning(lvl2pool != NULL, "calloc failed\n");
	if (lvl2pool == NULL) return f_Pool_MallocFailed;
	Pool->m_Objects[i] = lvl2pool;
	if (Pool->m_Available.Head == -1){
		bbAssert(Pool->m_Available.Tail == -1, "Head/Tail mismatch\n");


		for (int32_t j = 0; j < Pool->m_Level2; j++) {

			bbPool_null *Object = bbPool_Lookup2(Pool, i, j);

			Object->p_Pool.Self = i * Pool->m_Level2 + j;
			Object->p_Pool.Prev = i * Pool->m_Level2 + j - 1;
			Object->p_Pool.Next = i * Pool->m_Level2 + j + 1;
			Object->p_Pool.InUse = f_Pool_NotInUse;
			Object->p_Pool.Map = Pool->m_Map;
		}
		bbPool_null* Object = bbPool_Lookup2(Pool, i, 0);
		Object->p_Pool.Prev = f_Pool_None;
		Object = bbPool_Lookup2(Pool, i, Pool->m_Level2 -1);
		Object->p_Pool.Next = f_Pool_None;

		Pool->m_Available.Head = i * Pool->m_Level2;
		Pool->m_Available.Tail = (i+1) * Pool->m_Level2 - 1;

		//Level1_Address >= 0, try to initiate lvl2 pool at location Level1_Address >= 0
	} else {

	}
}

int32_t bbPool_New(bbPool* Pool, int32_t address){
	bbAssert(address == f_Pool_NextAvailable, "Feature not implemented\m");

	if(Pool->m_Available.Head == f_Pool_None){
		bbAssert(Pool->m_Available.Tail == f_Pool_None, "Head/Tail mismatch\n");
		bbPool_IncreasePool(Pool, f_Pool_NextAvailable);
	}

	address = Pool->m_Available.Head;

	bbPool_null* Object = bbPool_Lookup_sudo(Pool, address);
	Pool->m_Available.Head = Object->p_Pool.Next;
	if (Pool->m_Available.Head == f_Pool_None){
		Pool->m_Available.Tail = f_Pool_None;
	} else {
		//Should be able to remove sudo?
		bbPool_null* Head = bbPool_Lookup_sudo(Pool, Pool->m_InUse.Head);
		Head->p_Pool.Prev = f_Pool_None;
	}
	Object->p_Pool.InUse = f_Pool_InUse;

	if (Pool->m_InUse.Head == f_Pool_None){
		bbAssert(Pool->m_InUse.Head == f_Pool_None, "Head/Tail mismatch\n");
		Pool->m_InUse.Head = address;
		Pool->m_InUse.Tail = address;
		Object->p_Pool.Prev = f_Pool_None;
		Object->p_Pool.Next = f_Pool_None;
		return address;
	}

	bbPool_null* Tail = bbPool_Lookup(Pool, Pool->m_InUse.Tail);
	Tail->p_Pool.Next = address;
	Object->p_Pool.Prev = Pool->m_InUse.Tail;
	Object->p_Pool.Next = f_Pool_None;
	Pool->m_InUse.Tail = address;
	return address;

}