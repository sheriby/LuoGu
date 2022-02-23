#include <stdio.h>
#define ll long long

int map[5001];
int mod = 1e9 + 7;

ll c2(ll x) { return (x * (x - 1) / 2) % mod; }

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
        if (map[i] >= 2) {
            ll a = c2(map[i]);
            for (int j = minx; j <= i / 2; j++) {
                if (j == i - j && map[j] >= 2)
                    ans += a * c2(map[j]);
                else if (j != i - j && map[j] >= 1 && map[i - j] >= 1)
                    ans += (a * map[j] * map[i - j]) % mod;

                ans %= mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}