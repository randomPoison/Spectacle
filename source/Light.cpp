#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Light.h>

#include "Light.h"

namespace Spectacle
{
	entityx::Entity CreateLight( Gunship::Scene& scene )
	{
		entityx::Entity light = scene.CreateGameObject();
		Gunship::Components::Transform::Handle lightTransform =
			light.assign< Gunship::Components::Transform >( scene );
		lightTransform->SetPosition( 12.0f, 56.0f, 3.0f );
		light.assign< Gunship::Components::Light >( scene, lightTransform );

		return light;
	}
}
