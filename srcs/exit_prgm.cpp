#include "../includes/embed.h"

void    exit_prgm(t_sdl *sdl, string error_msg) {
    cout << error_msg << endl;
    //destructor usage
    //destroy surface

    SDL_DestroyTexture(sdl->s_controller);    //all textures, loop or caveman
    sdl->s_controller = NULL;
    SDL_DestroyRenderer(sdl->renderer);
    sdl->renderer = NULL;
    SDL_DestroyWindow(sdl->window);
    sdl->window = NULL;
    SDL_Quit();
    cout << "Program has been terminated." << endl;
    exit(0);
}
