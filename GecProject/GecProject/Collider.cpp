#include "Collider.h"
#include <iostream>

bool Collider::CheckForCollision(Actor& OtherActor)
{
	//TopLeft
	if (OtherActor.Position.x > ColliderX && OtherActor.Position.x < ColliderX + ColliderWidth)
	{
		//Inside the width
		if (OtherActor.Position.y > ColliderY && OtherActor.Position.y < ColliderY + ColliderHeight)
		{
			std::cerr << "COLLISIONNNN!" << std::endl;
		}
	}

	//TopRight
	if (OtherActor.Position.x + OtherActor.Size.x > ColliderX && OtherActor.Position.x + OtherActor.Size.x < ColliderX + ColliderWidth)
	{
		//Inside the width
		if (OtherActor.Position.y > ColliderY && OtherActor.Position.y < ColliderY + ColliderHeight)
		{
			std::cerr << "COLLISIONNNN!" << std::endl;
		}
	}

	//BottomLeft
	if (OtherActor.Position.x > ColliderX && OtherActor.Position.x < ColliderX + ColliderWidth)
	{
		//Inside the width
		if (OtherActor.Position.y + OtherActor.Size.y > ColliderY && OtherActor.Position.y + OtherActor.Size.y < ColliderY + ColliderHeight)
		{
			std::cerr << "COLLISIONNNN!" << std::endl;
		}
	}

	//BottomRight
	if (OtherActor.Position.x + OtherActor.Size.x > ColliderX && OtherActor.Position.x + OtherActor.Size.x < ColliderX + ColliderWidth)
	{
		//Inside the width
		if (OtherActor.Position.y + OtherActor.Size.y > ColliderY && OtherActor.Position.y + OtherActor.Size.y < ColliderY + ColliderHeight)
		{
			std::cerr << "COLLISIONNNN!" << std::endl;
		}
	}
	return false;
}