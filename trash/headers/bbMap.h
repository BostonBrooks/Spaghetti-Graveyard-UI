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
#include "headers/bbActor.h"
#include "headers/bbMedia.h"
#include "headers/bbWidget.h"
#include "headers/bbMapConstants.h"
#include "headers/bbSkins.h"
#include "headers/bbElevations.h"


typedef struct { //bbMap

	bbMapConstants m_Constants;

	char* path;  //path to map folder

	char m_Name[128];
	bbTextures* m_Textures;
	bbSprites* m_Sprites;
	bbAnimations* m_Animations;
	bbSkins* m_Skins;

    //vtables


	bbElevations* m_Elevations;
	bbTerrainSquares* m_Terrain;
	bbDrawables* m_Drawables;
	bbActors* m_Actors;
	bbWidgets* m_Widgets;

	bbMapCoords m_Viewpoint;
	int32_t m_ViewpointDrawable;


	/// Increased with every update of the map
	int32_t m_MapTime;

} bbMap;

int32_t bbMap_new(bbMap** Map, char* file_path);
int32_t bbMap_printConstants(bbMap* map);


#endif //BBMAP_H
