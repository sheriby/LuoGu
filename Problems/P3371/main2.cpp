#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
const int M = 5e5 + 1;
const int INF = 0x7fffffff;
int d[N], n, m, s, h[N], e[M], ne[M], w[M], idx;
bool vis[N];
priority_queue<pair<int, int>> q;

void add(int a, int b, int c) //构建邻接表
{
    e[++idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx;
}

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = 0x7fffffff;
    }
    d[s] = 0;
    q.push(make_pair(0, s));
    while (q.size()) {
        int t = q.top().second;
        q.pop();
        vis[t] = true;
        for (int i = h[t]; i; i = ne[i]) {
            int y = e[i];
            if (!vis[y] && d[y] > d[t] + w[i]) {
                d[y] = d[t] + w[i];
                q.push(make_pair(-d[y], y));
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
