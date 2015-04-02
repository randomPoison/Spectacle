#include <iostream>

#include <Engine.h>
#include <Scene.h>
#include <Mouse.h>
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
	void InitializeScene( Gunship::Scene& scene )
	{
		scene.AddSystem< Systems::LevelManagerSystem >();

		CreatePlayer( scene );
		CreateCamera( scene );
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
