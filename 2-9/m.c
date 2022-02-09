#include <stdio.h>

int gcd(int m, int n) {
    if (m % n == 0)
        return n;
    return gcd(n, m % n);
}

int main(int argc, char const *argv[]) {
    int min = 0x7fffffff, max = 0, x;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &x);
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }
    int g = gcd(max, min);
    printf("%d/%d\n", min / g, max / g);

    return 0;
}
