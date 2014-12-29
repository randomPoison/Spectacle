#include <entityx/Entity.h>
#include <Components/Transform.h>
#include <Input.h>

#include "Systems/PlayerMovementSystem.h"
#include "Components/Player.h"

namespace Spectacle
{
	void PlayerMovementSystem::Update( entityx::EntityManager& entities,
	                                   float delta )
	{
		Gunship::Components::Transform::Handle transform;
		Player::Handle player;
		for ( auto entity : entities.entities_with_components< Gunship::Components::Transform, Player >() )
		{
			entity.unpack< Gunship::Components::Transform >( transform );
			entity.unpack< Player >( player );

			if ( Gunship::Input::KeyDown( SDL_SCANCODE_D ) )
			{
				transform->Translate( Gunship::Vector3::UNIT_X * player->moveSpeed * delta );
			}
			if ( Gunship::Input::KeyDown( SDL_SCANCODE_A ) )
			{
				transform->Translate( Gunship::Vector3::NEGATIVE_UNIT_X * player->moveSpeed * delta );
			}
			if ( Gunship::Input::KeyDown( SDL_SCANCODE_W ) )
			{
				transform->Translate( Gunship::Vector3::UNIT_Y * player->moveSpeed * delta );
			}
			if ( Gunship::Input::KeyDown( SDL_SCANCODE_S ) )
			{
				transform->Translate( Gunship::Vector3::NEGATIVE_UNIT_Y * player->moveSpeed * delta );
			}

//			transform->node->_getDerivedPositionUpdated();
		}
	}
}
