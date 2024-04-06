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




int32_t bbWidget_menuButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent) {
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


    widget->m_AnimationInt[0] = 220; // SPELLBAR_MENU
    widget->m_DrawFunction[0] = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "sprite");

    bbWidget *parentWidget;

    bbPool_Lookup(&parentWidget, pool, parent);

    bbNode_setParent(widget, parentWidget, pool);

    *reference = widget;
    return f_Success;

}

int32_t bbWidget_showHideButton_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_plus_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_minus_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_times_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_divide_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_determinant_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_twoPower_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_piNDigits_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

}

int32_t bbWidget_spellBar_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){


}
