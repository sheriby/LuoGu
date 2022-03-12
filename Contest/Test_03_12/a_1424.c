#include <stdio.h>

int m[8] = {0, 1, 2, 3, 4, 5, 5, 5};

int main(int argc, const char *argv[]) {
    int x, n;
    scanf("%d%d", &x, &n);
    n += x - 1;
    long long ans = 5 * (n / 7) + m[n % 7] - m[x - 1];
    printf("%lld\n", ans * 250);
    return 0;
}