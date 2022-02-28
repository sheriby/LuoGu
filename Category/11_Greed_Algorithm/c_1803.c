#include <stdio.h>
#include <stdlib.h>

typedef struct Contest {
    int start;
    int end;
} Contest;

Contest contests[1000001];

int cmp(const void *a, const void *b) {
    return ((Contest *)a)->start - ((Contest *)b)->start;
}

// 按照事件的开始的时间排序，使用贪心算法
int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &contests[i].start, &contests[i].end);
    }
    qsort(contests, n, sizeof(Contest), cmp);

    int end = contests[0].end, cnt = 1;
    int s, e;
    for (int i = 1; i < n; i++) {
        s = contests[i].start, e = contests[i].end;
        if (s >= end) {
            cnt++;
            end = e;
        } else if (e < end) {
            end = e;
        }
    }
    printf("%d\n", cnt);
    return 0;
}