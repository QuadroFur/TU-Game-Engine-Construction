#pragma once
//#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Camera.h"
#include "Actor.h"
#include "World.h"

class Game
{

public:
	void Run();

	Game();
	~Game();

private:

	Graphics GameGraphics;
	sf::RenderWindow* Window{ nullptr };
	Camera* MainCamera{ nullptr };
	std::optional<sf::Event> SFEvent;
	sf::Clock Clock;

	World GameWorld;

	void LoadGraphics();
	void StepGraphics();
	void WindowEvents();

	Actor* Player{ nullptr };
};