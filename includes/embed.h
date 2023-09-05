#ifndef EMBED_H
# define EMBED_H
# include <SDL2/SDL.h>
# include <iostream>
# include "classes.h"
const int   SCREEN_WIDTH = 1280;
const int   SCREEN_HEIGHT = 720;

using namespace std;

typedef struct s_sdl {
    SDL_Window  *window;
    SDL_Surface *surface;
    SDL_Event   event;
    bool        quit;
}   t_sdl;

void    prgm_loop(Parameter& param, t_sdl *sdl);
void    sdl_init(t_sdl *sdl);
void    exit_prgm(t_sdl *sdl);

#endif