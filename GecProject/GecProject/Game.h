#pragma once
//#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Camera.h"
#include "Actor.h"
#include "World.h"
#include "GameData.h"

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

	GameDataStruct GameData{500, 0};

	void LoadGraphics();
	void StepGraphics();
	void StepGameplay();
	void WindowEvents();

	Actor* Player{ nullptr };
};