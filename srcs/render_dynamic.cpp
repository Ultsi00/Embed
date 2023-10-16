#include "../includes/embed.h"

static void number_parser(int counter, int *nbs) {
    nbs[2] = counter * 0.01;
    nbs[0] = counter % 10;
    while (counter > 99) {
        counter = counter - 100;
    }
    nbs[1] = counter * 0.1;
}

static void render_numbers(t_sdl *sdl, vector<DevicePart> &txt_nbs_container, Param& param) {
    SDL_Rect quad;
    int nbs[3];

    //render Err
    if (param.counter >= 1000) {
        quad = {txt_nbs_container[11].txt_x, txt_nbs_container[11].txt_y,
            txt_nbs_container[11].getTxtWidth(), txt_nbs_container[11].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_nbs_container[11].getTxt(), txt_nbs_container[11].getClip(), &quad);
        quad = {txt_nbs_container[11].txt_x - (NBS_DIST), txt_nbs_container[11].txt_y,
            txt_nbs_container[11].getTxtWidth(), txt_nbs_container[11].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_nbs_container[11].getTxt(), txt_nbs_container[11].getClip(), &quad);
        quad = {txt_nbs_container[10].txt_x - (NBS_DIST * 2), txt_nbs_container[10].txt_y,
            txt_nbs_container[10].getTxtWidth(), txt_nbs_container[10].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_nbs_container[10].getTxt(), txt_nbs_container[10].getClip(), &quad);
    }
    //render numbers
    else {
        number_parser(param.counter, nbs);
        //right-hand side number: 0 0 X
        quad = {txt_nbs_container[nbs[0]].txt_x, txt_nbs_container[nbs[0]].txt_y,
            txt_nbs_container[nbs[0]].getTxtWidth(), txt_nbs_container[nbs[0]].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_nbs_container[nbs[0]].getTxt(), txt_nbs_container[nbs[0]].getClip(), &quad);
        //middle number: 0 X 0
        quad = {txt_nbs_container[nbs[1]].txt_x - (NBS_DIST), txt_nbs_container[nbs[1]].txt_y,
            txt_nbs_container[nbs[1]].getTxtWidth(), txt_nbs_container[nbs[1]].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_nbs_container[nbs[1]].getTxt(), txt_nbs_container[nbs[1]].getClip(), &quad);
        //left-hand side number: X 0 0
        quad = {txt_nbs_container[nbs[2]].txt_x - (NBS_DIST * 2), txt_nbs_container[nbs[2]].txt_y,
            txt_nbs_container[nbs[2]].getTxtWidth(), txt_nbs_container[nbs[2]].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_nbs_container[nbs[2]].getTxt(), txt_nbs_container[nbs[2]].getClip(), &quad);
    }
}

/*
    Render sprites, which have adjustable coordinates during program run.
    SDL_Rect quad = {x, y, w, h}
        x/y: sprite render coordinates
        w/h: sprite size. Use same as in DevicePart::loadMedia() to keep this original size,
            else, sprite will stretch/constrict.
*/
void render_dynamic(t_sdl *sdl, vector<DevicePart>& txt_container,
        vector<DevicePart> &txt_nbs_container, Param& param) {

    //controller knob (rotation affected by input, starts at default sprite appearance)
    SDL_Rect quad = {txt_container[1].txt_x, txt_container[1].txt_y,
        txt_container[1].getTxtWidth(), txt_container[1].getTxtHeight()};
    SDL_RenderCopy(sdl->renderer, txt_container[1].getTxt(), txt_container[1].getClip(), &quad);

    //device slider
    quad = {(txt_container[3].txt_x + (param.energy * SLIDER_STEPS * SCREEN_WIDTH / 1280)),
        txt_container[3].txt_y, txt_container[3].getTxtWidth(), txt_container[3].getTxtHeight()};
    SDL_RenderCopy(sdl->renderer, txt_container[3].getTxt(), txt_container[3].getClip(), &quad);

    //device light red/green (start(status == off): red)
    if (param.status == false) {
        quad = {txt_container[4].txt_x, txt_container[4].txt_y,
            txt_container[4].getTxtWidth(), txt_container[4].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_container[4].getTxt(), txt_container[4].getClip(), &quad);
    }
    else if (param.status == true) {
        quad = {txt_container[5].txt_x, txt_container[5].txt_y,
            txt_container[5].getTxtWidth(), txt_container[5].getTxtHeight()};
        SDL_RenderCopy(sdl->renderer, txt_container[5].getTxt(), txt_container[5].getClip(), &quad);
    }    

    //numbers
    render_numbers(sdl, txt_nbs_container, param);
}   
