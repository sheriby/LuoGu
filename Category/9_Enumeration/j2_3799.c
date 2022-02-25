#include <stdio.h>
#define ll long long

int map[5001];
int mod = 1e9 + 7;

ll c2(ll x) { return (x * (x - 1) / 2); }

// 组合和枚举
int main(int argc, const char *argv[]) {
    int n, x, maxx = 0, minx = 0x7fffffff;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > maxx)
            maxx = x;
        if (x < minx)
            minx = x;
        map[x]++;
    }

    ll ans = 0;
    for (int i = minx; i <= maxx; i++) {
        for (int j = i; i + j <= maxx; j++) {
            if (map[i + j] >= 2) {
                if (i == j)
                    ans += (c2(map[i]) * c2(map[i + j]));
                else
                    ans += (map[i] * map[j] * c2(map[i + j]));
                ans %= mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}