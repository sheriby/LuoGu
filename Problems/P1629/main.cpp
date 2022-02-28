#include <iostream>
using namespace std;
const int N = 2001;
const int M = 200005;
int n, m;

int head[N], nxt[M], to[M], weight[M];
int dis[N], vis[N], in[N];
int tot = 0;

void add_edge(int x, int y, int w) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    weight[tot] = w;
}

void dijkstra(int x) {
    for (int i = x; i <= x + n; i++) {
        dis[i] = 0x7fffffff;
    }

    dis[x] = 0;
    int cot = 1;
    while (cot < n) {
        int min = 0x7fffffff, t;
        for (int i = x; i <= x + n; i++) {
            if (!vis[i] && dis[i] < min) {
                min = dis[i];
                t = i;
            }
        }
        vis[t] = 1;
        for (int i = head[t]; i; i = nxt[i]) {
            int y = to[i];
            if (dis[y] > dis[t] + weight[i]) {
                dis[y] = dis[t] + weight[i];
            }
        }
        cot++;
    }
}

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add_edge(x, y, z);
        add_edge(y + n, x + n, z);
    }
    long long ans = 0;

    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        ans += dis[i];
    }
    dijkstra(1 + n);
    for (int i = 1 + n; i <= n * 2; i++) {
        ans += dis[i];
    }
    cout << ans << endl;
    return 0;
}