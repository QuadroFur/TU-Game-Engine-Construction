#pragma once
#include "Actor.h"
#include "Collider.h"

class Structure :
    public Actor
{

public:
    int Health = 100;
    Collider StructureBounds;

};