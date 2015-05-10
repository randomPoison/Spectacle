#include <OgreCamera.h>

#include <Scene.h>
#include <Components/Camera.h>
#include <Components/SimpleStructComponentManager.h>

#include "Camera.h"
#include "Components/FollowTargetLinear.h"

namespace Spectacle
{
	Gunship::Entity CreateCamera( Gunship::Scene& scene )
	{
		Gunship::Entity camera = scene.entities().Create();

		Gunship::Components::Transform& cameraTransform =
			scene.componentManager< Gunship::Components::TransformManager >().Assign( camera );
		scene.componentManager< Gunship::Components::CameraManager >().Assign( camera ).camera->setFOVy( Ogre::Radian( 1.0471975512f ) );

		cameraTransform.SetPosition( 0.0f, 0.0f, 30.0f );
		cameraTransform.LookAt( 0.0f, 0.0f, 0.0f );
/*
		Gunship::Components::Transform::Handle playerTransform = player.component< Gunship::Components::Transform >();
		camera.assign< FollowTargetLinear >( playerTransform, Gunship::Vector3( 0.0f, 0.0f, 30.0f ), 5.0f );
*/
		return camera;
	}
}
