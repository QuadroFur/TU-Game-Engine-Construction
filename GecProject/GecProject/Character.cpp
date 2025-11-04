#include "Character.h"

void Character::UpdateCharState(Graphics& Graphics) {
	if (CharState == Idle)
	{
		//Change texture to Idle.
	}
	else if (CharState == Walking)
	{
		//Change texture to Walking.
	}
}
Character::Character()
{
}
Character::Character(std::vector<std::string>Textures) {

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