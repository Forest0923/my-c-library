#include "myfunc.h"
#include <stdarg.h>
#include <stdio.h>

int mysprintf_d(signed int val, char *s, int zflag, int width) {
    int i, len = 0, minus = 0;
    char tmp[10];
    char *ptmp = tmp + 9;
    
    if (!val) {
        *(ptmp--) = '0';
        len++;
    } else {
        if (val < 0) {
            val = ~val;
            val++;
            minus = 1;
        }
        while (val) {
            if (len >= 8) {
                break;
            }
            *ptmp = (val % 10) + '0';
            val /= 10;
            ptmp--;
            len++;
        }
    }
    if (zflag) {
        if (minus) {
            width--;
        }
        while (len < width) {
            *(ptmp--) = '0';
            len++;
        }
        if (minus) {
            *(ptmp--) = '-';
            len++;
        }
    } else {
        if (minus) {
            *(ptmp--) = '-';
            len++;
        }
        while (len < width) {
            *(ptmp--) = ' ';
            len++;
        }
    }
    for (i = 0; i < len; i++) {
        *(s++) = *(++ptmp);
    }
    return len;
}

int mysprintf_h(unsigned int val, char *s, int capital, int zflag, int width) {
    int i, len = 0;
    char tmp[10], str_a;
    char *ptmp = tmp + 9;

    if (capital) {
        str_a = 'A';
    } else {
        str_a = 'a';
    }

    if (!val) {
        *(ptmp--) = '0';
        len++;
    } else {
        while (val) {
            if (len >= 8) {
                break;
            }
            *ptmp = val % 16;
            if (*ptmp > 9) {
                *ptmp += str_a - 10;
            } else {
                *ptmp += '0';
            }
            val >>= 4;
            ptmp--;
            len++;
        }
    }
    while (len < width) {
        *(ptmp--) = zflag ? '0' : ' ';
        len++;
    }
    for (i = 0; i < len; i++) {
        *(s++) = *(++ptmp);
    }
    return len;
}

int mysprintf_c(int c, char *s) {
    *s = (char)c;
    return 1;
}

int mysprintf_s(char *str, char *s) {
    int count = 0;
    while (*str) {
        *(s++) = *str;
        str++;
        count++;
    }
    return count;
}

int myvsprintf(char *s, const char *fmt, va_list arg) {
    int len = 0, size = 0, zflag, width;
    while (*fmt) {
        if (*fmt == '%') {
            zflag = 0;
            width = 0;
            fmt++;
            if (*fmt == '0') {
                fmt++;
                zflag = 1;
            }
            if ('0' <= *fmt && *fmt <= '9') {
                width = *(fmt++) - '0';
            }
            switch(*fmt) {
            case 'd':
                size = mysprintf_d(va_arg(arg, signed int), s, zflag, width);
                break;
            case 'x':
                size = mysprintf_h(va_arg(arg, unsigned int), s, 0, zflag, width);
                break;
            case 'X':
                size = mysprintf_h(va_arg(arg, unsigned int), s, 1, zflag, width);
                break;
            case 'c':
                size = mysprintf_c(va_arg(arg, int), s);
                break;
            case 's':
                size = mysprintf_s(va_arg(arg, char*), s);
                break;
            default:
                len++;
                *(s++) = *fmt;
                break;
            }
            len += size;
            s += size;
            fmt++;
        } else {
            *(s++) = *(fmt++);
            len++;
        }
    }
    *s = '\0';
    return len;
}

int mysprintf(char *s, const char *fmt, ...) {
    va_list arg;
    int len;

    va_start(arg, fmt);
    len = myvsprintf(s, fmt, arg);
    va_end(arg);

    return len;
}

