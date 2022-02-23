#include <cstdio>

const int MAX = 1001;
int dp[MAX]{0};

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int mid = i / 2;
        dp[i] += mid;
        for (int j = 0; j <= mid; j++) {
            dp[i] += dp[j];
        }
    }

    printf("%d\n", dp[n] + 1);

    return 0;
}
