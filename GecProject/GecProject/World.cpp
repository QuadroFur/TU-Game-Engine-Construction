#include "World.h"

void World::GenerateLevel(int MapSize) {

	for (int y = 0; y < MapSize; y++)
	{
		for (int x = 0; x < MapSize; x++)
		{
			//An algorithm using perlin noise to map terrain heights.

			//int TerrainHeight = 0;
			//TerrainMap[y][x] == '-';
		}
	}
}
void World::LoadLevel(std::string Path) {

	//Load a level from a file. Probably JSON or somethin.

}

bool World::CheckFreeSpace(int X, int Y) {

	//if (TerrainMap[Y][X] == '-' && StructureMap[Y][X] == '-')
		//return true;
	//else:
	return false;
}