#include <iostream>
using namespace std;

char maps[1001][1001];

int visit[1001][1001];
int ans[100001];

int n, m;
int count;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

// dfs
void run(int x, int y, int a) {
    ans[a]++;
    visit[x][y] = a;
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (!visit[newx][newy] && newx >= 0 && newx < n && newy >= 0 &&
            newy < n && maps[x][y] != maps[newx][newy]) {
            run(newx, newy, a);
        }
    }
}

int main(int argc, const char *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maps[i];
    }
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        x--;
        y--;
        count = 0;
        if (visit[x][y])
            ans[i] = ans[visit[x][y]];
        else
            run(x, y, i);
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}