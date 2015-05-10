#include <math.h>

#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <Input.h>
#include <Mouse.h>

#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>
#include <Utility/Random.h>

#include "Systems/CircleMovementSystem.h"
#include "Components/CircleMovement.h"

using Gunship::Scene;
using Gunship::Entity;
using Gunship::Components::Transform;
using Gunship::Components::TransformManager;
using Gunship::Components::Mesh;
using Gunship::Components::MeshManager;

namespace Spectacle {
namespace Systems {

void CircleMovementSystem::Update( Scene& scene, float delta )
{
	TransformManager& transformManager = scene.componentManager< TransformManager >();
	CircleMovementManager& circleManager = scene.componentManager< CircleMovementManager >();

	for ( CircleMovement& circleMovement : circleManager )
	{
		Transform& transform = transformManager.Get( circleMovement.entity );

		// Calculate the position of the cube.
		circleMovement.offset += delta;
		float t = circleMovement.offset * M_PI * 2.0f / circleMovement.period;
		float xOffset = cosf( t ) * circleMovement.radius;
		float yOffset = sinf( t ) * circleMovement.radius;

		// Move the cube.
		transform.position( circleMovement.center + Vector3( xOffset, yOffset, 0.0f ) );
	}
}

}
}

