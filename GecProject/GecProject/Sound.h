#pragma once
#include <unordered_map>
#include <string>
#include <SFML/Audio.hpp>

class Sound
{
private:
	std::unordered_map<std::string, sf::SoundBuffer*> SFX;
	std::unordered_map<std::string, std::string> Tracks;
public:
	bool LoadSound(std::string SoundName, std::string Path);
	bool LoadTrack(std::string TrackName, std::string Path);

	bool PlaySound(std::string SoundName);
	~Sound();
};