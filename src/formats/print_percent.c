#include "stdlib.h"

#include "../printf.h"

int print_percent(width_t* width, flags_t* flags) {
    int count = 0;
    int padding_needed = 0;

    if(width && width->is_exists) {
        padding_needed = 1;
        if(!flags->minus) {
            count += set_width(width, width->width - 1);
        }
    }

    count += print_char('%', NULL, NULL);

    if(padding_needed && flags->minus) {
        count += set_width(width, width->width - 1);
    }

    return count;
}
