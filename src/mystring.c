#include "myfunc.h"

int mystrcmp(const char *s1, const char *s2) {
    unsigned char c1, c2;
    do {
        c1 = *s1++;
        c2 = *s2++;

        if (c1 == '\0') {
            return c1 - c2;
        }
    } while (c1 == c2);
    return c1 - c2;
}

int mystrncmp(const char *s1, const char *s2, int n) {
    unsigned char c1, c2;
    int i;
    for (i = 0; i < n; i++) {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 == '\0') {
            return c1 - c2;
        }
        if (c1 != c2) {
            return c1 - c2;
        }
    }
    return 0;
}

int mystrlen(const char *s) {
    int len = 0;
    for (; *s != '\0'; s++) {
        len++;
    }
    return len;
}
