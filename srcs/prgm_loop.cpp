#include "../includes/embed.h"

void tester(t_sdl *sdl, vector<DevicePart>& txt_container) {
    SDL_Rect quad = {400, 200, 100, 100};
    SDL_RenderCopy(sdl->renderer, txt_container[0].getTxt(), txt_container[1].getClip(), &quad);
}

//
void render(t_sdl *sdl, vector<DevicePart>& txt_container) {
    tester(sdl, txt_container);

}


void ren(t_sdl *sdl, int x, int y, SDL_Rect *clippi, SDL_Texture *txt) {
    //x,y : where sprite is positioned
    //w,h : strect/constrict
    // w/h should be equal to values in sprite_sheet_main -> ss_txt, use .h
    SDL_Rect quad = {x, y, 200, 200}; //controller_frame.getW / .getH
    SDL_RenderCopy(sdl->renderer, txt, clippi, &quad);
}

void    prgm_loop(t_sdl *sdl, vector<DevicePart> &txt_container) {
    sdl->quit = false;
    while(sdl->quit == false) {
        while(SDL_PollEvent(&sdl->event)) {
            if (sdl->event.type == SDL_QUIT)
                sdl->quit = true;
            else if (sdl->event.type == SDL_KEYDOWN)
                key_events(sdl);
            SDL_RenderClear(sdl->renderer);
            SDL_SetRenderDrawColor(sdl->renderer, 0x00, 0x00, 0x00, 0x00);

            // ren(sdl, 200, 200, controller_frame.getClip(), controller_frame.getTxt());
            render(sdl, txt_container);

            SDL_RenderPresent(sdl->renderer);
            //render controller
            //render device
            //take input
            //render controller
            //send input to device
            //render device
            //validate input against device hardware
        }
    }
}
//SDL_SetRenderDrawColor(sdl->renderer, 0x11, 0x44, 0x23, 0x00);
