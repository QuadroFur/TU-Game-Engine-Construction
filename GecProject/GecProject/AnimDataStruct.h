#pragma once
#include <string>
#include <SFML/Graphics.hpp>

struct AnimData {
	std::string TextureName;
	int NumFrames{ 0 };
	bool Orentation = false;
	bool Looped = false;
};