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
		struct CreateDestroySystem : public Gunship::System< CreateDestroySystem, Gunship::BehaviorSystemBase >
		{
			std::queue< Gunship::Entity > entities;

			void Update( Gunship::Scene& scene, float delta ) override;
		};
	}
}