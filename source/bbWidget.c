#define BBDEBUG

#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbPrintf.h"

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
int32_t bbWidget_new(bbWidget** self, bbWidgets* widgets , int32_t type, int32_t parent){
	bbDebug("in bbWidget_new\n");
	bbWidget* widget;
	bbWidget_Constructor* constructor = widgets->m_Functions->Constructors[type];

	bbScreenCoordsI SCI;
	SCI.x = 0;
	SCI.y = 0;


	int32_t flag = constructor(&widget, widgets, SCI, parent);

	bbDebug("in bbWidget_new: map = %d, self = %d\n", widget->p_Pool.Map, widget->p_Pool.Self);
	*self = widget;
	return flag;
}

int32_t bbWidget_draw (bbWidget* widget){
	bbDebug("in bbWidget_draw\n");

	bbWidget_DrawFunction* drawFunction = g_Game->m_Maps[widget->p_Pool.Map]->m_Widgets->m_Functions->DrawFunctions[widget->m_OnDraw];
	int32_t flag = drawFunction(widget);

	bbDebug("out bbWidget_draw\n");
	return flag;
}

int32_t bbWidget_update (bbWidget* widget){
	bbDebug("in bbWidget_update\n");

	bbWidget_DrawFunction* drawFunction = g_Game->m_Maps[widget->p_Pool.Map]->m_Widgets->m_Functions->Update[widget->m_OnUpdate];
	int32_t flag = drawFunction(widget);

	bbDebug("out bbWidget_update\n");
	return flag;
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

	const int32_t numDrawFunctions = g_Game->m_Maps[map]->p_Constants.Widget_DrawFunctions;
	functions->DrawFunctions = calloc(numDrawFunctions,
									  sizeof(bbWidget_DrawFunction));
	bbDictionary_new(&functions->DrawFunction_dict, numDrawFunctions);
	functions->DrawFunction_available = 0;

	const int32_t numDestructors = g_Game->m_Maps[map]->p_Constants.Widget_Destructors;
	functions->Destructors = calloc(numDestructors,
									sizeof(bbWidget_Destructor));
	bbDictionary_new(&functions->Destructor_dict, numDestructors);
	functions->Destructor_available = 0;

	const int32_t numOnCommands = g_Game->m_Maps[map]->p_Constants.Widget_OnCommands;
	functions->OnCommands = calloc(numDestructors, sizeof(bbWidget_Destructor));
	bbDictionary_new(&functions->OnCommand_dict, numOnCommands);
	functions->OnCommand_available = 0;

	const int32_t numAnimationDraws = g_Game->m_Maps[map]->p_Constants.Widget_OnCommands;
	functions->AnimationDraw = calloc(numAnimationDraws,
									  sizeof(bbWidget_Destructor));
	bbDictionary_new(&functions->AnimationDraw_dict, numAnimationDraws);
	functions->AnimationDraw_available = 0;

	g_Game->m_Maps[map]->m_Widgets->m_Functions = functions;

	return f_Success;
}



int32_t bbWidgetFunctions_add(bbWidgetFunctions* WFS, int32_t bin, void* fun_ptr, char* key ){
	int available;
	switch (bin) {
		case wf_Constructor:
			available = WFS->Constructor_available++;
			//bbAssert available < MAX
			WFS->Constructors[available] = fun_ptr;
			bbDictionary_add(WFS->Constructor_dict, key, available);
			return f_Success;

		case wf_Update:
			available = WFS->Update_available++;
			//bbAssert available < MAX
			WFS->Update[available] = fun_ptr;
			bbDictionary_add(WFS->Update_dict, key, available);
			return f_Success;

		case wf_DrawFunction:
			available = WFS->DrawFunction_available++;
			//bbAssert available < MAX
			WFS->DrawFunctions[available] = fun_ptr;
			bbDictionary_add(WFS->DrawFunction_dict, key, available);
			return f_Success;

		case wf_Destructor:
			available = WFS->Destructor_available++;
			//bbAssert available < MAX
			WFS->Destructors[available] = fun_ptr;
			bbDictionary_add(WFS->Destructor_dict, key, available);
			return f_Success;

		case wf_OnCommand:
			available = WFS->OnCommand_available++;
			//bbAssert available < MAX
			WFS->OnCommands[available] = fun_ptr;
			bbDictionary_add(WFS->OnCommand_dict, key, available);
			return f_Success;

		case wf_AnimationDraw:
			available = WFS->AnimationDraw_available++;
			//bbAssert available < MAX
			WFS->AnimationDraw[available] = fun_ptr;
			bbDictionary_add(WFS->AnimationDraw_dict, key, available);
			return f_Success;
		default:
			return f_None;
	}
}

int32_t bbWidgetFunctions_getFunction(void** function, bbWidgetFunctions* WFS, int32_t bin, char* key){
	int32_t intAddress;
	switch (bin) {
		case wf_Constructor:
			intAddress = bbDictionary_lookup(WFS->Constructor_dict, key);
			*function = WFS->Constructors[intAddress];
			return f_Success;

		case wf_Update:
			intAddress = bbDictionary_lookup(WFS->Update_dict, key);
			*function = WFS->Update[intAddress];
			return f_Success;

		case wf_DrawFunction:
			intAddress = bbDictionary_lookup(WFS->DrawFunction_dict, key);
			*function = WFS->DrawFunctions[intAddress];
			return f_Success;

		case wf_Destructor:
			intAddress = bbDictionary_lookup(WFS->Destructor_dict, key);
			*function = WFS->Destructors[intAddress];
			return f_Success;

		case wf_OnCommand:
			intAddress = bbDictionary_lookup(WFS->OnCommand_dict, key);
			*function = WFS->OnCommands[intAddress];
			return f_Success;

		case wf_AnimationDraw:
			intAddress = bbDictionary_lookup(WFS->AnimationDraw_dict, key);
			*function = WFS->AnimationDraw[intAddress];
			return f_Success;
		default:
			return NULL;
	}
}
int32_t bbWidgetFunctions_getInt(bbWidgetFunctions* WFS, int32_t bin, char* key){
	int32_t intAddress;
	switch (bin) {
		case wf_Constructor:
			intAddress = bbDictionary_lookup(WFS->Constructor_dict, key);
			return intAddress;

		case wf_Update:
			intAddress = bbDictionary_lookup(WFS->Update_dict, key);
			return intAddress;

		case wf_DrawFunction:
			intAddress = bbDictionary_lookup(WFS->DrawFunction_dict, key);
			return intAddress;

		case wf_Destructor:
			intAddress = bbDictionary_lookup(WFS->Destructor_dict, key);
			return intAddress;

		case wf_OnCommand:
			intAddress = bbDictionary_lookup(WFS->OnCommand_dict, key);
			return intAddress;

		case wf_AnimationDraw:
			intAddress = bbDictionary_lookup(WFS->AnimationDraw_dict, key);
			return intAddress;
		default:
			return f_None;
	}
}