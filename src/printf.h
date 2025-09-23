#ifndef PRINTF
#define PRINTF

#include "stdarg.h"

int _printf(const char* format, ...);

int get_format(const char specifier, va_list args);

int print_char(char symbol);
int print_int(int number);
int print_string(char* str);

#endif
