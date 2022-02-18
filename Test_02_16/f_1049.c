#include <stdio.h>

int weight[31];
int dp[200001];

// 经典0/1背包问题
int main(int argc, const char *argv[]) {
    int v, n;
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }
    int val;
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= weight[i]; j--) {
            val = dp[j - weight[i]] + weight[i];
            if (val > dp[j])
                dp[j] = val;
        }
    }
    printf("%d\n", v - dp[v]);
    return 0;
}