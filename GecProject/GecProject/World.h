#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Camera.h"
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
	Camera MainCamera;
	std::optional<sf::Event> SFEvent;

	sf::Clock Clock;

	//char Map[1000][1000];

	void LoadGraphics();
	void StepGraphics();
	void WindowEvents();

	Actor* Player{ nullptr };
};