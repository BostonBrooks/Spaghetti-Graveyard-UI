/**
 * @file bbMouse
 * This file passes mouse state on to widgets
 * Another file will later handle key events
 * Both of these are of type sfEvent
*/

#ifndef BBMOUSE
#define BBMOUSE

#include <stdbool.h>
#include "headers/bbSystemIncludes.h"
#include "headers/bbGeometry.h"

#define f_MouseMove 0
#define f_MouseLeft 1
#define f_MouseRight 2


typedef struct {
    bbScreenCoordsI m_ScreenCoords;
    int32_t m_type;
} bbMouseEvent;






/// If the event is a mouse click
int32_t EventMouse(bbMouseEvent* mouse, int map);

#endif //BBMOUSE
