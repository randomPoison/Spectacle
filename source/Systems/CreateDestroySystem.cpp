#include <OgreSceneNode.h>

#include <Input.h>
#include <Mouse.h>

#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>
#include <Utility/Random.h>

#include "Systems/CreateDestroySystem.h"

using Gunship::Scene;
using Gunship::Entity;
using Gunship::Components::Transform;
using Gunship::Components::TransformManager;
using Gunship::Components::Mesh;
using Gunship::Components::MeshManager;

const int CUBES_PER_FRAME = 1000;
const int TOTAL_CUBES = 10000;

namespace Spectacle {
namespace Systems {

void CreateDestroySystem::Update( Scene& scene, float delta )
{
	TransformManager& transformManager = scene.componentManager< TransformManager >();
	MeshManager& meshManager = scene.componentManager< MeshManager >();

	while ( entities.size() < TOTAL_CUBES + CUBES_PER_FRAME )
	{
		Entity entity = CreateCube(
			scene,
			Random::Range( -15.0f, 15.0f ),
			Random::Range( -15.0f, 15.0f ),
			0.0f );

		entities.push( entity );
	}

	while ( entities.size() > TOTAL_CUBES )
	{
		Entity entity = entities.front();
		entities.pop();

		// Destroy the entity.
		//scene.entities().Destroy( entity );

		// Recycle the entity.
		Transform& transform = transformManager.Get( entity );
		transform.node->setVisible( false );
		disabledPool.push_back( entity );
	}
}

Entity CreateDestroySystem::CreateCube( Scene& scene, float x, float y, float z )
{
	TransformManager& transformManager = scene.componentManager< TransformManager >();
	MeshManager& meshManager = scene.componentManager< MeshManager >();

	if ( disabledPool.empty() )
	{
		Entity entity = scene.entities().Create();

		Transform& transform = transformManager.Assign( entity );
		transform.SetPosition( x, y, z );

		meshManager.Assign( entity, "Cube.mesh" );

		return entity;
	}
	else
	{
		Entity entity = disabledPool.back();
		disabledPool.pop_back();

		Transform& transform = transformManager.Get( entity );
		transform.node->setVisible( true );
		transform.SetPosition( x, y, z );

		return entity;
	}
}

}
}

