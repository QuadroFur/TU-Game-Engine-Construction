#pragma once
#include <SFML/Graphics.hpp>
#include "AnimDataStruct.h"

class Actor
{
private:
	std::string Name;
public:
	sf::Vector2f Position{100, 100};
	sf::Vector2f Scale{1, 1};

	sf::Sprite* Sprite{ nullptr };
	AnimData LoadedAnimData;
	int RenderFrameNum{ 0 };

	std::unordered_map<std::string, AnimData> AnimationSets;
};