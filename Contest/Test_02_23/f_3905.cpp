#include <cstdio>
#include <queue>
#define N 101
#define M 5000

int head[N], to[M], nxt[M], dis[N], weight[M], destroy[M];
int tot = 0;

int visit[M];
std::queue<int> q;

void add(int x, int y, int w) {
    to[++tot] = y;
    weight[tot] = w;
    nxt[tot] = head[x];
    head[x] = tot;
}

// Dijstrual算法
int main(int argc, const char *argv[]) {
    int n, m;
    int a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

    int d;
    scanf("%d", &d);
    for (int i = 0; i < d; i++) {
        scanf("%d%d", &a, &b);
        for (int j = head[a]; j; j = nxt[j]) {
            if (to[j] == b) {
                destroy[j] = 1;
                break;
            }
        }
        for (int j = head[b]; j; j = nxt[j]) {
            if (to[j] == a) {
                destroy[j] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = 1e9;
    }

    int s, e;
    scanf("%d%d", &s, &e);
    dis[s] = 0;
    q.push(s);
    while (q.size()) {
        int t = q.front();
        q.pop();
        if (visit[t])
            continue;
        visit[t] = 1;
        for (int i = head[t]; i; i = nxt[i]) {
            int y = to[i];
            if (!destroy[i]) {
                dis[y] = dis[t];
            } else if (dis[y] > dis[t] + weight[i]) {
                dis[y] = dis[t] + weight[i];
            }
            q.push(y);
        }
    }
    printf("%d\n", dis[e]);
    return 0;
}