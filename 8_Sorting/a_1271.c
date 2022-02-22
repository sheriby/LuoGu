#include <stdio.h>

int map[1000];

int main(int argc, const char *argv[]) {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        map[x]++;
    }

    int start = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < map[i]; j++) {
            if (!start)
                printf(" ");
            printf("%d", i);
            start = 0;
        }
    }
    return 0;
}