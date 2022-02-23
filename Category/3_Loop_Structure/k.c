#include <stdio.h>

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int is_huiwen(int x) {
    if (x % 10 == 0)
        return 0;
    int sum = 0;
    while (x > sum) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    if (sum == x || sum / 10 == x)
        return 1;
    return 0;
}

int main(int argc, const char *argv[]) {
    int a = 5, b = 10000000, count = 0;
    freopen("k.output.txt", "w", stdout);
    // scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (is_huiwen(i) && is_prime(i))
            printf("%d,", i), count++;
    }
    printf("%d", count);

    return 0;
}