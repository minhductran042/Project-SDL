
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int FRAME_PER_SECOND = 25;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 255;

#define BLANK_TILE 0

#define TILE_SIZE  64
#define MAX_MAP_X_ 400
#define MAX_MAP_Y_ 10

typedef struct Map {
	int start_x_;
	int start_y_;
	int max_x_;
	int max_y_;
	int tile[MAX_MAP_Y_][MAX_MAP_X_];
	char* file_name_;
};

typedef struct Input {
	int left_;
	int right_;
	int up_;
	int down_;
	int jump_;
};

#endif 
