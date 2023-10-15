#include "../includes/embed.h"

//only for testing, remove
void input_output(Param &param) {
    cout << "status : " << param.status << endl;
    cout << "energy : " << param.energy << endl;
    cout << "counter : " << param.counter << endl;
}

void    prgm_loop(t_sdl *sdl, vector<DevicePart> &txt_container,
            vector<DevicePart> &txt_nbs_container, Param &param) {

    sdl->quit = false;
    while(sdl->quit == false) {
        while(SDL_PollEvent(&sdl->event)) {
            if (sdl->event.type == SDL_QUIT)
                sdl->quit = true;
            else if (sdl->event.type == SDL_KEYDOWN)
                input(sdl, param);

            SDL_RenderClear(sdl->renderer);
            SDL_SetRenderDrawColor(sdl->renderer, 0x00, 0x00, 0x00, 0x00);

            input_output(param);

            render(sdl, txt_container, txt_nbs_container, param);
            SDL_RenderPresent(sdl->renderer);
            //validate input against device hardware
        }
    }
}
//decent background colour:
//SDL_SetRenderDrawColor(sdl->renderer, 0x11, 0x44, 0x23, 0x00);
