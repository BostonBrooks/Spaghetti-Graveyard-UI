/**
 * @brief Pools pre-allocate space for objects in the game to quickly allocate and de-allocate individual objects
*/

///Write a macro that, for a given class of objects, declares a new class CLASS##_Pool
///Write a macro that, for a given class of objects, defines a new class CLASS##_Pool

/** @name Pool Error Codes
 * Stuff for passing flags around when using pools
 **/
///@{
#define SUCCESS                           0
#define OBJECT_IN_USE                    -1
#define OBJECT_NOT_IN_USE                -2
#define LEVEL_1_POOL_NOT_INITIALISED     -3
#define LEVEL_1_POOL_ALREADY_INITIALISED -4
#define LEVEL_1_POOL_OUT_OF_BOUNDS       -5
#define MALLOC_FAILED                    -6
#define POOL_FULL                        -7
#define LEVEL_1_POOL_FULL                -8
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