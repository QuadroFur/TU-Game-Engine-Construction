#pragma once
#include "Structure.h"
#include "Graphics.h"
#include "GameData.h"

class PowerPlant :
    public Structure
{
private:
    int PowerProduction{ 10 };
public:
    PowerPlant(Graphics& WorldGraphics, GameDataStruct& GameData);
    void StructureBuild(GameDataStruct& GameData) override;
    void StructureTick(GameDataStruct& GameData, sf::Clock& Clock) override;
};

