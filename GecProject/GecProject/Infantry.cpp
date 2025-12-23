#include "Infantry.h"
#include <iostream>

bool Infantry::MoveToPosition(sf::Vector2f Position,bool IsAttackMove, World& GameWorld)
{
    if (CharState != Dead || CharState != Gathering)
    {
        if (IsAttackMove == false)
        {
            
        }
    }
    else
    {
        std::cout << "State incompatible with movement command! Skipping..." << std::endl;
    }
    return false;
}
