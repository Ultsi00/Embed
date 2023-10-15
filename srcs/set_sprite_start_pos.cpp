#include "../includes/embed.h"

/*
    Sets sprite y-coordinate based on screen resolution.
    Base resolution is 1280x720.
*/
int set_pos_x(int x) {
    x = x * SCREEN_WIDTH / 1280;
    return x;
}

/*
    Sets sprite x-coordinate based on screen resolution.
    Base resolution is 1280x720.
*/
int set_pos_y(int y) {
    y = y * SCREEN_HEIGHT / 720;
    return y;
}

/*
    Sets the initial coordinates for sprites.
    Sprites from embed_dev_nbs.png are not initially rendered.
    Sprite "device_light_green" from spritesheet embed_dev0.png is not initially rendered.
*/
void    set_sprite_start_pos(vector<DevicePart> &txt_container, 
            vector<DevicePart> &txt_nbs_container) {
    //controller
    txt_container[0].txt_x = set_pos_x(CTRL_FRAME_START_X);
    txt_container[0].txt_y = set_pos_y(CTRL_FRAME_START_Y);
    txt_container[1].txt_x = set_pos_x(CTRL_KNOB_START_X);
    txt_container[1].txt_y = set_pos_y(CTRL_KNOB_START_Y);

    //device
    txt_container[2].txt_x = set_pos_x(DEV_FRAME_START_X);
    txt_container[2].txt_y = set_pos_y(DEV_FRAME_START_Y);
    txt_container[3].txt_x = set_pos_x(DEV_SLIDER_START_X);
    txt_container[3].txt_y = set_pos_y(DEV_SLIDER_START_Y);
    txt_container[4].txt_x = set_pos_x(DEV_LIGHT_START_X);
    txt_container[4].txt_y = set_pos_y(DEV_LIGHT_START_Y);
    txt_container[5].txt_x = set_pos_x(DEV_LIGHT_START_X);
    txt_container[5].txt_y = set_pos_y(DEV_LIGHT_START_Y);

    //nbs
    for (int i = 0; i < (NBS_SPRITES + ERR_SPRITES); i++) {
        txt_nbs_container[i].txt_x = set_pos_x(NBS_ANCHOR_X);
        txt_nbs_container[i].txt_y = set_pos_y(NBS_ANCHOR_Y);
    }
}