#include <stdio.h>

int is_prime(int x) {
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, const char *argv[]) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (is_prime(x))
            printf("%d ", x);
    }
    return 0;
}