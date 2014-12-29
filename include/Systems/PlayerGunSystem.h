#pragma once

#include <System.h>

namespace Spectacle
{
	struct PlayerGunSystem : public Gunship::System< PlayerGunSystem, Gunship::BehaviorSystemBase >
	{
		void Update( entityx::EntityManager& entities,
		             float delta );
	};
}
