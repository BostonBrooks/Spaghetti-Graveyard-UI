#define BBDEBUG

#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbPrintf.h"


// g_Game->m_Maps[map]->m_Widgets = widgets; OR return by reference?
int32_t bbWidgets_new(int32_t map){
	bbWidgets* widgets = calloc(1, sizeof(bbWidgets));

	bbPool_NewPool(&widgets->m_Pool, map, sizeof(bbWidget), 100, 100); //todo lvl1 lvl2
	bbDictionary_new(&widgets->m_AddressDict, 777);
	bbDictionary_new(&widgets->m_PromptDict, 666);
	widgets->m_Decal = NULL;
	widgets->m_TextInput = NULL;
	widgets->m_Functions = NULL;

	g_Game->m_Maps[map]->m_Widgets = widgets;
	return f_Success;
}

// Should m_Widgets be an argument?
int32_t bbWidget_new(bbWidget** self, bbWidgets* widgets , int32_t type, int32_t parent, bbScreenCoordsI SCI){
    bbAssert(type >= 0, "Constructor not found\n");

	bbWidget* widget;
    bbWidget* parentWidget;



    bbPool_Lookup(&parentWidget, widgets->m_Pool, parent);
	bbWidget_Constructor* constructor = widgets->m_Functions->Constructors[type];

	int32_t flag = constructor(&widget, widgets, SCI, parentWidget);

	*self = widget;
	return flag;
}
/*

int32_t bbWidget_draw (bbWidget* widget){

	bbWidget_DrawFunction* drawFunction = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_Functions->DrawFunctions[widget->m_OnDraw];
	int32_t flag = drawFunction(widget);

	return flag;
}
*/

//typedef int32_t bbTreeFunction (void* reference, void* node);
int32_t bbWidget_draw(void* void_unused, void* void_widget){
	bbWidget* widget = void_widget;
	int32_t map = widget->p_Node.p_Pool.Map;
	bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;
	bbWidget_DrawFunction* drawFunctions = *functions->DrawFunction;

	for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
		int drawFunction_int = widget->m_DrawFunction[i];
		if (drawFunction_int >= 0) {
			//TODO skins, default drawfunction given by animation or skin
			functions->DrawFunction[drawFunction_int](widget, i);

		}
	}
    return f_Continue;
}
//typedef int32_t bbTreeFunction (void* reference, void* node);
int32_t bbWidget_mouse(void* void_mouseEvent, void* void_widget){
    bbWidget* widget = void_widget;
    int32_t map = widget->p_Node.p_Pool.Map;
    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;

    bbWidget_Mouse* mouseFunction = functions->MouseHandler[widget->m_OnMouse];

    return mouseFunction(void_mouseEvent, void_widget);
}

int32_t bbWidget_update (bbWidget* widget){


}

int32_t bbWidgetFunctions_new(int32_t map) {
	bbWidgetFunctions *functions = calloc(1, sizeof(bbWidgetFunctions));


	const int32_t numConstructors = g_Game->m_Maps[map]->p_Constants.Widget_Constructors;
	functions->Constructors = calloc(numConstructors,
									 sizeof(bbWidget_Constructor));
	bbDictionary_new(&functions->Constructor_dict, numConstructors);
	functions->Constructor_available = 0;

	const int32_t numUpdate = g_Game->m_Maps[map]->p_Constants.Widget_Updates;
	functions->Update = calloc(numUpdate,
									 sizeof(bbWidget_Update));
	bbDictionary_new(&functions->Update_dict, numUpdate);
	functions->Update_available = 0;


	const int32_t numDestructors = g_Game->m_Maps[map]->p_Constants.Widget_Destructors;
	functions->Destructors = calloc(numDestructors,
									sizeof(bbWidget_Destructor));
	bbDictionary_new(&functions->Destructor_dict, numDestructors);
	functions->Destructor_available = 0;

	const int32_t numOnCommands = g_Game->m_Maps[map]->p_Constants.Widget_OnCommands;
	functions->OnCommands = calloc(numOnCommands, sizeof(bbWidget_OnCommand));
	bbDictionary_new(&functions->OnCommand_dict, numOnCommands);
	functions->OnCommand_available = 0;

	const int32_t numDrawFunctions = g_Game->m_Maps[map]->p_Constants.Widget_DrawFunctions;
	functions->DrawFunction = calloc(numDrawFunctions,
									  sizeof(bbWidget_DrawFunction));
	bbDictionary_new(&functions->DrawFunction_dict, numDrawFunctions);
	functions->DrawFunction_available = 0;

    const int32_t numMouseHandlers = g_Game->m_Maps[map]->p_Constants.Widget_Mouses;
    functions->MouseHandler = calloc(numMouseHandlers,
                                     sizeof(bbWidget_DrawFunction));
    bbDictionary_new(&functions->MouseHandler_dict, numMouseHandlers);
    functions->MouseHandler_available = 0;

	g_Game->m_Maps[map]->m_Widgets->m_Functions = functions;

	return f_Success;
}



