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

int _printf(const char* format, ...);

int get_format(const char specifier, va_list args);
flags_t get_flags(const char* format, int* count);

int print_char(char symbol);
int print_int(int number);
int print_string(char* str);
int print_pointer(void* ptr);
int print_percent();

#endif
