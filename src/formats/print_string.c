#include "string.h"

#include "../printf.h"

int print_string(char* str, width_t* width, flags_t* flags) {
    int count = 0;
    int padding_needed = 0;

    if(!str) {
        return print_string("(nil)", NULL, NULL);
    }

    if(width && width->is_exists) {
        padding_needed = 1;
        if(!flags->minus) {
            count += set_width(width, width->width - strlen(str));
        }
    }

    char* current = str;
    while(*current != '\0') {
        count += print_char(*current, NULL, flags);
        current++;
    }

    if(padding_needed && flags->minus) {
        count += set_width(width, width->width - strlen(str));
    }

    return count;
}
