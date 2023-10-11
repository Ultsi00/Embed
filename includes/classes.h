#ifndef CLASSES_H
# define CLASSES_H
# include "embed.h"

struct t_sdl;   //forward declaration

class DevicePart
{
    private:
        int mW;
        int mH;
        SDL_Texture *mTxt;
        SDL_Rect mClip[1];
    public:
        DevicePart(int txt_w, int txt_h);
        int getTxtWidth() { return(mW); }
        int getTxtHeight() { return(mH); }
        void setTxtWidth(int txt_w);
        void setTxtHeight(int txt_h);
        void loadMedia(t_sdl *sdl, const char* txt_path);
        SDL_Texture* getTxt() { return mTxt; }
        SDL_Rect* getClip() { return mClip; }
};

#endif