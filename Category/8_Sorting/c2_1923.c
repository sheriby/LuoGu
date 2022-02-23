#include <stdio.h>

int arr[5000001];

int n, k;
int quick_sort_find(int left, int right) {
    int l = left, r = right;
    int base = arr[l];
    while (l < r) {
        while (arr[r] >= base && r > l)
            r--;
        if (l >= r)
            break;
        arr[l++] = arr[r];
        while (arr[l] <= base && l < r)
            l++;
        if (l >= r)
            break;
        arr[r--] = arr[l];
    }
    arr[l] = base;
    if (k <= l - 1)
        return quick_sort_find(left, l - 1);
    else if (k >= l + 1)
        return quick_sort_find(l + 1, right);
    else
        return arr[l];
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