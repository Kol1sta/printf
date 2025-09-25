#include "stdarg.h"
#include "unistd.h"

#include "./printf.h"

#include "stdio.h"

int _printf(const char* format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);
    char* current = (char*)format;

    while(*current != '\0') {
        if(*current == '%') {
            if(*(current + 1) == '\0') {
                break;
            }

            flags_t flags = get_flags(current + 1, &count);

            count += get_format(*(current + flags.length + 1), args);
            current += flags.length + 1;
        } else {
            write(1, current, 1);
            count++;
        }

        current++;
    }

    va_end(args);

    return count;
}
