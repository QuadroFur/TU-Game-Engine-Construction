#pragma once
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Camera
{
private:
	sf::View MainCamera;
public:
	Camera();

	bool IsCameraLocked = false;

	void SetView(sf::RenderWindow& Window);
	void MoveCamera();
};