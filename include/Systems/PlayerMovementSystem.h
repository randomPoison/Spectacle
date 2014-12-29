#pragma once

#include <System.h>

namespace Spectacle
{
	struct PlayerMovementSystem : public Gunship::System< PlayerMovementSystem, Gunship::BehaviorSystemBase >
	{
		void Update( entityx::EntityManager& entities,
		             float delta ) override;
	};
}
