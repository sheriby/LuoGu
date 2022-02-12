#include <math.h>
#include <stdio.h>

int main() {
    int s, v;
    scanf("%d%d", &s, &v);
    int t = ceil(s * 1.0 / v) + 10;
    int h = 7 - (t / 60), m = 60 - t % 60;
    printf("%02d:%02d", h >= 0 ? h : h + 24, m);
    return 0;
}
