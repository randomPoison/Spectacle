#pragma once

#include <Components/SimpleStructComponent.h>
#include <Math/Vector3.h>

namespace Spectacle
{
	struct Bullet : public Gunship::Components::SimpleStructComponent
	{
		Gunship::Vector3 velocity;

		Bullet( Gunship::Vector3 direction, float speed = 1.0f );
	};
}
