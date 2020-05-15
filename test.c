#include <stdio.h>
#include "myfunc.h"

int main() {
    char *s1 = "hello";
    char *s2 = "hello, world";
    char *s3 = "hello, World";
    int n;

    printf("Length of \"%s\": %d\n", s1, mystrlen(s1));
    printf("Compare \"%s\" and \"%s\": %d\n", s2, s3, mystrcmp(s2, s3));
    n = 7;
    printf("Compare \"%s\" and \"%s\" up to %d characters: %d\n", s1, s3, n, mystrncmp(s1, s3, n));
    n = 9;
    printf("Compare \"%s\" and \"%s\" up to %d characters: %d\n", s2, s3, n, mystrncmp(s2, s3, n));

    printf("Random number: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", myrand() % 100);
    }
    printf("\n");

    char *num1 = "+12";
    char *num2 = "-24";
    char *err1 = "1a";
    printf("%s: %d, %s: %d, %s: %d\n", num1, myatoi(num1), num2, myatoi(num2), err1, myatoi(err1));

    int x = 12;
    char s[18];
    mysprintf(s, "x is 0x%04x (%d)", x, x);
    printf("%s\n", s);
    return 0;
}
