#include <stdio.h>
#include <stdlib.h>

int dis[100] = {990,  1010, 1970, 2030, 2940, 3060, 3930,
                4060, 4970, 5030, 5990, 6010, 7000};

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }
long long cnt = 0;
int a, b, n;

void run(int i, int pre) {
    if (i == n - 1) {
        if (dis[n - 1] - pre <= b && dis[n - 1] - pre >= a)
            cnt++;
        return;
    }
    if (dis[i] - pre > b)
        return;
    run(i + 1, pre);
    if (dis[i] - pre >= a) {
        run(i + 1, dis[i]);
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d%d%d", &a, &b, &n);
    n += 13;
    for (int i = 13; i < n; i++) {
        scanf("%d", &dis[i]);
    }
    qsort(dis, n, sizeof(int), cmp);
    run(0, 0);
    printf("%lld\n", cnt);
    return 0;
}