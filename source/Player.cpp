#include <Scene.h>
#include <Components/Transform.h>
#include <Components/Mesh.h>

#include "Player.h"
#include "Components/Player.h"
#include "Components/PlayerCursor.h"

namespace Spectacle
{
	Gunship::Entity CreatePlayer( Gunship::Scene& scene )
	{
		Gunship::Entity player = scene.entities().Create();

		Gunship::Components::Transform& playerTransform =
			scene.componentManager< Gunship::Components::TransformManager >().Assign( player );
		scene.componentManager< Gunship::Components::MeshManager >().Assign( player, "Cube.mesh" );

		playerTransform.SetPosition( 0.0f, 0.0f, -10.0f );
		playerTransform.SetScale( 1.0f, 1.0f, 1.0f );

		return player;
	}

	Gunship::Entity CreateCursor( Gunship::Scene& scene, Gunship::Entity player )
	{
		Gunship::Entity cursor = scene.entities().Create();

/*
		Gunship::Components::Transform::Handle playerTransform = player.component< Gunship::Components::Transform >();
		Gunship::Components::Transform::Handle cursorTransform =
			cursor.assign< Gunship::Components::Transform >( scene );
		playerTransform->AddChild( cursorTransform );
		cursorTransform->SetScale( 0.3f, 0.3f, 0.3f );
		cursor.assign< Gunship::Components::Mesh >( scene, cursorTransform, "Cube.mesh" );

		cursor.assign< PlayerCursor >( playerTransform, 0.01f );
*/
		return cursor;
	}
}
