#include "headers/bbMap.h"

int32_t bbMap_new(char* path, bbMap** return_map){

	FILE* file = fopen(path, "r");

	bbMap* map = calloc(1, sizeof(bbMap));

	int integer;
	float floatingpoint;
	char string[128];

	fscanf(file, "%[^\n]\n", string);
	bbAssert(strcmp(string, "Map Data:") == 0, "bad mapdata file\n");
	fscanf(file, "MapName: \"%[^\"]\"\n", string);
	printf("loading %s\n", string);
	strcpy(map->m_Name, string);

	fscanf(file, "ViewportScale: %f\n", &floatingpoint);
	map->m_Constants.ViewportScale = floatingpoint;

	fscanf(file, "WidgetScale: %f\n", &floatingpoint);
	map->m_Constants.WidgetScale = floatingpoint;

	fscanf(file, "ElevationScale: %d\n", &integer);
	map->m_Constants.ElevationScale = integer;

	fscanf(file, "MaxPixelValue: %d\n", &integer);
	map->m_Constants.MaxPixelValue = integer;

	fscanf(file, "PointsPerPixel: %d\n", &integer);
	map->m_Constants.PointsPerPixel = integer;

	fscanf(file, "PixelsPerTile: %d\n", &integer);
	map->m_Constants.PixelsPerTile = integer;

	fscanf(file, "TilesPerSquare: %d\n", &integer);
	map->m_Constants.TilesPerSquare = integer;

	fscanf(file, "SquaresPerMapI: %d\n", &integer);
	map->m_Constants.SquaresPerMapI = integer;

	fscanf(file, "SquaresPerMapJ: %d\n", &integer);
	map->m_Constants.SquaresPerMapJ = integer;

	fscanf(file, "ScreenPointsPerPixel: %d\n", &integer);
	map->m_Constants.ScreenPPP = integer;

	fscanf(file, "FrameRateLimit: %d\n", &integer);
	map->m_Constants.FramerateLimit = integer;

	fscanf(file, "Textures: %d\n", &integer);
	map->m_Constants.Textures = integer;

	fscanf(file, "Sprites: %d\n", &integer);
	map->m_Constants.Sprites = integer;

	fscanf(file, "Animations: %d\n", &integer);
	map->m_Constants.Animations = integer;

	fscanf(file, "Skins: %d\n", &integer);
	map->m_Constants.Skins = integer;

	fscanf(file,"%[^\n]", string);

	printf("the last lines of mapdata.txt are %s\n", string);

	map->m_Constants.PointsPerTile = map->m_Constants.PointsPerPixel * map->m_Constants.PixelsPerTile;
	map->m_Constants.PointsPerSquare = map->m_Constants.PointsPerPixel * map->m_Constants.PixelsPerTile * map->m_Constants.TilesPerSquare;
	map->m_Constants.PixelsPerSquare =  map->m_Constants.PixelsPerTile * map->m_Constants.TilesPerSquare;

	map->m_MapTime = 0;

	*return_map = map;

	return 1;
}

int32_t bbMap_printConstants(bbMap* map){
	printf("MapName: %s\n", map->m_Name);
	printf("ViewportScale: %f\n", map->m_Constants.ViewportScale);
	printf("WidgetScale: %f\n", map->m_Constants.WidgetScale);
	printf("ElevationScale: %d\n", map->m_Constants.ElevationScale);
	printf("MaxPixelValue: %d\n", map->m_Constants.MaxPixelValue);
	printf("PointsPerPixel: %d\n", map->m_Constants.PointsPerPixel);
	printf("PixelsPerTile: %d\n", map->m_Constants.PixelsPerTile);
	printf("TilesPerSquare: %d\n", map->m_Constants.TilesPerSquare);
	printf("SquaresPerMapI: %d\n", map->m_Constants.SquaresPerMapI);
	printf("SquaresPerMapJ: %d\n", map->m_Constants.SquaresPerMapJ);
	printf("ScreenPointsPerPixel: %d\n", map->m_Constants.ScreenPPP);
	printf("Textures: %d\n", map->m_Constants.Textures);
	printf("Sprites: %d\n", map->m_Constants.Sprites);
	printf("Animations: %d\n", map->m_Constants.Animations);
	printf("Skins: %d\n", map->m_Constants.Skins);
}
