#include "myfunc.h"

static unsigned int xorshift_x = 123456789;
static unsigned int xorshift_y = 362436069;
static unsigned int xorshift_z = 521288629;
static unsigned int xorshift_w = 88675123;

int myrand() {
    unsigned int r;
    r = xorshift_x ^ (xorshift_x<<11);
    xorshift_x = xorshift_y;
    xorshift_y = xorshift_z;
    xorshift_z = xorshift_w;
    xorshift_w ^= r ^ (r>>8) ^ (xorshift_w>>19);
    return ((xorshift_x) / 4294967296 + xorshift_w);
}

int myatoi(const char *nptr) {
    int ret = 0, operand = 1;
    if (*nptr == '+') {
        nptr++;
    } else if (*nptr == '-') {
        operand = -1;
        nptr++;
    }
    while (*nptr != '\0' && '0' <= *nptr && *nptr <= '9') {
        ret *= 10;
        ret += *nptr++ - '0';
    }
    return ret * operand;
}
