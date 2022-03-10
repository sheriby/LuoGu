#include <stdio.h>

char map[101][101];
int cnt = 0;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    map[x][y] = '0';

    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= n || newy < 0 || newy >= m ||
            map[newx][newy] == '0')
            continue;
        dfs(newx, newy);
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", &map[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != '0')
                cnt++, dfs(i, j);
        }
    }
    printf("%d\n", cnt);
    return 0;
}