#include "Player.h"

//Keyboard input handling
void Player::KeyInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		Direction = Directions::Forward;
		MoveCharacter();
		if (CharState == States::Idle)	//Only switch the state and update if nessisary, or animation frame will reset.
		{
			CharState = Walking;
			//UpdateCharState();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		Direction = Directions::Backward;
		MoveCharacter();
		if (CharState == States::Idle)
		{
			CharState = Walking;
			//UpdateCharState();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		Direction = Directions::Left;
		MoveCharacter();
		if (CharState == States::Idle)
		{
			CharState = Walking;
			//UpdateCharState();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		Direction = Directions::Right;
		MoveCharacter();
		if (CharState == States::Idle)
		{
			CharState = Walking;
			//UpdateCharState();
		}
	}
	else
	{
		if (CharState == Walking)	//Only switch the state and update if nessisary, or animation frame will reset.
		{
			CharState = Idle;
			//UpdateCharState();
		}
	}
}