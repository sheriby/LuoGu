#include <stdio.h>

char map[10][11];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int visit[10][10][10][10];

int legal(int x, int y) {
    if (x < 0 || x > 9 || y < 0 || y > 9 || map[x][y] == '*')
        return 0;
    return 1;
}

int main(int argc, const char *argv[]) {
    for (int i = 0; i < 10; i++) {
        scanf("%s", &map[i]);
    }
    int dirf = 0, dirc = 0;
    int fx, fy, cx, cy;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'F') {
                fx = i;
                fy = j;
            }
            if (map[i][j] == 'C') {
                cx = i;
                cy = j;
            }
        }
    }
    int time = 0;
    int newfx, newfy, newcx, newcy;
    int flag = 1;
    while (1) {
        newcx = cx + dx[dirc];
        newcy = cy + dy[dirc];
        if (legal(newcx, newcy)) {
            cx = newcx;
            cy = newcy;
        } else
            dirc = (dirc + 1) % 4;

        newfx = fx + dx[dirf];
        newfy = fy + dy[dirf];
        if (legal(newfx, newfy)) {
            fx = newfx;
            fy = newfy;
        } else
            dirf = (dirf + 1) % 4;
        time++;
        if (cx == fx && cy == fy) {
            break;
        }
        if (visit[cx][cy][fx][fy]++ >= 4) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("%d\n", time);
    else
        printf("0\n");

    return 0;
}