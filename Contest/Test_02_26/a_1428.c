#include <stdio.h>

int arr[101];
int res[101];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                res[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}