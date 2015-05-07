#pragma once

#include <Components/SimpleStructComponent.h>
#include <Components/Transform.h>

namespace Spectacle
{
	struct PlayerCursor : public Gunship::Components::SimpleStructComponent
	{
		float moveSpeed;

		PlayerCursor( float speed = 1.0f );
	};
}
