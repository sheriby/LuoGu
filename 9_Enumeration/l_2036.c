#include <math.h>
#include <stdio.h>

int food[10][2];
int minv = 0x7fffffff;

int n, s = 1, k = 0, flag = 0;

// 回溯枚举
void run(int ind) {
    if (ind == n) {
        if (flag && abs(s - k) < minv)
            minv = abs(s - k);
        return;
    }
    s *= food[ind][0];
    k += food[ind][1];
    flag++;
    run(ind + 1);
    flag--;
    s /= food[ind][0];
    k -= food[ind][1];
    run(ind + 1);
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    int zero = 0, minz = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &food[i][0], &food[i][1]);
        if (food[i][0] == 0) {
            zero = 1;
            if (food[i][1] < minz)
                minz = food[i][1];
        }
    }
    if (zero) {
        printf("%d\n", minz);
    } else {
        run(0);
        printf("%d\n", minv);
    }
    return 0;
}