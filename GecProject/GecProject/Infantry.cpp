#include "Infantry.h"
#include <iostream>

bool Infantry::MoveToPosition(sf::Vector2f Position, bool IsAttackMove, World& GameWorld)
{
    if (CharState != Dead || CharState != Gathering)
    {
        if (IsAttackMove == false)
        {
            CharState == Moving;
            do {
				int XDir = this->Position.x - Position.x;
				int YDir = this->Position.y - Position.y;

                if (XDir != 0)
                {
                    if (XDir > 0)
                    {
                        if (GameWorld.CheckFreeSpace(this->Position.x - GameWorld.GetGridSize(), this->Position.y))
                        {
                            this->Position = sf::Vector2f(this->Position.x - GameWorld.GetGridSize(), this->Position.y);
                        }
                    }
                    else if (XDir < 0)
                    {
                        if (GameWorld.CheckFreeSpace(this->Position.x + GameWorld.GetGridSize(), this->Position.y))
                        {
                            this->Position = sf::Vector2f(this->Position.x + GameWorld.GetGridSize(), this->Position.y);
                        }
					}
                }
                else
                {
                    if (YDir > 0)
                    {
						if (GameWorld.CheckFreeSpace(this->Position.x, this->Position.y - GameWorld.GetGridSize()))
                        {
                            this->Position = sf::Vector2f(this->Position.x, this->Position.y - GameWorld.GetGridSize());
                        }
                    }
                    else if (YDir < 0)
                    {
                        if (GameWorld.CheckFreeSpace(this->Position.x, this->Position.y + GameWorld.GetGridSize()))
                        {
                            this->Position = sf::Vector2f(this->Position.x, this->Position.y - GameWorld.GetGridSize());
                        }
                    }
                }
                if (GameWorld.CheckFreeSpace(Position.x, Position.y))
                {
                    this->Position = Position;
                }
            } while (this->Position != Position && CharState == Moving);
        }
    }
    else
    {
        std::cout << "State incompatible with movement command! Skipping..." << std::endl;
    }
    return false;
}
