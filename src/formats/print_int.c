#include "../printf.h"

int print_int(int number, flags_t flags) {
    int count = 0;
    int is_negative = 0;
    long number_long = number;

    if(number_long < 0) {
        is_negative = 1;
        number_long = -number_long;
    }

    if(is_negative) {
        count += print_char('-');
    } else if(flags.plus) {
        count += print_char('+');
    }

    if(number_long == 0) {
        return count + print_char('0');
    }

    int reversed = 0;
    int digits = 0;

    while (number_long > 0) {
        reversed = reversed * 10 + (number_long % 10);
        number_long /= 10;
        digits++;
    }

    while (digits > 0) {
        count += print_char('0' + (reversed % 10));
        reversed /= 10;
        digits--;
    }

    return count;
}
