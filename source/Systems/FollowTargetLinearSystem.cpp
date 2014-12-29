#include <entityx/Entity.h>
#include <Components/Transform.h>

#include "Systems/FollowTargetLinearSystem.h"
#include "Components/FollowTargetLinear.h"

namespace Spectacle
{
	void FollowTargetLinearSystem::Update( entityx::EntityManager& entities,
	                                       float delta )
	{
		FollowTargetLinear::Handle followTarget;
		Gunship::Components::Transform::Handle transform;
		for ( auto entity : entities.entities_with_components< FollowTargetLinear, Gunship::Components::Transform >() )
		{
			entity.unpack< FollowTargetLinear >( followTarget );
			entity.unpack< Gunship::Components::Transform >( transform );
			Ogre::Vector3 desiredPostition = followTarget->desiredPosition();
			Ogre::Vector3 resultPosition = Ogre::Math::lerp( transform->position(),
			                                                 desiredPostition,
			                                                 followTarget->followSpeed * delta );
			transform->position( resultPosition );
		}
	}
}
