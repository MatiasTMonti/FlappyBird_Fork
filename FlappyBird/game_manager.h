#pragma once

#include "menu.h"
#include "credits.h"
#include "gameplay.h"

namespace FlappyBird
{
	class GameManager
	{
	private:
		SceneManager* sceneManager;
		Menu* menu;
		Credits* credits;
		Gameplay* gameplay;

		Scenes menuInputScenes[maxButtonsMenu];

		bool exit;
		bool isMultiplayer;
	public:
		GameManager();
		~GameManager();

		void Init();
		void Deinit();
		void Run();
	};
}