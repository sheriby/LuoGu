#include <math.h>
#include <stdio.h>

int ss[11], kk[11];
int n;
int minv = 0x7fffffff;

void run(int ind, int s, int k, int flag) {
    if (ind == n) {
        if (flag && abs(s - k) < minv)
            minv = abs(s - k);
        return;
    }
    run(ind + 1, s * ss[ind], k + kk[ind], 1);
    run(ind + 1, s, k, flag | 0);
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ss[i], &kk[i]);
    }
    run(0, 1, 0, 0);
    printf("%d\n", minv);
    return 0;
}