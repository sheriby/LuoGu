#include <stdio.h>

int arr[5000001];

int n, k;
int quick_sort_find(int left, int right) {
    int l = left, r = right;
    int mid = arr[(l + r) / 2];
    int tmp;
    do {
        while (arr[l] < mid)
            l++;
        while (arr[r] > mid)
            r--;
        if (l <= r) {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    } while (l <= r);
    if (k <= r)
        return quick_sort_find(left, r);
    else if (k >= l)
        return quick_sort_find(l, right);
    else
        return arr[r + 1];
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int res = quick_sort_find(0, n - 1);
    printf("%d\n", res);
    return 0;
}