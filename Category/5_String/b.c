#include <stdio.h>

char str[51];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d%s", &n, &str);
    char *p = str;
    while (*p) {
        *p = 'a' + (*p - 'a' + n) % 26;
        p++;
    }
    printf("%s\n", str);
    return 0;
}