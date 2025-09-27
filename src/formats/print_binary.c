#include "stdlib.h"

#include "../printf.h"

int print_binary(unsigned int number, width_t* width, flags_t* flags) {
    int count = 0;
    int sign_needed = flags->plus || flags->space;
    int total_length = 0;
    unsigned int temp = number;

    if(temp == 0) {
        return print_char('0', NULL, NULL);
    } else {
        while(temp > 0) {
            total_length++;
            temp >>= 1;
        }
    }

    total_length += (sign_needed ? 1 : 0);

    if(width && width->is_exists && !flags->minus) {
        count += set_width(width, width->width - total_length, flags->zero);
    }

    if(flags->plus) {
        count += print_char('+', NULL, NULL);
    } else if(flags->space) {
        count += print_char(' ', NULL, NULL);
    }

    if(number == 0) {
        count += print_char('0', NULL, NULL);
    } else {
        char bit_buffer[33];
        int pos = 0;

        temp = number;
        while(temp > 0) {
            bit_buffer[pos++] = (temp & 1) ? '1' : '0';
            temp >>= 1;
        }

        for(int i = pos - 1; i >= 0; i--) {
            count += print_char(bit_buffer[i], NULL, NULL);
        }
    }

    if(width && width->is_exists && flags->minus) {
        count += set_width(width, width->width - total_length, 0);
    }

    return count;
}
