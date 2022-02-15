#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, m, x;
    double avg, max_avg = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int sum = 0, max = 0, min = 11;
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            sum += x;
            if (x > max)
                max = x;
            if (x < min)
                min = x;
        }
        avg = (sum - max - min) * 1.0 / (m - 2);
        if (avg > max_avg)
            max_avg = avg;
    }
    printf("%.2lf\n", max_avg);
    return 0;
}