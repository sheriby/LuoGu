#include <stdio.h>

int dp[10001];
int price[101];

// 发现dp只和前面一个状态有关，状态压缩为一维数组
int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= price[i]; j--) {
            if (price[i] == j) // 刚好可以吃
                dp[j] = dp[j] + 1;
            if (price[i] < j) // 吃了还剩点
                dp[j] = dp[j] + dp[j - price[i]];
        }
    }

    printf("%d\n", dp[m]);

    return 0;
}