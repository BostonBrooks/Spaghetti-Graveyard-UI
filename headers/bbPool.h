/**
 * @file
 * @brief Pools pre-allocate space for objects in the game to quickly allocate and de-allocate individual objects
 *
 * Objects in pool must contain members:<br>
 * int32_t p_Pool_Self;<br>
 * int32_t p_Pool_Prev;<br>
 * int32_t p_Pool_Next;<br>
 * int32_t p_Pool_InUse;<br>
 * int32_t p_Map;<br>
 * TODO Write a macro that, for a given class of objects, declares a new class CLASS##_Pool<br>
 * TODO Write a macro that, for a given class of objects, defines a new class CLASS##_Pool
 */



/** @name Pool Error Codes
 * Stuff for passing flags around when using pools
 **/
///@{
#define f_Pool_Success                    0
#define f_Pool_InUse                     -1
#define f_Pool_NotInUse                  -2
#define f_Pool_Lvl1NotInitialised        -3
#define f_Pool_Lvl1AlreadyInitialised    -4
#define f_Pool_Lvl1OutOfBounds           -5
#define f_Pool_MallocFailed              -6
#define f_Pool_Full                      -7
#define f_Pool_Lvl1Full                  -8
///@}

/* CLASS##_Pool will have the following data
 *
 * A list of lists of CLASS objects
 * int size of list
 * int size of list of lists
 * int available head
 * int available tail
 * int in use head
 * int in use tail
 */

/* CLASS##_Pool will have the following methods
 * new pool
 * delete pool
 * increase pool
 * new object
 * delete object
 * lookup object (returns pointer to existing object)
 * lookup object sudo (returns pointer to object that may not exist)
 */