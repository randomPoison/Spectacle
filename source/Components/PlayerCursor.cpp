#include "Components/PlayerCursor.h"

namespace Spectacle
{
	PlayerCursor::PlayerCursor( Gunship::Components::Transform::Handle playerTransform, float speed )
		: playerTransform( playerTransform ),
		  moveSpeed( speed )
	{
	}
}
