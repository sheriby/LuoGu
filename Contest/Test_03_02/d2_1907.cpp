#include <cmath>
#include <cstdio>

struct Lukou {
    double x;
    double y;
} lukou[1001];

int r_road[1001][1001];

double dis[1005];
int vis[1005];
double d[1005][1005];
double d_unhappy, r_unhappy;

int main(int argc, const char *argv[]) {
    scanf("%lf%lf", &d_unhappy, &r_unhappy);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &lukou[i].x, &lukou[i].y);
    }
    while (1) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (!x && !y)
            break;
        r_road[x][y] = 1;
        r_road[y][x] = 1;
        d[x][y] = d[y][x] = r_unhappy * sqrt(pow(lukou[x].x - lukou[y].x, 2) +
                                             pow(lukou[x].y - lukou[y].y, 2));
    }
    scanf("%lf%lf%lf%lf", &lukou[0].x, &lukou[0].y, &lukou[n + 1].x,
          &lukou[n + 1].y);
    for (int i = 0; i < n + 1; i++) {
        for (int j = i + 1; j <= n + 1; j++) {
            if (!r_road[i][j]) {
                d[i][j] = d[j][i] =
                    d_unhappy * sqrt(pow(lukou[i].x - lukou[j].x, 2) +
                                     pow(lukou[i].y - lukou[j].y, 2));
            }
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        dis[i] = 1e10;
    }
    dis[0] = 0;
    for (int i = 0; i <= n + 1; i++) {
        int u = -1;
        double minv = 1e10;
        for (int j = 0; j <= n + 1; j++) {
            if (!vis[j] && dis[j] < minv) {
                u = j;
                minv = dis[j];
            }
        }
        vis[u] = 1;
        for (int k = 1; k <= n + 1; k++) {
            if (k == u)
                continue;
            double r = dis[u] + d[u][k];
            if (dis[k] > r) {
                dis[k] = r;
            }
        }
    }
    printf("%.4lf\n", dis[n + 1]);
    return 0;
}