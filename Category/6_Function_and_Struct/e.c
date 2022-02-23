#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, res = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    printf("%d\n", res);
    return 0;
}