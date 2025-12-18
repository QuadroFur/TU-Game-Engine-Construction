#include "Game.h"
#include <iostream>
#include "PowerPlant.h"

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
	StepGraphics();
}
void Game::LoadGraphics()
{
	Window = new sf::RenderWindow(sf::VideoMode({ 800, 800 }), "GEC");
	GameGraphics.Addtexture("PowerPlantIdle", "Data/Textures/Structures/Power Plant.png");
	GameGraphics.Addtexture("PlaceSquare", "Data/Textures/Other/Selector.png");
	MainCamera = new Camera(GameGraphics);
	MainCamera->SetView(*Window);
	return;
}
void Game::StepGraphics()
{
	while (Window->isOpen())
	{
		WindowEvents();
		StepGameplay();
		Window->clear();
		MainCamera->MoveCamera();
		MainCamera->SetView(*Window);
		MainCamera->ChangeState(); //Move out into a StepWorld function
		MainCamera->StepCamera(GameGraphics, *Window, GameWorld);
		GameGraphics.Render(*Window, Clock);
		Window->display();
	}
	return;
}
void Game::StepGameplay()
{
	sf::Vector2i MousePos = sf::Mouse::getPosition(*Window);
	sf::Vector2f WorldPos = Window->mapPixelToCoords(MousePos);
	if (MainCamera->CameraState == MainCamera->Build && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		PowerPlant* NewStructure{ nullptr };
		NewStructure = new PowerPlant(GameGraphics, GameData);
		bool out = GameWorld.PlaceStructure(GameGraphics, WorldPos, NewStructure, GameData);
		if (!out)
		{
			std::cerr << "Structure did not place!" << std::endl;
		}
		std::cout << "Resources " + GameData.Resources << std::endl;
		std::cout << "Power " + GameData.Power << std::endl;
	}
}

//Constructor and Destructor
Game::Game() {}
Game::~Game()
{
	delete Player;
	delete Window;
}