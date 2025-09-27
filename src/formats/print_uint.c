#include "stdlib.h"

#include "../printf.h"

int print_uint(unsigned int number, width_t* width, flags_t* flags) {
    int count = 0;
    int digits = 0;
    unsigned int temp = number;

    if(temp == 0) {
        digits = 1;
    } else {
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
    }

    int total_length = digits;

    if(width && width->is_exists && !flags->minus) {
        count += set_width(width, width->width - total_length, flags->zero && !flags->minus);
    }

    if(number == 0) {
        count += print_char('0', NULL, NULL);
    } else {
        char buffer[22];
        int i = 0;
        temp = number;

        while(temp > 0) {
            buffer[i] = '0' + (temp % 10);
            temp /= 10;
            i++;
        }

        for(int j = i - 1; j >= 0; j--) {
            count += print_char(buffer[j], NULL, NULL);
        }
    }

    if(width != NULL && width->is_exists && flags->minus) {
        count += set_width(width, width->width - total_length, 0);
    }

    return count;
}
