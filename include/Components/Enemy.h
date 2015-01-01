#pragma once

#include <entityx/Entity.h>

namespace Spectacle
{
	namespace Components
	{
		struct Enemy : entityx::Component< Enemy >
		{
			entityx::Entity player;
			float bulletDelay;
			float moveSpeed;

			Enemy( entityx::Entity player,
			       float bulletDelay = 1.0f,
			       float moveSpeed = 5.0f);
		};
	}
}
