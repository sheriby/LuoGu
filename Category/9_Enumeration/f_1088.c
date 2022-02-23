#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); };

int hand[10001];
int n, m;

void next() {
    for (int i = n - 1; i >= 1; i--) {
        if (hand[i - 1] > hand[i])
            continue;
        for (int j = n - 1; j > i - 1; j--) {
            if (hand[j] > hand[i - 1]) {
                int tmp = hand[j];
                hand[j] = hand[i - 1];
                hand[i - 1] = tmp;
                qsort(hand + i, n - i, sizeof(int), cmp);
                break;
            }
        }
        break;
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &hand[i]);
    }
    for (int j = 0; j < m; j++) {
        next();
    }
    for (int i = 0; i < n; i++) {
        printf("%d", hand[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}