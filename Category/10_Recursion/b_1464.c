#include <stdio.h>
typedef long long ll;

int map[21][21][21];

ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 | b > 20 | c > 20)
        return w(20, 20, 20);
    if (map[a][b][c])
        return map[a][b][c];
    if (a < b && b < c) {
        ll res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        map[a][b][c] = res;
        return res;
    }
    ll res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
             w(a - 1, b - 1, c - 1);
    map[a][b][c] = res;
    return res;
}

int main(int argc, const char *argv[]) {
    ll a, b, c;
    while (1) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}