#include <iostream>

#include <Engine.h>
#include <Scene.h>
#include <Mouse.h>

// Used for testing purposes, should be removed before merge.
#include <Components/Alarm.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>

#include <Systems/EnemyBehaviorSystem.h>

#include "Player.h"
#include "Camera.h"
#include "Light.h"
#include "Enemy.h"
#include "Systems/FollowTargetLinearSystem.h"
#include "Systems/PlayerMovementSystem.h"
#include "Systems/PlayerGunSystem.h"
#include "Systems/BulletMovementSystem.h"
#include "Systems/LevelManagerSystem.h"

namespace Spectacle
{
	void CreateTimedBlocks( Gunship::Scene& scene )
	{
		for ( int i = 0; i < 20; ++i )
		{
			auto entity = scene.entities().Create();

			auto& transform =
				scene.componentManager< Gunship::Components::TransformManager >().Assign( entity );
			transform.SetPosition( -10.0f, 10.0f - i, 0.0f );

			scene.componentManager< Gunship::Components::MeshManager >().Assign( entity, "Cube.mesh" );
			scene.componentManager< Gunship::Components::AlarmManager >().Assign(
				entity,
				20.0f - i,
				[]( Gunship::Scene& scene, Gunship::Entity entity )
				{
					scene.componentManager< Gunship::Components::TransformManager >().Destroy( entity );
					scene.componentManager< Gunship::Components::MeshManager >().Destroy( entity );
				} );
		}
	}

	void TimedBlocksReset( Gunship::Scene& scene, Gunship::Entity entity )
	{
		CreateTimedBlocks( scene );
		scene.componentManager< Gunship::Components::AlarmManager >().Assign(
			entity,
			22.0f,
			TimedBlocksReset );
	}

	void InitializeScene( Gunship::Scene& scene )
	{
		scene.AddSystem< Systems::LevelManagerSystem >();

		CreatePlayer( scene );
		CreateCamera( scene );

		TimedBlocksReset( scene, scene.entities().Create() );
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
