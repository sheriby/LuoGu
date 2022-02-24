#include <stdio.h>

// 签到题
int main(int argc, const char *argv[]) {
    int n, x;
    int s = 0, k;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        k = i;
        while (k) {
            if (k % 10 == x)
                s++;
            k /= 10;
        }
    }
    printf("%d\n", s);
    return 0;
}