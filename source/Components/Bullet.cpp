#include "Components/Bullet.h"

namespace Spectacle
{
	Bullet::Bullet( Gunship::Vector3 direction, float speed )
		: velocity( direction * speed )
	{
	}
}
