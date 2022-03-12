#include <math.h>
#include <stdio.h>
#include <string.h>

char a[2001];
char b[2001];
int k, lena, lenb;
// 此处dp[i][j]的含义为上面用i个下面用j个得到的最短的距离
int dp[2001][2001];

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c)
            return a;
        return c;
    }
    if (b < c)
        return b;
    return c;
}

int main(int argc, const char *argv[]) {
    scanf("%s%s%d", &a, &b, &k);
    lena = strlen(a), lenb = strlen(b);

    for (int i = 0; i <= lena; i++) {
        dp[i][0] = i * k;
    }
    for (int i = 0; i <= lenb; i++) {
        dp[0][i] = i * k;
    }

    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            dp[i][j] = min(dp[i][j - 1] + k, dp[i - 1][j] + k,
                           dp[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]));
        }
    }

    printf("%d\n", dp[lena][lenb]);

    return 0;
}