#include <stdio.h>

int ans[1000];

int main(int argc, const char *argv[]) {
    int n, k = 0;
    scanf("%d", &n);
    ans[0] = n;
    while (n != 1) {
        if (n & 1)
            n = 3 * n + 1;
        else
            n >>= 1;
        ans[++k] = n;
    }

    for (int i = k; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i != 0)
            printf(" ");
    }

    return 0;
}