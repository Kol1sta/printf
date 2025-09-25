# printf
My implementation of `printf` from C

### Features
- Formats
- Arguments
- Output to console

### Formats
| Specifier | Description            |
|:---------:|:-----------------------|
| %d        | Signed decimal integer |
| %i        | Signed decimal integer |
| %c        | Single character       |
| %s        | String of characters   |
| %p        | Pointer address        |
| %%        | Percent symbol         |

### Example
```c
#include "./printf.h"

int main(void) {
    _printf("%s, %d\n", "Hello, world!", 1984);
}
```
