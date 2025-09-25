#include "./printf.h"

width_t get_width(const char* format) {
    width_t width;
    width.width = 0;
    width.length = 0;

    while(*format != '\0' && (*format < '0' || *format > '9')) {
        format++;
    }

    while(*format >= '0' && *format <= '9') {
        width.width = width.width * 10 + (*format - '0');
        width.length++;
        format++;
    }

    return width;
}
