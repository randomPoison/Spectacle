#include <Input.h>
#include <Mouse.h>

#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>
#include <Utility/Random.h>

#include "Systems/LevelManagerSystem.h"

using Gunship::Entity;
using Gunship::Components::Transform;
using Gunship::Components::TransformManager;
using Gunship::Components::Mesh;
using Gunship::Components::MeshManager;

namespace Spectacle
{
	namespace Systems
	{
		void LevelManagerSystem::Update( Gunship::Scene& scene, float delta )
		{
			//if ( Gunship::Input::KeyPressed( SDL_SCANCODE_ESCAPE ) )
			//{
			//	Gunship::Mouse::SetRelativeMode( false );
			//}
			//else if ( Gunship::Input::MouseButtonDown( SDL_BUTTON_LEFT ) )
			//{
			//	Gunship::Mouse::SetRelativeMode( true );
			//}

			while ( entities.size() < 20 )
			{
				Gunship::Entity entity = scene.entities().Create();

				Gunship::Components::Transform& transform =
					scene.componentManager< TransformManager >().Assign( entity );
				transform.SetPosition(
					Random::Range( 0.0f, 10.0f ),
					Random::Range( -10.0f, 10.0f ),
					Random::Range( -10.0f, 10.0f ) );

				scene.componentManager< MeshManager >().Assign( entity, "Cube.mesh" );

				entities.push( entity );
			}

			while ( entities.size() > 10 )
			{
				Entity entity = entities.front();
				entities.pop();

				scene.componentManager< TransformManager >().Destroy( entity );
				scene.componentManager< MeshManager >().Destroy( entity );

				// TODO: Destroy popped entity.
			}
		}
	}
}

