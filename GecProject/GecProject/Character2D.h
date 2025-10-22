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
private:
	std::unordered_map<std::string, AnimSet> AnimSetData;
public:
	void AddAnimationSet(const std::string& Name, AnimationSetData& SetData, sf::Texture* Texture);
};