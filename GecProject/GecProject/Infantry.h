#pragma once
#include "Character.h"
#include "World.h" //Already has Vector2f included, so passes into this.

class Infantry :
    public Character
{

private:
    int SightRadius{ 4 };

public:
    bool MoveToPosition(sf::Vector2f Position, bool IsAttackMove, World& GameWorld);

};

