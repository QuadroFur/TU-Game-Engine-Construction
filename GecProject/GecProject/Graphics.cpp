#include "Graphics.h"
#include <iostream>
#include "Character2D.h"

//ANIMATION HANDLING
//
//	Handle animation playing in Graphics.CPP, but change the loaded anim in the Character, to avoid passing states.
//	State machine in Character, will then call the animation changes. Naming conventions to be used for the animations,
//	such as Zombie_Walk, or Zombie_Idle. Each type of character will have their own states to change to.
//
//	Base Character state machine will have Idle, Walk, and Death. State machine is virtual, so can be overriden by
//	other classes inheriting off Character.
//

//COLLISION HANDLING
//
//	Either as it's own class, or as a part of Graphics?
//	Needs to be able to support at least Square and Circle. Circle for AOE.

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
//Maybe split into seperate functions. One for loading the texture, and another for animations, positions and other dynamic elements. 
void Graphics::Render(const std::string& Char2DName, sf::Vector2f Position, sf::Vector2f Scale, const std::string AnimSetName)
{

	if (Character2DMap.find(Char2DName) == Character2DMap.end() || Character2DMap[Char2DName]->AnimSetData.find(AnimSetName) == Character2DMap[Char2DName]->AnimSetData.end())
	{
		std::cerr << "No Character2D or Animation Set found when rendering! >L43 >Graphics.cpp";
		return;
	}
	Character2D* Char = Character2DMap[Char2DName];
	Char->Sprite->setTexture(*Char->AnimSetData[AnimSetName].Texture);
	Char->Sprite->setPosition(Position);
	Char->Sprite->setScale(Scale);

	//Top-Left : Size
	if (Char->AnimSetData[AnimSetName].SetData.Orentation == false)
	{
		//Calculate Frame Size (width), by size of texture / number of frames
		int FrameSizeX = Char->AnimSetData[AnimSetName].Texture->getSize().x ;
		int FrameSizeY = Char->AnimSetData[AnimSetName].Texture->getSize().y / Char->AnimSetData[AnimSetName].SetData.NumFrames;
		int TopCorner = FrameSizeY * Char->FrameNumber; //Top corner is size of 1 frame multiplied by the frame number.
		Char->Sprite->setTextureRect(sf::IntRect({ 0, TopCorner }, { FrameSizeX, FrameSizeY }));
	}
	else if (Char->AnimSetData[AnimSetName].SetData.Orentation == true)
	{
		int FrameSizeX = Char->AnimSetData[AnimSetName].Texture->getSize().x / Char->AnimSetData[AnimSetName].SetData.NumFrames;
		int FrameSizeY = Char->AnimSetData[AnimSetName].Texture->getSize().y;
		int TopCorner = FrameSizeX * Char->FrameNumber;
		Char->Sprite->setTextureRect(sf::IntRect({ TopCorner, 0 }, { FrameSizeX, FrameSizeY }));
	}
	//When FrameSizeY value is moved into the IntRect, an error occurs due to the types being different.
	//Seems to be due to tge IntRect taking an int Vector2i, but the getSize supplying a unsigned int Vector2u.
	//C++ does not seem to be able to convert the getSize to a standard int (because it doesn't know the type?).
	//Works fine when in a dedicated variable though.

	if (Char->FrameNumber < Char->AnimSetData[AnimSetName].SetData.NumFrames - 1)
	{
		Char->FrameNumber++;
	}
	else
	{
		Char->FrameNumber = 0;
	}
}
void Graphics::Draw(sf::RenderWindow& Window)
{
	for (auto& i : Character2DMap)
	{
		if (i.second->Sprite != nullptr)
			Window.draw(*i.second->Sprite);
	}
}