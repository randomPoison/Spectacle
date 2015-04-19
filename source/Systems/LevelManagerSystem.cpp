#include <Input.h>
#include <Mouse.h>
#include <Scene.h>

#include "Systems/LevelManagerSystem.h"
#include "Systems/CreateDestroySystem.h"

using Gunship::Input;
using Spectacle::Systems::CreateDestroySystem;

namespace Spectacle
{
	namespace Systems
	{
		void LevelManagerSystem::Update( Gunship::Scene& scene, float delta )
		{
			//if ( Gunship::Input::KeyPressed( SDL_SCANCODE_ESCAPE ) )
			//{
			//	Gunship::Mouse::SetRelativeMode( false );
			//}
			//else if ( Gunship::Input::MouseButtonDown( SDL_BUTTON_LEFT ) )
			//{
			//	Gunship::Mouse::SetRelativeMode( true );
			//}

			if ( Input::KeyPressed( SDL_SCANCODE_SPACE ) )
			{
				auto& system = scene.behaviors().Get< CreateDestroySystem >();
				system.active = !system.active;
			}
		}
	}
}

