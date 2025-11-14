#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
class Actor :
    public Object
{

public:

    sf::Vector2f Position;
    sf::Vector2f Size;

    virtual bool BeginOverlap(Object Obj);
    virtual bool EndOverlap(Object Obj);

    virtual void GameTick();
    virtual void Draw(sf::RenderWindow& Window);
};