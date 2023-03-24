#include <Windows.h>
#include "BaseFunction.h"
#include "BaseObject.h"

BaseObject g_background;

bool Init() {
	bool sucess = true;
	int start = SDL_Init(SDL_INIT_VIDEO);
	if (start < 0) {
		return false;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
	g_window = SDL_CreateWindow("PROJECT GAME 22028244", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (g_window == NULL) {
		sucess = false;
	}
	else {
		g_screen = SDL_CreateRenderer(g_window, - 1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL) {
			sucess = false;
		}
		else {
			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags)) {
				sucess = false;
			}
		}
	}
	return sucess;
}

bool LoadBackground()
{
	bool ret = g_background.LoadImg("img/bg.png", g_screen);
	if (ret == false) {
		return false;
	}
	return true;
}

void close() {
	g_background.Free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;

	SDL_DestroyWindow(g_window);
	g_window = NULL;
	
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	if (Init() == false) {
		return false;
	}
	if (LoadBackground() == false) {
		return false;
	}
	bool is_quit = false;
	while (!is_quit) {
		while (SDL_PollEvent(&g_event) != 0){
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
			}
		}
		SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(g_screen);

		g_background.Render(g_screen, NULL);

		SDL_RenderPresent(g_screen);
	}
	close();
	return 0;
}