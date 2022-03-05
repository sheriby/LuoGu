#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 10001
#define M 40001
#define INF 0x3f3f3f3f

int n, m, s, t;
int head[N], to[N], nxt[M], weight[M], dis[N], vis[N];
int tot;
priority_queue<pair<int, int>> q;

void add_edge(int x, int y, int w) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    weight[tot] = w;
}

int dijkstra(int x) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dis[i] = INF;
    }
    while (q.size()) {
        q.pop();
    }
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (u == t)
            return 1;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i]) {
            int y = to[i];
            if (!vis[y] && weight[i] <= x && dis[y] > weight[i] + dis[u]) {
                dis[y] = weight[i] + dis[u];
                q.push(make_pair(-dis[y], y));
            }
        }
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int ea, eb, ew, maxew = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &ea, &eb, &ew);
        add_edge(ea, eb, ew);
        add_edge(eb, ea, ew);
        if (ew > maxew)
            maxew = ew;
    }

    int l = 1, r = maxew, mid, ans;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (dijkstra(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}