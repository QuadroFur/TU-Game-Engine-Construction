#pragma once
//#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Graphics.h"
#include "Camera.h"
#include "Actor.h"
#include "World.h"
#include "Unit.h"
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
	sf::Time TickStartTime{ sf::Time::Zero };
	sf::Time TickTime{ sf::seconds(5) };

	std::unordered_map<std::string, Unit*>UnitList;

	World GameWorld;

	GameDataStruct GameData{500, 0};

	void LoadGraphics();
	void StepGraphics();
	void StepGameplay();
	void WindowEvents();

	Actor* Player{ nullptr };
};