#include <stdio.h>
#include <stdlib.h>

int arr[301];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    long long ans = 0;
    int pre = 0, l = 0, r = n - 1, flag = 1;
    for (int i = 0; i < n; i++) {
        if (flag) {
            ans += (arr[r] - pre) * (arr[r] - pre);
            pre = arr[r--];
            flag = 0;
        } else {
            ans += (pre - arr[l]) * (pre - arr[l]);
            pre = arr[l++];
            flag = 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}