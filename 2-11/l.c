#include <stdio.h>

int main(int argc, const char *argv[]) {
    double x, step = 2, sum = 0;
    int count = 0;
    scanf("%lf", &x);
    while (sum < x) {
        sum += step;
        step *= 0.98;
        count++;
    }
    printf("%d\n", count);
    return 0;
}