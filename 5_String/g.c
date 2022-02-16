#include <stdio.h>
#include <string.h>

void lowwer(char *s) {
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            *s += 32;
        s++;
    }
}

char word[11];
char str[1000001];

int main(int argc, const char *argv[]) {
    gets(word);
    gets(str);
    lowwer(word);
    lowwer(str);
    int first = -1, times = 0;
    int len = strlen(word);
    char *p = str, *q;
    while (q = strstr(p, word)) {
        if ((q == str || *(q - 1) == ' ') &&
            (*(q + len) == '\0' || *(q + len) == ' ')) {
            times++;
            if (first == -1) {
                first = q - str;
            }
        }
        p = q + len;
    }

    if (first != -1)
        printf("%d %d\n", times, first);
    else
        printf("-1\n");
    return 0;
}