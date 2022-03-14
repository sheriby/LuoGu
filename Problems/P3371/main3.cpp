#include <iostream>
#include <queue>
using namespace std;

const int N = 1e4 + 1;
const int M = 5e5 + 1;
const int INF = 0x7fffffff;

int d[N], n, m, s, h[N], e[M], ne[M], w[M], idx;
bool in[N];
priority_queue<pair<int, int>> q;

void add(int a, int b, int c) {
    e[++idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx;
}

// spfa算法，可以处理负权图的问题，但是容易被卡，最好不要使用
// 负权图不能出现环
void spfa(int s) {
    for (int i = 1; i <= n; i++) {
        d[i] = 0x7fffffff;
    }
    d[s] = 0;
    in[s] = true;
    q.push(make_pair(0, s));
    while (q.size()) {
        int t = q.top().second;
        q.pop();
        in[t] = false;
        for (int i = h[t]; i; i = ne[i]) {
            int y = e[i];
            if (d[y] > d[t] + w[i]) {
                d[y] = d[t] + w[i];
                // 不在队列中的话，加入队列
                if (!in[y])
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
    spfa(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
