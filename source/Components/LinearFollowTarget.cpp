#include "Components/LinearFollowTarget.h"

Spectacle::FollowTarget::FollowTarget( Gunship::Transform::Handle target,
                                       Ogre::Vector3 offset,
                                       float followSpeed)
	: targetTransform( target ),
	  offset( offset ),
	  followSpeed( followSpeed )
{
}

Ogre::Vector3 Spectacle::FollowTarget::desiredPosition()
{
	return targetTransform->node->_getDerivedPosition() + offset;
}
