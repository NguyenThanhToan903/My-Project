#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.h"

using namespace std;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		cout << "Window faide to init. Error: " << SDL_Error << endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp() {
	SDL_DestroyWindow(window);
}


SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL) {
		cout << "Faide to load texture. Error: " << SDL_GetError() << endl;		
	}
	return texture;
}


void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex) {
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32; 

	SDL_Rect dst;
	dst.x = 400;
	dst.y = 200;
	dst.w = 32*4;
	dst.h = 32*4;

	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}