#include "printf.h"

flags_t get_flags(const char* format) {
    flags_t flags = { 0, 0, 0, 0, 0, 0 };

    while(*format != '\0') {
        if(*format == '-') flags.minus = 1;
        else if(*format == '+') flags.plus = 1;
        else if(*format == ' ') flags.space = 1;
        else if(*format == '#') flags.hash = 1;
        else if(*format == '0') flags.zero = 1;
        else return flags;

        flags.length++;
        format++;
    }

    return flags;
}
