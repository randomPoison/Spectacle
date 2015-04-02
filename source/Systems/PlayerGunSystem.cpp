#include <iostream>

#include <Input.h>
#include <Scene.h>

#include "Systems/PlayerGunSystem.h"
#include "Components/PlayerCursor.h"
#include "Bullet.h"

namespace Spectacle
{
	void PlayerGunSystem::Update( Gunship::Scene& scene,
	                              float delta )
	{
		PlayerCursor::Handle cursor;
		Gunship::Components::Transform::Handle cursorTransform;
		for ( auto entity : scene.entities()
			.entities_with_components< PlayerCursor, Gunship::Components::Transform >() )
		{
			entity.unpack< PlayerCursor >( cursor );
			entity.unpack< Gunship::Components::Transform >( cursorTransform );

			Gunship::Input::MouseCoord mouseMovement = Gunship::Input::mouseMovement();
			cursorTransform->Translate( mouseMovement.x * cursor->moveSpeed,
			                            mouseMovement.y * -cursor->moveSpeed,
			                            0.0f );

			if ( Gunship::Input::MouseButtonPressed( SDL_BUTTON_LEFT ) )
			{
				CreateBullet( scene,
				              cursor->playerTransform->position(),
				              cursorTransform->position() );
			}
		}
	}
}
