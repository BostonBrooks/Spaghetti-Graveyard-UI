/**
 * @file
 * @brief bbWidgets are things like menu buttons, text prompts, click to cast spells etc.
*/
#ifndef BBWIDGET_H
#define BBWIDGET_H

#include "headers/bbPool.h"
#include "headers/bbTree.h"
#include "headers/bbDictionary.h"
#include "headers/bbGeometry.h"


typedef struct{
	bbNode p_Node;

	bbScreenCoordsI m_ScreenCoords;
	bbScreenCoordsI m_Dimensions;
	bool m_Visible;
	bool m_SubwidgetsVisible;
	char* m_String;
	sfText* m_Text;
	sfFont* m_Font;
    char* m_Code;


	int32_t m_AnimationInt[ANIMATIONS_PER_WIDGET];
	int32_t m_Angle[ANIMATIONS_PER_WIDGET];
	int32_t m_Frame[ANIMATIONS_PER_WIDGET];
	int32_t m_AnimationDraw[ANIMATIONS_PER_WIDGET];

	int32_t m_OnCommand;
	int32_t m_OnUpdate;
	int32_t m_OnDraw;
	int32_t m_OnDelete;


	void* m_ExtraData;

} bbWidget;
 //wf stands for widget function
#define wf_Constructor     0
#define wf_Update          1
//#define wf_DrawFunction    2
#define wf_Destructor      2
#define wf_OnCommand       3
#define wf_AnimationDraw   4



typedef int32_t bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, int32_t parent);
typedef int32_t bbWidget_Update (bbWidget* widget);
typedef int32_t bbWidget_Destructor (bbWidget* widget);
typedef int32_t bbWidget_OnCommand (bbWidget* widget, int32_t command, void* data);
typedef int32_t bbWidget_AnimationDraw (bbWidget* widget, int32_t i);

typedef struct {
	bbWidget_Constructor** Constructors;
	bbDictionary* Constructor_dict;
	int32_t Constructor_available;
	bbWidget_Update** Update;
	bbDictionary* Update_dict;
	int32_t Update_available;
	bbWidget_Destructor** Destructors;
	bbDictionary* Destructor_dict;
	int32_t Destructor_available;
	//includes on click and on prompt?
	bbWidget_OnCommand** OnCommands;
	bbDictionary* OnCommand_dict;
	int32_t OnCommand_available;
	bbWidget_AnimationDraw** AnimationDraw;
	bbDictionary* AnimationDraw_dict;
	int32_t AnimationDraw_available;
} bbWidgetFunctions;


typedef struct {
	bbPool* m_Pool;
	bbDictionary* m_AddressDict; //reference widgets be key
	bbDictionary* m_PromptDict; //enter code "key" to click widget at "address"

	bbWidget* m_Decal; //the root widget in the hierarchy
	bbWidget* m_TextInput; //key events are passed to this widget
	bbWidgetFunctions* m_Functions;
} bbWidgets;

int32_t bbWidgets_new(int32_t map);
int32_t bbWidgetFunctions_new(int32_t map);

int32_t bbWidgetFunctions_populate(int32_t map);
int32_t bbWidgetFunctions_add(bbWidgetFunctions* WFS, int32_t bin, void* pointer, char* key );
int32_t bbWidgetFunctions_getFunction(void** function, bbWidgetFunctions* WFS, int32_t bin, char* key);
int32_t bbWidgetFunctions_getInt(bbWidgetFunctions* WFS, int32_t bin, char* key);

int32_t bbWidget_new(bbWidget** self, bbWidgets* widgets , int32_t type, int32_t parent);
//int32_t bbWidget_draw (bbWidget* widget);
int32_t bbWidget_draw_new(void* void_unused, void* void_widget);
#endif //BBWIDGET_H
