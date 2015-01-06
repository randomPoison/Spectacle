#pragma once

#include <Entity/Entity.h>
#include <Components/Transform.h>
#include <Math/Vector3.h>

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	Gunship::Entity CreateBullet( Gunship::Scene& scene,
	                              Gunship::Vector3 position,
	                              Gunship::Vector3 direction );
}
