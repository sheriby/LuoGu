#include <algorithm>
#include <cstdio>

int dp[1001];
int weight[101];
int value[101];

// 01背包问题的优化：压缩成一维数组，反向遍历
int main(int argc, char const *argv[]) {
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &weight[i], &value[i]);
    }

    for (int i = 1; i <= m; i++) {
        for (int k = t; k >= weight[i]; k--) {
            dp[k] = std::max(value[i] + dp[k - weight[i]], dp[k]);
        }
    }
    printf("%d\n", dp[t]);
    return 0;
}
