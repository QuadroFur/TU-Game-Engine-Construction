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
	GameGraphics.Addtexture("ZombieIdle", "Data/Textures/MaleZombie/idle_combined.png");
	GameGraphics.Addtexture("PlaceSquare", "Data/Textures/Other/Selector.png");
	Player = new Actor;
	GameGraphics.AddAnimation("Idle", AnimData{ "ZombieIdle", 15, false, true, sf::Time(sf::seconds(1.0f / 120.0f))}, Player);
	GameGraphics.ChangeAnimation("Idle", Player);
	GameGraphics.MakeRenderable("Zombie", Player);
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