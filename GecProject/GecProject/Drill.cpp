#include "Drill.h"
#include "AnimDataStruct.h"
#include <iostream>

Drill::Drill(Graphics& WorldGraphics, GameDataStruct& GameData)
{
	Cost = 200;
	WorldGraphics.AddAnimation("Idle", AnimData{ "DrillIdle", 1, true, true, sf::seconds(1.0f / 24.0f) }, this);
	WorldGraphics.ChangeAnimation("Idle", this);
}
void Drill::StructureBuild(GameDataStruct& GameData)
{
	std::cout << "" << std::endl;
	//GameData.Resources += RecourceProduction;	//Broken due to infinite loop of cost and gain.
}
void Drill::StructureTick(GameDataStruct& GameData, sf::Clock& Clock)
{
	sf::Time CurrentTime = Clock.getElapsedTime();
	if (CurrentTime - TickStartTime >= TickRate)
	{
		TickStartTime = CurrentTime;
		GameData.Resources += RecourceProduction;
	}
}