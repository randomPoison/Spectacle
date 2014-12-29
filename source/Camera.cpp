#include <Scene.h>
#include <Components/Camera.h>

#include "Camera.h"
#include "Components/FollowTargetLinear.h"

namespace Spectacle
{
	entityx::Entity CreateCamera( Gunship::Scene& scene, entityx::Entity player )
	{
		entityx::Entity camera = scene.CreateGameObject();
		Gunship::Components::Transform::Handle cameraTransform =
			camera.assign< Gunship::Components::Transform >( scene );
		camera.assign< Gunship::Components::Camera >( scene, cameraTransform );
		cameraTransform->SetPosition( 0.0f, 0.0f, 30.0f );

		cameraTransform->LookAt( Gunship::Vector3( 0.0f, 0.0f, 0.0f ) );

		Gunship::Components::Transform::Handle playerTransform = player.component< Gunship::Components::Transform >();
		camera.assign< FollowTargetLinear >( playerTransform, Gunship::Vector3( 0.0f, 0.0f, 30.0f ), 5.0f );

		return camera;
	}
}
