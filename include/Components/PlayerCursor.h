#pragma once

#include <entityx/Entity.h>
#include <Components/Transform.h>

namespace Spectacle
{
	struct PlayerCursor : public entityx::Component< PlayerCursor >
	{
		Gunship::Transform::Handle playerTransform;

		PlayerCursor( Gunship::Transform::Handle playerTransform );
	};
}
