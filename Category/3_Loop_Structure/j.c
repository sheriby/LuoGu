#include <stdio.h>

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, const char *argv[]) {
    int l, sum = 0, count = 0;
    scanf("%d", &l);
    for (int i = 2; i < l; i++) {
        if (is_prime(i)) {
            sum += i;
            if (sum > l)
                break;
            printf("%d\n", i);
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}