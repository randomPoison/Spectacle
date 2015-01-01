#include "Components/Enemy.h"

namespace Spectacle
{
	namespace Components
	{
		Enemy::Enemy( entityx::Entity player,
		              float bulletDelay,
		              float moveSpeed )
			: player( player ),
			  bulletDelay( bulletDelay ),
			  moveSpeed( moveSpeed )
		{
		}
	}
}

