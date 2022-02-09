#include <stdio.h>
#include <stdlib.h>
int arr[3];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, 3, sizeof(int), cmp);
    for (int i = 0; i < 3; i++) {
        printf("%d", arr[i]);
        if (i != 2)
            printf(" ");
    }

    return 0;
}
