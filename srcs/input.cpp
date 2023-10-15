#include "../includes/embed.h"

void input(t_sdl *sdl, Param &param) {
    if (sdl->event.key.keysym.sym == SDLK_RETURN)
        param.status = (param.status == false ? true : false);
    else if (sdl->event.key.keysym.sym == SDLK_UP && param.status == true) {
        if (param.energy < 10)
            param.modifyEnergy(1);
    }
    else if (sdl->event.key.keysym.sym == SDLK_DOWN && param.status == true) {
        if (param.energy > 0)
            param.modifyEnergy(-1);
    }
    else if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
        exit_prgm(sdl,"");
}
