#include "Graphics.h"

bool Graphics::LoadTexture(std::string Filename, std::string Name) {
	if (TextureMap.find(Name) == TextureMap.end())
	{
		sf::Texture* Texture = new sf::Texture;
		if (!Texture->loadFromFile(Filename))
		{
			return false;
		}
		TextureMap[Name] = Texture;
		return true;
	}
}

void Graphics::RenderActor(const std::string& ActorName, const std::string& SetName, int FrameNum, const sf::RenderWindow& Window)
{
	if (Actor2DMap.find(ActorName) == Actor2DMap.end() || TextureMap.find(SetName) == TextureMap.end())
	{
		return;
	}
}