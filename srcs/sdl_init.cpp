#include "../includes/embed.h"

//Comment out all function, make this with Renderer instead of CPU
void    sdl_init(t_sdl *sdl) {
    sdl->window = NULL;
    sdl->surface = NULL;
    sdl->renderer = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        exit_prgm(sdl, "sdl_init(): SDL_INIT fail.");
    else {
        sdl->window = SDL_CreateWindow("embed", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (sdl->window == NULL)
            exit_prgm(sdl, "sdl_init(): SDL_CreateWindow() fail.");
        sdl->surface = SDL_GetWindowSurface(sdl->window);
        if (sdl->surface == NULL)
            exit_prgm(sdl, "sdl_init(): SDL_GetWindowSurface() fail.");
        SDL_FillRect(sdl->surface, NULL, 
            SDL_MapRGB(sdl->surface->format, 0x88, 0x88, 0x11));
        SDL_UpdateWindowSurface(sdl->window);
	}
}

//renderer stuff:
//
// SDL_Renderer *renderer = NULL;
// renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//     SDL_RenderClear(renderer);

//     SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);   //rgba
//     SDL_Rect fillRect = {SCREEN_W / 4, SCREEN_H / 4, 50, 200};

//     SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x99, 0x99);
//     SDL_RenderFillRect(renderer, &fillRect);
//     SDL_Rect outlineRect = {SCREEN_W / 2, SCREEN_H / 4, 50, 200};

//     SDL_SetRenderDrawColor(renderer, 0xBB, 0x00, 0x00, 0xFF);
//     SDL_RenderDrawRect(renderer, &outlineRect);
//     //Render a line
//     SDL_SetRenderDrawColor(renderer, 0x00, 0xCC, 0x00, 0x00);
//     SDL_RenderDrawLine(renderer, 10, 100, 700, 100);
//     //Render a line using dots ("pixelPut")
//     SDL_SetRenderDrawColor(renderer, 0xBB, 0x00, 0xFF, 0xFF);
//     int x_drawPixel = SCREEN_W * 0.8;
//     int y_drawPixel = SCREEN_H * 0.2;
//     while (y_drawPixel <= (SCREEN_H * 0.4))
//     {
//         SDL_RenderDrawPoint(renderer, x_drawPixel, y_drawPixel);
//         y_drawPixel = y_drawPixel + 1;
//         x_drawPixel = x_drawPixel + 1;
//     }

//     SDL_RenderPresent(renderer);
