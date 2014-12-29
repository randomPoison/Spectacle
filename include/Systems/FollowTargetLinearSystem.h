#pragma once

#include <System.h>

namespace Spectacle
{
	struct FollowTargetLinearSystem : public Gunship::System< FollowTargetLinearSystem, Gunship::BehaviorSystemBase >
	{
		void Update( entityx::EntityManager& entities,
		             float delta ) override;
	};
}
