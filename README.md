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

### Widths
You can set the minimum field width for your _printf output using digits after flags
```c
_printf("%10s", "Hola");   // Output: "      Hola" (right-aligned)
```

### Flags
| Flag        | Description                                         |
|:-----------:|:----------------------------------------------------|
| +           | Always show sign for signed numeric conversions	    |
| ' ' (Space) | Prefix positive numbers with space if no sign shown |

### Example
```c
#include "./printf.h"

int main(void) {
    _printf("%s, %d\n", "Hello, world!", 1984);
    return 0;
}
```
