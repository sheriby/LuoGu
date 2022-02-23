#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    long long zfx = 0, cfx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j)
                zfx += (n - i) * (m - j);
            else
                cfx += (n - i) * (m - j);
        }
    }
    printf("%lld %lld\n", zfx, cfx);
    return 0;
}