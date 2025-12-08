#include "Graphics.h"
#include "iostream"

bool Graphics::Addtexture(std::string TextureName, std::string Path)
{
	if (TextureMap.find(TextureName) != TextureMap.end())
	{
		std::cerr << "Texture with name already exists!" << std::endl;
		return false;
	}
	sf::Texture* Texture = new sf::Texture;
	if (!Texture->loadFromFile(Path))
	{
		std::cerr << "Bad path for texture!" << std::endl;
		delete Texture;
		return false;
	}
	TextureMap[TextureName] = Texture;
	return true;
}
bool Graphics::AddAnimation(std::string AnimationName, AnimData AnimationData, Actor* Actor)
{
	if (Actor->AnimationSets.find(AnimationName) != Actor->AnimationSets.end())
	{
		std::cerr << "Animation with name already exists!" << std::endl;
		return false;
	}
	if (TextureMap.find(AnimationData.TextureName) == TextureMap.end())
	{
		std::cerr << "Unable to find texture for animation!" << std::endl;
		return false;
	}
	Actor->AnimationSets[AnimationName] = AnimationData;
	return true;
}
bool Graphics::ChangeAnimation(std::string AnimationName, Actor* Actor)
{
	if (Actor->AnimationSets.find(AnimationName) == Actor->AnimationSets.end())
	{
		std::cerr << "Unable to find animation for that actor!" << std::endl;
		return false;
	}
	Actor->LoadedAnimData = Actor->AnimationSets[AnimationName];
	if (Actor->Sprite == nullptr)
	{
		Actor->Sprite = new sf::Sprite(*TextureMap[Actor->LoadedAnimData.TextureName]);
	}
	else
	{
		Actor->Sprite->setTexture(*TextureMap[Actor->LoadedAnimData.TextureName]);
	}
	return true;
}
bool Graphics::MakeRenderable(std::string ActorName, Actor* RenderableActor)
{
	if (Renderable.find(ActorName) != Renderable.end()) {
		std::cerr << "Actor with name already exists!" << std::endl;
		return false;
	}
	Renderable[ActorName] = RenderableActor;
	return true;
}
bool Graphics::RemoveRenderable(std::string ActorName)
{
	if (Renderable.find(ActorName) == Renderable.end())
	{
		std::cerr << "Actor with name not found!" << std::endl;
		return false;
	}
	Renderable.erase(ActorName);
}

//KEEP AT THE BOTTOM
void Graphics::Render(sf::RenderWindow& Window) //DO NOT CALL OUTSIDE OF WORLD FUNCTION
{

	for (auto& i : Renderable) {

		if (i.second->LoadedAnimData.NumFrames > 1) {
			if (i.second->LoadedAnimData.Orentation == false)
			{
				int FrameSizeX = TextureMap[i.second->LoadedAnimData.TextureName]->getSize().x;
				int FrameSizeY = TextureMap[i.second->LoadedAnimData.TextureName]->getSize().y / i.second->LoadedAnimData.NumFrames;
				int TopCorner = FrameSizeY * i.second->RenderFrameNum;
				i.second->Sprite->setTextureRect(sf::IntRect({ 0, TopCorner }, { FrameSizeX, FrameSizeY }));
			}
			else
			{
				int FrameSizeX = TextureMap[i.second->LoadedAnimData.TextureName]->getSize().x / i.second->LoadedAnimData.NumFrames;
				int FrameSizeY = TextureMap[i.second->LoadedAnimData.TextureName]->getSize().y;
				int TopCorner = FrameSizeX * i.second->RenderFrameNum;
				i.second->Sprite->setTextureRect(sf::IntRect({ TopCorner, 0 }, { FrameSizeX, FrameSizeY }));
			}
			if (i.second->RenderFrameNum < i.second->LoadedAnimData.NumFrames - 1)
			{
				i.second->RenderFrameNum++;
			}
			else
			{
				i.second->RenderFrameNum = 0;
			}
		}
		i.second->Sprite->setPosition(i.second->Position);
		i.second->Sprite->setScale(i.second->Scale);
		Window.draw(*i.second->Sprite);
	}
}
Graphics::~Graphics() {
	TextureMap.clear();
	Renderable.clear();
}