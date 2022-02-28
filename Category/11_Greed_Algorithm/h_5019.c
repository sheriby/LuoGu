#include <stdio.h>

int arr[100001];
int cnt = 0;

void run(int l, int r) {
    if (l > r)
        return;
    if (l == r) {
        cnt += arr[l];
        return;
    }
    int min = 0x7fffffff, mini = -1;
    for (int i = l; i <= r; i++) {
        if (arr[i] < min) {
            min = arr[i];
            mini = i;
        }
    }
    cnt += min;
    for (int i = l; i <= r; i++) {
        arr[i] -= min;
    }
    run(l, mini - 1);
    run(mini + 1, r);
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    run(0, n);
    printf("%d\n", cnt);
    return 0;
}