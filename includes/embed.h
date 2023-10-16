#ifndef EMBED_H
#define EMBED_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>
#include "classes.h"
#include "txt_dimensions.h"
#include "txt_pos_modifiers.h"
const int   SCREEN_WIDTH = 1280;
const int   SCREEN_HEIGHT = 720;

using namespace std;

struct t_sdl {
    SDL_Window  *window;
    SDL_Event   event;
    SDL_Renderer *renderer;
    bool        quit;
};

void    sdl_init(t_sdl *sdl);
void    exit_prgm(t_sdl *sdl, string error_msg);
void    txts_init(vector<DevicePart>& txt_container, vector<DevicePart>& txt_nbs_container);
void    input(t_sdl *sdl, Param &param); //whole struct?
void    prgm_loop(t_sdl *sdl, vector<DevicePart> &txt_container,
            vector<DevicePart> &txt_nbs_container, Param &param);
void    load_media_main(t_sdl *sdl, vector<DevicePart>& txt_container,
            vector<DevicePart>& txt_nbs_container);
void    set_sprite_start_pos(vector<DevicePart> &txt_container,
            vector<DevicePart> &txt_nbs_container);
void    render(t_sdl *sdl, vector<DevicePart> &txt_container,
            vector<DevicePart> &txt_nbs_container, Param &param);
void    render_dynamic(t_sdl *sdl, vector<DevicePart>& txt_container,
            vector<DevicePart> &txt_nbs_container, Param& param);

#endif