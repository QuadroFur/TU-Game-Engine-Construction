#pragma once

#include <SFML/Graphics.hpp>
#include "Actor.h"

class Collider {

public:

	int ColliderX;
	int ColliderY;
	int ColliderWidth;
	int ColliderHeight;

	bool CheckForCollision(Actor& OtherActor);
};