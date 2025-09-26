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

    int digits = 0;
    long temp = number_long;

    if(temp == 0) {
        digits = 1;
    } else {
        while(temp > 0) {
            digits++;
            temp /= 10;
        }
    }

    int sign_needed = is_negative || flags->plus || flags->space;
    int total_length = digits + (sign_needed ? 1 : 0);

    if (width != NULL && width->is_exists && !flags->minus) {
        count += set_width(width, width->width - total_length);
    }

    if(is_negative) {
        count += print_char('-', NULL, NULL);
    } else if(flags->plus) {
        count += print_char('+', NULL, NULL);
    } else if(flags->space) {
        count += print_char(' ', NULL, NULL);
    }

    if (number_long == 0) {
        count += print_char('0', NULL, NULL);
    } else {
        char digit_buffer[12];
        int pos = 0;

        temp = number_long;
        while (temp > 0) {
            digit_buffer[pos++] = '0' + (temp % 10);
            temp /= 10;
        }

        for (int i = pos - 1; i >= 0; i--) {
            count += print_char(digit_buffer[i], NULL, NULL);
        }
    }

    if (width != NULL && width->is_exists && flags->minus) {
        count += set_width(width, width->width - total_length);
    }

    return count;
}
