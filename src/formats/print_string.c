#include "string.h"

#include "../printf.h"

int print_string(char* str, width_t* width) {
    int count = 0;

    if(!str) {
        return print_string("(nil)", NULL);
    }

    if(width != NULL && width->is_exists == 1) {
        count += set_width(width, width->width - strlen(str));
    }

    char* current = str;
    while(*current != '\0') {
        count += print_char(*current, NULL);
        current++;
    }

    return count;
}
