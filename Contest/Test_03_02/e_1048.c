#include <stdio.h>

int weight[101];
int value[101];
int dp[1001];

int main(int argc, const char *argv[]) {
    int t, m, v;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &weight[i], &value[i]);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= weight[i]; j--) {
            v = dp[j - weight[i]] + value[i];
            if (v > dp[j])
                dp[j] = v;
        }
    }
    printf("%d\n", dp[t]);
    return 0;
}