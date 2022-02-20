#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
    int from;
    int to;
    int len;
} edges[100001];

int f[1001];

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void _union(int x, int y) { f[find(x)] = find(y); }

bool cmp(const Edge &a, const Edge &b) { return a.len < b.len; }

// Krustral and UnionFind
int main(int argc, const char *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].len;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    sort(edges, edges + m, cmp);
    int from, to, count = 0, time = 0;
    for (int i = 0; i < m; i++) {
        from = edges[i].from;
        to = edges[i].to;
        if (find(from) != find(to)) {
            _union(from, to);
            if (edges[i].len > time)
                time = edges[i].len;
            count++;
            if (count == n - 1)
                break;
        }
    }
    if (count == n - 1)
        cout << time << endl;
    else
        cout << -1 << endl;
    return 0;
}