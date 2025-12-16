#include "Game.h"
#include "AnimDataStruct.h"

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
Game::Game() {}
Game::~Game()
{
	delete Player;
	delete Window;
}