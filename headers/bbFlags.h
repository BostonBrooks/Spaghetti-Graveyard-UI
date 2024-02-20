/**
 * @file
 * @brief This header file contains all of the flags passes by functions
 */

///The number of maps that can be loaded at one time.

#ifndef FLAGS_H
#define FLAGS_H

#define F_SUCCESS               0

///have reached the end of the list
#define F_NONE                 -1

#define F_CONTINUE             -2
#define F_REPEAT               -3
#define F_BREAK                -4

/// After iterating over object, remove object from any lists then delete object
#define F_DELETE               -5

/// Trying to create new object in a pool that's already full
#define F_FULL                 -6

#endif //FLAGS_H