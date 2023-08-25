#include "common.h"

void putchar(char ch);

void printf(const char *fmt, ...) {
    va_list vargs;
    va_start(vargs, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
                case '\0':
                case '%':
                    putchar('%');
                    break;
                case 's': {
                    const char *s = va_arg(vargs, const char *);
                    while (*s) {
                        putchar(*s);
                        s++;
                    }
                    break;
                }
                case 'd': {
                    int value = va_arg(vargs, int);
                    if (value < 0) {
                        putchar('-');
                        value = -value;
                    }

                    int devisor = 1;
                    while (value / devisor > 9)
                        devisor *= 10;
                    
                    while (devisor > 0) {
                        putchar('0' + value / devisor);
                        value %= devisor;
                        devisor /= 10;
                    }
                    
                    break;
                }
            }
        } else {
            putchar(*fmt);
        }

        fmt++;
    }

    va_end(vargs);
}