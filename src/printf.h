#ifndef PRINTF
#define PRINTF

#include "stdarg.h"
#include "stdbool.h"

int _printf(const char* format, ...);

int get_format(const char specifier, va_list args);

int print_char(char symbol);
int print_int(int number);
int print_string(char* str);
int print_pointer(void* ptr);

#endif
