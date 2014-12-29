#include <iostream>

#include <Engine.h>
#include <Scene.h>
#include <Mouse.h>

#include "Player.h"
#include "Camera.h"
#include "Light.h"
#include "Systems/FollowTargetLinearSystem.h"
#include "Systems/PlayerMovementSystem.h"
#include "Systems/PlayerGunSystem.h"

namespace Spectacle
{
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
