#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;
int arr[MAX][MAX];

struct Edge {
    int from;
    int to;
    int len;
};

vector<Edge> edges;
int f[MAX];

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

// 最小生成树 Krustral算法，将所有的边按照长度排序
// 利用并查集判断，如果两个边位于不同的集合时，放入

void unionn(int x, int y) { f[find(x)] = find(y); }

bool cmp(Edge &a, Edge &b) { return a.len < b.len; }

int main(int argc, const char *argv[]) {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (i > j) {
                Edge e;
                e.from = i;
                e.to = j;
                e.len = x;
                edges.push_back(e);
            }
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    int from, to, sum_len = 0, cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (find(edges[i].from) != find(edges[i].to)) {
            sum_len += edges[i].len;
            unionn(edges[i].from, edges[i].to);
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }

    cout << sum_len << endl;
    return 0;
}