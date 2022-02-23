#include <stdio.h>

int num[4];
int s[20];
int dp[1201];
int res = 0;

// 不是贪心，是动态规划，经典01背包问题
// 在总和的一半时间内，一个脑子最多可以做多长时间的题目
int main(int argc, const char *argv[]) {
    for (int i = 0; i < 4; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < num[i]; j++) {
            scanf("%d", &s[j]);
            sum += s[j];
        }
        for (int k = 0; k < num[i]; k++) {
            for (int j = sum / 2; j >= s[k]; j--) {
                if (dp[j] < dp[j - s[k]] + s[k])
                    dp[j] = dp[j - s[k]] + s[k];
            }
        }
        res += sum - dp[sum / 2];
        for (int k = 0; k <= sum / 2; k++) {
            dp[k] = 0;
        }
    }
    printf("%d\n", res);
    return 0;
}