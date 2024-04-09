/** Loop through event queue and dispatch to handlers
    This function is the only part of the code that handles sfEvent structures.
 */

#ifndef BBDISPATCH_H
#define BBDISPATCH_H

#include <inttypes.h>

int32_t EventDispatch(int32_t map);

#endif //BBDISPATCH_H