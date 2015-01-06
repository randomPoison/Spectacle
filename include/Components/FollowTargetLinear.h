#pragma once

#include <Components/SimpleStructComponent.h>
#include <Math/Vector3.h>
#include <Entity/System.h>
#include <Components/Transform.h>

namespace Spectacle
{
	struct FollowTargetLinear : public Gunship::Components::SimpleStructComponent
	{
		Gunship::Entity target;
		Ogre::Vector3 offset;
		float followSpeed;

		FollowTargetLinear( Gunship::Entity target,
		              Ogre::Vector3 offset = Ogre::Vector3::ZERO,
		              float followSpeed = 10.0f );

		/**
		 * @brief Calculates the current desired position of the following object.
		 *
		 * @details
		 *     The desired position is current position of the target plus the offset.
		 */
		Gunship::Vector3 desiredPosition();
	};
}
