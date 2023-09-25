#ifndef EMBED_H
# define EMBED_H
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <iostream>
# include "classes.h"
const int   SCREEN_WIDTH = 1280;
const int   SCREEN_HEIGHT = 720;

using namespace std;

typedef struct s_sdl {
    SDL_Window  *window;
    SDL_Surface *surface;
    SDL_Event   event;
    SDL_Renderer *renderer;
    bool        quit;
    SDL_Texture *s_controller;  //think if smart to put textures in classes, else to sub-struct
}   t_sdl;

void    prgm_loop(Parameter& param, t_sdl *sdl);
void    sdl_init(t_sdl *sdl);
void    exit_prgm(t_sdl *sdl, string error_msg);
void    key_events(t_sdl *sdl); // necessary to send whole struct?
void    load_media(t_sdl *sdl);

#endif