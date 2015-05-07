#pragma

#include <Entity/System.h>

namespace Spectacle {
namespace Systems {

struct CircleMovementSystem : public Gunship::System< CircleMovementSystem, Gunship::BehaviorSystemBase >
{
	void Update( Gunship::Scene& scene, float delta ) override;
};

}
}
