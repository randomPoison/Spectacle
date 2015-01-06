#pragma once

#include <Entity/System.h>

namespace Spectacle
{
	struct PlayerMovementSystem : public Gunship::System< PlayerMovementSystem, Gunship::BehaviorSystemBase >
	{
		void Update( Gunship::Scene& scene,
		             float delta ) override;
	};
}
