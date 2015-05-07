#pragma once

#include <Components/SimpleStructComponent.h>
#include <Components/SimpleStructComponentManager.h>
#include <Math/Vector3.h>
#include <Utility/Random.h>


using Ogre::Vector3;

struct CircleMovement : public Gunship::Components::SimpleStructComponent
{
	Vector3 center;
	float radius;
	float period;
	float offset;

	CircleMovement()
		: center( Random::Range( -15.0f, 15.0f ), Random::Range( -15.0f, 15.0f ), 0.0f ),
		  radius( Random::Range( 1.0f, 5.0f ) ),
		  period( Random::Range( 1.0f, 5.0f ) ),
		  offset( 0.0f )
	{
	}
};

typedef Gunship::SimpleStructComponentManager< CircleMovement > CircleMovementManager;
