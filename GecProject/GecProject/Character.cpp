#include "Character.h"

void Character::MoveCharacter()
{
	if (Direction == Forward) {
		Position.y = Position.y - MovementSpeed;
	}
	else if (Direction == Backward) {
		Position.y = Position.y + MovementSpeed;
	}
	else if (Direction == Left) {
		Position.x = Position.x + MovementSpeed;
	}
	else if (Direction == Right) {
		Position.x = Position.x - MovementSpeed;
	}
}