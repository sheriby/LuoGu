#include <stdio.h>

#define MAXN 10000005

int prime[MAXN];
int vis[MAXN];
int is_huiwen(int x) {

    int y = x, num = 0;
    while (y != 0) {
        num = num * 10 + y % 10;
        y /= 10;
    }
    if (num == x)
        return 1;
    else
        return 0;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt = 0;
    if (b > 10000000)
        b = 10000000;
    // 线性筛法
    for (int i = 2; i <= b; i++) {
        if (!vis[i])          // 没被筛到，说明是质数
            prime[cnt++] = i; // 保存该质数
        // 合数 = 最小质因数 * 最大因子
        // 最需要枚举最小质因数
        for (int j = 0; j < cnt && i * prime[j] <= b; j++) {
            vis[i * prime[j]] = 1;
            // 当 i % prime[j] == 0，不需要往后枚举，因为之后的不是最小质因数
            // 如 4 % 2 == 0，不需要枚举 4 * 3，因为 4 * 3 = 2 * 6,
            // 2才是最小质因
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = a; i <= b; i++) {
        if (!vis[i] && is_huiwen(i))
            printf("%d\n", i);
    }
}