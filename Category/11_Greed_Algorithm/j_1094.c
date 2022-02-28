#include <stdio.h>
#include <stdlib.h>

int arr[30001];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, const char *argv[]) {
    int w, n;
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    int ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (arr[l] + arr[r] <= w)
            ans++, l++, r--;
        else
            ans++, r--;
    }
    printf("%d\n", ans);
    return 0;
}