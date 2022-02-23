#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maps[151][151];

vector<pair<int, int>> res;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

// dfn id => 记录dfs访问的顺序
// f => 记录上一次访问的元素
// low => 记录可以接触到的最早的访问时间
int dfn[151], low[151], n, m, id, f[151];

// 求图中的桥（割边），使用tarjan算法
void tarjan(int x) {
    dfn[x] = low[x] = ++id;
    for (int i = 1; i <= n; i++) {
        if (!maps[x][i])
            continue;
        int y = i;
        if (dfn[y] && y != f[x]) // 不是其父结点
            low[x] = min(low[x], dfn[y]);
        if (!dfn[y]) {
            f[y] = x; // x是y的父，是上一个时间访问的节点
            tarjan(y);
            low[x] = min(low[x], low[y]); // 回溯时候带着父结点更新low
            if (low[y] > dfn[x]) // 子时间大于父时间, 即从子回不到父
                res.push_back(make_pair(x, y)); // 该边为割边
        }
    }
}

int main(int argc, const char *argv[]) {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        maps[x][y] = maps[y][x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}