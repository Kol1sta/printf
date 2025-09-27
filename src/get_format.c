#include "stdint.h"
#include "stdarg.h"

#include "printf.h"

int get_format(const char specifier, va_list args, flags_t* flags, width_t* width) {
    int count = 0;

    if(specifier == 'c') {
        count += print_char(va_arg(args, int), width, flags);
    } else if(specifier == 'd' || specifier == 'i') {
        count += print_int(va_arg(args, int), width, flags);
    } else if(specifier == 's') {
        count += print_string(va_arg(args, char*), width, flags);
    } else if(specifier == 'p') {
        count += print_pointer(va_arg(args, void*), width, flags);
    } else if(specifier == 'u') {
        count += print_uint(va_arg(args, unsigned int), width, flags);
    } else if(specifier == 'f') {
        count += print_double(va_arg(args, double), width, flags);
    } else if(specifier == '%') {
        count += print_percent(width, flags);
    }

    return count;
}
