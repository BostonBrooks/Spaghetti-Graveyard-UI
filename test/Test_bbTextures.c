#include "headers/bbTextures.h"

int main (void){

	//new game
	//new map

	//new textures
	bbTextures_new(0, "../maps/demo/textures.csv", 512);

	sfVideoMode mode = {800, 600, 32};

	sfRenderWindow* window;
	sfTexture* texture;
	sfSprite& sprite;

	window = sfRenderWindow_create(mode, "Test Textures", sfResize | sfClose, NULL);



}