#ifndef PRINTF
#define PRINTF

#include "stdarg.h"

typedef struct {
    int minus;
    int plus;
    int zero;
    int space;
    int hash;

    int length;
} flags_t;

typedef struct {
    int width;
    int length;
    int is_exists;
} width_t;

int _printf(const char* format, ...);

int get_format(const char specifier, va_list args, flags_t* flags, width_t* width);
flags_t get_flags(const char* format);
width_t get_width(const char* format);

int print_char(char symbol, width_t* width, flags_t* flags);
int print_int(int number, width_t* width, flags_t* flags);
int print_string(char* str, width_t* width, flags_t* flags);
int print_pointer(void* ptr, width_t* width, flags_t* flags);
int print_percent(width_t* width, flags_t* flags);

int set_width(width_t* width, int spaces);

#endif
