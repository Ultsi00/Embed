#include "../includes/embed.h"

DevicePart::DevicePart(int txt_w, int txt_h) {
    setTxtWidth(txt_w);
    setTxtHeight(txt_h);
}

void DevicePart::setTxtWidth(int txt_w) {
    mW = txt_w;
}

void DevicePart::setTxtHeight(int txt_h) {
    mH = txt_h;
}

void DevicePart::loadMedia(t_sdl *sdl, const char* txt_path, int clip_x, int clip_y) {
    SDL_Surface *loaded_surface = NULL;
    SDL_Texture *new_texture = NULL;

    loaded_surface = IMG_Load(txt_path);
    if (!loaded_surface)
        exit_prgm(sdl, "load_texture(): IMG_Load() fail.");
    //This defines a transparent colour, in this case 'black'
    SDL_SetColorKey(loaded_surface, true, SDL_MapRGB(loaded_surface->format, 0x00, 0x00, 0x00));
    new_texture = SDL_CreateTextureFromSurface(sdl->renderer, loaded_surface);
    if (!new_texture)
        exit_prgm(sdl, "load_texture(): SDL_CreateTextureFromSurface() fail.");
    SDL_FreeSurface(loaded_surface);
    mTxt = new_texture;
    if (!mTxt)
        exit_prgm(sdl, "load_media(): load_texture() fail.");
    // x,y: coordinates at which clipping starts in the spritesheet.
    // w,h: area of the clipped part in the spritesheet.
    // To maintain the original size, set w/h equal to the size of the sprite in the sheet.
    mClip->x = clip_x;
    mClip->y = clip_y;
    mClip->w = getTxtWidth();
    mClip->h = getTxtHeight();
}
