#include <stdio.h>

int main(int argc, const char *argv[]) {
    int k, i = 1;
    double sum = 1;
    scanf("%d", &k);
    while (sum <= k) {
        sum += 1.0 / ++i;
    }
    printf("%d\n", i);
    return 0;
}