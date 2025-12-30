#pragma once
#include "Graphics.h"

class Unit : public Actor
{
public:
	
	enum UnitStates {
		Idle,
		Moving,
		Attacking,
		Gathering,
		Dead
	};
	enum UnitDirections {
		Forward,
		Backward,
		Left,
		Right
	};
	
	UnitStates CharState = Idle;
	UnitDirections Direction = Right;

	int MovementSpeed = 10;
	sf::Vector2f TargetPosition{ 0, 0 }; //Use this for movement calculations per game tick.

	virtual void MoveUnit();
	virtual void UpdateUnitState(Graphics& Graphics) = 0;
};