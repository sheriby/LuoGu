#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> edges;

int f[100001];

int find(int x) {
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void unite(int x, int y) { f[find(x)] = find(y); }

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    int ns = 0;
    while (1) {
        cin >> a >> b;
        if (a == -1 && b == -1)
            return 0;
        if (a == 0 && b == 0) {
            int flag = 1;
            if (ns != edges.size() + 1) {
                flag = 0;
            } else {
                for (int i = 0; i < edges.size(); i++) {
                    int fir = edges[i].first, sec = edges[i].second;
                    if (find(fir) != find(sec))
                        unite(fir, sec);
                    else {
                        flag = 0;
                        break;
                    }
                }
            }
            cout << flag << endl;
            ns = 0;
            memset(f, 0, sizeof(f));
            edges.clear();
        } else {
            edges.push_back(make_pair(a, b));
            if (!f[a])
                ns++, f[a] = a;
            if (!f[b])
                ns++, f[b] = b;
        }
    }
    return 0;
}