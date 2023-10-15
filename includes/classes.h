#ifndef CLASSES_H
# define CLASSES_H
# include "embed.h"

//forward declaration
struct t_sdl;

class DevicePart
{
    private:
        int mW;
        int mH;
        SDL_Texture *mTxt;
        SDL_Rect mClip[1];
    public:
        DevicePart(int txt_w, int txt_h);
        //destructor, define in c_device_part.cpp
        int txt_x;
        int txt_y;
        int getTxtWidth() { return(mW); }
        int getTxtHeight() { return(mH); }
        void setTxtWidth(int txt_w);
        void setTxtHeight(int txt_h);
        void loadMedia(t_sdl *sdl, const char* txt_path, int clip_x, int clip_y);
        SDL_Texture* getTxt() { return mTxt; }
        SDL_Rect* getClip() { return mClip; }
};

//if better name, change in the end.
//Could be derived for child classes, for different devices
//  keeping in Parent only status + counter
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
        void    modifyEnergy(int value) {
            energy = energy + (value);
            counter = energy * energy * energy;
        }


};

#endif