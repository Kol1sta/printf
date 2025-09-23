#include "./src/printf.h"

int main(int argc, char* argv[]) {
    _printf("%s %d\n", "Hello, world\0", 30);
    return 0;
}
