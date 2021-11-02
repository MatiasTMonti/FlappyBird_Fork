#pragma once

#include "button.h"

namespace FlappyBird
{
	class Credits
	{
	private:
		Button* goMenuButton;
	public:
		Credits();
		~Credits();

		void Input(SceneManager* sceneManager);
		void Update();
		void Draw();
	};
}