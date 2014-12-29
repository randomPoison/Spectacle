#include <Input.h>

#include "Systems/PlayerGunSystem.h"
#include "Components/PlayerCursor.h"

namespace Spectacle
{
	void PlayerGunSystem::Update( entityx::EntityManager& entities,
	                              float delta )
	{
		PlayerCursor::Handle cursor;
		Gunship::Transform::Handle cursorTransform;
		for ( auto entity : entities.entities_with_components< PlayerCursor, Gunship::Transform >() )
		{
			entity.unpack< PlayerCursor >( cursor );
			entity.unpack< Gunship::Transform >( cursorTransform );

			Gunship::Input::MouseCoord mouseMovement = Gunship::Input::mouseMovement();
			cursorTransform->Translate( mouseMovement.x * cursor->moveSpeed,
			                            mouseMovement.y * -cursor->moveSpeed,
			                            0.0f );
		}
	}
}
