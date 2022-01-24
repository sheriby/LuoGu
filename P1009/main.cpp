#include <cstdio>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    // 无法处理大整数，需要使用高精度
    long long sum = 0, cur = 1;
    for (int i = 1; i <= n; i++) {
        cur *= i;
        sum += cur;
    }

    printf("%d\n", sum);

    return 0;
}
