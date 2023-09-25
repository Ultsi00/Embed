#include "../includes/embed.h"

void    key_events(t_sdl *sdl) {
    if (sdl->event.key.keysym.sym == SDLK_UP)
        cout << "up" << endl;
    if (sdl->event.key.keysym.sym == SDLK_DOWN)
        cout << "down" << endl;
    else if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
        exit_prgm(sdl,"");



}
