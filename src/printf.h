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
} width_t;

int _printf(const char* format, ...);

int get_format(const char specifier, va_list args, flags_t flags);
flags_t get_flags(const char* format);
width_t get_width(const char* format);

int print_char(char symbol);
int print_int(int number, flags_t flags);
int print_string(char* str);
int print_pointer(void* ptr);
int print_percent();

#endif
