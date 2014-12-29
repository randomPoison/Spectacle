#include <Components/FollowTargetLinear.h>

Spectacle::FollowTargetLinear::FollowTargetLinear( Gunship::Transform::Handle target,
                                                   Ogre::Vector3 offset,
                                                   float followSpeed)
	: targetTransform( target ),
	  offset( offset ),
	  followSpeed( followSpeed )
{
}

Ogre::Vector3 Spectacle::FollowTargetLinear::desiredPosition()
{
	return targetTransform->derivedPosition() + offset;
}
