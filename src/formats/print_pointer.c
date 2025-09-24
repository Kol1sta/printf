#include "unistd.h"

#include "../printf.h"

int print_pointer(void* ptr) {
    if(ptr == NULL) return print_string("(nil)");

    unsigned long address = (unsigned long)ptr;
    char buffer[20];
    char* hex_digits = "0123456789abcdef";

    buffer[0] = '0';
    buffer[1] = 'x';

    if(address == 0) {
        buffer[2] = '0';
        buffer[3] = '\0';
    } else {
        int digits = 0;
        unsigned long temp = address;

        while(temp > 0) {
            digits++;
            temp /= 16;
        }

        temp = address;
        for(int i = digits - 1; i >= 0; i--) {
            buffer[2 + i] = hex_digits[temp % 16];
            temp /= 16;
        }

        buffer[2 + digits] = '\0';
    }

    return print_string(buffer);
}
