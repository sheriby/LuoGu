#include <stdio.h>

char str[6];

int main(int argc, const char *argv[]) {
    gets(str);
    // scanf("%[^\n]", &str);
    int count = 0;
    char *p = str;
    while (*p) {
        if (*p != ' ' && *p != '\n')
            count++;
        p++;
    }
    printf("%d\n", count);
    return 0;
}