#include <stdio.h>
#include <stdlib.h>
#define N 1001
#define M 10001

int f[N];
int n, m, k;

typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;

Edge edges[M];

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

int unite(int x, int y) { f[find(x)] = find(y); }

int main(int argc, const char *argv[]) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }
    qsort(edges, m, sizeof(Edge), cmp);
    for (int i = 0; i < n; i++) {
        f[i] = i;
    }
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        if (find(edges[i].from) != find(edges[i].to)) {
            ans += edges[i].weight;
            unite(edges[i].from, edges[i].to);
            cnt++;
        }
        if (cnt == n - k)
            break;
    }
    if (cnt == n - k)
        printf("%d\n", ans);
    else
        printf("No Answer\n");
}