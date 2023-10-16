#include "../includes/embed.h"

DevicePart::DevicePart(uint16_t txt_w, uint16_t txt_h) {
    setTxtWidth(txt_w);
    setTxtHeight(txt_h);
}

void DevicePart::setTxtWidth(uint16_t txt_w) {
    mW = txt_w;
}

void DevicePart::setTxtHeight(uint16_t txt_h) {
    mH = txt_h;
}

/*
    Loads .png file from given path, sets the image to a member variable (mTxt),
    sets a selected clipping area of the image and stores these values to member
    variables.

    SDL_SetColorKey(): defines a colour code, which is considered transparent
        in the spritesheet. In this case, black.

    mClip:
    x, y: coordinates at which clipping starts in the spritesheet.
    w, h: clipped area in the spritesheet.
*/
void DevicePart::loadMedia(t_sdl *sdl, const char* txt_path, int clip_x, int clip_y) {
    SDL_Surface *loaded_surface = NULL;
    SDL_Texture *new_texture = NULL;

    loaded_surface = IMG_Load(txt_path);
    if (!loaded_surface)
        exit_prgm(sdl, "load_texture(): IMG_Load() fail.");
    SDL_SetColorKey(loaded_surface, true, SDL_MapRGB(loaded_surface->format, 0x00, 0x00, 0x00));
    new_texture = SDL_CreateTextureFromSurface(sdl->renderer, loaded_surface);
    if (!new_texture)
        exit_prgm(sdl, "load_texture(): SDL_CreateTextureFromSurface() fail.");
    SDL_FreeSurface(loaded_surface);
    loaded_surface = NULL;
    mTxt = new_texture;
    if (!mTxt)
        exit_prgm(sdl, "load_media(): load_texture() fail.");
    mClip->x = clip_x;
    mClip->y = clip_y;
    mClip->w = getTxtWidth();
    mClip->h = getTxtHeight();
}

DevicePart::~DevicePart() {
}
