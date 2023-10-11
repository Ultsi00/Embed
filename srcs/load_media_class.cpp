#include "../includes/embed.h"

/*
    x,y: coordinates at which clipping starts in the spritesheet.
    w,h: area of the clipped part in the spritesheet.
    To maintain the original size, set w/h equal to the size of the sprite in the sheet.
*/
static void sprite_clip_txt(SDL_Rect *clip, int x, int y, int w, int h) {
    clip->x =  x;
    clip->y =  y;
    clip->w =  w;
    clip->h =  h;
}

static void sprite_clip_main(t_sdl *sdl) {
    sprite_clip_txt(&sdl->sc_controller[0], 0, 0, 56, 56);
    sprite_clip_txt(&sdl->sc_controller[1], 0, (1024 / 2) - 1, 184, 352);
    //rest of the spritesheets
}

static SDL_Texture *load_texture(t_sdl *sdl) {
    SDL_Surface *loaded_surface = NULL; //not here lol. put in struct. use for all sprites. used, freed, used...
    SDL_Texture *new_texture = NULL;
    loaded_surface = IMG_Load("spritesheets/embed_controller.png"); //think if ABS or REL path
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

void load_media_class(vector<DevicePart> &v_texture, t_sdl *sdl) {
    SDL_Texture *clip_temp = NULL;
    clip_temp = load_texture(sdl);
    if (!clip_temp)
        exit_prgm(sdl, "load_media(): load_texture() fail.");
    
    v_textures[0].setTexture(clip_temp);
    //free clip_temp
    
    
    sprite_clip_main(sdl);
}
