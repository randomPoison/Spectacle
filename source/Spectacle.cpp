#include <iostream>

#include <Engine.h>
#include <Scene.h>
#include <Mouse.h>

#include "Player.h"
#include "Camera.h"
#include "Light.h"
#include "Enemy.h"
#include "Systems/FollowTargetLinearSystem.h"
#include "Systems/PlayerMovementSystem.h"
#include "Systems/PlayerGunSystem.h"
#include "Systems/BulletMovementSystem.h"
#include "Systems/EnemyBehavior.h"

namespace Spectacle
{
	void InitializeScene( Gunship::Scene& scene )
	{
		//Gunship::Mouse::SetRelativeMode( true );

		// add systems to scene
		scene.AddSystem< PlayerMovementSystem >();
		scene.AddSystem< FollowTargetLinearSystem >();
		scene.AddSystem< PlayerGunSystem >();
		scene.AddSystem< BulletMovementSystem >();
		scene.AddSystem< Systems::EnemyBehavior >();

		entityx::Entity player = CreatePlayer( scene );
		CreateCursor( scene, player );
		CreateCamera( scene, player );
		CreateLight( scene );
		CreateEnemy( scene, Gunship::Vector3( 10.0f, 10.0f, 0.0f ), player );
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
