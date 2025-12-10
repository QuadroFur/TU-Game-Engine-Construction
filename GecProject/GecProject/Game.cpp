#include "Game.h"
#include "AnimDataStruct.h"

void World::WindowEvents()
{
	while (SFEvent = Window->pollEvent())
	{
		if (SFEvent->is<sf::Event::Closed>())
			this->Window->close();
	}
}
void World::Run()
{
	LoadGraphics();
	StepGraphics();
}
void World::LoadGraphics()
{
	Window = new sf::RenderWindow(sf::VideoMode({ 800, 800 }), "GEC");
	WorldGraphics.Addtexture("ZombieIdle", "Data/Textures/MaleZombie/idle_combined.png");
	WorldGraphics.Addtexture("PlaceSquare", "Data/Textures/Other/Selector.png");
	Player = new Actor;
	WorldGraphics.AddAnimation("Idle", AnimData{ "ZombieIdle", 15, false, true, sf::Time(sf::seconds(1.0f / 15.0f))}, Player);
	WorldGraphics.ChangeAnimation("Idle", Player);
	WorldGraphics.MakeRenderable("Zombie", Player);
	MainCamera = new Camera(WorldGraphics);
	MainCamera->SetView(*Window);
	return;
}
void World::StepGraphics()
{
	while (Window->isOpen())
	{
		WindowEvents();
		Window->clear();
		MainCamera->MoveCamera();
		MainCamera->SetView(*Window);
		MainCamera->ChangeState(); //Move out into a StepWorld function
		MainCamera->StepCamera(WorldGraphics, *Window);
		WorldGraphics.Render(*Window, Clock);
		Window->display();
	}
	return;
}
World::World() {}
World::~World()
{
	delete Player;
	delete Window;
}