#include <math.h>
#include <stdio.h>

int food[10][2];
int minv = 0x7fffffff;

int n;

// 回溯枚举，需要变的量可以放在回溯函数中
void run(int ind, int s, int k, int flag) {
    if (ind == n) {
        if (flag && abs(s - k) < minv)
            minv = abs(s - k);
        return;
    }
    run(ind + 1, s, k, flag | 0);
    run(ind + 1, s * food[ind][0], k + food[ind][1], 1);
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &food[i][0], &food[i][1]);
    }
    run(0, 1, 0, 0);
    printf("%d\n", minv);
    return 0;
}