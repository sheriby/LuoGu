#include <stdio.h>

int arr[101];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min = 1001;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    printf("%d\n", min);
    return 0;
}