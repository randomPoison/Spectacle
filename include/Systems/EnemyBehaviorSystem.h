#pragma once

#include <Entity/System.h>

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	namespace Systems
	{
		struct EnemyBehaviorSystem : public Gunship::System< EnemyBehaviorSystem, Gunship::BehaviorSystemBase >
		{
			void Update( Gunship::Scene& scene, float delta ) override;
		};
	}
}
