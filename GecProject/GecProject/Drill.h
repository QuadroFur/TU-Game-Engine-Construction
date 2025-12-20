#pragma once
#include "Structure.h"
#include "GameData.h"
#include "Graphics.h"

class Drill :
    public Structure
{
private:
    int RecourceProduction{ 100 };
    sf::Time TickStartTime{ sf::Time::Zero };
    sf::Time TickRate{ sf::seconds(10.0f) };
public:
    Drill(Graphics& WorldGraphics, GameDataStruct& GameData);

    void StructureBuild(GameDataStruct& GameData) override;
    void StructureTick(GameDataStruct& GameData, sf::Clock Clock) override;
};

