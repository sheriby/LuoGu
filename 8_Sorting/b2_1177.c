#include <stdio.h>
#include <stdlib.h>

int arr[100001];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
    return 0;
}