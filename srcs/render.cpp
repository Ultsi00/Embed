#include "../includes/embed.h"

/*
    Render sprites, which have fixed coordinates during program run.
    SDL_Rect quad = {x, y, w, h}
        x/y: sprite render coordinates
        w/h: sprite size. Use same as in DevicePart::loadMedia() to keep this original size,
            else, sprite will stretch/constrict.
*/
static void render_static(t_sdl *sdl, vector<DevicePart>& txt_container) {
    //controller frame
    SDL_Rect quad = {txt_container[0].txt_x, txt_container[0].txt_y,
        txt_container[0].getTxtWidth(), txt_container[0].getTxtHeight()};
    SDL_RenderCopy(sdl->renderer, txt_container[0].getTxt(), txt_container[0].getClip(), &quad);

    //device frame
    quad = {txt_container[2].txt_x, txt_container[2].txt_y,
        txt_container[2].getTxtWidth(), txt_container[2].getTxtHeight()};
    SDL_RenderCopy(sdl->renderer, txt_container[2].getTxt(), txt_container[2].getClip(), &quad);
}

/*
    Rendering function. Divided into sprites, which are not affected by user input,
    and into sprites, which are.
*/
void render(t_sdl *sdl, vector<DevicePart> &txt_container,
        vector<DevicePart> &txt_nbs_container, Param &param) {

    render_static(sdl, txt_container);
    render_dynamic(sdl, txt_container, txt_nbs_container, param);
}
