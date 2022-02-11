#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, x, min = 1001, max = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > max)
            max = x;
        if (x < min)
            min = x;
    }
    printf("%d\n", max - min);
    return 0;
}