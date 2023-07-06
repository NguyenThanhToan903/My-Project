#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#undef	main

#include "RenderWindow.h"
using namespace std;

int main() {
	if ((SDL_Init(SDL_INIT_VIDEO)) > 0)
		cout << "Error_SDL: " << SDL_GetError << endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "Error_SDL_Image: " << SDL_GetError << endl;

	RenderWindow window("Game v1.0", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("../res/gfx/grass.png");

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
		window.clear();
		window.render(grassTexture);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}