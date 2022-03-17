#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
    int x;
    int y;
    int w;
} edges[250000];
int cnt = 0;

bool cmp(const Edge &a, const Edge &b) { return a.w < b.w; }

int f[501];

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void unite(int x, int y) { f[find(x)] = find(y); }

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, x;
    cin >> a >> b;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> x;
            if (j <= i)
                continue;
            if (x > a || x == 0)
                x = a;
            edges[cnt].x = i, edges[cnt].y = j, edges[cnt].w = x;
            cnt++;
        }
    }

    for (int i = 1; i <= b; i++)
        f[i] = i;
    sort(edges, edges + cnt, cmp);
    long long ans = a, res = 0;
    for (int i = 0; i < cnt; i++) {
        int from = edges[i].x;
        int to = edges[i].y;
        if (find(from) != find(to)) {
            unite(from, to);
            ans += edges[i].w;
            res++;
        }
        if (res == b - 1)
            break;
    }

    cout << ans << endl;

    return 0;
}