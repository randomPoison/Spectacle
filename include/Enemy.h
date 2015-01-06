#pragma once

#include <Entity/Entity.h>
#include <Math/Vector3.h>

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	Gunship::Entity CreateEnemy( Gunship::Scene& scene,
	                             Gunship::Vector3 position,
	                             Gunship::Entity player );
}
