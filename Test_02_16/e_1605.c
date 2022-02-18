#include <stdio.h>

int ans[6][6];
int visit[6][6];
int cnt = 0;
int n, m, t;
int sx, sy, ex, ey;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int is_valid(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m || ans[x][y] == 1 || visit[x][y] == 1)
        return 0;
    return 1;
}

// 递归与回溯
void run(int x, int y) {
    if (x == ex && y == ey) {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (is_valid(newx, newy)) {
            // 添加已经走过了的标记
            visit[x][y] = 1;
            run(newx, newy);
            // 取消标记
            visit[x][y] = 0;
        }
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d%d%d%d%d%d%d", &n, &m, &t, &sx, &sy, &ex, &ey);
    int x, y;
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &x, &y);
        ans[x][y] = 1;
    }
    run(sx, sy);
    printf("%d\n", cnt);
    return 0;
}