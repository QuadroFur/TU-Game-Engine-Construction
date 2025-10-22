#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
class Actor :
    public Object
{

public:

    sf::Vector2f Position;
    sf::Vector2f Size;

    virtual bool BeginOverlap(Object Obj) = 0;
    virtual bool EndOverlap(Object Obj) = 0;

    virtual void GameTick() = 0;
    virtual void Draw(sf::RenderWindow& Window);

};