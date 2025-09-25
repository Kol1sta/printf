#include "unistd.h"

#include "../printf.h"

int set_width(width_t* width, int spaces) {
    char space = ' ';
    int count = 0;

    if(spaces > 0) {
        while(spaces > 0) {
            count += write(1, &space, 1);
            spaces--;
        }
    }

    return count;
}
