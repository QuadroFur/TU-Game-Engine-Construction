#pragma once
#include <string>

struct AnimData {
	std::string TextureName;
	int NumFrames{ 0 };
	bool Orentation = false;
	bool Looped = false;
};