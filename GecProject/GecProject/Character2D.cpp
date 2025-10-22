#include "Character2D.h"

void Character2D::AddAnimationSet(const std::string& Name, AnimationSetData& SetData, sf::Texture* Texture)
{
	if (AnimSetData.find(Name) != AnimSetData.end())
	{
		AnimSetData[Name] = AnimSet{ SetData, Texture };
		return;
	}
	else { return; }
}