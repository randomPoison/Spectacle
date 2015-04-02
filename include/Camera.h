#pragma once

#include <Components/Transform.h>

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	entityx::Entity CreateCamera( Gunship::Scene& scene, entityx::Entity player );
}
