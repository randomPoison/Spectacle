#include <Input.h>
#include <Mouse.h>

#include "Systems/LevelManagerSystem.h"

namespace Spectacle
{
	namespace Systems
	{
		void LevelManagerSystem::Update( Gunship::Scene& scene, float delta )
		{
			if ( Gunship::Input::KeyPressed( SDL_SCANCODE_ESCAPE ) )
			{
				Gunship::Mouse::SetRelativeMode( false );
			}
			else if ( Gunship::Input::MouseButtonDown( SDL_BUTTON_LEFT ) )
			{
				Gunship::Mouse::SetRelativeMode( true );
			}
		}
	}
}

