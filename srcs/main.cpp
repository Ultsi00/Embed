#include "../includes/embed.h"

int main() {
    t_sdl   sdl;
    sdl_init(&sdl);

    Param param = Param(false, 0, 0);
    vector<DevicePart> txt_container;
    vector<DevicePart> txt_nbs_container;
    txts_init(txt_container, txt_nbs_container);
    load_media_main(&sdl, txt_container, txt_nbs_container);
    set_sprite_start_pos(txt_container, txt_nbs_container);
    prgm_loop(&sdl, txt_container, txt_nbs_container, param);
    return 0;
}
