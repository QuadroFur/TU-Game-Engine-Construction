#include "Game.h"
#include <iostream>
#include "PowerPlant.h"
#include "Drill.h"

void Game::WindowEvents()
{
	while (SFEvent = Window->pollEvent())
	{
		if (SFEvent->is<sf::Event::Closed>())
			this->Window->close();
	}
}
void Game::Run()
{
	LoadGraphics();
	while (Window->isOpen())
	{
		WindowEvents();
		StepGameplay();
		StepGraphics();
	}
}
void Game::LoadGraphics()
{
	Window = new sf::RenderWindow(sf::VideoMode({ 800, 800 }), "GEC");
	GameGraphics.Addtexture("PowerPlantIdle", "Data/Textures/Structures/Power Plant.png");
	GameGraphics.Addtexture("DrillIdle", "Data/Textures/Structures/Drill.png");
	GameGraphics.Addtexture("PlaceSquare", "Data/Textures/Other/Selector.png");
	MainCamera = new Camera(GameGraphics);
	MainCamera->SetView(*Window);
	return;
}
void Game::StepGraphics()
{
	Window->clear();
	MainCamera->MoveCamera();
	MainCamera->SetView(*Window);
	GameGraphics.Render(*Window, Clock);
	Window->display();
}

void Game::StepGameplay()
{
	if (Window->hasFocus()) {

		MainCamera->ChangeState(); //Move out into a StepWorld function
		MainCamera->StepCamera(GameGraphics, *Window, GameWorld);

		sf::Vector2i MousePos = sf::Mouse::getPosition(*Window);
		sf::Vector2f WorldPos = Window->mapPixelToCoords(MousePos);
		if (MainCamera->CameraState == MainCamera->Build && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			Drill* NewStructure{ nullptr };
			NewStructure = new Drill(GameGraphics, GameData);
			bool out = GameWorld.PlaceStructure(GameGraphics, WorldPos, NewStructure, GameData);
			if (!out)
			{
				std::cerr << "Structure did not place!" << std::endl;
			}
			std::cout << "Resources " + std::to_string(GameData.Resources) << std::endl;
			std::cout << "Power " + std::to_string(GameData.Power) << std::endl;
		}
		GameWorld.GameTick(GameData, Clock);
	}
}

//Constructor and Destructor
Game::Game() {}
Game::~Game()
{
	delete Player;
	delete Window;
}