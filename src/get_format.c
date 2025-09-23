#include "printf.h"
#include "stdint.h"
#include "stdarg.h"

int get_format(const char specifier, va_list args) {
    int count = 0;

    if(specifier == 'c') {
        count += print_char(va_arg(args, int));
    } else if(specifier == 'd') {
        count += print_int(va_arg(args, int));
    } else if(specifier == 's') {
        count += print_string(va_arg(args, char*));
    }

    return count;
}
