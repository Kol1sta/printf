#include "unistd.h"

#include "../printf.h"

int print_char(char symbol) {
    return write(1, &symbol, 1);
}
