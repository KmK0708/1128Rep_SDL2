#include <iostream>

#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

int SDL_main(int argc, char* argv[])
{
	srand((unsigned int)time(nullptr));

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("Hello World", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	SDL_Event MyEvent;
	bool IsRunning = true;
	while (IsRunning) // message loop
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_QUIT:
			IsRunning = false;
			break;
		case SDL_KEYDOWN:
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
			{
				IsRunning = false;
			}
			break;
		}
		// º×
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0x00);
		SDL_RenderClear(MyRenderer);
		
		for (int i = 0; i < 1000; ++i)
		{
			int X = rand() % 800;
			int Y = rand() % 600;
			int W = rand() % 90 + 10;
			int H = rand() % 90 + 10;
			int R = rand() % 256;
			int G = rand() % 256;
			int B = rand() % 256;
			int A = rand() % 256;
			SDL_SetRenderDrawColor(MyRenderer, R, G, B, A);
			SDL_Rect MyRect = { X, Y, W, H };
			SDL_RenderFillRect(MyRenderer, &MyRect);
		}

		SDL_RenderPresent(MyRenderer);
	}

	SDL_Quit();

	return 0;
}