#pragma once

#include "button.h"

namespace FlappyBird
{
	class Menu
	{
	private:
		Button* playButton;
		Button* play2Button;
		Button* creditsButton;
		Button* exitButton;
	public:
		Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu]);
		~Menu();

		void Input(SceneManager* sceneManager, Scenes scenes[maxButtonsMenu], bool& isMultiplayer);
		void Update();
		void Draw();
	};
}