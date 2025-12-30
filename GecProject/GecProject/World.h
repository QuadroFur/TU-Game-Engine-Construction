#pragma once
#include <string>
#include "GameData.h"
#include "Graphics.h"
#include "Structure.h"
#include <unordered_map>
#include <SFML/System/Vector2.hpp>

class World
{
private:

	char WorldMap[200][200];

	int GridSize = 32;
	std::unordered_map<std::string, Structure*>StructureList;

public:
	void GenerateLevel(int MapSize);
	void LoadLevel(std::string Path);
	bool PlaceStructure(Graphics& WorldGraphics, sf::Vector2f Position, Structure* Structure, GameDataStruct& GameData);

	bool CheckFreeSpace(int X, int Y);
	sf::Vector2f GetGridPosition(sf::Vector2f Pos);
	int GetGridSize() { return GridSize; }

	void GameTick(GameDataStruct& GameData);
};