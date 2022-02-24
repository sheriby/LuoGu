#include <stdio.h>
int n, m;
int s, cnt;
int price[101];

// 递归与回溯，容易TLE，该题最后一个点TLE
// 正确的做法还是得动态规划
void run(int ind) {
    if (s > m)
        return;
    if (ind > n) {
        if (s == m)
            cnt++;
        return;
    }
    s += price[ind];
    run(ind + 1);
    s -= price[ind];
    run(ind + 1);
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
    }
    run(1);
    printf("%d\n", cnt);
    return 0;
}