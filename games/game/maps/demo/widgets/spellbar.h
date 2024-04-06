/**
 * @file
 * @brief The functions in this file define the behavior of an object with class bbWidget and type spellBar
 * and its member widgets
 *
 * The bbTree representing the spellBar is structured as such
 *
 *    spellBar
 *      - menuButton
 *      - showHideButton
 *          - plus
 *          - minus
 *          - times
 *          - divide
 *          - determinant
 *          - twoPower
 *          - squared
 *          - piNDigits
 */


#include "headers/bbPrintf.h"
#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"

//typedef int32_t bbWidget_Constructor (bbWidget** reference, void* widgets, bbScreenCoordsI screen_coords, bbWidget* parent);


int32_t bbWidget_menuButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent) {
///	Spawn a null widget on selected map at coordinates mc


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 0;         // MENU
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");


    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;

}

int32_t bbWidget_showHideButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 1;         // SHOWHIDE
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");



    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}

int32_t bbWidget_plusButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 2;         // PLUS
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");



    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}

int32_t bbWidget_minusButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 3;         // MINUS
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");


    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}

int32_t bbWidget_timesButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 4;         // TIMES
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");



    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}

int32_t bbWidget_divideButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 5;         // DIVIDE
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");



    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}

int32_t bbWidget_detButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 6;         // DETERMINANT
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");



    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}

int32_t bbWidget_twoPowerButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 7;         // TWO TO THE POWER
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");



    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}

int32_t bbWidget_squaredButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.DrawableScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 8;         // SQUARED
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");



    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}
int32_t bbWidget_piNDigitsButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;

    bbWidget *widget;
    int32_t flag;

    flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


    widget->m_ScreenCoords = sc;
    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.WidgetScale;
    SCF.y = 80 * g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants.WidgetScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;

    bbWidgetFunctions *functions = widgets->m_Functions;


    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        widget->m_AnimationInt[i] = f_None;
        widget->m_Angle[i] = 0;
        widget->m_Frame[i] = 0;
        widget->m_DrawFunction[i] = f_None;
    }


    widget->m_AnimationInt[0] = 24; // SPELLBAR
    widget->m_Frame[0] = 9;         // N DIGITS OF PI
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "frame");


    bbNode_setParent(widget, parent, pool);

    *reference = widget;
    return f_Success;
}
int32_t bbWidget_spellBar_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){

    bbWidget* spellBar;
    bbWidget* menuButton;
    bbWidget* showHideButton;
    bbWidget* plusButton;
    bbWidget* minusButton;
    bbWidget* timesButton;
    bbWidget* divideButton;
    bbWidget* detButton;
    bbWidget* twoPowerButton;
    bbWidget* squaredButton;
    bbWidget* piNDigitsButton;


    bbPool *pool = widgets->m_Pool;
    bbDictionary *dict = widgets->m_AddressDict;
    int32_t map = widgets->m_Pool->m_Map;

    int32_t flag;

    flag = bbPool_New(&spellBar, pool, f_PoolNextAvailable);
    spellBar->m_ScreenCoords = sc;

    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;


    SCF.x = 10 * 80 * g_Game->m_Maps[spellBar->p_Node.p_Pool.Map]->p_Constants.WidgetScale;
    SCF.y = 80 * g_Game->m_Maps[spellBar->p_Node.p_Pool.Map]->p_Constants.WidgetScale;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[spellBar->p_Node.p_Pool.Map]->p_Constants);
    spellBar->m_Dimensions = SCI;

    for (int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++) {
        spellBar->m_AnimationInt[i] = f_None;
        spellBar->m_Angle[i] = 0;
        spellBar->m_Frame[i] = 0;
        spellBar->m_DrawFunction[i] = f_None;
    }


    bbNode_setParent(spellBar, parent, pool);

    bbWidget_menuButton_new(&menuButton, widgets, sc, spellBar);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_showHideButton_new(&showHideButton, widgets, sc, spellBar);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_plusButton_new(&plusButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_minusButton_new(&minusButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_timesButton_new(&timesButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_divideButton_new(&divideButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_detButton_new(&detButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_twoPowerButton_new(&twoPowerButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_squaredButton_new(&squaredButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    bbWidget_piNDigitsButton_new(&piNDigitsButton, widgets, sc, showHideButton);
    sc.x += 80 * g_Game->m_Maps[map]->p_Constants.ScreenPPP * g_Game->m_Maps[map]->p_Constants.WidgetScale;

    *reference = spellBar;





}
