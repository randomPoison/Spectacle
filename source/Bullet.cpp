#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>
#include <Components/Alarm.h>
#include <entityx/Entity.h>

#include "Bullet.h"
#include "Components/Bullet.h"

namespace Spectacle
{
	entityx::Entity CreateBullet( Gunship::Scene& scene,
	                              Gunship::Vector3 position,
	                              Gunship::Vector3 direction )
	{
		entityx::Entity bullet = scene.CreateGameObject();
		Gunship::Components::Transform::Handle bulletTransform =
			bullet.assign< Gunship::Components::Transform >(
				scene,
				position,
				Gunship::Quaternion::IDENTITY,
				Gunship::Vector3( 0.25f, 0.25f, 0.25f ) );
		bullet.assign< Bullet >( direction.normalisedCopy(), 25.0f );
		bullet.assign< Gunship::Components::Mesh >( scene, bulletTransform, "Cube.mesh" );
		bullet.assign< Gunship::Components::Alarm >(
			0.5f,
			[]( Gunship::Scene& scene, entityx::Entity entity )
			{
				entity.destroy();
			} );

		return bullet;
	}
}
