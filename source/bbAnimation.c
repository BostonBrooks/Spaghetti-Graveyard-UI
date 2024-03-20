#include "headers/bbSystemIncludes.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"
#include "headers/bbDictionary.h"
#include "headers/bbGame.h"
#include "headers/bbAnimation.h"




int32_t _bbAnimations_new(bbAnimations** self, int32_t numAnimations){
	bbAnimations* animations = calloc(1, sizeof(bbAnimations));
	bbAssert(animations != NULL, "calloc failed\n");
	animations->m_NumAnimations = numAnimations;
	int32_t flag = bbDictionary_new(&animations->m_Dictionary, numAnimations);
    animations->m_Animations = calloc(numAnimations, sizeof(bbAnimation*));
	bbAssert(flag == f_Success, "bbDictionary_new failed\n");
	*self = animations;
	return f_Success;

}
int32_t animation_load(bbAnimations* animations, bbSprites* sprites, char* key, int32_t address, int32_t DrawFunction, int32_t angles, int32_t frames, int32_t framerate, int* spriteInts){
	bbAnimation* anim = calloc(1, sizeof(bbAnimation) + angles * frames * sizeof(int32_t));
	bbAssert(anim != NULL, "calloc failed");
	strcpy(anim->m_Key, key);
	anim->v_DrawFunction = DrawFunction;
	anim->m_Angles = angles;
	anim->m_Frames = frames;
	anim->m_Sprites = sprites;
	anim->m_Framerate = framerate;

	for (int32_t i = 0; i < angles*frames; i++){
		anim->i_Sprites[i] = spriteInts[i];
	}

	animations->m_Animations[address] = anim;
	bbDictionary_add(animations->m_Dictionary, key, address);

	//bbDebug("bbAnimations_load: %s,%d,%d,%d,%d,%d,%d,%d\n",
	//		anim->m_Key, address, anim->v_DrawFunction, anim->m_Angles, anim->m_Frames,anim->m_Framerate, anim->i_Sprites[0], anim->i_Sprites[1]);

	return f_Success;
}


int32_t bbAnimations_new(bbAnimations** self, bbSprites* Sprites, char* folderPath,
						 int32_t numAnimations){
	bbAnimations* animations;
	_bbAnimations_new(&animations, numAnimations);

	char string[256];
	sprintf(string, "%s/animations.csv", folderPath);
	bbDebug("file path is %s\n", string);

	FILE* file = fopen(string,"r");

	bbAssert(file != NULL, "fopen failed\n");
	fscanf(file, "%[^\]]%*[^\n]\n", string);
	bbAssert(strcmp(string,
					"Label:,V_Address:,V_DrawFunction:,Angles:,Frames:,Framerate:,Sprites[") == 0,
			 "bad sprites.csv file\n");

	fscanf(file, "%[^\n]\n", string);

	char key[KEY_LENGTH];
	int32_t address, drawFunction, angles, frames, framerate, sprites[256];
	int32_t flag = 1;
	while (fscanf(file, "%[^,],%d,%d,%d,%d,%d", key, &address, &drawFunction, &angles, &frames, &framerate) == 6){

		//bbDebug("bbAnimations_new: %s,%d,%d,%d,%d,%d", key, address, drawFunction, angles, frames, framerate);
		for (int32_t i = 0; i < angles * frames; i++){
			fscanf(file, ",%[^,]", string);
			//bbPrintf(",%s", string);
			int32_t spriteInt = bbDictionary_lookup(Sprites->m_Dictionary, string);

			sprites[i] = spriteInt;

		}
		fscanf(file, "%*[^\n]\n");
		//bbPrintf("\n");
		animation_load(animations, Sprites, key, address,drawFunction,angles, frames, framerate, sprites);
	}
	*self = animations;

	return f_Success;

}

