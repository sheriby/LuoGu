#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, x, sum = 0, min = 11, max = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }
    printf("%.2lf", (sum - min - max) * 1.0 / (n - 2));
    return 0;
}