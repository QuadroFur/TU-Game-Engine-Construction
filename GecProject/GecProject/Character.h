#pragma once
#include "Graphics.h"

class Character : public Actor
{
public:
	
	enum CharacterStates {
		Idle,
		Moving,
		Attacking,
		Gathering,
		Dead
	};
	enum CharacterDirections {
		Forward,
		Backward,
		Left,
		Right
	};
	
	CharacterStates CharState = Idle;
	CharacterDirections Direction = Right;

	int MovementSpeed = 10;

	virtual void MoveCharacter();
	virtual void UpdateCharacterState(Graphics& Graphics) = 0;
};