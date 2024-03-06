/**
 * @file
 * @brief bbMap stores all the game data pertaining to one map in the game
 */
#ifndef BBMAP_H
#define BBMAP_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbGeometry.h"
#include "headers/bbTerrain.h"
#include "headers/bbDrawable.h"
#include "headers/bbAI_FSM.h"
#include "headers/bbMedia.h"
#include "headers/bbWidget.h"
#include "headers/bbMapConstants.h"


typedef struct { //bbMap

	bbMapConstants m_Constants;


    bbTextures* m_Textures;
    bbSprites* m_Sprites;
    bbAnimations* m_Animations;
    bbSkins* m_Skins;

	/// Increased with every update of the map
	int32_t m_MapTime;

	char* path;

    bbElevations* m_Elevations;
	bbTerrainSquares* m_Terrain;
	bbDrawables* m_Drawables;
	bbAI_FSMs* m_AI_FSMs;
	bbMedia* m_Media;
	bbWidgets* m_widgets;

    bbMapCoords m_Viewpoint;
	int32_t m_ViewpointDrawable;

} bbMap;

bbMap* bbMap_new(char* file_path);


#endif //BBMAP_H