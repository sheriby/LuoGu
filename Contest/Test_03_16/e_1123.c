#include <stdio.h>
#include <string.h>

int map[7][7];
// 该vis数组表示的含义是，周围有几个数被访问了，只有有一个数被访问该数就不能添加
int vis[7][7];
int t, n, m, ans, max;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y) {
    // 下一行
    if (y == m) {
        dfs(x + 1, 0);
        return;
    }

    // dfs结束
    if (x == n) {
        if (ans > max)
            max = ans;
        return;
    }

    // 不添加该数
    dfs(x, y + 1);

    // 可以添加，添加该数
    if (!vis[x][y]) {
        for (int i = 0; i < 8; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m)
                continue;
            vis[newx][newy]++;
        }
        ans += map[x][y];
        dfs(x, y + 1);
        // 状态回溯
        for (int i = 0; i < 8; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m)
                continue;
            vis[newx][newy]--;
        }
        ans -= map[x][y];
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d", &t);
    for (int k = 0; k < t; k++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        ans = 0, max = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0);
        printf("%d\n", max);
    }
    return 0;
}