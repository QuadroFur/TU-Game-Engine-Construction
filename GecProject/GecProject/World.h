#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

class World
{
private:

	//char TerrainMap[1000][1000];
	//char StructureMap[1000][1000];
	//float PathMap[1000][1000];

	int GridSize = 32;

public:
	void GenerateLevel(int MapSize);
	void LoadLevel(std::string Path);

	bool CheckFreeSpace(int X, int Y);
	sf::Vector2f GetGridPosition(sf::Vector2f Pos);
};