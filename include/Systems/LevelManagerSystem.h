#pragma once

#include <queue>

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
			std::queue< Gunship::Entity > entities;
			unsigned long count = 0;

			void Update( Gunship::Scene& scene, float delta ) override;
		};
	}
}
