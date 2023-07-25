#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past '%'

            // Check for conversion specifiers
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%'); // Print the '%' character
                    putchar(*format); // Print the unrecognized character
                    count += 2;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

// Example usage:
int main() {
    int num_chars = _printf("I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life %%\n");
    printf("\nNumber of characters printed: %d\n", num_chars);
    return 0;
}

