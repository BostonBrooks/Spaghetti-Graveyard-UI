#include "headers/bbSystemIncludes.h"
#include "headers/bbGame.h"
#include "headers/bbGraphicsSettings.h"
#include "headers/bbMap.h"

bbGame* g_Game;

int main (void){
	g_Game = bbGame_new(GAME_PATH);
}
