#include "World.h"

World::World()
{
	this->initWindow();
	this->initGraphics();
}

World::~World()
{
	delete this->Window;
}

void World::Run()
{
	while (this->Window->isOpen())
	{
		updatedt();
		UpdateEvents();
		render(); 
	}
}

void World::render()
{
	this->Window->clear();
	MainGraphics->Render("Zombie", NewPlayer.Position, sf::Vector2f(1, 1), "Idle");
	

	ActorCollider.CheckForCollision(NewPlayer);

	MainGraphics->Draw(*Window);
	NewPlayer.KeyInput();

	
	this->Window->display(); 
	sf::sleep(Time);
}

void World::UpdateEvents()
{
	while (this->sfEvent = this->Window->pollEvent())
	{
		if (sfEvent->is<sf::Event::Closed>())
			this->Window->close();
    }
}

void World::endApplication()
{

}

void World::updatedt()
{
	this->deltaTime = this->dtClock.restart().asSeconds();
}

void World::initWindow()
{
	this->Window = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "GEC Start Project"); 
}

void World::initGraphics()
{


	if (!MainGraphics->LoadTexture("Data/Textures/MaleZombie/idle_combined.png", "ZombieIdle"))
		return ;
	if (!MainGraphics->LoadTexture("Data/Textures/MaleZombie/walk_combined.png", "ZombieWalk"))
		return ;

	MainGraphics->CreateChar2D("Zombie");
	MainGraphics->AddAnimationSet("Idle", "Zombie", AnimationSetData{ "ZombieIdle", 15, false, true });
	MainGraphics->AddAnimationSet("Walk", "Zombie", AnimationSetData{ "ZombieWalk", 10, false, true });

	MainGraphics->CreateChar2D("Zombie2");
	MainGraphics->AddAnimationSet("Idle", "Zombie2", AnimationSetData{ "ZombieIdle", 15, false, true });
	MainGraphics->AddAnimationSet("Walk", "Zombie2", AnimationSetData{ "ZombieWalk", 10, false, true });

	ActorCollider.ColliderX = 200;
	ActorCollider.ColliderY = 200;
	ActorCollider.ColliderWidth = 20;
	ActorCollider.ColliderHeight = 20;
}
