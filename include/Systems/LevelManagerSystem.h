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
		struct LevelManagerSystem : public Gunship::System< LevelManagerSystem, Gunship::BehaviorSystemBase >
		{
			void Update( Gunship::Scene& scene, float delta ) override;
		};
	}
}
