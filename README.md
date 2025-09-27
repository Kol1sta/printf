# printf
My implementation of `printf` from C

### Features
- Formats
- Arguments
- Width
- Output to console

### Formats
| Specifier | Description             |
|:---------:|:------------------------|
| %d        | Signed decimal integer  |
| %i        | Signed decimal integer  |
| %u        | Unigned decimal integer |
| %c        | Single character        |
| %s        | String of characters    |
| %p        | Pointer address         |
| %f        | Floating-point number   |
| %%        | Percent symbol          |

### Widths
You can set the minimum field width for your _printf output using digits after flags
```c
_printf("%10s", "Hola");    // Output: "      Hola" (right-aligned)
_printf("%-10s", "Hola");   // Output: "Hola      " (left-aligned)
```

### Flags
| Flag        | Description                                         |
|:-----------:|:----------------------------------------------------|
| +           | Always show sign for signed numeric conversions	    |
| -           | Left-align the result within the given field width  |
| ' ' (Space) | Prefix positive numbers with space if no sign shown |
| 0           | Pad with zeros instead of spaces for numeric conversions. Ignored if - is present or for non-numeric conversions |

### Example
```c
#include "./printf.h"

int main(void) {
    _printf("%s, %d\n", "Hello, world!", 1984);
    return 0;
}
```
