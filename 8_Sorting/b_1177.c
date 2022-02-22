#include <stdio.h>

int arr[100001];

void quick_sort(int arr[], int left, int right) {
    int l = left, r = right;
    if (l >= r)
        return;
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
    if (l - 1 > left)
        quick_sort(arr, left, l - 1);
    if (right > l + 1)
        quick_sort(arr, l + 1, right);
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
    return 0;
}