#include "gameplay.h"

namespace FlappyBird
{
	Gameplay::Gameplay()
	{
		character = new Character();

		obstacle = new Obstacle();

		isMultiplayer = false;

		obstacleVelocity = baseObstacleVelocity;

		LoadTextures();
		ResizeTextures();

		scrollingBack = 0.0f;
		scrollingBackTwo = 0.0f;
		scrollingMidOne = 0.0f;
		scrollingMidTwo = 0.0f;
		scrollingFore = 0.0f;
	}
	Gameplay::~Gameplay()
	{
		delete character;
		delete obstacle;

		if (!character2)
		{
			delete character2;
		}

		UnloadTextures();
	}

	void Gameplay::Input()
	{
		character->InputCharacter('W');

		if (isMultiplayer)
		{
			character2->InputCharacter('P');
		}
	}
	void Gameplay::Update(SceneManager* sceneManager)
	{
		character->UpdateCharacter();

		if (isMultiplayer)
		{
			character2->UpdateCharacter();
		}

		obstacle->UpdateObstacle(obstacleVelocity);

		EndGameCondition(sceneManager);

		BackgroundTexturesParallax();
	}
	void Gameplay::Draw()
	{
		BeginDrawing();
		ClearBackground(gameClearBackgroundColor);

		DrawBackgroundTextures();

		character->DrawCharacter();

		if (isMultiplayer)
		{
			character2->DrawCharacter();
		}

		obstacle->DrawObstacle();

		EndDrawing();
	}

	bool Gameplay::CollisionCharacterObstacle(Character* character, Obstacle* obstacle)
	{
		return (CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetTopRec())
			|| CheckCollisionCircleRec(character->GetPosition(), character->GetRadius(), obstacle->GetDownRec()));
	}
	void Gameplay::EndGameCondition(SceneManager* sceneManager) //Las dos condiciones de derrota son la colision de los objetos y cuando el pajaro toca el borde
	{
		if (!isMultiplayer)
		{
			if (CollisionCharacterObstacle(character, obstacle))
			{
				ResetGame();

				sceneManager->SetCurrentScene(Scenes::menu);
			}

			if (character->PlayerTouchesDownBorder())
			{
				ResetGame();
			}
		}
		else
		{
			if (CollisionCharacterObstacle(character, obstacle) || CollisionCharacterObstacle(character2, obstacle))
			{
				ResetGame();

				sceneManager->SetCurrentScene(Scenes::menu);
			}

			if (character->PlayerTouchesDownBorder() || character2->PlayerTouchesDownBorder())
			{
				ResetGame();

				sceneManager->SetCurrentScene(Scenes::menu);
			}
		}
	}
	void Gameplay::ResetGame() //Resetea las variables del pajaro y el obstaculo
	{
		obstacle->ResetObstaclePosition();
		character->ResetCharacter();

		if (isMultiplayer)
		{
			character2->ResetCharacter();
			delete character2;
			isMultiplayer = false;
		}
	}

	void Gameplay::LoadTextures()
	{
		backgroundSky = LoadTexture("assets/sky.png");
		backgroundMountain = LoadTexture("assets/glacial_mountains.png");
		midgroundCloudsTwo = LoadTexture("assets/clouds_mg_2.png");
		midgroundCloudsOne = LoadTexture("assets/clouds_mg_1.png");
		backgroundClouds = LoadTexture("assets/clouds_bg.png");
		foregroundLonelyCloud = LoadTexture("assets/cloud_lonely.png");
	}
	void Gameplay::ResizeTextures() //El fondo azul lo iguala a la pantalla
	{
		backgroundSky.width = GetScreenWidth();
		backgroundSky.height = GetScreenHeight();
	}
	void Gameplay::UnloadTextures()
	{
		UnloadTexture(backgroundSky);
		UnloadTexture(backgroundMountain);
		UnloadTexture(midgroundCloudsTwo);
		UnloadTexture(midgroundCloudsOne);
		UnloadTexture(backgroundClouds);
		UnloadTexture(foregroundLonelyCloud);
	}
	void Gameplay::DrawBackgroundTextures()
	{
		DrawTexture(backgroundSky, 0, 0, texturesColor);

		DrawTextureEx(backgroundClouds, { scrollingBack, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(backgroundClouds, { backgroundClouds.width * 2.0f + scrollingBack, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(backgroundMountain, { scrollingBackTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(backgroundMountain, { backgroundMountain.width * 2.0f + scrollingBackTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(midgroundCloudsTwo, { scrollingMidOne, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(midgroundCloudsTwo, { midgroundCloudsTwo.width * 2.0f + scrollingMidOne, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(midgroundCloudsOne, { scrollingMidTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(midgroundCloudsOne, { midgroundCloudsOne.width * 2.0f + scrollingMidTwo, backgroundYPos }, 0.0f, backgroundSize, texturesColor);

		DrawTextureEx(foregroundLonelyCloud, { scrollingFore, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
		DrawTextureEx(foregroundLonelyCloud, { foregroundLonelyCloud.width * 2.0f + scrollingFore, backgroundYPos }, 0.0f, backgroundSize, texturesColor);
	}
	void Gameplay::BackgroundTexturesParallax()
	{
		scrollingBack -= 0.1f;
		scrollingBackTwo -= 0.25f;
		scrollingMidOne -= 0.5f;
		scrollingMidTwo -= 0.75f;
		scrollingFore -= 1.25f;

		if (scrollingBack <= -backgroundClouds.width * 2) { scrollingBack = 0; }
		if (scrollingBackTwo <= -backgroundMountain.width * 2) { scrollingBackTwo = 0; }
		if (scrollingMidOne <= -midgroundCloudsTwo.width * 2) { scrollingMidOne = 0; }
		if (scrollingMidTwo <= -midgroundCloudsOne.width * 2) { scrollingMidTwo = 0; }
		if (scrollingFore <= -foregroundLonelyCloud.width * 2) { scrollingFore = 0; }
	}
	void Gameplay::ActivateMultiplayer()
	{
		character2 = new Character();
		isMultiplayer = true;
	}
}