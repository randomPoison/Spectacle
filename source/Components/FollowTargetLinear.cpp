#include <Components/FollowTargetLinear.h>

Spectacle::FollowTargetLinear::FollowTargetLinear( Gunship::Entity target,
                                                   Ogre::Vector3 offset,
                                                   float followSpeed)
	: target( target ),
	  offset( offset ),
	  followSpeed( followSpeed )
{
}

Gunship::Vector3 Spectacle::FollowTargetLinear::desiredPosition()
{
	//return targetTransform->derivedPosition() + offset;
	return Gunship::Vector3::ZERO;
}
