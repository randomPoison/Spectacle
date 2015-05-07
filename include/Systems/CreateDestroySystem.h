#pragma once

#include <queue>

#include <Entity/System.h>
#include <Entity/Entity.h>
#include <Containers/FastArray.h>

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
			Gunship::Containers::FastArray< Gunship::Entity > disabledPool;

			void Update( Gunship::Scene& scene, float delta ) override;
			Gunship::Entity CreateCube( Gunship::Scene& scene, float x, float y, float z );
		};
	}
}
