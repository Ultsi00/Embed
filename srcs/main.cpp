#include "../includes/embed.h"

int main(int argc, char **argv) {
    
    //parameter goes into vector container, in which each iterator is another param
    //same for device(s)
    Parameter param_0 = Parameter(1);
    //loads(), etc.
    //additional stuff
    t_sdl   sdl;
    sdl_init(&sdl);
    //class parameter is changed to vector
    prgm_loop(param_0, &sdl);

    cout << param_0.getParamValue() << endl;

    return 0;
}
