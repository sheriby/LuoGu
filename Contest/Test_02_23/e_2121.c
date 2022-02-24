#include <stdio.h>
#include <stdlib.h>
int n, m, k;

typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;
Edge edges[100001];
int f[100001];

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

int unite(int x, int y) { f[find(x)] = f[y]; }

int cmp(const void *a, const void *b) {
    return ((Edge *)b)->weight - ((Edge *)a)->weight;
}

// Kruskal算法
int main(int argc, const char *argv[]) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }
    qsort(edges, m, sizeof(Edge), cmp);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    int from, to, beauty = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        from = edges[i].from;
        to = edges[i].to;
        if (find(from) != find(to)) {
            beauty += edges[i].weight;
            unite(from, to);
            cnt++;
            if (cnt == k)
                break;
        }
    }
    printf("%d\n", beauty);
    return 0;
}