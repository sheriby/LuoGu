#include <cstdio>
#include <queue>
using namespace std;

int mod = 100003;
int n, m, x, y, tot = 0;
const int N = 1000005, M = 4000005;
int head[N], to[M], nxt[M], dis[N], count[N];
bool visit[N];
queue<int> q;

void add(int x, int y) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

// Dijstral算法
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = 1e9;
        visit[i] = 0;
    }

    dis[1] = 0;
    count[1] = 1;
    q.push(1);
    while (q.size()) {
        x = q.front();
        q.pop();
        if (visit[x])
            continue;
        visit[x] = 1;
        for (int i = head[x]; i; i = nxt[i]) {
            y = to[i];
            if (dis[y] > dis[x] + 1) {
                dis[y] = dis[x] + 1;
                count[y] = count[x];
                q.push(y);
            } else if (dis[y] == dis[x] + 1) {
                count[y] += count[x];
                count[y] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", count[i]);
    return 0;
}