#include <iostream>

#include <Engine.h>
#include <Mouse.h>
#include <Components/Transform.h>
#include <Components/Camera.h>
#include <Components/Mesh.h>
#include <Components/Light.h>

#include "Components/Player.h"
#include "Components/PlayerCursor.h"
#include "Components/FollowTargetLinear.h"
#include "Systems/FollowTargetLinearSystem.h"
#include "Systems/PlayerMovementSystem.h"
#include "Systems/PlayerGunSystem.h"

namespace Spectacle
{
	entityx::Entity CreatePlayer( Gunship::Scene& scene )
	{
		entityx::Entity player = scene.CreateGameObject();

		Gunship::Transform::Handle playerTransform =
			player.assign< Gunship::Transform >( scene );
		player.assign< Gunship::Mesh >( scene, playerTransform, "Cube.mesh" );
		player.assign< Player >( 10.0f );

		return player;
	}

	entityx::Entity CreateCursor( Gunship::Scene& scene, entityx::Entity player )
	{
		Gunship::Transform::Handle playerTransform = player.component< Gunship::Transform >();

		entityx::Entity cursor = scene.CreateGameObject();
		Gunship::Transform::Handle cursorTransform =
			cursor.assign< Gunship::Transform >( scene );
		playerTransform->AddChild( cursorTransform );
		cursorTransform->SetScale( 0.3f, 0.3f, 0.3f );
		cursor.assign< Gunship::Mesh >( scene, cursorTransform, "Cube.mesh" );

		cursor.assign< PlayerCursor >( playerTransform, 0.01f );

		return cursor;
	}

	entityx::Entity CreateCamera( Gunship::Scene& scene, entityx::Entity player )
	{
		entityx::Entity camera = scene.CreateGameObject();
		Gunship::Transform::Handle cameraTransform =
			camera.assign< Gunship::Transform >( scene );
		camera.assign< Gunship::Camera >( scene, cameraTransform );
		cameraTransform->SetPosition( 0.0f, 0.0f, 30.0f );

		cameraTransform->LookAt( Gunship::Vector3( 0.0f, 0.0f, 0.0f ) );

		Gunship::Transform::Handle playerTransform = player.component< Gunship::Transform >();
		camera.assign< FollowTargetLinear >( playerTransform, Gunship::Vector3( 0.0f, 0.0f, 30.0f ), 5.0f );

		return camera;
	}

	entityx::Entity CreateLight( Gunship::Scene& scene )
	{
		entityx::Entity light = scene.CreateGameObject();
		Gunship::Transform::Handle lightTransform =
			light.assign< Gunship::Transform >( scene );
		lightTransform->SetPosition( 12.0f, 56.0f, 3.0f );
		light.assign< Gunship::Components::Light >( scene, lightTransform );

		return light;
	}

	void InitializeScene( Gunship::Scene& scene )
	{
		Gunship::Mouse::SetRelativeMode( true );

		// add systems to scene
		scene.AddSystem< PlayerMovementSystem >();
		scene.AddSystem< FollowTargetLinearSystem >();
		scene.AddSystem< PlayerGunSystem >();

		entityx::Entity player = CreatePlayer( scene );
		CreateCursor( scene, player );
		CreateCamera( scene, player );
		CreateLight( scene );
	}
}

int main( int argc, char* argv[] )
{
	Gunship::Engine engine;

	// initialize and run the engine
	if ( engine.InitSystems() )
	{
		engine.SetupCurrentScene( Spectacle::InitializeScene );
		engine.Start();
		engine.ShutDown();
	}

	return 0;
}
