/**
 * @file
 * @brief The functions in this folder define the behavior of an object with class bbWidget and type NULL
 */
#define BBDEBUG

#include "headers/bbPrintf.h"

#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbWidgetTimer.h"

///	Spawn a null widget on selected map at coordinates mc
I32 bbWidgetNew_Viewport(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, bbWidget* parent){



    bbWidget* widget;
    bbWidget_empty_new(&widget, widgets, sc, parent);

    bbPrintf("viewport -> map = %d\n", widget->p_Node.p_Pool.Map);

    I32 flag;
    widget->m_String = "Mock Viewport";

    bbWidgetFunctions* functions = widgets->m_Functions;
    widget->v_OnMouse = bbWidgetFunctions_getInt(functions, f_WidgetMouseHandler, "clickSphere");


    bbScreenCoordsF SCF;
    bbScreenCoordsI SCI;

    SCF.x = g_Game->m_GraphicsSettings->m_ViewportLeft;
    SCF.y = g_Game->m_GraphicsSettings->m_ViewportTop;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_ScreenCoords = SCI;

    SCF.x = g_Game->m_GraphicsSettings->m_ViewportWidth;
    SCF.y = g_Game->m_GraphicsSettings->m_ViewportHeight;
    SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
    widget->m_Dimensions = SCI;


    widget->m_AnimationInt[0] = bbSprites_lookupInt(g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Sprites,
													g_Game->m_GraphicsSettings->m_ViewportMock); // VIEWPORT

	widget->m_RenderTexture = sfRenderTexture_create(g_Game->m_GraphicsSettings->m_ViewportWidth, g_Game->m_GraphicsSettings->m_ViewportHeight, sfFalse);
	I32 map = widget->p_Node.p_Pool.Map;
	bbSprites* sprites = g_Game->m_Maps[map]->m_Sprites;
	I32 spriteNum = widget->m_AnimationInt[0];
	sfSprite* sprite = sprites->m_Sprites[spriteNum];

	sfRenderTexture_drawSprite(widget->m_RenderTexture, sprite,NULL);
	sfRenderTexture_display(widget->m_RenderTexture );

	widget->m_Sprite = sfSprite_create();
	sfSprite_setTexture(widget->m_Sprite, sfRenderTexture_getTexture(widget->m_RenderTexture), sfTrue);

    widget->v_DrawFunction[0] = bbWidgetFunctions_getInt(functions, f_WidgetDrawFunction, "rendertexture");

	g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_Viewport = widget;

    *reference = widget;
    return f_Success;
}

/// Update widget
I32 bbWidget_Viewport_update(bbWidget* widget){}

/// Send a command to the widget / update widget, etc
I32 bbWidgetCommand_Viewport(bbWidget* widget, void* command){}

/// Delete widget
I32 bbWidgetDelete_Viewport(bbWidget* widget){}

/// Draw widget to screen
I32 bbWidgetDraw_Viewport(bbWidget* widget){}


