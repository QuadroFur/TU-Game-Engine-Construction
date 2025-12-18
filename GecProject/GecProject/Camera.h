#pragma once
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Graphics.h"
#include "Actor.h"
#include "World.h"

class Camera
{
private:
	sf::View MainCamera;
	Actor PlaceSquare;

public:

	enum States {
		Move,
		Build,
		Command
	};

public:

	Camera(Graphics& WorldGraphics);

	States CameraState{ Move };
	bool IsCameraLocked = false;

	void ChangeState();
	void SetView(sf::RenderWindow& Window);
	void MoveCamera();
	void StepCamera(Graphics& WorldGraphics, sf::RenderWindow& Window, World& GameWorld);
};