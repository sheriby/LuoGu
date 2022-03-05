#include <cstdio>
#include <cstring>
#include <queue>

int map[401][401];
int vis[401][401];
int n, m, x, y;
std::queue<std::pair<int, int>> q;

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int main(int argc, const char *argv[]) {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    memset(map, -1, sizeof(map));
    q.push(std::make_pair(x, y));
    int a, b, s;
    map[x][y] = 0;
    vis[x][y] = 1;
    while (q.size()) {
        a = q.front().first, b = q.front().second;
        q.pop();
        for (int j = 0; j < 8; j++) {
            int newx = a + dx[j];
            int newy = b + dy[j];
            if (newx < 1 || newx > n || newy < 1 || newy > m)
                continue;
            if (!vis[newx][newy]) {
                q.push(std::make_pair(newx, newy));
                vis[newx][newy] = 1;
                map[newx][newy] = map[a][b] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}