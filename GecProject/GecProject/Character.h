#pragma once
#include "Actor.h"
#include <string>
#include "Graphics.h"

class Character :
    public Actor
{

public:

    enum States {
        Idle,
        Walking
    };

    enum Directions {
        Forward,
        Backward,
        Left,
        Right
    };

    States CharState = Idle;

    int TextureFrame = 0;
    float MovementSpeed = 10.0f;
    Directions Direction = Right;

    void GameTick() override;

    void MoveCharacter();
    virtual void UpdateCharState(Graphics& Graphics);

    Character();
    Character(std::vector<std::string>Textures); //Pass list of textures to load, and load one by one.
};

