#include "Character.h"

void Character::UpdateCharState() {
	/*if (CharState == Idle) {
		Texture = IdleTexture;
		TextureFrame = 0;
	}
	else if (CharState == Walking) {
		Texture = WalkingTexture;
		TextureFrame = 0;
	}*/
}
void Character::MoveCharacter() {
	if (Direction == Directions::Forward) {
		Position.y = Position.y - MovementSpeed;
	}
	else if (Direction == Directions::Backward) {
		Position.y = Position.y + MovementSpeed;
	}
	else if (Direction == Directions::Left) {
		Position.x = Position.x - MovementSpeed;
	}
	else if (Direction == Directions::Right) {
		Position.x = Position.x + MovementSpeed;
	}
}
void Character::GameTick() {};
bool Character::BeginOverlap(Object Obj) {
	return false;
};
bool Character::EndOverlap(Object Obj) {
	return false;
};