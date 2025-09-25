#include "stdlib.h"

#include "../printf.h"

int print_percent(width_t* width) {
    int count = 0;

    if(width != NULL && width->is_exists == 1) {
        count += set_width(width, width->width - 1);
    }

    return count + print_char('%', NULL);
}
