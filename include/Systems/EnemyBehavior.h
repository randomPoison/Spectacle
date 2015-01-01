#pragma once

#include <System.h>

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	namespace Systems
	{
		struct EnemyBehavior : public Gunship::System< EnemyBehavior, Gunship::BehaviorSystemBase >
		{
			void Update( Gunship::Scene& scene, float delta ) override;
		};
	}
}
