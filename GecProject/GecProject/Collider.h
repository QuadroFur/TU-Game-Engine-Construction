#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
private:
	sf::FloatRect BoundingBox;

public:
	Collider(sf::FloatRect Bounds);
	Collider();

	void AddBoundingBox(sf::FloatRect Bounds);
	bool CheckCollision(sf::FloatRect OtherBound);
};