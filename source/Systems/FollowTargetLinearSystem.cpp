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
		Gunship::Transform::Handle transform;
		for ( auto entity : entities.entities_with_components< FollowTargetLinear, Gunship::Transform >() )
		{
			entity.unpack< FollowTargetLinear >( followTarget );
			entity.unpack< Gunship::Transform >( transform );
			Ogre::Vector3 desiredPostition = followTarget->desiredPosition();
			Ogre::Vector3 resultPosition = Ogre::Math::lerp( transform->position(),
			                                                 desiredPostition,
			                                                 followTarget->followSpeed * delta );
			transform->position( resultPosition );
		}
	}
}
