#include "Camera.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Camera::Camera()
{
	//{CENTRE}, {SIZE}
	MainCamera = sf::View({ 400, 400 }, {800, 800});
}

void Camera::SetView(sf::RenderWindow& Window)
{
	Window.setView(MainCamera);
}

void Camera::MoveCamera()
{
	if (IsCameraLocked == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			MainCamera.move(sf::Vector2f(0, 5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			MainCamera.move(sf::Vector2f(0, -5));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			MainCamera.move(sf::Vector2f(5, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			MainCamera.move(sf::Vector2f(-5, 0));
		}
		std::cerr << "Camera Pos: " << MainCamera.getCenter().x << " + " << MainCamera.getCenter().y << std::endl;
	}
}