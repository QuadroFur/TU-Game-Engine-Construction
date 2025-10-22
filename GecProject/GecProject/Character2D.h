#pragma once

#include "AnimationSetData.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

struct AnimSet
{
	AnimationSetData SetData;
	sf::Texture* Texture{ nullptr };
};

class Character2D
{
//private:
public:

	std::unordered_map<std::string, AnimSet> AnimSetData; //Moved from Private to access in graphics.

	sf::Sprite* Sprite{ nullptr };
	void AddAnimationSet(const std::string& Name, const AnimationSetData& SetData, sf::Texture* Texture);
};