#include <stdio.h>

char str[203];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n + 2; i++) {
        if (i < n)
            str[i] = 'o';
        else if (i < 2 * n)
            str[i] = '*';
        else
            str[i] = '-';
    }
    str[2 * n + 2] = 0;
    int l = n - 1, r = 2 * n;
    int dir = 1;
    while (l > 2) {
        printf("%s\n", str);
        str[r] = 'o';
        str[r + 1] = '*';
        str[l] = '-';
        str[l + 1] = '-';
        printf("%s\n", str);
        if (l <= 2)
            break;
        for (int i = l; i < r - 2; i++) {
            str[i] = '*';
        }
        str[r - 2] = '-';
        str[r - 1] = '-';
        r -= 2;
        l -= 1;
    }
    char *a[4] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
    for (int i = 0; i < 4; i++) {
        printf("%s", a[i]);
        for (int j = 0; j < n - 4; j++) {
            printf("o*");
        }
        printf("\n");
    }

    return 0;
}