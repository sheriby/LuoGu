#include <algorithm>
#include <cstdio>

int v[25];
int w[25];
int dp[30000];

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &v[i], &w[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= v[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - v[i]] + v[i] * w[i]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
