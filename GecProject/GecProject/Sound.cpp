#include "Sound.h"
#include <iostream>

bool Sound::LoadSound(std::string SoundName, std::string Path)
{
	if (SFX.find(SoundName) != SFX.end()) {
		std::cerr << "Sound with name already exists!" << std::endl;
		return false;
	}
	sf::SoundBuffer* Buffer = new sf::SoundBuffer;
	if (!Buffer->loadFromFile(Path)) {
		std::cerr << "Unable to load sound from path!" << std::endl;
		delete Buffer;
		return false;
	}
	SFX[SoundName] = Buffer;
	return true;
}
bool Sound::LoadTrack(std::string TrackName, std::string Path)
{
	if (Tracks.find(TrackName) != Tracks.end()) {
		std::cerr << "Track with name already exists" << std::endl;
		return false;
	}
	sf::Music Music;
	if (!Music.openFromFile(Path)) {
		std::cerr << "Unable to load track from path!" << std::endl;
		return false;
	}
	Tracks[TrackName] = Path;
	return true;
}
bool Sound::PlaySound(std::string SoundName) {
	if (SFX.find(SoundName) == SFX.end()) {
		std::cerr << "No sound with name found!" << std::endl;
		return false;
	}
	sf::Sound Sound(*SFX[SoundName]);
	Sound.play();
	return true;
}