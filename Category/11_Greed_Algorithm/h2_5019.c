#include <stdio.h>

int arr[100001];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i - 1])
            ans += arr[i] - arr[i - 1];
    }
    printf("%d\n", ans);
    return 0;
}