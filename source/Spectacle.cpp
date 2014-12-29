#include <iostream>

#include <Engine.h>
#include <Components/Transform.h>
#include <Components/Camera.h>
#include <Components/FollowTargetLinear.h>
#include <Components/Mesh.h>
#include <Components/Light.h>
#include <Components/Player.h>
#include <Components/PlayerCursor.h>
#include <Systems/FollowTargetLinearSystem.h>
#include <Systems/PlayerMovementSystem.h>

namespace Spectacle
{
	void InitializeScene( Gunship::Scene& scene )
	{
		// add systems to scene
		scene.AddSystem< PlayerMovementSystem >();
		scene.AddSystem< FollowTargetLinearSystem >();

		// PLAYER OBJECT
		entityx::Entity player = scene.CreateGameObject();
		Gunship::Transform::Handle playerTransform =
			player.assign< Gunship::Transform >( scene );
		playerTransform->node->_getDerivedPositionUpdated();
		player.assign< Gunship::Mesh >( scene, playerTransform, "Cube.mesh" );
		player.assign< Player >( 10.0f );

		// PLAYER CURSOR
		entityx::Entity cursor = scene.CreateGameObject();
		Gunship::Transform::Handle cursorTransform =
			cursor.assign< Gunship::Transform >( scene );
		cursorTransform->SetScale( 0.3f, 0.3f, 0.3f );
		cursor.assign< Gunship::Mesh >( scene, cursorTransform, "Cube.mesh" );
		cursor.assign< PlayerCursor >( playerTransform );

		// CAMERA
		entityx::Entity camera = scene.CreateGameObject();
		Gunship::Transform::Handle cameraTransform = camera.assign<
			Gunship::Transform >( scene );
		camera.assign< Gunship::Camera >( scene, cameraTransform );
		cameraTransform->node->setPosition( 0.0f, 0.0f, 30.0f );
		cameraTransform->node->_getDerivedPositionUpdated(); // trigger ogre to recalculate derived position.
		cameraTransform->node->lookAt( Gunship::Vector3( 0.0f, 0.0f, 0.0f ),
		                               Ogre::Node::TS_WORLD );
		camera.assign< FollowTargetLinear >( playerTransform, Gunship::Vector3( 0.0f, 0.0f, 30.0f ), 5.0f );

		// LIGHT
		entityx::Entity light = scene.CreateGameObject();
		Gunship::Transform::Handle lightTransform =
			light.assign< Gunship::Transform >( scene );
		lightTransform->node->setPosition( 12.0f, 56.0f, 3.0f );
		light.assign< Gunship::Components::Light >( scene, lightTransform );
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
