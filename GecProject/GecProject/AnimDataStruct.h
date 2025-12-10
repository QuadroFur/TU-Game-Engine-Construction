#pragma once
#include <string>
#include <SFML/System/Time.hpp>

struct AnimData {
	std::string TextureName;
	int NumFrames{ 0 };
	bool Orentation = false;
	bool Looped = false;
	sf::Time FrameTime{ sf::seconds(1.0f / 2.0f) }; //2 FPS default.
	sf::Time FrameStartTime{ sf::Time::Zero }; // Used as a base for frame time calc.
};