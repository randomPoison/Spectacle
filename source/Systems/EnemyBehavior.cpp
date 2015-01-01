#include <Scene.h>
#include <Components/Transform.h>

#include "Systems/EnemyBehavior.h"
#include "Components/Enemy.h"

namespace Spectacle
{
	namespace Systems
	{
		void EnemyBehavior::Update( Gunship::Scene& scene, float delta )
		{
			for ( entityx::Entity entity : scene.entities()
				.entities_with_components< Gunship::Components::Transform, Components::Enemy >() )
			{
				Components::Enemy& enemy = *entity.component< Components::Enemy >().get();
				Gunship::Components::Transform& enemyTransform =
					*entity.component< Gunship::Components::Transform >().get();
				Gunship::Components::Transform& playerTransform =
					*enemy.player.component< Gunship::Components::Transform >().get();

				// move enemy towards player
				Gunship::Vector3 moveDir = ( playerTransform.position() - enemyTransform.position() ).normalisedCopy();
				enemyTransform.Translate( moveDir * enemy.moveSpeed * delta );
			}
		}
	}
}

