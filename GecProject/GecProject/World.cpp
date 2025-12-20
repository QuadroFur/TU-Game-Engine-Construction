#include "World.h"
#include <cmath>
#include <iostream>

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

bool World::PlaceStructure(Graphics& WorldGraphics, sf::Vector2f WorldPosition, Structure* Structure, GameDataStruct& GameData)
{
	sf::Vector2f GridPosition = GetGridPosition(WorldPosition);
	//Structure Key == X.Y-NAME;
	std::string StructureKey = std::to_string(GridPosition.x) + '.' + std::to_string(GridPosition.y) + '-' + Structure->Name;
	if (StructureList.find(StructureKey) != StructureList.end() || GameData.Resources < Structure->Cost) {
		std::cerr << "Structure with key already exists or not enough resources!" << std::endl;
		delete Structure;
		return false;
	}
	Structure->Position = GridPosition;
	StructureList[StructureKey] = Structure;
	WorldMap[static_cast<int>(GridPosition.x)][static_cast<int>(GridPosition.y)];
	GameData.Resources -= Structure->Cost;
	Structure->StructureBuild(GameData);
	WorldGraphics.MakeRenderable(StructureKey, Structure);
	return true;
}

bool World::CheckFreeSpace(int X, int Y) {

	//if (TerrainMap[Y][X] == '-' && StructureMap[Y][X] == '-')
		//return true;
	//else:
	return false;
}

sf::Vector2f World::GetGridPosition(sf::Vector2f Pos)
{
	float PosX = Pos.x;
	float PosY = Pos.y;
	PosX = std::floor(PosX / GridSize) * GridSize;
	PosY = std::floor(PosY / GridSize) * GridSize;
	//PosX = PosX / GridSize * GridSize;
	//PosY = PosY / GridSize * GridSize;
	return sf::Vector2f(PosX, PosY);
}

void World::GameTick(GameDataStruct& GameData)
{
	for (auto& i : StructureList)
	{
		sf::Clock Clock;
		i.second->StructureTick(GameData, Clock);
	}
}