#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

class World
{
private:

	//char TerrainMap[1000][1000];
	//char StructureMap[1000][1000];
	//float PathMap[1000][1000];

	int GridSize = 20;

public:
	void GenerateLevel(int MapSize);
	void LoadLevel(std::string Path);

	bool CheckFreeSpace(int X, int Y);
	sf::Vector2f GetGridPosition(sf::Vector2f Pos) { return sf::Vector2f(Pos.x * GridSize, Pos.y * GridSize); };
};

