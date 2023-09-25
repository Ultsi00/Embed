#include "../includes/embed.h"

void    prgm_loop(Parameter& param_0, t_sdl *sdl) {
    sdl->quit = false;
    while(sdl->quit == false) {
        while(SDL_PollEvent(&sdl->event)) {
            if (sdl->event.type == SDL_QUIT)
                sdl->quit = true;
            else if (sdl->event.type == SDL_KEYDOWN)
                key_events(sdl);
            //render controller
            //render device
            //take input
            //render controller
            //send input to device
            //render device

            //validate input against device hardware
        }
    }


    // int x;
    // x = 1;
    // cout << param_0.getParamValue() << endl;
    // while(x != 0) {
    //     std::cin >> x;
    //     if (x != 0)
    //         param_0.setParamValue(x);
    // }

    SDL_FreeSurface(sdl->surface);
    sdl->surface = NULL;
    

}
