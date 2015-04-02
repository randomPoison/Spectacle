#pragma once

#include <entityx/Entity.h>
#include <Math/Vector3.h>

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	entityx::Entity CreateEnemy( Gunship::Scene& scene,
	                             Gunship::Vector3 position,
	                             entityx::Entity player );
}
