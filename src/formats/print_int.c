#include "stdlib.h"

#include "../printf.h"

int print_int(int number, width_t* width, flags_t* flags) {
    int count = 0;
    int is_negative = 0;
    long number_long = number;

    if(number_long < 0) {
        is_negative = 1;
        number_long = -number_long;
    }

    if(is_negative) {
        count += print_char('-', NULL, NULL);
    } else if(flags->plus) {
        count += print_char('+', NULL, NULL);
    } else if(flags->space) {
        count += print_char(' ', NULL, NULL);
    }

    if(number_long == 0) {
        return count + print_char('0', NULL, NULL);
    }

    int reversed = 0;
    int digits = 0;

    while(number_long > 0) {
        reversed = reversed * 10 + (number_long % 10);
        number_long /= 10;
        digits++;
    }

    if(width != NULL && width->is_exists == 1) {
        count += set_width(width, width->width - digits);
    }

    while(digits > 0) {
        count += print_char('0' + (reversed % 10), NULL, NULL);
        reversed /= 10;
        digits--;
    }

    return count;
}
