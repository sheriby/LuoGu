#include <cmath>
#include <cstdio>

int main(int argc, char const *argv[]) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double p = 0.5 * (a + b + c);
    printf("%.1lf\n", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}
