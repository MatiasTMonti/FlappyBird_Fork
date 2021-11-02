#include "menu.h"

namespace FlappyBird
{
	Menu::Menu(Rectangle recs[maxButtonsMenu], const char* texts[maxButtonsMenu])
	{
		playButton = new Button(recs[0], buttonColor, texts[0]);
		play2Button = new Button(recs[1], buttonColor, texts[1]);
		creditsButton = new Button(recs[2], buttonColor, texts[2]);
		exitButton = new Button(recs[3], buttonColor, texts[3]);
	}
	Menu::~Menu()
	{
		delete playButton;
		delete play2Button;
		delete creditsButton;
		delete exitButton;
	}

	void Menu::Input(SceneManager* sceneManager, Scenes scenes[maxButtonsMenu], bool& isMultiplayer)
	{
		playButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[0]);
		play2Button->ChageSceneWhenButtonPressedP2(sceneManager, scenes[0], isMultiplayer);
		creditsButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[1]);
		exitButton->ChangeSceneWhenButtonPressed(sceneManager, scenes[2]);
	}
	void Menu::Update()
	{
		
	}
	void Menu::Draw()
	{
		BeginDrawing();

		ClearBackground(menuClearBackgroundColor);

		playButton->DrawButton();
		play2Button->DrawButton();
		creditsButton->DrawButton();
		exitButton->DrawButton();

		DrawText(version, GetScreenWidth() - 100, GetScreenHeight() - 50, creditsFontSize + 10, creditsColor);

		EndDrawing();
	}
}