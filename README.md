# my-c-library
- myfunc.h

```c
#ifndef MYFUNC_H
#define MYFUNC_H
int mysprintf(char *s, const char *fmt, ...);

int myrand(void);
int myatoi(const char *nptr);

int mystrcmp(const char *s1, const char *s2);
int mystrncmp(const char *s1, const char *s2, int n);
int mystrlen(const char *s);
#endif
```

