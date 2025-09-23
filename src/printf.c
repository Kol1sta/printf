#include "stdarg.h"
#include "unistd.h"

#include "./printf.h"

int _printf(const char* format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);
    char* current = (char*)format;

    while(*current != '\0') {
        if(*current == '%') {
            count += get_format(*(current + 1), args);
            current++;
        } else {
            write(1, current, 1);
            count++;
        }

        current++;
    }

    va_end(args);

    return count;
}
