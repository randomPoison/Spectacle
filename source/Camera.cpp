#include <Scene.h>
#include <Components/Camera.h>
#include <Components/SimpleStructComponentManager.h>

#include "Camera.h"
#include "Components/FollowTargetLinear.h"

namespace Spectacle
{
	Gunship::Entity CreateCamera( Gunship::Scene& scene, Gunship::Entity player )
	{
		Gunship::Entity camera = scene.entities().Create();

//		camera.assign< Gunship::Components::Transform >();
//		camera.assign< Gunship::Components::Camera >();

		scene.componentManager< Gunship::Components::TransformManager >().Assign( camera.id );
		scene.componentManager< Gunship::Components::CameraManager >().Assign( camera.id );

//		cameraTransform->SetPosition( 0.0f, 0.0f, 30.0f );
//		cameraTransform->LookAt( Gunship::Vector3( 0.0f, 0.0f, 0.0f ) );
/*
		Gunship::Components::Transform::Handle playerTransform = player.component< Gunship::Components::Transform >();
		camera.assign< FollowTargetLinear >( playerTransform, Gunship::Vector3( 0.0f, 0.0f, 30.0f ), 5.0f );
*/
		return camera;
	}
}
