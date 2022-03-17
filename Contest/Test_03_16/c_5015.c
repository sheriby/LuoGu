#include <stdio.h>

char str[10];

int main(int argc, const char *argv[]) {
    gets(str);
    char *p = str;
    int ans = 0;
    while (*p) {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') ||
            (*p >= '0' && *p <= '9'))
            ans++;
        p++;
    }
    printf("%d\n", ans);
    return 0;
}