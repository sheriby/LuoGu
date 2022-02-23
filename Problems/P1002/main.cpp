#include <cstdio>
const int MAX = 25;
typedef long long ll;

ll dp[MAX][MAX]{0};
int s[MAX][MAX]{0};

const int dx[9] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
const int dy[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

int main() {
    int n, m, mn, mm;
    scanf("%d%d%d%d", &n, &m, &mn, &mm);
    dp[0][0] = 1;

    for (int i = 0; i < 9; i++) {
        int newx = mn + dx[i];
        int newy = mm + dy[i];
        if (newx >= 0 && newy >= 0)
            s[mn + dx[i]][mm + dy[i]] = 1;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (s[i][j])
                continue;
            if (i - 1 >= 0)
                dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    printf("%lld\n", dp[n][m]);
    return 0;
}