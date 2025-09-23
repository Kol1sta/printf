#include "../printf.h"

int print_int(int number) {
    int count = 0;

    if(number < 0) {
        count += print_char('-');
        number = -number;
    } else if(number == 0) {
        count = print_char('0');
    }

    int reversed = 0;
    int digits = 0;
    
    while (number > 0) {
        reversed = reversed * 10 + (number % 10);
        number /= 10;
        digits++;
    }
    
    while (digits > 0) {
        count += print_char('0' + (reversed % 10));
        reversed /= 10;
        digits--;
    }

    return count;
}
