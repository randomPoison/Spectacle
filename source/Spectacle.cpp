#include <iostream>

#include "Spectacle.h"

namespace Spectacle
{
	void InitializeScene( Gunship::Scene& scene )
	{
		// add systems to scene
		scene.AddSystem< PlayerMovementSystem >();
		scene.AddSystem< FollowTargetLinearSystem >();

		entityx::Entity camera = scene.CreateGameObject();
		Gunship::Transform::Handle cameraTransform = camera.assign<
			Gunship::Transform >( scene );
		camera.assign< Gunship::Camera >( scene, cameraTransform );
		cameraTransform->node->setPosition( 0.0f, 0.0f, 30.0f );
		cameraTransform->node->_getDerivedPositionUpdated(); // trigger ogre to recalculate derived position.
		cameraTransform->node->lookAt( Ogre::Vector3( 0.0f, 0.0f, 0.0f ),
		                               Ogre::Node::TS_WORLD );

		entityx::Entity cube = scene.CreateGameObject();
		Gunship::Transform::Handle cubeTransform =
			cube.assign< Gunship::Transform >( scene );
		cubeTransform->node->_getDerivedPositionUpdated();
		cube.assign< Gunship::Mesh >( scene, cubeTransform, "Cube.mesh" );
		cube.assign< Player >( 10.0f );

		camera.assign< FollowTargetLinear >( cubeTransform, Ogre::Vector3( 0.0f, 0.0f, 30.0f ), 5.0f );

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
