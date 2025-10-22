#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "AnimationSetData.h"

class Character2D;

class Graphics
{
private:
	std::unordered_map<std::string, Character2D*> Character2DMap;
	std::unordered_map<std::string, sf::Texture*> TextureMap;
public:
	bool LoadTexture(const std::string Filename, const std::string Name);
	bool CreateChar2D(const std::string& Name);
	bool AddAnimationSet(const std::string& SetName, const std::string& CharName, const AnimationSetData& SetData);
};