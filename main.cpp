#include <Windows.h>
#include "BaseFunction.h"
#include "BaseObject.h"
#include "Game_map.h"
#include "MainObject.h"
#include "ImpTimer.h"

BaseObject g_background;

bool Init() {
	bool sucess = true;
	int start = SDL_Init(SDL_INIT_VIDEO);
	if (start < 0) {
		return false;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
	g_window = SDL_CreateWindow("PROJECT GAME 22028244", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
	bool ret = g_background.LoadImg("img//Background.png", g_screen);
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

int main(int argc, char* argv[]){

	ImpTimer fps_timer;

	if (Init() == false) {
		return -1;
	}
	if (LoadBackground() == false) {
		return -1;
	}
	GameMap game_map;
	char gm[] = "map//map01.dat";
	game_map.LoadMap(gm);
	game_map.LoadTiles(g_screen);

	MainObject p_player;
	p_player.LoadImg("img//player_right.png", g_screen);
	p_player.set_clip();

	bool is_quit = false;
	while (!is_quit) {
		fps_timer.start();
		while (SDL_PollEvent(&g_event) != 0){
			if (g_event.type == SDL_QUIT) {
				is_quit = true;
			}
			p_player.HandleInputAction(g_event, g_screen);
		}
		SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(g_screen);

		g_background.Render(g_screen, NULL);

		Map map_data = game_map.getMap();

		p_player.HandleBullet(g_screen);
		p_player.SetMapXY(map_data.start_x_, map_data.start_y_);
		p_player.DoPlayer(map_data);
		p_player.Show(g_screen);

		game_map.SetMap(map_data);
		game_map.DrawMap(g_screen);


		SDL_RenderPresent(g_screen);

		int real_imp_time = fps_timer.get_ticks();
		int time_one_frame = 1000 / FRAME_PER_SECOND;

		if (real_imp_time < time_one_frame) {
			int delay_time = time_one_frame - real_imp_time;
			if (delay_time >= 0) {
				SDL_Delay(delay_time);
			}
		}
	}

	close();

	return 0;
}