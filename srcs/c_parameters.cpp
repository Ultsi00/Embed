#include "../includes/embed.h"

Parameter::Parameter(int value) {
    setParamValue(value);
}

void    Parameter::setParamValue(int value) {
    p_value = value;
}