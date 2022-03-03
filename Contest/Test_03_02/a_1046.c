#include <stdio.h>

int arr[10];

int main(int argc, const char *argv[]) {
    int n;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &n);
    n += 30;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] <= n)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}