#include "game_manager.h"

int main()
{
	FlappyBird::GameManager* game = new FlappyBird::GameManager();

	game->Run();

	delete game;

	return 0;
}