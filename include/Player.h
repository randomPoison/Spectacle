#pragma once

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	entityx::Entity CreatePlayer( Gunship::Scene& scene );
	entityx::Entity CreateCursor( Gunship::Scene& scene, entityx::Entity player );
}
