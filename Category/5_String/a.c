#include <stdio.h>

char str[101];

int main(int argc, const char *argv[]) {
    scanf("%s", &str);
    char *p = str;
    while (*p) {
        if ('a' <= *p && *p <= 'z')
            *p -= 32;
        p++;
    }
    printf("%s", str);
    return 0;
}