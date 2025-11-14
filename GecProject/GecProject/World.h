#pragma once

#include "Graphics.h"
#include "Player.h"
#include "Collider.h"

class World
{
public:
	World();
	virtual ~World();

	void Run();
	void render();
	void UpdateEvents();
	void endApplication(); 
	void updatedt(); 
private:

	void initWindow();
	void initGraphics(); 

	sf::RenderWindow* Window = nullptr; 
	std::optional<sf::Event> sfEvent; 
	sf::Clock dtClock;
	float deltaTime = 0;
	//Graphics setup
	Graphics* MainGraphics = new Graphics;
	sf::RenderWindow window; //(sf::VideoMode({ 800, 600 }), "GEC Start Project"); 

	Player NewPlayer;
	Collider ActorCollider;
	sf::Time Time = sf::milliseconds(50);

};

