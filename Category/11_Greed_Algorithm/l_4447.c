#include <stdio.h>
#include <stdlib.h>

int arr[100005], n;
int cnt, min = 0x7fffffff;
int lst[100005], len[100005];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        int find = 0;
        int res = 0, min_len = 0x7fffffff;
        for (int j = 0; j < cnt; j++)
            // 找到符合要求的最短的队列
            if (lst[j] == arr[i] - 1 && len[j] < min_len) {
                min_len = len[j];
                res = j;
                find = 1;
            }
        if (!find) {
            lst[cnt] = arr[i];
            len[cnt++] = 1;
        } else {
            lst[res] = arr[i];
            len[res]++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (len[i] < min)
            min = len[i];
    }
    printf("%d\n", min);
    return 0;
}