#include <stdio.h>

int f[1000001];
int g[1000001];
int mod = 10000;

int mod_add(int a, int b) { return (a + b) % mod; }

// 主要在于如何找状态转移方程
int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    f[0] = 1;
    g[1] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = mod_add(mod_add(f[i - 1], f[i - 2]), 2 * g[i - 2]);
        g[i] = mod_add(f[i - 1], g[i - 1]);
    }
    printf("%d\n", f[n]);
    return 0;
}