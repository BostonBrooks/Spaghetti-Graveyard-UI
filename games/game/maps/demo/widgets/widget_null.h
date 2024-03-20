/**
 * @file
 * @brief The functions in this folder define the behavior of an object with class bbWidget and type NULL
 */
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"

///	Spawn a null widget on selected map at coordinates mc
int32_t bbWidget_NULL_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI screen_coords, int32_t parent){}

/// Update widget
int32_t bbWidget_NULL_update(bbWidget* widget){}

/// Send a command to the widget / update widget, etc
int32_t bbWidget_NULL_onCommand(bbWidget* widget, int32_t command, void* data){}

/// Delete widget
int32_t bbWidget_NULL_delete(bbWidget* widget){}

/// Draw widget to screen
int32_t bbWidget_NULL_draw(bbWidget* widget){}