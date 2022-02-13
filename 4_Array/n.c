#include <math.h>
#include <stdio.h>

int light[2000002];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    double a;
    int t, tmp;
    for (int i = 0; i < n; i++) {
        scanf("%lf%d", &a, &t);
        for (int j = 1; j <= t; j++) {
            int tmp = floor(a * j);
            light[tmp]++;
        }
    }

    for (int i = 0; i < 2000002; i++) {
        if (light[i] & 1) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}