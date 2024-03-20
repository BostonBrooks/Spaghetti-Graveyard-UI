#include "headers/bbSystemIncludes.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"
#include "headers/bbDictionary.h"
#include "headers/bbGame.h"

//dimensions are given in numbers of pixels
typedef struct {
	int32_t left;
	int32_t top;
	int32_t width;
	int32_t height;
	float originx;
	float originy;
	float scalex;
	float scaley;
} sprite_dimensions;

#define scaleNone     0;
#define scaleWidget   1;
#define scaleDrawable 2;


int32_t _bbSprites_new(bbSprites** self, int32_t numSprites){
	bbSprites* sprites = calloc(1, sizeof(bbSprites));
	bbAssert(sprites != NULL, "calloc failed\n");
	sprites->m_NumSprites = numSprites;
	sprites->m_Sprites = calloc(numSprites, sizeof(sfSprite*));
	int32_t flag = bbDictionary_new(&sprites->m_Dictionary, numSprites);




	bbAssert(flag == f_Success, "bbDictionary_new failed\n");
	*self = sprites;
	return f_Success;

}

//scale by widgets, drawables or none. there are a lot of arguments :S
//We need to know bbMapConstants::DrawableScale and bbMapConstants::WidgetScale;
int32_t sprite_load(bbSprites* sprites, char* key, int32_t address,
					sfTexture* texture,
					sprite_dimensions* dimensions)
{
	//create sprite

	sfSprite* sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);

	sfIntRect rect;
	rect.left = dimensions->left;
	rect.top = dimensions->top;
	rect.width = dimensions->width;
	rect.height = dimensions->height;
	sfSprite_setTextureRect(sprite, rect);

	sfVector2f origin;
	origin.x = dimensions->originy;
	origin.y = dimensions->originy;
	sfSprite_setOrigin(sprite, origin);

	sfVector2f scale;
	scale.x = dimensions->scalex;
	scale.y = dimensions->scaley;
	sfSprite_setScale(sprite, scale);



/* DEBUG
    sfVector2f position;
	position.x = 400;
	position.y = 320;
	sfSprite_setPosition(sprite, position);
	sfRenderWindow_clear(g_Game->m_Window, sfBlue);
	sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);
	sfRenderWindow_display(g_Game->m_Window);
	sfTime delay = sfMilliseconds(100);
	sfSleep(delay);

DEBUG */

	//add sprite to sprites container

	sprites->m_Sprites[address] = sprite;
	bbDictionary_add(sprites->m_Dictionary, key, address);
	return f_Success;

}



int32_t bbSprites_new(bbSprites** self, bbTextures* textures, char* folderPath, bbMapConstants* constants){

	bbSprites* sprites;
	_bbSprites_new(&sprites, constants->Sprites);

	char string[256];
	sprintf(string, "%s/sprites.csv", folderPath);
	bbDebug("file path is %s\n", string);

	FILE* file = fopen(string, "r");


	fscanf(file, "%[^\n]\n", string);
	bbAssert(strcmp(string,
					"Label:,Virtual Address:,sfTexture:,Left:,Top:,Width:,Height:,Origin_X:,Origin_Y:,Scale_X:,Scale_Y:,Scale_By:,Comment:") == 0,
			 "bad sprites.csv file\n");

	char key[KEY_LENGTH];
	int32_t address;
	char texture_key[KEY_LENGTH];
	sprite_dimensions dimensions;
	char scaleBy[16];

	while (fscanf(file,
		   "%[^,],%d,%[^,],%d,%d,%d,%d,%f,%f,%f,%f,%[^,]%*[^\n]\n",
		   key,
		   &address,
		   texture_key,
		   &dimensions.left,
		   &dimensions.top,
		   &dimensions.width,
		   &dimensions.height,
		   &dimensions.originx,
		   &dimensions.originy,
		   &dimensions.scalex,
		   &dimensions.scaley,
		   scaleBy) == 12 ) {

//		bbDebug("%s,%d,%s,%d,%d,%d,%d,%f,%f,%f,%f,%s\n",
//				key,
//				address,
//				texture_key,
//				dimensions.left,
//				dimensions.top,
//				dimensions.width,
//				dimensions.height,
//				dimensions.originx,
//				dimensions.originy,
//				dimensions.scalex,
//				dimensions.scaley,
//				scaleBy);


		sfTexture* texture;
		bbTextures_lookup(&texture, textures, texture_key);

		if (strcmp(scaleBy, "Drawable") == 0){
			dimensions.scalex *= constants->DrawableScale;
			dimensions.scaley *= constants->DrawableScale;
		} else if (strcmp(scaleBy, "Widget") == 0){
			dimensions.scalex *= constants->WidgetScale;
			dimensions.scaley *= constants->WidgetScale;
		}

		sprite_load(sprites, key, address, texture, &dimensions);
	}
	*self = sprites;

	return f_Success;
}


int32_t bbSprites_lookupInt(bbSprites* sprites, char* key){

	int32_t len = strlen(key);
	char digits[] = "0123456789";
	int32_t int_len = strspn(key, digits);
	int32_t  address;
	if(len == int_len) {
		address = atoi(key);
		return address;
	}
	address = bbDictionary_lookup(sprites->m_Dictionary, key);
	bbAssert(address >= 0, "bad index from dictionary\n");
	return address;

}