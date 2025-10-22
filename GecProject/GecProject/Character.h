#pragma once
#include "Actor.h"
#include <string>
#include "AnimationSetData.h"

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

    sf::Sprite* Character2D = nullptr;

    States CharState = Idle;

    sf::Texture IdleTexture;
    sf::Texture WalkingTexture;

    int TextureFrame = 0;
    float MovementSpeed = 10.0f;
    Directions Direction = Right;

    void GameTick() override;
    bool BeginOverlap(Object Obj) override;
    bool EndOverlap(Object Obj) override;

    void MoveCharacter();
    void UpdateCharState();

};

