#pragma once

#include <Entity/System.h>

namespace Spectacle
{
	struct PlayerGunSystem : public Gunship::System< PlayerGunSystem, Gunship::BehaviorSystemBase >
	{
		void Update( Gunship::Scene& scene,
		             float delta );
	};
}
