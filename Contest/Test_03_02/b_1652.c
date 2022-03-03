#include <stdio.h>

struct Round {
    int x;
    int y;
    int r;
} rod[51];

int is_in(int x, int y, struct Round r) {
    return (x - r.x) * (x - r.x) + (y - r.y) * (y - r.y) < r.r * r.r;
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &rod[i].x);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &rod[i].y);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &rod[i].r);
    }
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (is_in(x1, y1, rod[i]) != is_in(x2, y2, rod[i])) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}