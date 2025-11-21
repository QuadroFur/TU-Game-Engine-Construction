#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Actor.h"

class World
{

public:
	void Run();

	World();
	~World();

private:

	Graphics WorldGraphics;
	sf::RenderWindow* Window{ nullptr };
	std::optional<sf::Event> SFEvent;

	sf::Clock Clock;

	void LoadGraphics();
	void StepGraphics();
	void WindowEvents();

	Actor* Player{ nullptr };
};