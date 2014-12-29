#pragma once

#include <entityx/Entity.h>
#include <OgreVector3.h>
#include <System.h>
#include <Components/Transform.h>

namespace Spectacle
{
	struct FollowTargetLinear : public entityx::Component< FollowTargetLinear >
	{
		Gunship::Transform::Handle targetTransform;
		Ogre::Vector3 offset;
		float followSpeed;

		FollowTargetLinear( Gunship::Transform::Handle target,
		              Ogre::Vector3 offset = Ogre::Vector3::ZERO,
		              float followSpeed = 10.0f );

		/**
		 * @brief Calculates the current desired position of the following object.
		 *
		 * @details
		 *     The desired position is current position of the target plus the offset.
		 */
		Ogre::Vector3 desiredPosition();
	};
}
