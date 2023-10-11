#include "../includes/embed.h"

// w/h: from outside (use txt_dimensions.h macroes)
void txts_init(vector<DevicePart> &txt_container) {

    DevicePart controller_frame = DevicePart(CTRL_FRAME_W, CTRL_FRAME_H);
    DevicePart controller_knob = DevicePart(CTRL_KNOB_W, CTRL_KNOB_H);
    DevicePart device_frame = DevicePart(DEV_FRAME_W, DEV_FRAME_H);
    DevicePart device_slider = DevicePart(DEV_SLIDER_W, DEV_SLIDER_H);
    DevicePart device_light_red = DevicePart(DEV_LIGHT_W, DEV_LIGHT_H);
    DevicePart device_light_green = DevicePart(DEV_LIGHT_W, DEV_LIGHT_H);
    DevicePart number_0 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_1 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_2 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_3 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_4 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_5 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_6 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_7 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_8 = DevicePart(DEV_NB_W, DEV_NB_H);
    DevicePart number_9 = DevicePart(DEV_NB_W, DEV_NB_H);

    txt_container = {controller_frame, controller_knob, device_frame, device_slider, device_light_red,
        device_light_green, number_0, number_1, number_2, number_3, number_4, number_5,
        number_6, number_7, number_8, number_9};
}
