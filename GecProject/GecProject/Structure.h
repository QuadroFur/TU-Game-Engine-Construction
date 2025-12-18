#pragma once
#include "Actor.h"
#include "GameData.h"
#include "Collider.h"

class Structure :
    public Actor
{

public:
    int Health = 100;
    int Cost{ 0 };
    Collider StructureBounds;

    virtual void StructureBuild(GameDataStruct& GameData) = 0; //Runs once, when the structure is first made.
    virtual void StructureTick(GameDataStruct& GameData) = 0; //Runs every frame, to step the structure.
};