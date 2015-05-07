#pragma once

namespace Gunship
{
	class Scene;
}

namespace Spectacle
{
	Gunship::Entity CreatePlayer( Gunship::Scene& scene );
	Gunship::Entity CreateCursor( Gunship::Scene& scene, Gunship::Entity player );
}
