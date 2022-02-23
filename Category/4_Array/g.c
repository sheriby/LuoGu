#include <stdio.h>
#include <stdlib.h>

int jiang[7];
int ans[7];
int res[8];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 7; i++) {
        scanf("%d", &jiang[i]);
    }
    qsort(jiang, 7, sizeof(int), cmp);
    int count;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            scanf("%d", &ans[j]);
        }
        count = 0;
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                if (ans[j] == jiang[k]) {
                    count++;
                    break;
                }
                if (ans[j] < jiang[k])
                    break;
            }
        }
        res[count]++;
    }

    for (int i = 7; i > 0; i--) {
        printf("%d", res[i]);
        if (i != 1)
            printf(" ");
    }
    return 0;
}