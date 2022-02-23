#include <stdio.h>
#define MAX (1 << 10 + 1)

int ans[MAX][MAX];

void run(int x, int y, int n) {
    if (n == 1)
        return;
    for (int i = x; i < x + n / 2; i++) {
        for (int j = y; j < y + n / 2; j++) {
            ans[i][j] = 1;
        }
    }
    run(x, y + n / 2, n / 2);
    run(x + n / 2, y, n / 2);
    run(x + n / 2, y + n / 2, n / 2);
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    run(0, 0, 1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            printf("%d", !ans[i][j]);
            if (j != (1 << n) - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}