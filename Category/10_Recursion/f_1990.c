#include <stdio.h>

int f[1000001];
int g[1000001];
int mod = 10000;

// 主要在于如何找状态转移方程
int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    f[0] = 1;
    g[1] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2] + 2 * g[i - 2];
        f[i] %= mod;
        g[i] = f[i - 1] + g[i - 1];
        g[i] %= mod;
    }
    printf("%d\n", f[n]);
    return 0;
}