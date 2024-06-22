#include "Game.hpp"

Game* game = nullptr;

int main(int n, char* b[])
{


	const int FPS = 75;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	game = new Game();
	game->init("Engine 69", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return 0;
}
