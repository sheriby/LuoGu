#include <stdio.h>
#define inf 0x2f2f2f2f

int n, m, dis[101][101];

// 对于这种多源的最短路径，使用floyd算法更优
// 和dijkstra算法不同的是，floyd算法可以处理带负权的图，只要没有负环
// 运行一次算法可得任意两点之间的最短路
// 下面的是对特定的题目进行优化了之后的floyd算法
int main() {
    int a, s, d, e;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                dis[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &s, &d);
        if (a == 0) {
            if (dis[s][d] != inf)
                printf("%d\n", dis[s][d]);
            else
                printf("-1\n");
        } else {
            scanf("%d", &e);
            if (e < dis[d][s]) {
                dis[d][s] = dis[s][d] = e;
                for (int k = 1; k <= n; k++) {
                    for (int l = 1; l <= n; l++) {
                        if (dis[k][s] + dis[s][d] + dis[d][l] < dis[k][l])
                            dis[k][l] = dis[l][k] =
                                dis[k][s] + dis[s][d] + dis[d][l];
                    }
                }
            }
        }
    }
    return 0;
}