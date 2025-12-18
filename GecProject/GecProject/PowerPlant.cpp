#include "PowerPlant.h"
#include "AnimDataStruct.h"

PowerPlant::PowerPlant(Graphics& WorldGraphics, GameDataStruct& GameData)
{
	Cost = 100;	//Cheesy, but it *should* work. Keyword being should.
	WorldGraphics.AddAnimation("Idle", AnimData{ "PowerPlantIdle", 11, true, false, sf::seconds(1.0f / 10.0f) }, this);
	WorldGraphics.ChangeAnimation("Idle", this);
}

void PowerPlant::StructureBuild(GameDataStruct& GameData)
{
	GameData.Power += PowerProduction;
}
void PowerPlant::StructureTick(GameDataStruct& GameData)
{
	//DoNothing
}
