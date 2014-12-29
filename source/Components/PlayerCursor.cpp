#include "Components/PlayerCursor.h"

namespace Spectacle
{
	PlayerCursor::PlayerCursor( Gunship::Transform::Handle playerTransform, float speed )
		: playerTransform( playerTransform ),
		  moveSpeed( speed )
	{
	}
}
