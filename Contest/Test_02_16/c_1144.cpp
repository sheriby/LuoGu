#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1000001;

vector<int> edges[MAX];
int counts[MAX];
int visit[MAX];
int dep[MAX];

// 广度优先搜索
int main(int argc, const char *argv[]) {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visit[1] = 1;
    counts[1] = 1;
    dep[1] = 0;
    int t, k;
    while (!q.empty()) {
        while (!q.empty()) {
            t = q.front();
            q.pop();

            for (int i = 0; i < edges[t].size(); i++) {
                k = edges[t][i];
                if (!visit[k]) {
                    visit[k] = 1;
                    q.push(k);
                    dep[k] = dep[t] + 1;
                }
                if (dep[k] == dep[t] + 1) {
                    counts[k] = (counts[k] + counts[t]) % 100003;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << counts[i] << endl;
    }

    return 0;
}