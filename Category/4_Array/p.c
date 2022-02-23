#include <stdio.h>

int ans[20][20];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || i == j)
                ans[i][j] = 1;
            else
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            printf("%d", ans[i][j]);
            if (j != i)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}