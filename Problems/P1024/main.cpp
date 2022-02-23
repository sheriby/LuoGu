#include <cmath>
#include <cstdio>

double a, b, c, d;
int count = 0;

double fx(double x) { return a * pow(x, 3) + b * pow(x, 2) + c * x + d; }

void print(double x) {
    printf("%.2lf", x);
    count++;
    if (count != 3)
        printf(" ");
}

void findg(double x1, double x2) {
    while (fabs(x1 - x2) > 0.001) {
        double mid = (x1 + x2) / 2;
        if (fx(mid) * fx(x1) < 0) {
            x2 = mid;
        } else {
            x1 = mid;
        }
    }
    print(x1);
}

int main(int argc, char const *argv[]) {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double x1, x2;
    for (int i = 0; i <= 200; i++) {
        x1 = -100 + i;
        x2 = x1 + 1;

        double fx1 = fx(x1);
        double fx2 = fx(x2);

        if (fx1 == 0)
            print(x1);
        if (fx(x1) * fx(x2) < 0) {
            findg(x1, x2);
        }
    }
}
