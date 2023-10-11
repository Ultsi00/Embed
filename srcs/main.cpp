#include "../includes/embed.h"

int main(int argc, char **argv) {
    t_sdl   sdl;
    sdl_init(&sdl);

    vector<DevicePart> txt_container;
    txts_init(txt_container);


    txt_container[0].loadMedia(&sdl, "spritesheets/embed_controller.png"); //these into load_main

    prgm_loop(&sdl, txt_container); //change: controller_frame -> txt_container

    return 0;
}
