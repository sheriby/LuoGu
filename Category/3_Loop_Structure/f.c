#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, x, k, tmp, count = 0;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        k = i;
        while (k) {
            tmp = k % 10;
            if (tmp == x)
                count++;
            k /= 10;
        }
    }
    printf("%d\n", count);
    return 0;
}