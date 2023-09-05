#include "../includes/embed.h"

void    exit_prgm(t_sdl *sdl) {
    //destructor usage
    //destroy surface
    SDL_DestroyWindow(sdl->window);
    sdl->window = NULL;
    SDL_Quit();
    cout << "Program has been terminated." << endl;
    exit(0);
}
