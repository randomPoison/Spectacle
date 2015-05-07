#pragma once

#include <Entity/System.h>
#include <Entity/Entity.h>

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	namespace Systems
	{
		struct LevelManagerSystem : public Gunship::System< LevelManagerSystem, Gunship::BehaviorSystemBase >
		{
			void Update( Gunship::Scene& scene, float delta ) override;
		};
	}
}
