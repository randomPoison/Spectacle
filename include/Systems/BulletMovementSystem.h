#pragma once

#include <System.h>

namespace Spectacle
{
	struct BulletMovementSystem : public Gunship::System< BulletMovementSystem, Gunship::BehaviorSystemBase >
	{
		void Update( Gunship::Scene& scene, float delta ) override;
	};
}
