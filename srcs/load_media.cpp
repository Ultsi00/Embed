#include "../includes/embed.h"

static SDL_Texture *load_texture(t_sdl *sdl, string path) {
    SDL_Texture *new_texture = NULL;
    SDL_Surface *loaded_surface = IMG_Load(path);
    if (!loaded_surface)
        exit_prgm(sdl, "load_texture(): IMG_Load() fail.");
    //This defines a transparent colour, in this case 'black'
    SDL_SetColorKey(loaded_surface, true, SDL_MapRGB(loaded_surface->format, 0x00, 0x00, 0x00));
    new_texture = SDL_CreateTextureFromSurface(sdl->renderer, loaded_surface);
    if (!new_texture)
        exit_prgm(sdl, "load_texture(): SDL_CreateTextureFromSurface() fail.");
    SDL_FreeSurface(loaded_surface);
    return new_texture; //think if this needs to be destroyed, now it contains a spritesheet
}

void load_media(t_sdl *sdl) {
    sdl->s_controller = load_texture(sdl, "spritesheets/embed_controller.png"); //think if ABS or REL path
    //rest of the spritesheets
    if (!sdl->s_controller)
        exit_prgm(sdl, "load_media(): load_texture() fail.");
}
