#pragma once

#include <Components/SimpleStructComponent.h>

namespace Spectacle
{
	namespace Components
	{
		struct Enemy : public Gunship::Components::SimpleStructComponent
		{
			Gunship::Entity player;
			float bulletDelay;
			float moveSpeed;

			Enemy( Gunship::Entity player,
			       float bulletDelay = 1.0f,
			       float moveSpeed = 5.0f);
		};
	}
}
