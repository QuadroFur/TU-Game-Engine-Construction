#pragma once
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Graphics.h"

class Camera
{
private:
	sf::View MainCamera;

	enum States {
		Move,
		Build,
		Command
	};

public:
	Camera();

	States CameraState{ Move };
	bool IsCameraLocked = false;

	void ChangeState();
	void SetView(sf::RenderWindow& Window);
	void MoveCamera();
};