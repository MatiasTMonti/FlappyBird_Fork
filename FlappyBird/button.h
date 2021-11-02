#pragma once

#include "scene_manager.h"

namespace FlappyBird
{
	class Button
	{
	private:
		Rectangle rec;
		Color color;
		const char* text;
		bool isMultiplayer;
	public:
		Button(Rectangle rec, Color color, const char* text);

		bool IsMouseOnButton();
		bool IsButtonPressed();
		void DrawButton();
		void ChangeSceneWhenButtonPressed(SceneManager* sceneManager, Scenes nextScene);
		void ChageSceneWhenButtonPressedP2(SceneManager* sceneManager, Scenes nextScene, bool& isMultiplayer);
	};
}