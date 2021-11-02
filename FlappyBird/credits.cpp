#include "credits.h"

namespace FlappyBird
{
	Credits::Credits()
	{
		goMenuButton = new Button({ static_cast<float>(GetScreenWidth() / 2) - 150, static_cast<float>(GetScreenHeight() / 2), 300.0f, 40.0f }, buttonColor, "MENU");
	}
	Credits::~Credits()
	{
		delete goMenuButton;
	}

	void Credits::Input(SceneManager* sceneManager)
	{
		goMenuButton->ChangeSceneWhenButtonPressed(sceneManager, Scenes::menu);
	}
	void Credits::Update()
	{

	}
	void Credits::Draw()
	{
		BeginDrawing();

		ClearBackground(creditsClearBackgroundColor);

		goMenuButton->DrawButton();

		DrawText("GAME DEVELOPED BY MATIAS MONTI", GetScreenHeight() / 2 - 50, 25, creditsFontSize, creditsColor);
		DrawText("Bird: Facundo Williams", GetScreenHeight() / 2 - 50, 70, creditsFontSize, creditsColor);
		DrawText("Parallax: Facundo Williams", GetScreenHeight() / 2 - 50, 115, creditsFontSize, creditsColor);
		DrawText(version, GetScreenWidth(), GetScreenHeight() - 50, creditsFontSize + 10, creditsColor);

		EndDrawing();
	}
}