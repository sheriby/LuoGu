#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
const int M = 5e5 + 1;
const int INF = 0x7fffffff;
int d[N], n, m, s, h[N], e[M], ne[M], w[M], idx;
bool vis[N];
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
    for (int i = 1; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) //找到当前距离最小的点
        {
            if (vis[j] == false && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        vis[u] = true;
        for (int i = h[u]; i; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[u] + w[i])
                d[j] = d[u] + w[i];
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
