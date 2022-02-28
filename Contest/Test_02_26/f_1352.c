#include <stdio.h>
#define N 6001
#define ll long long

int happy[N];
int head[N], nxt[N], to[N];
int in[N];
ll with[N], without[N];
int cnt = 0;

void add_edge(int x, int y) {
    to[++cnt] = y;
    nxt[cnt] = head[x];
    head[x] = cnt;
    in[y]++;
}

ll get_happy(int n);

ll get_happy_without(int n) {
    if (without[n] != 0)
        return without[n];

    ll val = 0;
    for (int i = head[n]; i; i = nxt[i]) {
        int y = to[i];
        ll h = get_happy(y);
        ll t = get_happy_without(y);
        if (h < 0 && t < 0)
            continue;
        if (h > t)
            val += h;
        else
            val += t;
    }
    without[n] = val;
    return val;
}

ll get_happy(int n) {
    if (with[n] != 0)
        return with[n];
    ll val = 0;
    for (int i = head[n]; i; i = nxt[i]) {
        int y = to[i];
        ll h = get_happy_without(y);
        if (h > 0)
            val += h;
    }
    val += happy[n];
    with[n] = val;
    return val;
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &happy[i]);
    }
    int x, y;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        add_edge(y, x);
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            root = i;
            break;
        }
    }
    ll res1 = get_happy(root);
    ll res2 = get_happy_without(root);
    printf("%lld\n", res1 > res2 ? res1 : res2);
    return 0;
}