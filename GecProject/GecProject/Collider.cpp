#include "Collider.h"
#include <optional>

Collider::Collider(sf::FloatRect Bounds)
{
	BoundingBox = Bounds;
}

Collider::Collider()
{
}

void Collider::AddBoundingBox(sf::FloatRect Bounds)
{
	BoundingBox = Bounds;
}

bool Collider::CheckCollision(sf::FloatRect OtherBound)
{
	if (const std::optional intersection = BoundingBox.findIntersection(OtherBound))
		return true;
	return false;
}
