#include "../printf.h"

int print_string(char *str) {
    int count = 0;

    if(!str) return print_string("(nil)");

    char* current = str;
    while(*current != '\0') {
        count += print_char(*current);
        current++;
    }

    return count;
}
