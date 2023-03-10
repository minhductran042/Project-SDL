
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

SDL_Surface *g_screen = NULL;
SDL_Surface *g_bk = NULL;
SDL_Event g_even;

bool Init(){
    if(SDL_Init(SDL_INIT_EVERYTHING == -1)){
        return false;
    }
    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE){
        if(g_screen==NULL){
            return false;
        }
    }
    return true;
}

SDL_Surface* LoadImage(string file_path){
    SDL_Surface *load_image=NULL;
    SDL_Surface *optimize_image = NULL;

    load_image = IMG_Load(file_path.c_str());
    if(load_image != NULL){
        optimize_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
    }
    return optimize_image;
}

void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, des, &offset);
}

void CleanUp(){
    SDL_FreeSurface(g_screen);
    SDL_FreeSurface(g_bk);
    // giai phong bo nho
}


int main(int arc, char* argv[]){

    bool is_quit = false;
    if(Init==false){
        return 0;
    }
    g_bk = LoadImage("bgr.jpg");
    if(g_bk == NULL){
        return 0;
    }
    ApplySurface(g_bk, g_screen, 0 , 0 );
    while(is_quit){
        while(SDL_PollEvent(&g_even)){
            is_quit = true;
            break;
        }
        if(SDL_Flip(g_screen) == -1){
            return 0;
        }
    }
    CleanUp();
    SDL_Quit();
}