int32_t bbWidgetFunctions_add(bbWidgetFunctions* WFS, int32_t bin, void* fun_ptr, char* key ){
	int available;
	switch (bin) {
		case f_WidgetConstructor:
			available = WFS->Constructor_available++;
			//bbAssert available < MAX
			WFS->Constructors[available] = fun_ptr;
			bbDictionary_add(WFS->Constructor_dict, key, available);
			return f_Success;

		case f_WidgetUpdate:
			available = WFS->Update_available++;
			//bbAssert available < MAX
			WFS->Update[available] = fun_ptr;
			bbDictionary_add(WFS->Update_dict, key, available);
			return f_Success;

		case f_WidgetDestructor:
			available = WFS->Destructor_available++;
			//bbAssert available < MAX
			WFS->Destructors[available] = fun_ptr;
			bbDictionary_add(WFS->Destructor_dict, key, available);
			return f_Success;

		case f_WidgetOnCommand:
			available = WFS->OnCommand_available++;
			//bbAssert available < MAX
			WFS->OnCommands[available] = fun_ptr;
			bbDictionary_add(WFS->OnCommand_dict, key, available);
			return f_Success;

		case f_WidgetDrawFunction:
			available = WFS->DrawFunction_available++;
			//bbAssert available < MAX
			WFS->DrawFunction[available] = fun_ptr;
			bbDictionary_add(WFS->DrawFunction_dict, key, available);
			return f_Success;

        case f_WidgetMouseHandler:
            available = WFS->MouseHandler_available++;
            //bbAssert available < MAX
            WFS->MouseHandler[available] = fun_ptr;
            bbDictionary_add(WFS->MouseHandler_dict, key, available);
            return f_Success;
		default:
            bbPrintf("Bad flag in bbWidgetFunctions_add\n");
			return f_None;
	}
}

int32_t bbWidgetFunctions_getFunction(void** function, bbWidgetFunctions* WFS, int32_t bin, char* key){
	int32_t intAddress;
	switch (bin) {
		case f_WidgetConstructor:
			intAddress = bbDictionary_lookup(WFS->Constructor_dict, key);
			*function = WFS->Constructors[intAddress];
			return f_Success;

		case f_WidgetUpdate:
			intAddress = bbDictionary_lookup(WFS->Update_dict, key);
			*function = WFS->Update[intAddress];
			return f_Success;

		case f_WidgetDestructor:
			intAddress = bbDictionary_lookup(WFS->Destructor_dict, key);
			*function = WFS->Destructors[intAddress];
			return f_Success;

		case f_WidgetOnCommand:
			intAddress = bbDictionary_lookup(WFS->OnCommand_dict, key);
			*function = WFS->OnCommands[intAddress];
			return f_Success;

		case f_WidgetDrawFunction:
			intAddress = bbDictionary_lookup(WFS->DrawFunction_dict, key);
			*function = WFS->DrawFunction[intAddress];
			return f_Success;

        case f_WidgetMouseHandler:
            intAddress = bbDictionary_lookup(WFS->MouseHandler_dict, key);
            *function = WFS->MouseHandler[intAddress];
            return f_Success;
		default:
			return f_None;
	}
}
int32_t bbWidgetFunctions_getInt(bbWidgetFunctions* WFS, int32_t bin, char* key){
	int32_t intAddress;
	switch (bin) {
		case f_WidgetConstructor:
			intAddress = bbDictionary_lookup(WFS->Constructor_dict, key);
			return intAddress;

		case f_WidgetUpdate:
			intAddress = bbDictionary_lookup(WFS->Update_dict, key);
			return intAddress;
		case f_WidgetDestructor:
			intAddress = bbDictionary_lookup(WFS->Destructor_dict, key);
			return intAddress;

		case f_WidgetOnCommand:
			intAddress = bbDictionary_lookup(WFS->OnCommand_dict, key);
			return intAddress;

		case f_WidgetDrawFunction:
			intAddress = bbDictionary_lookup(WFS->DrawFunction_dict, key);
			return intAddress;

        case f_WidgetMouseHandler:
            intAddress = bbDictionary_lookup(WFS->MouseHandler_dict, key);
            return intAddress;
		default:
			return f_None;
	}
}

int32_t bbWidget_onCommand(void* command, void* void_widget){

    bbWidget* widget = void_widget;
    int32_t map = widget->p_Node.p_Pool.Map;
    bbWidgetFunctions* functions = g_Game->m_Maps[map]->m_Widgets->m_Functions;
    int32_t commandFunction_int = widget->m_OnCommand;

        if (commandFunction_int >= 0) {
            functions->OnCommands[commandFunction_int](widget, command);

        }

    return f_Continue;
}