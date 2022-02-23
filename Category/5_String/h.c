#include <stdio.h>

int map[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
               2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

char strs[201];

int main(int argc, const char *argv[]) {
    gets(strs);
    int count = 0;
    char *p = strs;
    while (*p) {
        if (*p == '\r' || *p == '\n')
            break;
        if (*p == ' ')
            count++;
        else
            count += map[*p - 'a'];
        p++;
    }

    printf("%d\n", count);
    return 0;
}