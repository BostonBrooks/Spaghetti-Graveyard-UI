#include "headers/bbGeometry.h"
#include "headers/bbGame.h"


bbScreenCoordsF bbScreenCoordsI_getF(bbScreenCoordsI SCI, bbMapConstants* constants){
	bbScreenCoordsF SCF;
	SCF.x = (float)SCI.x / (float)constants->ScreenPPP;
	SCF.y = (float)SCI.y / (float)constants->ScreenPPP;
	return SCF;
}
bbScreenCoordsI bbScreenCoordsF_getI(bbScreenCoordsF SCF, bbMapConstants* constants){
	bbScreenCoordsI SCI;
	SCI.x = SCF.x * constants->ScreenPPP;
	SCI.y = SCF.y * constants->ScreenPPP;
	return SCI;
}