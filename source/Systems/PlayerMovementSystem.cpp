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
		Gunship::Transform::Handle transform;
		Player::Handle player;
		for ( auto entity : entities.entities_with_components< Gunship::Transform, Player >() )
		{
			entity.unpack< Gunship::Transform >( transform );
			entity.unpack< Player >( player );

			if ( Gunship::Input::KeyDown( SDL_SCANCODE_D ) )
			{
				transform->node->translate( Ogre::Vector3::UNIT_X * player->moveSpeed * delta );
			}
			if ( Gunship::Input::KeyDown( SDL_SCANCODE_A ) )
			{
				transform->node->translate( Ogre::Vector3::NEGATIVE_UNIT_X * player->moveSpeed * delta );
			}
			if ( Gunship::Input::KeyDown( SDL_SCANCODE_W ) )
			{
				transform->node->translate( Ogre::Vector3::UNIT_Y * player->moveSpeed * delta );
			}
			if ( Gunship::Input::KeyDown( SDL_SCANCODE_S ) )
			{
				transform->node->translate( Ogre::Vector3::NEGATIVE_UNIT_Y * player->moveSpeed * delta );
			}

			transform->node->_getDerivedPositionUpdated();
		}
	}
}
