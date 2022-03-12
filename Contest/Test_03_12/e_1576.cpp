#include <iostream>
#include <queue>
#define N 2001
#define M 200001
using namespace std;

int head[N], to[M], nxt[M], vis[N], tot;
double weight[M], dis[N];

void add_edge(int x, int y, int w) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    weight[tot] = 1 - double(w) / 100;
}

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add_edge(x, y, w);
        add_edge(y, x, w);
    }
    int s, e;
    cin >> s >> e;
    priority_queue<pair<double, int>> q;
    dis[s] = 1;
    q.push(make_pair(1, s));
    while (q.size()) {
        int t = q.top().second;
        q.pop();
        if (t == e)
            break;
        vis[t] = 1;
        for (int i = head[t]; i; i = nxt[i]) {
            int y = to[i];
            if (dis[y] < dis[t] * weight[i]) {
                dis[y] = dis[t] * weight[i];
                if (!vis[y])
                    q.push(make_pair(dis[y], y));
            }
        }
    }
    printf("%.8lf\n", 100 / dis[e]);

    return 0;
}