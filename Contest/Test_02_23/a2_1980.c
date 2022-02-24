#include <stdio.h>

int main() {
    int n, x, m = 1, ans = 0;
    scanf("%d%d", &n, &x);
    // 依次求每一位当中x的个数
    while (m <= n) {
        int a = n / (m * 10), b = n / m % 10, c = n % m;
        if (x) {
            if (b > x)
                ans += (a + 1) * m;
            if (b == x)
                ans += a * m + c + 1;
            if (b < x)
                ans += a * m;
        } else {
            if (b)
                ans += a * m;
            else
                ans += (a - 1) * m + c + 1;
        }
        m *= 10;
    }
    printf("%d\n", ans);
    return 0;
}
