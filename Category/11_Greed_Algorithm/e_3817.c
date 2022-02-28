#include <stdio.h>

int arr[100001];

// 贪心算法，从前往后遍历的时候，优先吃后面的果子
// 吃后面的果子还有可能影响后面后面的果子，局部最优=>全局最优
int main(int argc, const char *argv[]) {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    long long res, ans = 0;
    for (int i = 0; i < n - 1; i++) {
        res = arr[i] + arr[i + 1];
        if (res > x) {
            if (arr[i + 1] < res - x)
                arr[i + 1] = 0;
            else
                arr[i + 1] = x - arr[i];
            ans += res - x;
        }
    }

    printf("%lld\n", ans);

    return 0;
}