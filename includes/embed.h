#ifndef EMBED_H
#define EMBED_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>
#include "classes.h"
#include "txt_dimensions.h"
const int   SCREEN_WIDTH = 1680;
const int   SCREEN_HEIGHT = 1080;

using namespace std;

struct t_sdl {
    SDL_Window  *window;
    SDL_Event   event;
    SDL_Renderer *renderer;
    bool        quit;
    SDL_Texture *s_controller;      //remove. see load_media()
    SDL_Rect    sc_controller[2]; //remove. see load_media()
};

void    prgm_loop(t_sdl *sdl, vector<DevicePart> &txt_container);
void    sdl_init(t_sdl *sdl);
void    exit_prgm(t_sdl *sdl, string error_msg);
void    key_events(t_sdl *sdl); // necessary to send whole struct?
void    load_media(t_sdl *sdl); // remove from .h. See notes in load_media()
void    txts_init(vector<DevicePart> &txt_container);

#endif
