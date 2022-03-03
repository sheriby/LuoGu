#include <cmath>
#include <cstdio>
#include <queue>

struct Lukou {
    double x;
    double y;
} lukou[1001];

int r_road[1001][1001];

double dis[1005];
int vis[1005];
double d_unhappy, r_unhappy;
std::priority_queue<std::pair<double, int>> q;

double get_dis(int i, int j) {
    double base = d_unhappy;
    if (r_road[i][j])
        base = r_unhappy;
    return base * sqrt(pow(lukou[i].x - lukou[j].x, 2) +
                       pow(lukou[i].y - lukou[j].y, 2));
}

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
    }
    scanf("%lf%lf%lf%lf", &lukou[0].x, &lukou[0].y, &lukou[n + 1].x,
          &lukou[n + 1].y);

    for (int i = 0; i <= n + 1; i++) {
        dis[i] = 1e10;
    }
    dis[0] = 0;
    q.push(std::make_pair(0, 0));
    while (q.size()) {
        int t = q.top().second;
        q.pop();
        if (vis[t])
            continue;
        vis[t] = 1;
        for (int i = 1; i <= n + 1; i++) {
            if (i == t)
                continue;
            double r = dis[t] + get_dis(t, i);
            if (dis[i] > r) {
                dis[i] = r;
                if (!vis[i])
                    q.push(std::make_pair(-r, i));
            }
        }
    }

    printf("%.4lf\n", dis[n + 1]);

    return 0;
}