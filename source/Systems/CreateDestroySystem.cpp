#include <Input.h>
#include <Mouse.h>

#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>
#include <Utility/Random.h>

#include "Systems/CreateDestroySystem.h"

using Gunship::Entity;
using Gunship::Components::Transform;
using Gunship::Components::TransformManager;
using Gunship::Components::Mesh;
using Gunship::Components::MeshManager;

const int CUBES_PER_FRAME = 1000;
const int TOTAL_CUBES = 1000;

namespace Spectacle
{
	namespace Systems
	{
		void CreateDestroySystem::Update( Gunship::Scene& scene, float delta )
		{
			while ( entities.size() < TOTAL_CUBES + CUBES_PER_FRAME )
			{
				Gunship::Entity entity = scene.entities().Create();

				Gunship::Components::Transform& transform =
					scene.componentManager< TransformManager >().Assign( entity );
				transform.SetPosition(
					Random::Range( -15.0f, 15.0f ),
					Random::Range( -15.0f, 15.0f ),
					0.0f );

				scene.componentManager< MeshManager >().Assign( entity, "Cube.mesh" );

				entities.push( entity );
			}

			while ( entities.size() > TOTAL_CUBES )
			{
				Entity entity = entities.front();
				entities.pop();

				scene.entities().Destroy( entity );
			}
		}
	}
}

