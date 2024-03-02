/**
 * @file
 * @brief bbWidget includes things like menus and buttons.
 * Each widget owns a list of subwidgets and widgets are arranged in a hierarchy
 * bbWidgets is a container for all widgets corresponding to a given map
 * Spell slots are classified as widgets and they can either be clicked or have their code entered.
*/

#ifndef BBWIDGETS_H
#define BBWIDGETS_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbGeometry.h"
#include "headers/bbPool.h"
#include "headers/bbDictionary.h"


///include files containing widget functions, later these will be stored in a Dynamic Linked Library
#include "maps/demo/widgets/Widget_NULL.h"

/** bbWidget includes things like menus, buttons and spells */
typedef struct { //bbWidget

	bbPool_data p_Pool;

/** @name Graphics Stuff
 * Stuff for drawing widgets to the screen
 **/
///@{ */

	bool m_Visible;
	bool m_SubwidgetsVisible;
	bbScreenCoordsI m_ScreenCoords;

	char* m_Text;
	char* m_SpriteLabel;  /// Look up sprite label in dictionary to draw to screen.
///@}

/** @name Interactive Stuff
 * Stuff for interacting with the game. Integers refer to a location in a vtable.
**/
///@{ */
	char* m_Code; /// Enter this code to activate spell without clicking on it
	int32_t m_OnCommand;
	int32_t m_OnUpdate;
	int32_t m_OnDraw;
	int32_t m_OnDelete;
	int32_t m_OnMouse;


///@}

/** @name Hierarchy Stuff
 * Stuff for storing widgets in a hierarchy
**/
///@{ */
    int32_t m_ParentWidget;
	int32_t m_SubwidgetHead;
	int32_t m_SubwidgetTail;
	int32_t m_WidgetNext;
	int32_t m_WidgetPrevious;

///@}
} bbWidget;


/// bbWidgets is a container for objects of type bbWisget
typedef struct { //bbWidgets

	bbPool* m_Pool;
	bbDictionary* m_Codes;
	int32_t m_NumWidgets;

	int32_t *(*m_Constructor)(int32_t map, bbScreenCoordsI SC, int32_t parent);
	int32_t *(*m_Command)(int32_t map, int32_t self, int32_t command, void* data);
	int32_t *(*m_OnUpdate)(int32_t map, int32_t self);
	int32_t *(*m_OnDraw)(int32_t map, int32_t self);
	int32_t *(*m_OnDelete)(int32_t map, int32_t self);
	int32_t *(*m_OnMouse)(int32_t map, int32_t self /* mouse data */);



} bbWidgets;

/// Locate existing widget
bbWidget* bbWidget_Locate(int32_t map, int32_t self);

/// Load virtual functions into vtable
int32_t bbWidget_PopulateVTables(/* data? */);
/// Look up function in vtable then execute
int32_t bbWidget_New (int32_t map, bbScreenCoordsI SC, int32_t parent, int32_t type);
int32_t bbWidget_OnCommand(int32_t map, int32_t self, int32_t command, void* data);
int32_t bbWidget_OnUpdate(int32_t map, int32_t self);
int32_t bbWidget_OnDraw(int32_t map, int32_t self);
int32_t bbWidget_OnDelete(int32_t map, int32_t self);
int32_t bbWidget_OnMouse(int32_t map, int32_t self /* mouse data */);

#endif //BBWIDGETS_H