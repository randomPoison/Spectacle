#pragma once

#include <entityx/Entity.h>

namespace Spectacle
{
	struct Player : public entityx::Component< Player >
	{
		float moveSpeed;

		Player( float speed = 1.0f );
	};
}
