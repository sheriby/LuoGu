#include <stdio.h>

// dp[i][j]表示有j元时只吃前面i样东西的方式
int dp[101][10001];
int price[101];

// 二维数组的DP
int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (price[i] == j) // 刚好可以吃
                dp[i][j] = dp[i - 1][j] + 1;
            if (price[i] < j) // 吃了还剩点
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - price[i]];
            if (price[i] > j) // 吃不起
                dp[i][j] = dp[i - 1][j];
        }
    }

    printf("%d\n", dp[n][m]);

    return 0;
}