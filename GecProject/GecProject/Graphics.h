#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include "AnimDataStruct.h"
#include "Actor.h"

class Graphics
{

private:
	std::unordered_map<std::string, sf::Texture*> TextureMap;
	std::unordered_map<std::string, Actor*> Renderable; //MUST BE A POINTER -> Graphics.cpp ln 61.
public:
	bool Addtexture(std::string TextureName, std::string Path);
	bool AddAnimation(std::string AnimationName, AnimData AnimationData, Actor* Actor);
	bool ChangeAnimation(std::string AnimationName, Actor* Actor);
	bool MakeRenderable(std::string ActorName, Actor* RenderableActor);
	bool RemoveRenderable(std::string ActorName);
	void Render(sf::RenderWindow& Window, sf::Clock& Clock);

	~Graphics();
};