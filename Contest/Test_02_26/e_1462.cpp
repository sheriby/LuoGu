#include <algorithm>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;

#define N 10001
#define M 100002

struct Edge {
    ll to;
    ll next;
    ll weight;
} edges[M];

struct Node {
    ll first;
    ll money;
} nodes[N];

ll vis[N], dis[N], tmp[N];
ll tot;
ll inf = 0x7fffffffffffffff;
ll n, m, hp;
priority_queue<pair<ll, ll>> q;

void add_edge(ll x, ll y, ll w) {
    edges[++tot].to = y;
    edges[tot].next = nodes[x].first;
    edges[tot].weight = w;
    nodes[x].first = tot;
}

ll check(ll x) {
    if (x < nodes[1].money || x < nodes[n].money)
        return 0;
    for (ll i = 1; i <= n; i++)
        dis[i] = inf;

    dis[1] = 0;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        ll now = q.top().second;
        q.pop();
        for (ll i = nodes[now].first; i; i = edges[i].next) {
            ll y = edges[i].to;
            if (nodes[y].money <= x && dis[y] > edges[i].weight + dis[now]) {
                dis[y] = edges[i].weight + dis[now];
                q.push(make_pair(-dis[y], y));
            }
        }
    }
    if (dis[n] <= hp)
        return 1;
    return 0;
}

// Dijkstral+二分法
int main(int argc, const char *argv[]) {
    scanf("%d%d%d", &n, &m, &hp);
    for (ll i = 1; i <= n; i++) {
        scanf("%d", &nodes[i].money);
        tmp[i] = nodes[i].money;
    }
    ll f, t, w;
    for (ll i = 1; i <= m; i++) {
        scanf("%d%d%d", &f, &t, &w);
        if (f == t)
            continue;
        add_edge(f, t, w);
        add_edge(t, f, w);
    }

    sort(tmp + 1, tmp + n + 1);

    if (!check(tmp[n])) {
        printf("AFK\n");
        return 0;
    }
    ll ans;
    ll l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(tmp[mid])) {
            ans = tmp[mid];
            r = mid - 1;
        } else
            l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}