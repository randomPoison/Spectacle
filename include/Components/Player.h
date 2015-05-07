#pragma once

#include <Components/SimpleStructComponent.h>

namespace Spectacle
{
	struct Player : public Gunship::Components::SimpleStructComponent
	{
		float moveSpeed;

		Player( float speed = 1.0f );
	};
}
