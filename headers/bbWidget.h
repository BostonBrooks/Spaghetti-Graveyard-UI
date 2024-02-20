/**
 * @file
 * @brief bbWidget includes things like menus and buttons.
 * Each widget owns a list of subwidgets and widgets are arranged in a hierarchy
 * bbWidgets is a container for all widgets corresponding to a given map
 * Spell slots are classified as widgets and they can either be clicked or have their code entered.
*/

#ifndef BBWIDGETS_H
#define BBWIDGETS_H

#include "../headers/bbSystemIncludes.h"

/** bbWidget includes things like menus and buttons. */
typedef struct { //bbWidget


/** @name Pool Stuff
 * Stuff for including object in pool
 **/
///@{
	int32_t m_Pool_Self;
	int32_t m_Pool_Prev;
	int32_t m_Pool_Next;
	int32_t m_Pool_In_Use;
	int32_t m_Map;  ///What map was being loaded when this object was constructed?
///@}

/** @name Graphics Stuff
 * Stuff for drawing widgets to the screen
 **/
///@{ */

	bool m_Visible;
	bool m_SubwidgetsVisible;
	bbScreenCoords m_ScreenCoords;

	char* m_Text;
	char* m_SpriteLabel;  /// Look up sprite label in dictionary to draw to screen.
///@}

/** @name Interactive Stuff
 * Stuff for interacting with the game. Integers refer to a location in a vtable.
**/
///@{ */
	char* m_Code; /// Enter this code to activate spell without clicking on it
	int32_t m_OnCommand;
	int32_t m_OnDraw;
	int32_t m_OnDelete;
	int32_t m_OnClick;

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

	bbWidget_Pool* m_Pool;
} bbWidgets;

#endif //BBWIDGETS_H