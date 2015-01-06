#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>

#include "Enemy.h"
#include "Components/Enemy.h"

namespace Spectacle
{
	Gunship::Entity CreateEnemy( Gunship::Scene& scene,
	                             Gunship::Vector3 position,
	                             Gunship::Entity player )
	{
		Gunship::Entity enemy = scene.entities().Create();
/*
		Gunship::Components::Transform::Handle enemyTransform =
			enemy.assign< Gunship::Components::Transform >(
				scene,
				position );
		enemy.assign< Gunship::Components::Mesh >( scene, enemyTransform, "Cube.mesh" );
		enemy.assign< Components::Enemy >( player );
*/
		return enemy;
	}
}

