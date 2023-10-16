#ifndef CLASSES_H
# define CLASSES_H
# include "embed.h"

struct t_sdl;

class DevicePart
{
    private:
        uint16_t mW;
        uint16_t mH;
        SDL_Texture *mTxt;
        SDL_Rect mClip[1];
    public:
        DevicePart(uint16_t txt_w, uint16_t txt_h);
        ~DevicePart();
        int txt_x;
        int txt_y;
        inline int getTxtWidth() { return(mW); }
        inline int getTxtHeight() { return(mH); }
        void setTxtWidth(uint16_t txt_w);
        void setTxtHeight(uint16_t txt_h);
        void loadMedia(t_sdl *sdl, const char* txt_path, int clip_x, int clip_y);
        inline SDL_Texture* getTxt() { return mTxt; }
        inline SDL_Rect* getClip() { return mClip; }
};

class Param
{
    public:
        Param(bool status_start, int energy_start, int counter_start) {
            status = status_start;
            energy = energy_start;
            counter = counter_start;
        };
        bool    status;
        int     energy;
        int     counter;
        void modifyEnergy(int value) {
            energy = energy + (value);
            counter = energy * energy * energy;
        }
};

#endif