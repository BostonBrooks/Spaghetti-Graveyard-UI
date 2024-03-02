#include "headers/bbGame.h"
#include "headers/bbMap.h"
#include "headers/bbMapConstants.h"
#include "headers/bbGeometry.h"

bbScreenCoordsF bbScreenCoordsI_toFloat(int32_t map, bbScreenCoordsI sc){
	float ScreenPPP = g_Game->m_Maps[map]->Constants.m_ScreenPPP;

	bbScreenCoordsF scf;
	scf.x = sc.x / ScreenPPP;
	scf.y = sc.y / ScreenPPP;

	return scf;
}

