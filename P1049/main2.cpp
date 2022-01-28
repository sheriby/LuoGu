#include <algorithm>
#include <cstdio>

int value[31];
int dp[20001];
int v, m;

// 求最小剩余空间，也就是求可放的最大质量
int main(int argc, char const *argv[]) {
    scanf("%d%d", &v, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &value[i]);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = v; j >= value[i]; j--) {
            dp[j] = std::max(value[i] + dp[j - value[i]], dp[j]);
        }
    }

    printf("%d\n", v - dp[v]);

    return 0;
}
