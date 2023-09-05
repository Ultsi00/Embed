#ifndef CLASSES_H
# define CLASSES_H
# include "embed.h"

class Parameter
{
    private:
        int p_value;
    public:
        Parameter(int value);
        int     getParamValue() {return (p_value); }
        void    setParamValue(int value);

};

#endif