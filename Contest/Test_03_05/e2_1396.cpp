#include <algorithm>
#include <cstdio>
using namespace std;
#define N 10001
#define M 40001

int n, m, s, t;
int f[N];

struct Edge {
    int from;
    int to;
    int weight;
} edges[M];

bool cmp(const Edge &a, const Edge &b) { return a.weight < b.weight; }

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void unite(int x, int y) { f[find(x)] = find(y); }

// Krustral
int main(int argc, const char *argv[]) {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int ea, eb, ew, maxew = -1;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }
    sort(edges, edges + m, cmp);

    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].from, v = edges[i].to;
        if (find(u) != find(v)) {
            unite(u, v);
            if (find(s) == find(t)) {
                printf("%d\n", edges[i].weight);
                return 0;
            }
        }
    }

    return 0;
}