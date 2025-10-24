#include "Character2D.h"

void Character2D::AddAnimationSet(const std::string& Name, const AnimationSetData& SetData, sf::Texture* Texture)
{
	if (AnimSetData.find(Name) == AnimSetData.end())
	{
		AnimSetData[Name] = AnimSet{ SetData, Texture };

		if (Sprite == nullptr)
			Sprite = new sf::Sprite(*Texture);

		return;
	}
	else { return; }
}