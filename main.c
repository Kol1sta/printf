#include "./src/printf.h"

int main(int argc, char* argv[]) {
    int a = 2;
    int* b = &a;
    _printf("%%s %d %p\n", "Hello, world\0", 30, b);
    return 0;
}
