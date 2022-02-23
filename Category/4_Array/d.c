#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
    int right;
} Area;

Area area[100];

int cmp(const void *a, const void *b) {
    return ((Area *)a)->left - ((Area *)b)->left;
}

int main(int argc, const char *argv[]) {
    int l, m;
    scanf("%d%d", &l, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &area[i].left, &area[i].right);
    }

    qsort(area, m, sizeof(Area), cmp);
    int r = 0, count = 0;
    for (int i = 0; i < m; i++) {
        if (area[i].right <= r)
            continue;
        if (area[i].left < r)
            area[i].left = r + 1;
        count += area[i].right - area[i].left + 1;
        r = area[i].right;
    }
    printf("%d\n", l + 1 - count);
    return 0;
}