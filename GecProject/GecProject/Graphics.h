#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class Graphics
{
private:
	std::unordered_map<std::string, sf::Sprite*> Actor2DMap;
	std::unordered_map<std::string, sf::Texture*> TextureMap;
public:
	bool LoadTexture(const std::string Filename, const std::string Name);

	void RenderActor(const std::string& ActorName, const std::string& SetName, int FrameNum, const sf::RenderWindow& Window);
};