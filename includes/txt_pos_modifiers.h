#ifndef TXT_POS_MODIFIERS_H
#define TXT_POS_MODIFIERS_H
#include "embed.h"

//default start x/y coordinates for sprites
#define CTRL_FRAME_START_X (220 * (SCREEN_WIDTH / 1280))
#define CTRL_FRAME_START_Y (200 * (SCREEN_HEIGHT / 720))
#define CTRL_KNOB_START_X (240 * (SCREEN_WIDTH / 1280))
#define CTRL_KNOB_START_Y (295 * (SCREEN_HEIGHT / 720))
#define DEV_FRAME_START_X (600 * (SCREEN_WIDTH / 1280))
#define DEV_FRAME_START_Y (170 * (SCREEN_HEIGHT / 720))
#define DEV_SLIDER_START_X (682 * (SCREEN_WIDTH / 1280))
#define DEV_SLIDER_START_Y (386 * (SCREEN_HEIGHT / 720))
#define DEV_LIGHT_START_X (650 * (SCREEN_WIDTH / 1280))
#define DEV_LIGHT_START_Y (220 * (SCREEN_HEIGHT / 720))

#define NBS_ANCHOR_X (DEV_FRAME_START_X + 380)
#define NBS_ANCHOR_Y (DEV_FRAME_START_Y + 80)

//steps, by which a certain sprite moves depending on user input
#define SLIDER_STEPS 29
#define NBS_DIST (50 * SCREEN_WIDTH / 1280)

#endif