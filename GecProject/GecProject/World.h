#pragma once
#include <string>

class World
{
private:

	char TerrainMap[1000][1000];
	char StructureMap[1000][1000];
	//float PathMap[1000][1000];

public:

	void GenerateLevel(int MapSize);
	void LoadLevel(std::string Path);

	bool CheckFreeSpace(int X, int Y);
};

