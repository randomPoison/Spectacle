#pragma once

#include <entityx/Entity.h>
#include <Math/Vector3.h>

namespace Spectacle
{
	struct Bullet : public entityx::Component< Bullet >
	{
		Gunship::Vector3 velocity;

		Bullet( Gunship::Vector3 direction, float speed = 1.0f );
	};
}
