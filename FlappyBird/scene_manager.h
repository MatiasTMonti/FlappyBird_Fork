#pragma once

#include "variables.h"

namespace FlappyBird
{
	class SceneManager
	{
	private:
		Scenes currentScene;
	public:
		SceneManager();

		void SetCurrentScene(Scenes currentScene);
		Scenes GetCurrentScene();
	};
}