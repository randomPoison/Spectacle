#include <Engine.h>
#include <Scene.h>
#include <Mouse.h>

#include <Entity/Entity.h>
#include <Components/Alarm.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>
#include <Components/Collider.h>
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
	using Gunship::Scene;
	using Gunship::Entity;
	using Gunship::Components::AlarmManager;
	using Gunship::Components::TransformManager;
	using Gunship::Components::MeshManager;
	using Gunship::Components::ColliderManager;

	AlarmManager::AlarmID CreateBlock( Scene& scene, float x, float y, float time )
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
			[]( Scene& scene, Gunship::Entity entity )
			{
				scene.entities().Destroy( entity );
			} );
	}

	void CreateTimedBlocks( Scene& scene )
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

	void CreateReferenceBlocks( Scene& scene )
	{
		auto& alarmManager = scene.componentManager< AlarmManager >();

		for ( int i = 0; i < 20; ++i )
		{
			CreateBlock( scene, -15.0f, 10.0f - i, 20.0f - i );
		}
	}

	void TimedBlocksReset( Scene& scene, Gunship::Entity entity )
	{
		CreateTimedBlocks( scene );
		scene.componentManager< AlarmManager >().Assign(
			entity,
			22.0f,
			TimedBlocksReset );
	}

	void ReferenceBlocksReset( Scene& scene, Gunship::Entity entity )
	{
		CreateReferenceBlocks( scene );
		scene.componentManager< AlarmManager >().Assign(
			entity,
			22.0f,
			ReferenceBlocksReset );
	}

	void StartCreateDestroyTest( Scene& scene )
	{
		scene.AddSystem< Systems::LevelManagerSystem >();
		scene.AddSystem< Systems::CreateDestroySystem >();
	}

	void StartCircleMovementTest( Scene& scene )
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

	void CreateCollidable( Scene& scene, float x, float y, float z )
	{
		auto& transformManager = scene.componentManager< TransformManager >();
		auto& meshManager = scene.componentManager< MeshManager >();
		auto& colliderManager = scene.componentManager< ColliderManager >();

		// Create static cube with a sphere collider.
		Entity entity = scene.entities().Create();
		auto& transform = transformManager.Assign( entity );
		transform.SetPosition( x, y, z );
		meshManager.Assign( entity, "Cube.mesh" );
		colliderManager.Assign( entity ).radius = 0.5f;
	}

	void StartCollisionTest( Scene& scene )
	{
		CreateCollidable( scene, 0.0f, 0.0f, 0.0f );
		CreateCollidable( scene, 1.5f, 0.0f, 0.0f );
	}

	void InitializeScene( Scene& scene )
	{
		CreateCamera( scene );

		//StartCreateDestroyTest( scene );
		//StartCircleMovementTest( scene );
		StartCollisionTest( scene );
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
