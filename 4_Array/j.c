#include <stdio.h>

int ans[10];

int main(int argc, const char *argv[]) {
    int m, n, k;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++) {
        k = i;
        while (k) {
            ans[k % 10]++;
            k /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d", ans[i]);
        if (i != 9)
            printf(" ");
    }
    return 0;
}