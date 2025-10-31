#pragma once
#include "Actor.h"
#include <string>

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
    bool BeginOverlap(Object Obj) override;
    bool EndOverlap(Object Obj) override;

    void MoveCharacter();
    void UpdateCharState();

    Character();
    Character(std::vector<std::string>Textures); //Pass list of textures to load, and load one by one.
};

