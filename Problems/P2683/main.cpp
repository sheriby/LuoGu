#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int M = 10010;
const int INF = 0x7fffffff;
int h[N], e[M], ne[M], w[M], idx, n, m, d[N], a, u, v, k;
bool st[N];
typedef pair<int, int> PII;
void add(int a, int b, int c) //构建邻接表
{
    e[++idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx;
}
void dijkstra(int s, int v) //最短路模板
{
    memset(st, 0, sizeof(st));
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    while (q.size()) {
        PII t = q.top();
        q.pop();
        if (t.second == v)
            return;
        int distance = t.first, ver = t.second;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i; i = ne[i]) {
            int j = e[i];
            if (d[j] > distance + w[i])
                d[j] = distance + w[i];
            if (!st[j]) {
                q.push({d[j], j});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a);
        if (a == 0) {
            cin >> u >> v;
            dijkstra(u, v);
            if (d[v] == INF)
                cout << "-1" << endl;
            else
                cout << d[v] << endl;
        } else {
            cin >> u >> v >> k;
            add(u, v, k); //建边
            add(v, u, k); //建边
        }
    }
    return 0;
}
