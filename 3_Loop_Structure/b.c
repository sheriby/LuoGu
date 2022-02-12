#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, k, x;
    scanf("%d%d", &n, &k);
    int sum1 = 0, sum2 = 0, cot1 = 0, cot2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i % k) {
            sum2 += i;
            cot2++;
        } else {
            sum1 += i;
            cot1++;
        }
    }
    printf("%.1lf %.1lf\n", sum1 * 1.0 / cot1, sum2 * 1.0 / cot2);
    return 0;
}