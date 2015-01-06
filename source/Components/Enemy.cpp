#include "Components/Enemy.h"

namespace Spectacle
{
	namespace Components
	{
		Enemy::Enemy( Gunship::Entity player,
		              float bulletDelay,
		              float moveSpeed )
			: player( player ),
			  bulletDelay( bulletDelay ),
			  moveSpeed( moveSpeed )
		{
		}
	}
}

