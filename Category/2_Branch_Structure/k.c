#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    double sum = 0;
    if (n > 400)
        printf("%.1lf", 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663);
    else if (n > 150)
        printf("%.1lf", 150 * 0.4463 + (n - 150) * 0.4663);
    else
        printf("%.1lf", n * 0.4463);

    return 0;
}
