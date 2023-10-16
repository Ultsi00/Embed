#include "../includes/embed.h"

/*
	Loads all the spritesheets, for each texture object,
	by calling loadMedia() member function.
	Clips each sprite in the spritesheets to vector containers.
	Controller and Device sprites: txt_container,
		Number and Error sprites: txt_nbs_container.
*/
void load_media_main(t_sdl *sdl, vector<DevicePart>& txt_container,
		vector<DevicePart> &txt_nbs_container) {
			
    int clip_x = 0, clip_y = 0, i = 0;
	while (i < CTRL_SPRITES) {
    	txt_container[i].loadMedia(sdl, "spritesheets/embed_controller.png", clip_x, clip_y);
		clip_y = clip_y + (CTRL_SPRITESHEET_H / CTRL_SPRITES);
		i++;
	}
	clip_y = 0;
	while (i < (CTRL_SPRITES + DEV_SPRITES)) {
		txt_container[i].loadMedia(sdl, "spritesheets/embed_dev0.png", clip_x, clip_y);
		clip_y = clip_y + (DEV_SPRITESHEET_H / DEV_SPRITES);
		i++;
	}
	clip_y = 0;
	i = 0;
	while (i < NBS_SPRITES) {
		txt_nbs_container[i].loadMedia(sdl, "spritesheets/embed_dev0_nbs.png", clip_x, clip_y);
		clip_y = clip_y + (NBS_SPRITESHEET_H / NBS_SPRITES);
		i++;
	}
	clip_y = 0;
	while (i < (NBS_SPRITES + ERR_SPRITES)) {
		txt_nbs_container[i].loadMedia(sdl, "spritesheets/embed_dev0_err.png", clip_x, clip_y);
		clip_y = clip_y + (ERR_SPRITES_H / ERR_SPRITES);
		i++;
	}
}
