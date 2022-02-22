#include <stdio.h>

int map[1001];
int result[101];
int cnt = 0;

int main(int argc, const char *argv[]) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        map[x]++;
    }

    for (int i = 1; i < 1001; i++) {
        if (map[i])
            result[cnt++] = i;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d", result[i]);
        if (i != cnt - 1)
            printf(" ");
    }

    return 0;
}