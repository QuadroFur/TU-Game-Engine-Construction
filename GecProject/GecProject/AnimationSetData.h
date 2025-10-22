#pragma once
#include <string>
struct AnimationSetData
{
	std::string TextureName;
	int NumFrames{ 0 };
	bool Orentation;
	bool Looped{ true };
};