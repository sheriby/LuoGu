#include <stdio.h>

int arr[101];
int ind = 0;

int main(int argc, const char *argv[]) {
    int x;
    while (scanf("%d", &x), x) {
        arr[ind++] = x;
    }
    for (int i = ind - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    return 0;
}