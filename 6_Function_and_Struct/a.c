#include <math.h>
#include <stdio.h>

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

int main(int argc, const char *argv[]) {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double res = distance(x1, y1, x2, y2) + distance(x1, y1, x3, y3) +
                 distance(x2, y2, x3, y3);
    printf("%.2lf\n", res);
    return 0;
}