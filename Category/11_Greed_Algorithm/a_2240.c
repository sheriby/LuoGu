#include <stdio.h>
#include <stdlib.h>

typedef struct Gold {
    int weight;
    int value;
    double xjb;
} Gold;

Gold golds[101];

// 这题需要注意精度丢失的问题
int cmp(const void *a, const void *b) {
    return (((Gold *)b)->value) * (((Gold *)a)->weight) >
           (((Gold *)b)->weight) * (((Gold *)a)->value);
}

int main(int argc, const char *argv[]) {
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &golds[i].weight, &golds[i].value);
    }
    qsort(golds, n, sizeof(Gold), cmp);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (t > golds[i].weight) {
            ans += golds[i].value;
            t -= golds[i].weight;
        } else {
            ans += t * golds[i].value * 1.0 / golds[i].weight;
            break;
        }
    }
    printf("%.2lf", ans);
    return 0;
}