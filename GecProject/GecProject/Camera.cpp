#include "Camera.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

Camera::Camera(Graphics& WorldGraphics)
{
	//{CENTRE}, {SIZE}
	MainCamera = sf::View({ 400, 400 }, {800, 800});
	WorldGraphics.AddAnimation("PlaceSquare", AnimData{ "PlaceSquare", 1, false, false }, &PlaceSquare);
	WorldGraphics.ChangeAnimation("PlaceSquare", &PlaceSquare);
	WorldGraphics.MakeRenderable("PlaceSquare", &PlaceSquare);
}
void Camera::ChangeState()
{
	if (IsCameraLocked == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {
			CameraState = Build;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
			CameraState = Move;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V)) {
			CameraState = Command;
		}
	}
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
void Camera::StepCamera(Graphics& WorldGraphics, sf::RenderWindow& Window, World& GameWorld)
{
	sf::Vector2i MousePos = sf::Mouse::getPosition(Window);
	sf::Vector2f WorldPos = Window.mapPixelToCoords(MousePos);
	PlaceSquare.Position = GameWorld.GetGridPosition(WorldPos);
}