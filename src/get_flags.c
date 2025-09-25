#include "printf.h"

flags_t get_flags(const char* format, int* count) {
    flags_t flags;
    flags.minus = 0;
    flags.plus = 0;
    flags.zero = 0;
    flags.space = 0;
    flags.hash = 0;

    flags.length = 0;

    while(*format != '\0') {
        switch(*format) {
            case '-':
                flags.minus = 1;
                break;
            case '+':
                flags.plus = 1;
                break;
            case '0':
                flags.zero = 1;
                break;
            case ' ':
                flags.space = 1;
                break;
            case '#':
                flags.hash = 1;
                break;
            default:
                return flags;
        }

        flags.length++;
        (*count)++;
        format++;
    }

    return flags;
}
