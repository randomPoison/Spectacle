#include <Engine.h>
#include <Scene.h>
#include <Mouse.h>

#include <Entity/Entity.h>
#include <Components/Alarm.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>
#include <Systems/EnemyBehaviorSystem.h>
#include <Utility/Random.h>

#include "Player.h"
#include "Camera.h"
#include "Light.h"
#include "Enemy.h"
#include "Systems/FollowTargetLinearSystem.h"
#include "Systems/PlayerMovementSystem.h"
#include "Systems/PlayerGunSystem.h"
#include "Systems/BulletMovementSystem.h"
#include "Systems/LevelManagerSystem.h"
#include "Systems/CreateDestroySystem.h"
#include "Systems/CircleMovementSystem.h"
#include "Components/CircleMovement.h"

namespace Spectacle
{
	using Gunship::Components::AlarmManager;
	using Gunship::Components::TransformManager;
	using Gunship::Components::MeshManager;
	using Gunship::Entity;

	AlarmManager::AlarmID CreateBlock( Gunship::Scene& scene, float x, float y, float time )
	{
		auto& alarmManager = scene.componentManager< AlarmManager >();

		auto entity = scene.entities().Create();

		auto& transform =
			scene.componentManager< Gunship::Components::TransformManager >().Assign( entity );
		transform.SetPosition( x, y, 0.0f );

		scene.componentManager< Gunship::Components::MeshManager >().Assign( entity, "Cube.mesh" );
		return alarmManager.Assign(
			entity,
			time,
			[]( Gunship::Scene& scene, Gunship::Entity entity )
			{
					scene.entities().Destroy( entity );
			} );
	}

	void CreateTimedBlocks( Gunship::Scene& scene )
	{
		static float xOffset = -15.0f;
		xOffset += 1.0f;

		auto& alarmManager = scene.componentManager< AlarmManager >();

		for ( int i = 0; i < 20; ++i )
		{
			auto alarmID = CreateBlock( scene, xOffset, 10.0f - i, 20.0f - i );

			// Randomly cancel some alarms to see how the manager handles it.
			if ( Random::Probability( 0.5f ) )
			{
				alarmManager.Cancel( alarmID );
			}
		}
	}

	void CreateReferenceBlocks( Gunship::Scene& scene )
	{
		auto& alarmManager = scene.componentManager< AlarmManager >();

		for ( int i = 0; i < 20; ++i )
		{
			CreateBlock( scene, -15.0f, 10.0f - i, 20.0f - i );
		}
	}

	void TimedBlocksReset( Gunship::Scene& scene, Gunship::Entity entity )
	{
		CreateTimedBlocks( scene );
		scene.componentManager< AlarmManager >().Assign(
			entity,
			22.0f,
			TimedBlocksReset );
	}

	void ReferenceBlocksReset( Gunship::Scene& scene, Gunship::Entity entity )
	{
		CreateReferenceBlocks( scene );
		scene.componentManager< AlarmManager >().Assign(
			entity,
			22.0f,
			ReferenceBlocksReset );
	}

	void StartCreateDestroyTest( Gunship::Scene& scene )
	{
		scene.AddSystem< Systems::LevelManagerSystem >();
		scene.AddSystem< Systems::CreateDestroySystem >();
	}

	void StartCircleMovementTest( Gunship::Scene& scene )
	{
		// Register managers.
		scene.RegisterComponentManager< CircleMovementManager >( new CircleMovementManager );
		scene.AddSystem< Systems::CircleMovementSystem >();

		// Populate the scene.
		CircleMovementManager& circleManager = scene.componentManager< CircleMovementManager >();
		TransformManager& transformManager = scene.componentManager< TransformManager >();
		MeshManager& meshManager = scene.componentManager< MeshManager >();
		for ( int count = 0; count < 1000; ++count )
		{
			Entity entity = scene.entities().Create();
			circleManager.Assign( entity );
			transformManager.Assign( entity );
			meshManager.Assign( entity, "Cube.mesh" );
		}
	}

	void InitializeScene( Gunship::Scene& scene )
	{
		CreateCamera( scene );

		//StartCreateDestroyTest( scene );
		StartCircleMovementTest( scene );

		//ReferenceBlocksReset( scene, scene.entities().Create() );
		//TimedBlocksReset( scene, scene.entities().Create() );
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
