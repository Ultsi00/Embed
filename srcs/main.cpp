#include "../includes/embed.h"

int main(int argc, char **argv) {
    //parameter goes into vector container, in which each iterator is another param
    //same for device(s)
    Parameter param_0 = Parameter(1);

    t_sdl   sdl;
    sdl_init(&sdl);
    //loads(), etc.
    load_media(&sdl);
    //additional stuff
    //class parameter is changed to vector
    // prgm_loop(param_0, &sdl);

    return 0;
}
