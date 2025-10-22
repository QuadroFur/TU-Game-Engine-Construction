#include "Graphics.h"
#include <iostream>
#include "Character2D.h"

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
bool Graphics::CreateChar2D(const std::string& Name) {
	Character2D* NewChar = new Character2D;
	Character2DMap[Name] = NewChar;
	return true;
}

bool Graphics::AddAnimationSet(const std::string& SetName, const std::string& CharName, const AnimationSetData& SetData)
{
	if (TextureMap.find(SetData.TextureName) == TextureMap.end())
	{
		std::cerr << "No texture found while adding anim set! L>21 >Graphics.cpp" << std::endl;
		return false;
	}
	if (Character2DMap.find(CharName) == Character2DMap.end())
	{
		std::cerr << "No sprite found while adding animation set. L>26 >Graphics.cpp" << std::endl;
		return false;
	}
	Character2DMap[CharName]->AddAnimationSet(SetName, SetData, TextureMap[SetData.TextureName]);
}
