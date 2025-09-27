#include "math.h"
#include "stdlib.h"

#include "../printf.h"

int print_double(double number_double, width_t* width, flags_t* flags) {
    int count = 0;
    int is_negative = 0;
    int padding_needed = 0;

    if(number_double < 0) {
        is_negative = 1;
        number_double = -number_double;
    }

    if(isnan(number_double)) {
        return print_string("NaN", width, flags);
    }

    if(isinf(number_double)) {
        if(is_negative) {
            return print_string("-inf", width, flags);
        } else if(flags->plus) {
            return print_string("+inf", width, flags);
        } else {
            return print_string("inf", width, flags);
        }
    }

    int precision = 6;

    long int_part = (long)number_double;
    double fractional_part = number_double - int_part;

    double round_factor = 1.0;
    for(int i = 0; i < precision; i++) {
        round_factor *= 10.0;
        fractional_part *= 10.0;
    }

    fractional_part = round(fractional_part);
    long fraction_int = (long)fractional_part;

    if(fraction_int >= pow(10, precision)) {
        int_part++;
        fraction_int = 0;
    }

    int int_digits = 0;
    long temp_int = int_part;

    if(temp_int == 0) {
        int_digits = 1;
    } else {
        while(temp_int > 0) {
            int_digits++;
            temp_int /= 10;
        }
    }

    int sign_needed = is_negative || flags->plus || flags->space;
    int total_length = int_digits + (precision > 0 ? 1 + precision : 0) + (sign_needed ? 1 : 0);

    if(width && width->is_exists && !flags->minus) {
        count += set_width(width, width->width - total_length, flags->zero);
    }

    if(width && width->is_exists && flags->zero && !flags->minus) {
        if (is_negative) {
            count += print_char('-', NULL, NULL);
        } else if (flags->plus) {
            count += print_char('+', NULL, NULL);
        } else if (flags->space) {
            count += print_char(' ', NULL, NULL);
        }
        count += set_width(width, width->width - total_length, 1);
    } else {
        if(is_negative) {
            count += print_char('-', NULL, NULL);
        } else if (flags->plus) {
            count += print_char('+', NULL, NULL);
        } else if (flags->space) {
            count += print_char(' ', NULL, NULL);
        }
    }

    if(int_part == 0) {
        count += print_char('0', NULL, NULL);
    } else {
        char digit_buffer[20];
        int pos = 0;

        temp_int = int_part;
        while(temp_int > 0) {
            digit_buffer[pos] = '0' + (temp_int % 10);
            temp_int /= 10;
            pos++;
        }

        for(int i = pos - 1; i >= 0; i--) {
            count += print_char(digit_buffer[i], NULL, NULL);
        }
    }

    if(precision > 0) {
        count += print_char('.', NULL, NULL);

        if(fraction_int == 0) {
            for(int i = 0; i < precision; i++) {
                count += print_char('0', NULL, NULL);
            }
        } else {
            char frac_buffer[20];
            int pos = 0;
            long temp_frac = fraction_int;

            for(int i = 0; i < precision; i++) {
                if (temp_frac > 0) {
                    frac_buffer[precision - 1 - i] = '0' + (temp_frac % 10);
                    temp_frac /= 10;
                } else {
                    frac_buffer[precision - 1 - i] = '0';
                }
            }

            for(int i = 0; i < precision; i++) {
                count += print_char(frac_buffer[i], NULL, NULL);
            }
        }
    }

    if(width != NULL && width->is_exists && flags->minus) {
        count += set_width(width, width->width - total_length, 0);
    }

    return count;
}
