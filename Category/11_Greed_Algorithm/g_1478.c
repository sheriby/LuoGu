#include <stdio.h>
#include <stdlib.h>

struct Apple {
    int height;
    int weight;
} apples[5001];

int cmp(const void *a, const void *b) {
    return ((struct Apple *)a)->weight - ((struct Apple *)b)->weight;
}

int main(int argc, const char *argv[]) {
    int n, s, a, b;
    scanf("%d%d%d%d", &n, &s, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &apples[i].height, &apples[i].weight);
    }
    qsort(apples, n, sizeof(struct Apple), cmp);
    int h = a + b, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (h >= apples[i].height && s >= apples[i].weight) {
            cnt++;
            s -= apples[i].weight;
            if (!s)
                break;
        }
    }
    printf("%d\n", cnt);
    return 0;
}