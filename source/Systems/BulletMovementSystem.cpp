#include <Entity/Entity.h>
#include <Scene.h>
#include <Components/Transform.h>

#include "Systems/BulletMovementSystem.h"
#include "Components/Bullet.h"

namespace Spectacle
{
	void BulletMovementSystem::Update( Gunship::Scene& scene,
	                                   float delta )
	{
/*
		Bullet::Handle bullet;
		Gunship::Components::Transform::Handle bulletTransform;
		for ( auto entity : scene.entities()
			.entities_with_components< Bullet, Gunship::Components::Transform >() )
		{
			entity.unpack< Bullet >( bullet );
			entity.unpack< Gunship::Components::Transform >( bulletTransform );

			bulletTransform->Translate( bullet->velocity * delta );
		}
*/
	}
}
