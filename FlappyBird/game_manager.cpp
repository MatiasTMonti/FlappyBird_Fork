#include "game_manager.h"

namespace FlappyBird
{
    GameManager::GameManager()
    {
        InitWindow(screenWidth, screenHeight, tittle);

        SetTargetFPS(fps);

        Init();
    }
    GameManager::~GameManager()
    {
        CloseWindow();

        Deinit();
    }

    void GameManager::Init()
    {
        sceneManager = new SceneManager();

        Rectangle recs[maxButtonsMenu];
        recs[0] = { 50, 50, 300, 40 };
        recs[1] = { 50, 120, 300, 40 };
        recs[2] = { 50, 190, 300, 40 };
        recs[3] = { 50, 260, 300, 40 };

        const char* texts[maxButtonsMenu];
        texts[0] = "PLAY";
        texts[1] = "2 V 2";
        texts[2] = "CREDITS";
        texts[3] = "EXIT";

        menu = new Menu(recs, texts);

        menuInputScenes[0] = Scenes::gameplay;
        menuInputScenes[1] = Scenes::credits;
        menuInputScenes[2] = Scenes::exit;

        credits = new Credits();
        gameplay = new Gameplay();

        exit = false;
    }
    void GameManager::Deinit()
    {
        delete sceneManager;
        delete menu;
        delete credits;
        delete gameplay;
    }
    void GameManager::Run()
    {
        while (!WindowShouldClose() && !exit)    // Detect window close button or ESC key
        {
            switch (sceneManager->GetCurrentScene())
            {
            case Scenes::menu:

                menu->Input(sceneManager, menuInputScenes, isMultiplayer);
                menu->Update();
                menu->Draw();

                if (sceneManager->GetCurrentScene() == Scenes::gameplay && isMultiplayer)
                {
                    gameplay->ActivateMultiplayer();
                }

                break;
            case Scenes::credits:

                credits->Input(sceneManager);
                credits->Update();
                credits->Draw();

                break;
            case Scenes::gameplay:

                gameplay->Input();
                gameplay->Update(sceneManager);
                gameplay->Draw();

                isMultiplayer = gameplay->isMultiplayer;

                break;
            case Scenes::exit:

                exit = true;

                break;
            }
        }
    }
}