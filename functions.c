#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *ptr = format;

    while (*ptr) {
        if (*ptr == '%') {
            ptr++;  // Move past '%'
            if (*ptr == '\0') break;  // End of format string

            if (*ptr == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*ptr == 's') {
                char *s = va_arg(args, char *);
                while (*s) {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*ptr == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*ptr);
            count++;
        }
        ptr++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! This is a %c example %%.\n", "world", 'c');
    return 0;
}

