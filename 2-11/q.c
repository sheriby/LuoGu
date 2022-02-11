#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("%d\n", n / 2);
        return 0;
    }
    for (int i = 3; i * i < n; i += 2) {
        if (n % i == 0) {
            printf("%d\n", n / i);
        }
    }
    return 0;
}