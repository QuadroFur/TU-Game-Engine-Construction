#include "PowerPlant.h"
#include "AnimDataStruct.h"

PowerPlant::PowerPlant(Graphics& WorldGraphics)
{
	WorldGraphics.AddAnimation("Idle", AnimData{ "PowerPlantIdle", 11, true, false, sf::seconds(1.0f / 10.0f) }, this);
	WorldGraphics.ChangeAnimation("Idle", this);
}